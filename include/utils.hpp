#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#ifndef _UTILS
    #define UTILS_BEGIN namespace utils {
    #define UTILS_END   }
    #define _UTILS      utils
#endif // _UTILS


#include <type_traits>
#include "config.hpp"

UTILS_BEGIN


#if __HAS_CPP17

template<typename... Args>
using void_t = std::void_t<Args...>;

#else
namespace __detail {

template<typename... Args>
struct make_void { using type = void; };

}

template<typename... Args>
using void_t = typename __detail::make_void<Args...>::type;

#endif // __HAS_CPP17


template<bool val, typename T, typename U>  struct _if_else				{ using type = U; };
template<typename T,  typename U>			struct _if_else<true, T, U>	{ using type = T; };
template<bool val, typename T, typename U>  using  _if_else_t			= typename _if_else<val, T, U>::type;





template<typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
constexpr auto abs(T num) noexcept
{
	return num < 0 ? -num : num;
}


UTILS_END

#endif // _UTILS_HPP_