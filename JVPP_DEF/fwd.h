#pragma once
#include <string>

namespace Core {
	//Class global declaration
	template<typename>class _Type;
	template<typename>class _Function;
	template<typename>class _Attribute;
	template<typename>class _Operator;
	template<typename>class _Namespace;
	template<typename, typename>class Parser;
	template<typename>class _File;
	template<typename>class _Instance;
	class compiler;

	//CHAR ELEMENTS
	using typeNamespaceName = wchar_t;
	using typeTypeName		= wchar_t;
	using typeAttributeName = wchar_t;
	using typeOperatorName	= wchar_t;
	using typeFunctionName	= wchar_t;
	using typeFileName		= wchar_t;
	using typeInstanceName	= wchar_t;

	//STRING ELEMENTS CONSTRUCTED WITH CHAR ELEMENTS
	using typeInstanceString	= std::basic_string<typeInstanceName, std::char_traits<typeInstanceName>, std::allocator<typeInstanceName>>;
	using typeFunctionString	= std::basic_string<typeFunctionName, std::char_traits<typeFunctionName>, std::allocator<typeFunctionName>>;
	using typeNamespaceString	= std::basic_string<typeNamespaceName, std::char_traits<typeNamespaceName>, std::allocator<typeNamespaceName>>;
	using typeTypeString		= std::basic_string<typeTypeName, std::char_traits<typeTypeName>, std::allocator<typeTypeName>>;
	using typeAttributeString	= std::basic_string<typeAttributeName, std::char_traits<typeAttributeName>, std::allocator<typeAttributeName>>;
	using typeFileString		= std::basic_string<typeFileName, std::char_traits<typeFileName>, std::allocator<typeFileName>>;
	using typeOperatorString	= std::basic_string<typeOperatorName, std::char_traits<typeOperatorName>, std::allocator<typeOperatorName>>;

	//Alias Creation
	using Namespace		= _Namespace<typeNamespaceString>;
	using Type			= _Type<typeTypeString>;
	using Attribute		= _Attribute<typeAttributeString>;
	using Operator		= _Operator<typeOperatorString>;
	using Function		= _Function<typeFunctionString>;
	using File			= _File<typeFileString>;
	using WParser		= Parser<std::wstring, wchar_t>;
	using Instance		= _Instance<typeInstanceString>;
}
