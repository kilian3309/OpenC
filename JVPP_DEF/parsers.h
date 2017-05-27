#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include "global.h"
#include "fwd.h"
#include "file.h"
#include <cctype>
#include <functional>
#include <map>

namespace Core {
	template<typename fileNType, typename charType>class Parser {
		fileNType m_File;
		std::vector<charType> m_Separators = { '?', ',', '.', ';', '/', ':', '<', '>', '{', '}', '(', ')', '[', ']' };	//Non constant vector to allow adding symbols in run time
		using strType = std::basic_string<charType, std::char_traits<charType>, std::allocator<charType>>;

		Namespace* actualNamespace;

		std::wofstream outcode;

		std::map<strType, std::function<int(strType&&)>> m_ppParsers;


	public:
		Parser() {
			_Mybase();

		}

		Parser(File* output) {

		}

		void _Mybase() {
			assert((oclib::is_same_type<strType, std::string>::value || oclib::is_same_type<strType, std::wstring>::value) && "Incorrect strType ! (std::string or std::wstring only)");
			assert((oclib::is_same_type<charType, char>::value || oclib::is_same_type<charType, wchar_t>::value) && "Incorrect charType ! (char or wchar_t)");
			//m_ppParsers.insert(std::make_pair(L"define", ));
		}

		int defineParser(strType&& str) {

		}

		bool openOut(strType& name) {
			outcode.open(name);
			return outcode.good() && outcode.is_open();
		}


		/*
			Parse a line to separe expressions:

		*/
		std::vector<strType> wordParser(strType line) {
			std::vector<strType> ret;
			ret.push_back(null);
			for (strType::iterator it(line.begin()); it < line.end(); ++it) {
				if (isalnum(*it)) {	//Simple character, continuing
					if (GetLastOf(ret).size() > 0 && !isalnum(GetLastOf(GetLastOf(ret)))) { //Retour si dernier character n'est pas une lettre
						ret.push_back(null);
						GetLastOf(ret).push_back(*it);	//Application dernier character
					}
					else
						GetLastOf(ret).push_back(*it);
				}
				else {				//Chactere speciale, retour
					if (GetLastOf(ret).size() > 0 && isspace(*it) && isspace(GetLastOf(GetLastOf(ret)))) //On ne fait rien si le charactere actuelle est un espace et le précédent aussi
						continue;
					ret.push_back(null);
					GetLastOf(ret).push_back(*it); //Retour et application
				}
			}
			return ret;
		}

		int parseFile(fileNType) {
			return 0;
		}

		int parsePreprocessor(std::vector<strType>* line, File* file) {
			OC_LOG_INFO << "PREPROCESSOR";
			/*strType strLine;
			for (std::vector<strType>::iterator it(line->begin()); it != line->end(); ++it) {
				strLine+=(*it);
			}
			OC_LOG_INFO << strLine;*/
			



			return 0;
		}

		int parseVector(std::vector<strType>* vec, File* file) {
			for (std::vector<strType>::iterator it(vec->begin()); it != vec->end(); ++it) {
				OC_LOG_INFO << "IT :'" << (*it) << "'";
				if (*it == L"")
					continue;
				if (*it == L"#") {
					std::vector<strType> buf;
					std::vector<strType>::iterator endlIt(std::find(it, vec->end(), OC_WPARSING_ENDL));
					buf.insert(buf.begin(), it, endlIt);
					parsePreprocessor(&buf, file);
					it+=std::distance(it, endlIt);
				}
			}
			return 0;
		}

		int parseWFile(File* file) {
			OC_LOG_INFO << "Launching wild parsing on :" << file->name();
			if (oclib::is_same_type<strType, std::string>::value)
				return parseFile(file->name());
			if (!oclib::is_same_type<charType, wchar_t>::value) {
				OC_LOG_ERROR << "Cannot use non wchar_t charType with parseWFile !";
				return -1;
			}
			std::wifstream in(file->name());
			OC_LOG_INFO << "Trying to open file...";
			if (!in) {
				OC_LOG_ERROR << "PRELOAD -> Cannot open file: " << strerror(errno);
				return -1;
			}
			OC_LOG_INFO << "Done !";

			std::vector<strType>* Lines = new std::vector<strType>; //Dynamic because huge amount of memory (depending of the file's size)
			strType str;
			while (!in.eof()) {
				std::getline(in, str);
				Lines->push_back(str);
			}
			OC_LOG_INFO << "File readed successfully";
			//actualNamespace = 
			std::vector<strType>doc;
			for (std::vector<strType>::iterator it(Lines->begin()); it < Lines->end(); ++it) {
				std::vector<strType>buf(wordParser(*it));
				doc.insert(doc.end(), buf.begin(), buf.end());
				doc.push_back(L"\\OC_RETURN_COMPILED_LINE");
			}
			delete Lines;

			parseVector(&doc, file);




			in.close();
			return 0;
		}

	};
	
}
