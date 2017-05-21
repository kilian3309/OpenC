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
	class compiler;

	using typeNamespaceName = std::wstring;
	using typeTypeName		= std::wstring;
	using typeAttributeName = std::wstring;
	using typeOperatorName	= std::wstring;
	using typeFunctionName	= std::wstring;
	using typeFileName		= wchar_t;

	class Instance;

	//Alias Creation
	using Namespace		= _Namespace<typeNamespaceName>;
	using Type			= _Type<typeTypeName>;
	using Attribute		= _Attribute<typeAttributeName>;
	using Operator		= _Operator<typeOperatorName>;
	using Function		= _Function<typeFunctionName>;
	using File			= _File<typeFileName>;
	using WParser		= Parser<std::wstring, wchar_t>;
}
