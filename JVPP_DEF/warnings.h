#pragma once
#include <string>

template<typename tyName, template tyDesc>class _Warning {
	int m_Code;
	tyName m_Name;
	tyDesc m_Desc;

public:

	_Warning(tyName name, tyDesc desc, int code = 0) : m_Name(name), m_Desc(desc), m_Code(code) {

	}

	int code() const {
		return m_Code;
	}

	tyName name() const {
		return m_Name;
	}

	tyDesc desc() const {
		return m_Desc;
	}
};