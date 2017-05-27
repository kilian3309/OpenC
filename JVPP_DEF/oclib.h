#pragma once

template<class _Container>decltype(auto) getLastOf(const _Container& cont) {
	return cont.at(cont.size() - 1);
}

#define GetLastOf(x) x.at(x.size()-1)
#define GetLastOfPtr(x) x->at(x->size()-1)

template<class _Container>decltype(auto) getLastOf(const _Container* cont) {
	return cont->at(cont->size() - 1);
}


#ifdef OC_DEBUG_ASSERT
#include <iostream>
#define OC_MULTI_ASSERT(x, msg) 
#else
#include <assert.h>
#define OC_MULTI_ASSERT(x, msg) static_assert(x, msg); \
								assert(x&&msg);
#define OC_ASSERT(x) assert(x);
#endif

#ifndef OC_NO_VECTOR
#include <vector>
#endif // !OC_NO_VECTOR
#ifndef OC_NO_FUNCTIONAL
#include <functional>
#endif // !OC_NO_FUNCTIONAL
#include <type_traits>


namespace oclib {

	template<class T, class U>
	struct is_same_type : std::false_type {};

	template<class T>
	struct is_same_type<T, T> : std::true_type {};

	template <class C>
	constexpr auto size(const C& c) -> decltype(c.size()) {
		return c.size();
	}

	template <class T, size_t N>
	constexpr size_t size(const T(&array)[N]) noexcept {
		return N;
	}


	template<typename ret, typename args>class FunctionContainer {
		std::function<ret(args)> func;

	public:
		ret operator()(args& arg) {
			return func(arg);
		}
	};




#ifndef OC_NO_VECTOR

	template<typename T>bool is_in(const std::vector<T>&& vec, const T&& v) {
		for (std::vector<T>::iterator it(vec.begin()); it != vec.end(); ++it) {
			if (((*it)) == v)
				return true;
		}
		return false;
	}

	template<typename T, typename N>bool is_in(std::vector<T> vec, const N&&v, std::function<N()>* func) {
		for (std::vector<T>::iterator it(vec.begin()); it != vec.end(); ++it) {
			if ((*it).func() == v)
				return true;
		}
		return false;
	}

#endif // !OC_NO_VECTOR

}