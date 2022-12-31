#ifndef _RANGE_HPP_
#define _RANGE_HPP_

#include <cstdint>
#include <iterator>
#include <type_traits>
#include "utils.hpp"

UTILS_BEGIN


template<typename _Range>
struct range_iterator
{
	using iterator_category = std::bidirectional_iterator_tag;
	using value_type		= typename _Range::value_type;
	using difference_type	= value_type;
	using pointer			= value_type;
	using reference			= value_type;
	using iter_type			= range_iterator;

	static_assert(std::is_integral<value_type>::value, "value_type must be an integer type!");


	constexpr explicit range_iterator(pointer pos, difference_type step = 1) noexcept
		: _pos(pos), _step(step) { }

	iter_type& operator++() noexcept
	{ 
		_pos += _step; 
		return *this;
	}

	iter_type operator++(int) noexcept
	{
		iter_type temp = *this;
		++(*this);
		return temp;
	}

	iter_type& operator--() noexcept
	{ 
		_pos -= _step; 
		return *this;
	}

	iter_type operator--(int) noexcept
	{
		iter_type temp = *this;
		--(*this);
		return temp;
	}

	constexpr reference operator*() const noexcept					{ return _pos;										}

	constexpr bool operator==(const iter_type& iter) const noexcept	{ return _step == iter._step && _pos == iter._pos;	}
	constexpr bool operator!=(const iter_type& iter) const noexcept	{ return !(*this == iter);							}

private:
	pointer					_pos;
	const difference_type	_step;
};



struct range
{
	using value_type	= _if_else_t<sizeof(void*) == 4, std::int32_t, std::int64_t>;
	using size_type		= std::make_unsigned_t<value_type>;
	using iterator		= range_iterator<range>;

	static_assert(std::is_integral<value_type>::value, "value_type must be an integer type!");

	constexpr explicit range(value_type last) noexcept
		: _first(0), _last(last), _step(1) { }

	constexpr range(value_type first, value_type last) noexcept
		: _first(first), _last(first > last ? first : last), _step(1) { }

	CONSTEXPR range(value_type first, value_type last, value_type step) noexcept
		: _first(first), _last(last), _step(step ? step : 1)
	{
		if (_step > 0)	_last = _last < _first ? _first : _last;
		else			_last = _last > _first ? _first : _last;

		const value_type num = abs(_last - _first) / abs(_step);
		if (_last != _first + _step * num) _last = _first + _step * (num + 1);
	}


	constexpr iterator begin() const noexcept		{ return iterator(_first, _step);			}
	constexpr iterator end() const noexcept			{ return iterator(_last , _step);			}

	constexpr size_type size() const noexcept		{ return abs(_last - _first) / abs(_step);	}
	constexpr size_type max_size() const noexcept	{ return size_type(-1)		 / abs(_step);	}

private:
	value_type	_first;
	value_type	_last;
	value_type	_step;
};


UTILS_END

#endif // _RANGE_HPP_