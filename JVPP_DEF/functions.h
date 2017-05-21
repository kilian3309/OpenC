#pragma once
#include "global.h"
#include <vector>
#include "fwd.h"

namespace Core {

	//SPCIFIC :
	//Function container aren't containing a pointer !!!!
	// std::vector<Type*> --> std::vector<Type>
	//

	/*
	template<typename tyFName, typename tyRet>class _Function : public _PFunction {
		tyFName m_Name;
		tyRet m_ReturnedType;
		std::vector<Type> m_Args;

	public:
		using TypeReturedValue = tyRet;
		//typedef tyFName  TypeFunctionName;
		using TypeFunctionName = tyFName;

		_Function(std::vector<Type> args) : m_Args(args) {
			
		}

		_Function(tyFName name, std::vector<Type> args) : m_Args(args), m_Name(name) {

		}

		inline tyFName name() const {
			return m_Name;
		}
	};
	*/

	template<typename tyFName>class _Function {
		tyFName m_Name;
		Type* m_ReturnedType;
		std::vector<Type*> m_Args;

	public:
		_Function(tyFName _name, Type* retType, std::vector<Type*> args) : m_ReturnedType(retType), m_Args(args), m_Name(_name) {}
		_Function(tyFName _name, Type retType, std::vector<Type*> args) : m_ReturnedType(&retType), m_Args(args), m_Name(_name) {}

		inline Type* returnedType() const {
			return m_ReturnedType;
		}

		inline tyFName name() const {
			return m_Name;
		}

	};

}
