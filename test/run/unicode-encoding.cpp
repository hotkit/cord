/*
    Copyright 2016-2017, Felspar Co Ltd. http://www.kirit.com/f5
    Distributed under the Boost Software License, Version 1.0.
    See accompanying file LICENSE_1_0.txt or copy at
        http://www.boost.org/LICENSE_1_0.txt
*/


#include <cassert>
#include <iostream>
#include <f5/cord/unicode.hpp>


int main() {
    using u8encoded = decltype(f5::u8encode(0));
    assert((f5::u8encode(0) == u8encoded{1, {{0, 0, 0, 0}}}));
    assert((f5::u8encode(' ') == u8encoded{1, {{0x20, 0, 0, 0}}}));
    assert((f5::u8encode(0xa2) == u8encoded{2, {{0xc2, 0xa2, 0, 0}}}));
    assert((f5::u8encode(0x20ac) == u8encoded{3, {{0xe2, 0x82, 0xac, 0}}})); // euro
    assert((f5::u8encode(0x10348) == u8encoded{4, {{0xf0, 0x90, 0x8d, 0x88}}}));
    assert((f5::u8encode<void>(0xffffff) == u8encoded{0, {{0, 0, 0, 0}}}));

    using u16encoded = decltype(f5::u16encode(0));
    assert((f5::u16encode(0) == u16encoded{1, {{0, 0}}}));
    assert((f5::u16encode(' ') == u16encoded{1, {{' ', 0}}}));
    assert((f5::u16encode(0x10348) == u16encoded{2, {{0xD800, 0xDF48}}}));
    assert((f5::u16encode(0x1D11E) == u16encoded{2, {{0xD834, 0xDD1E}}}));

    return 0;
}

