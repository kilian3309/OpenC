#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <assert.h>
#include "global.h"
#include "fwd.h"
#include "file.h"
#include <cctype>

namespace Core {
	template<typename fileNType, typename charType>class Parser {
		fileNType m_File;
		std::vector<charType> m_Separators = { '?', ',', '.', ';', '/', ':', '<', '>', '{', '}', '(', ')', '[', ']' };	//Non constant vector to allow adding symbols in run time
		using strType = std::basic_string<charType, std::char_traits<charType>, std::allocator<charType>>;

	public:
		Parser() {
			assert((oclib::is_same_type<strType, std::string>::value || oclib::is_same_type<strType, std::wstring>::value) && "Incorrect strType ! (std::string or std::wstring only)");
			assert((oclib::is_same_type<charType, char>::value || oclib::is_same_type<charType, wchar_t>::value) && "Incorrect charType ! (char or wchar_t)");
		}

		/*
			Parse a line to separe expressions:
			
		*/
		std::vector<strType> wordParser(strType line) {
			std::vector<strType> ret;
			ret.push_back(null);
			for (strType::iterator it(line.begin()); it < line.end(); ++it) {
				if (isalnum(*it)) {	//Simple character, continuing
					if (GetLastOf(ret).size()>0&&!isalnum(GetLastOf(GetLastOf(ret)))) { //Retour si dernier character n'est pas une lettre
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

		int parseDeclaration(File* file) {

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
			
			std::vector<strType>* Lines = new std::vector<strType>;
			strType str;
			while (!in.eof()) {
				std::getline(in, str);
				Lines->push_back(str);
			}
			OC_LOG_INFO << "File readed successfully";
			std::vector<strType>doc;
			for (std::vector<strType>::iterator it(Lines->begin()); it < Lines->end(); ++it) {
				std::vector<strType>buf(wordParser(*it));
				doc.insert(doc.end(), buf.begin(), buf.end());
			}
			delete Lines;
			while (doc.size() > 0 && doc.at(0) == L" ") doc.erase(doc.begin(), doc.begin() + 1);
			OC_LOG_INFO << "LIST:";
			for (std::vector<strType>::iterator it(doc.begin()); it != doc.end(); ++it) {
				OC_LOG_INFO << (*it);
			}






			in.close();
			return 0;
		}

	};
	
}
