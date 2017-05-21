#pragma once
#include "global.h"
#include "fwd.h"
#include "nllclass.h"
#include "attributes.h"
#include <vector>



namespace Core {

	template<class tyName>class _Type {
		tyName m_Name;
		std::vector<Function*> m_Functions;
		std::vector<Type*> m_Types;
		std::vector<Attribute*> m_AvalAttributes;
		std::vector<Operator*> m_Operators;
		std::vector<Instance*> m_Instances;

	public:
		_Type(tyName name) : m_Name(name){

		}

		_Type(tyName name, std::vector<Function*> functs, std::vector<Type*> types=null) : m_Name(name), m_Functions(functs), m_Typess(types) {

		}


		void addFunction(Function* func) {
			m_Functions.push_back(func);
		}

		template<typename Ret>inline bool isFunction(typeFunctionName& funcName) const {
			for (std::vector<Function*>::iterator it(m_Functions.begin()); it != m_Functions.end(); ++it) {
				if ((*it)->name() == funcName)
					return true;
			}
			return false;
		}


		inline bool isAttribute(typeAttributeName atName) const {
			for (std::vector<Attribute*>::iterator it(m_AvalAttributes.begin()); it != m_AvalAttributes.end(); ++it) {
				if ((*it)->name() == atName)
					return true;
			}
			return false;
		}

		void addAttribute(Attribute* attr) {
			m_AvalAttributes.push_back(attr);
		}
	};


}