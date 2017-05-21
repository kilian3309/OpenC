#pragma once
#include "types.h"

namespace Core {
	class Instance {
		Type* m_Type;

	public:
		Instance(Type ty) : m_Type(&ty) {

		}
	
		inline Type* type() const {
			return m_Type;
		}
		


	};
}