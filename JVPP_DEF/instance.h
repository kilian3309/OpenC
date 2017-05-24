#pragma once
#include "types.h"

namespace Core {
	template<typename tyName>class _Instance {
		Type* m_Type;
		tyName m_Name;

	public:
		_Instance(Type ty, tyName name) : m_Type(&ty), m_Name(name) {

		}
	
		inline Type* type() const {
			return m_Type;
		}
		
		inline tyName name() const {
			return m_Name;
		}


	};
}