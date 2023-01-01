#ifndef _CONFIG_HPP_
#define _CONFIG_HPP_


#if defined(__GNUC__) || defined(__clang__)
#   define __CPLUSPLUS   __cplusplus
#elif defined(_MSC_VER)
#   define __CPLUSPLUS   _MSVC_LANG
#endif


#if __CPLUSPLUS < 201103L
	#error __CPLUSPLUS must be greater than or equal to 201103L
#endif
#if __CPLUSPLUS >= 201103L
	#define __HAS_CPP11 1
#endif
#if __CPLUSPLUS >= 201402L
	#define __HAS_CPP14 1
#endif
#if __CPLUSPLUS >= 201703L
	#define __HAS_CPP17 1
#endif




#if __HAS_CPP11
	#define NORETURN 		[[noreturn]]
#else
	#define NORETURN
#endif // __HAS_CPP11


#if __HAS_CPP14
	#define DEPRECATED 		[[deprecated]]
#else
	#define DEPRECATED
#endif // __HAS_CPP14


#if __HAS_CPP17
	#define CONSTEXPR 		constexpr
	#define NODISCARD 		[[nodiscard]]
	#define MAYBE_UNUSED	[[maybe_unused]]
#else
	#define CONSTEXPR
	#define NODISCARD
	#define MAYBE_UNUSED
#endif // __HAS_CPP17



#define __STR(x)	#x
#define _STR(x)		__STR(x)


#define __CAT(a, b)	a ## b
#define _CAT(a, b)	__CAT(a, b)


#define UTILS_VERSION_MAJOR	0
#define UTILS_VERSION_MINOR	1
#define UTILS_VERSION_PATCH 0


#define UTILS_VERSION_VALUE (UTILS_VERSION_MAJOR * 10000 + UTILS_VERSION_MINOR * 100 + UTILS_VERSION_PATCH)
#define UTILS_VERSION_STR	_STR(_CAT(_CAT(_CAT(UTILS_VERSION_MAJOR, .), _CAT(UTILS_VERSION_MINOR, .)), UTILS_VERSION_PATCH))


#endif // _CONFIG_HPP_