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

	public:
		_Namespace(tyName name) : m_Name(name) {

		}

		void addFunction(Function* func) {
			m_Functions.push_back(func);
		}

		bool isInstance(typeInstanceName insName) {

		}

		void name() const {
			return m_Name;
		}

		void addType(Type* ty) {
			m_Types.push_back(ty);
		}


		void addInstace(Instance* inst) {
			m_Instances.push_back(inst);
		}


	};
}