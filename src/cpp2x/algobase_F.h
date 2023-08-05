/*
 * Copyright (c) 1997    -zorjen122
 * Silicon Graphics Computer Systems, Inc.
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Silicon Graphics makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 */


#pragma once

#define _ALGOBASE_IOP_
#ifdef _ALGOBASE_IOP_

#include "cppconfig.h"

#include <string.h>


template<class _Ty, _Ty... _args>
struct _Args_is_unitvalue {
    static constexpr _Ty value = _Ty();
    static constexpr size_t N = 0;
};

template<class _Ty, _Ty _val>
struct _Args_is_unitvalue<_Ty, _val> {
    static constexpr _Ty value = _val;
    static constexpr size_t N = 1;
};


template<class _Iter, class _Ty>
IOP_CONSTEXPR_CXX14 void fill(_Iter __frist, _Iter __last, const _Ty& value) {
    for (;__frist != __last;++__frist) *__frist = value;
}

template<class _Iter, class _Size, class _Ty>
IOP_CONSTEXPR_CXX14 void fill_n(_Iter __frist, _Size __n, const _Ty& __val) {
    for (;__n > 0;--__n, ++__frist)
        *__frist = __val;
}

IOP_CONSTEXPR_CXX14 void fill(unsigned char* __first, unsigned char* __last,
    const unsigned char& __c) {
    unsigned char __tmp = __c;
    memset(__first, __tmp, __last - __first);
}

IOP_CONSTEXPR_CXX14 void fill(signed char* __first, signed char* __last,
    const signed char& __c) {
    signed char __tmp = __c;
    memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

IOP_CONSTEXPR_CXX14 void fill(char* __first, char* __last, const char& __c) {
    char __tmp = __c;
    memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}



template<class _Ty>
IOP_CONSTEXPR_CXX14 void swap_ptr(_Ty* _ptra, _Ty* _ptrb) {
    if (_ptrb != nullptr || _ptrb != nullptr) {
        auto _inner = *_ptra;
        *_ptra = *_ptrb;
        *_ptrb = _inner;
    }
}


template<class _Ty>
auto copy(_Ty __q, _Ty __p, _Ty __res) {
    return ::std::copy(__q, __p, __res);
}


template<class _Ty>
_Ty find(_Ty __first, _Ty __last, size_t __v) {
    _Ty it = __first;
    for (;it != __last;++it) {
        if (*it == __v)
            break;
    }
    return it;
}


#endif          //* _ALGOBASE_IOP_
