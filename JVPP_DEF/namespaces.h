#pragma once
#include "global.h"
#include "fwd.h"
#include <vector>
#include <boost\any.hpp>

namespace Core {
	template<class tyName>class _Namespace {
		std::vector<Function*> m_Functions;
		std::vector<Type*> m_Types;
		std::vector<Instance*> m_Instances;
		tyName m_Name;
		tyName m_Id;

	public:
		_Namespace(tyName name) : m_Name(name), m_Id(name) {

		}

		_Namespace(tyName name, tyName id) : m_Name(name), m_Id(id) {

		}

		void addFunction(Function* func) {
			m_Functions.push_back(func);
		}

		bool isInstance(typeInstanceName insName) {

		}

		tyName name() const {
			return m_Name;
		}

		tyName id() const {
			return m_Id;
		}

		void addType(Type* ty) {
			m_Types.push_back(ty);
		}

		void addInstace(Instance* inst) {
			m_Instances.push_back(inst);
		}
	};
}