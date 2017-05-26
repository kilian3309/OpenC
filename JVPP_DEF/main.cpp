#include "tools.h"
#include <vector>
#include <iostream>
#include "functions.h"
#include "types.h"
#include "fwd.h"
#include "oclib.h"
#include "namespaces.h"
#include "instance.h"
#include "logger.h"
#include <fstream>
#include <stdlib.h>
#include <string>
#include "parsers.h"
#include "compiler.h"
#include "file.h"

INITIALIZE_EASYLOGGINGPP
#define ELPP_THREAD_SAFE

int main() {
	//LOG INITIALIZATION
	std::remove("global.log");
	el::Configurations conf;
	conf.set(el::Level::Global, el::ConfigurationType::Filename, "global.log");
	conf.set(el::Level::Global, el::ConfigurationType::LogFlushThreshold, "1");
	el::Loggers::reconfigureAllLoggers(conf);


	Core::Namespace name(L"testNamespace");
	Core::Type t_int(L"int");
	Core::Function f(L"func", t_int, { &t_int });
	Core::Instance inst(t_int, L"var");

	t_int.addFunction(&f);

	name.addFunction(&f);
	name.addType(&t_int);
	name.addInstace(&inst);

	Core::File testFile(L"testFile.txt");

	Core::compiler _compil;
	Core::WParser _parser;
	
	_parser.parseWFile(&testFile);
	std::vector<std::wstring> test =_parser.wordParser(L"test,54++5 4+  ++      ++dfgsedrg5445:5ft!!;;,\\");

	system("PAUSE");

	return 0;
}