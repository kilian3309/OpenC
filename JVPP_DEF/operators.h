#pragma once
#include "oclib.h"

namespace Core {
	enum OP_TYPE {
		PRE,     //Operateur avant e.g: - (int)
		POST,	 //Operateur après e.g: (int) ++
		BETW,    //Operateur entre e.g: (int) == (int)
		SPE		 //Operateur spécial 
	};

	template<class opChars>class _Operator {
		opChars m_Chars;
		int m_MaxSize;
		OP_TYPE m_Type;

	public:

		inline _Operator(opChars ch, OP_TYPE type, int maxsize=3) : m_Chars(ch), m_Type(type), m_MaxSize(maxsize) {
			OC_ASSERT(oclib::size(ch) < maxsize&&"Operator is too long !");
		}

		inline bool operator==(const _Operator<opChars>& op) const {
			m_Chars == op.m_Chars&&m_MaxSize == op.m_MaxSize&&m_Type==op.m_Type;
		}

		inline bool operator!=(const _Operator<opChars>& op) const {
			m_Chars != op.m_Chars&&m_MaxSize != op.m_MaxSize&&m_Type==op.m_Type;
		}

		inline opChars get() const {
			return m_Chars;
		}

		inline int size() const {
			return m_MaxSize;
		}
	};
}
