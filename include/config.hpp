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





#endif // _CONFIG_HPP_