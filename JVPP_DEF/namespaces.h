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


	public:
		_Namespace() {

		}

		void addFunction(Function* func) {
			m_Functions.push_back(func);
		}

		void addType(Type* ty) {
			m_Types.push_back(ty);
		}


		void addInstace(Instance* inst) {
			m_Instances.push_back(inst);
		}


	};
}