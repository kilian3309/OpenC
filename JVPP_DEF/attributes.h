#pragma once

namespace Core {
	template<typename tyAName>class _Attribute {
		tyAName m_Name;
	public:
		_Attribute(tyAName name) : m_Name(name) {

		}

		tyAName name() const {
			return m_Name;
		}

		bool operator==(_Attribute<tyAName>& attr) const {
			return m_Name == attr.m_Name;
		}

		bool operator!=(_Attribute<tyAName>& attr) const {
			return m_Name != attr.m_Name;
		}
	};

	
}
