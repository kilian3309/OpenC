#pragma once

/*

			NULL_CLASS
		  DEV: KILIAN J.

	  Copyright 2017 J.Kilian
	    OPEN C VERSION ONLY

This C++ Header file is reserved to authorized
developpers and cannot be shared or distribued.

*/

#include <vector>
#include "fwd.h"

/*

namespace compiler { //Nike les rajeux de mon talent
	class Type;
	class Function;
	class Namespace;
}*/

//Uniform null for all objects (defines)
class null_class {
public:
	explicit operator int() const {
		return NULL;
	}

	explicit operator float() const {
		return NULL;
	}

	explicit operator double() const {
		return NULL;
	}

	operator std::string() const {
		return "";
	}

	explicit operator char() const {
		return '\0';
	}

	explicit operator char*() const {
		return '\0';
	}

	//Any pointer to nullptr conversion
	template<typename T>inline explicit operator T*() const {
		return nullptr;
	}

	template<typename T>inline operator std::vector<T>() const {
		return std::vector<T>({});
	}

	operator std::wstring() const {
		return L"";
	}

	operator wchar_t() const {
		return '\0';
	}

	template<typename T>inline bool operator ==(const std::vector<T>& vec) const {
		return vec == {};
	}

	template<typename T>inline bool operator !=(const std::vector<T>& vec) const {
		return vec != std::vector<T>({});
	}

	int operator-() const {
		return NULL;
	}

	int operator+() const {
		return NULL;
	}

	operator Core::Type() const;

	//operator compiler::Type& ();

/*	operator compiler::Type&() const;
	operator compiler::Function&() const;
	operator compiler::Namespace&() const;
	*/
};

/***CHAR***/

inline bool operator!=(char ch, null_class nn) {
	return (char)nn != ch;
}

inline bool operator==(char ch, null_class nn) {
	return (char)nn == ch;
}

/***INT***/

inline bool operator== (int _int, null_class nn) {
	return static_cast<int>(nn) == _int;
}

inline bool operator!=(int _int, null_class nn) {
	return static_cast<int>(nn) != _int;
}

/*OPERATOR <*/

inline bool operator<(int _int, null_class nn) {
	return _int < static_cast<int>(nn);
}

inline bool operator<(null_class nn, int _int) {
	return static_cast<int>(nn) < _int;
}

/*OPERATOR <*/

inline bool operator>(int _int, null_class nn) {
	return _int > static_cast<int>(nn);
}

inline bool operator>(null_class nn, int _int) {
	return static_cast<int>(nn) > _int;
}

/*OPERATOR >=*/

inline bool operator>=(int _int, null_class nn) {
	return _int >= static_cast<int>(nn);
}

inline bool operator>=(null_class nn, int _int) {
	return static_cast<int>(nn) >= _int;
}

/*OPERATOR <=*/

inline bool operator<=(int _int, null_class nn) {
	return _int <= static_cast<int>(nn);
}

inline bool operator<=(null_class nn, int _int) {
	return static_cast<int>(nn) <= _int;
}



/***STRING***/

inline bool operator==(std::string str, null_class nn) {
	return reinterpret_cast<std::string&>(nn) == str;
}

inline bool operator==(null_class nn, std::string str) {
	return reinterpret_cast<std::string&>(nn) == str;
}

inline bool operator!=(std::string str, null_class nn) {
	return reinterpret_cast<std::string&>(nn) != str;
}

inline bool operator!=(null_class nn, std::string str) {
	return reinterpret_cast<std::string&>(nn) != str;
}

/***WSTRING ***/
inline bool operator==(std::wstring str, null_class nn) {
	return reinterpret_cast<std::wstring&>(nn) == str;
}

inline bool operator==(null_class nn, std::wstring str) {
	return reinterpret_cast<std::wstring&>(nn) == str;
}

inline bool operator!=(std::wstring str, null_class nn) {
	return reinterpret_cast<std::wstring&>(nn) != str;
}

inline bool operator!=(null_class nn, std::wstring str) {
	return  reinterpret_cast<std::wstring&>(nn) != str;
}



null_class null;