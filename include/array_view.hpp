#ifndef _ARRAY_VIEW_HPP_
#define _ARRAY_VIEW_HPP_

#include <utility>
#include <stdexcept>
#include <type_traits>
#include "utils.hpp"

UTILS_BEGIN


template<typename T>
struct array_view
{
	using value_type		= T;
	using size_type			= std::size_t;
	using pointer			= value_type*;
	using const_pointer		= const value_type*;
	using reference			= value_type&;
	using const_reference	= const value_type&;
	using iterator			= value_type*;
	using const_iterator	= const value_type*;


	template<size_type LEN>
	array_view(value_type(&arr)[LEN]) noexcept
		: _elem(arr), _size(LEN) {}

	template<typename U, size_type LEN, size_type LEN_1,
			std::enable_if_t<std::is_same<T, array_view<U>>::value, int> = 0>
	array_view(T(&arr)[LEN], U(&arr_ad)[LEN][LEN_1]) noexcept
		: _elem(arr), _size(LEN)
	{
		for (size_type i = 0; i < LEN; ++i) _elem[i] = arr_ad[i];
	}

	array_view() noexcept
		: array_view(nullptr, 0) {}

	array_view(pointer ptr, size_type sz) noexcept
		: _elem(ptr), _size(sz)  {}


	size_type		size() const noexcept						{ return _size;						}
	size_type		max_size() const noexcept					{ return size_type(-1);				}
	bool			empty() const noexcept						{ return size() == 0;				}

	iterator		begin() noexcept							{ return _elem;						}
	const_iterator	begin() const noexcept						{ return _elem;						}
	iterator		end() noexcept								{ return _elem + _size;				}
	const_iterator	end() const noexcept						{ return _elem + _size;				}
	const_iterator	cbegin() noexcept							{ return begin();					}
	const_iterator	cbegin() const noexcept						{ return begin();					}
	const_iterator	cend() noexcept								{ return end();						}
	const_iterator	cend() const noexcept						{ return end();						}
	
	reference		operator[](size_type pos)					{ return _elem[pos];				}
	const_reference operator[](size_type pos) const				{ return _elem[pos];				}
	reference		at(size_type pos)							{ _check(pos); return _elem[pos];	}
	const_reference at(size_type pos) const						{ _check(pos); return _elem[pos];	}

	pointer			data() noexcept								{ return _elem;						}
	const_pointer	data() const noexcept						{ return _elem;						}
	pointer			operator&() noexcept						{ return data();					}
	const_pointer	operator&() const noexcept					{ return data();					}

	reference		front()										{ return *(begin());				}
	const_reference front() const								{ return *(begin());				}
	reference		back()										{ return *(end() - 1);				}
	const_reference back() const								{ return *(end() - 1);				}

	void			pop_front() noexcept						{ if (!empty()) {++_elem; --_size;} }
	void			pop_back() noexcept							{ if (!empty()) { 		  --_size;} }

	auto			assign() -> decltype(value_type(), void())	{ assign(value_type());																}
	void			assign(const value_type& val)				{ for (size_type i = 0; i < _size; ++i)	_elem[i] = val;								}
	void			reverse()									{ for (int i = 0, j = int(_size) - 1; i < j; ) std::swap(_elem[i++], _elem[j--]);	}


	array_view slice(size_type first = 0, size_type second = -1) noexcept
	{
		return const_cast<const array_view*>(this)->slice(first, second);
	}

	const array_view slice(size_type first = 0, size_type second = -1) const noexcept
	{
		if (second > _size)	 second = _size;
		if (first  > _size)	 first  = second = 0;
		if (first  > second) first  = second = 0;

		return { _elem + first, second - first };
	}
private:
	void			_check(size_type pos)const					{ if (pos >= _size) throw std::out_of_range("out_of_range"); }

private:
	pointer			_elem;
	size_type		_size;
};


template<typename T, std::size_t N>
array_view<T> make_array_view(T(&arr)[N]) noexcept 
{
	return array_view(arr);
}

template<typename T>
array_view<T> make_array_view(T* ptr, std::size_t len) noexcept 
{
	return array_view(ptr, len);
}


UTILS_END

#endif // _ARRAY_VIEW_HPP_