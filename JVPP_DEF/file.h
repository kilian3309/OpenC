#pragma once
#include "global.h"
#include "fwd.h"
#include "nllclass.h"
#include <string>
#include <vector>

namespace Core {

	template<typename charType>class _File {
		using string = std::basic_string<charType, std::char_traits<charType>, std::allocator<charType>>;

		string m_Name;
		std::vector<Core::Namespace> m_Namespaces;
	public:
		_File(string name, std::vector<Core::Namespace> nam = null) : m_Name(name), m_Namespaces(nam) {

		}

		string name() {
			return m_Name;
		}
	};
}