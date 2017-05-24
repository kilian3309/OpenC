#pragma once
#include "global.h"
#include "fwd.h"
#include "nllclass.h"
#include <string>
#include <vector>

namespace Core {

	template<typename strType>class _File {

		strType m_Name;
		std::vector<Core::Namespace> m_Namespaces;
	public:
		_File(strType name, std::vector<Core::Namespace> nam = null) : m_Name(name), m_Namespaces(nam) {

		}

		strType name() {
			return m_Name;
		}

		void addNamespace(Core::Namespace name) {
			m_Namespaces.push_back(name);
		}

		Core::Namespace* Namespace(typeNamespaceName name) {
			for (std::vector<Core::Namespace>::iterator it(m_Namespaces.begin()); it != m_Namespaces.end(); ++it) {
				if ((*it).name() == name)
					return &*it;
			}
			return null;
		}
	};
}