#pragma once

#include <cstdint>

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

template<typename T>
constexpr unsigned BitSize() {
    return sizeof(T) * 8; // yeah I know I shouldn't use 8 here.
}

template<unsigned bit_count, typename T>
constexpr T SignExtend(const T value) {
    static_assert(bit_count <= BitSize<T>(), "bit_count larger than bitsize of T");

    constexpr T mask = static_cast<T>(1ULL << bit_count) - 1;
    const bool sign_bit = (value >> (bit_count - 1)) != 0;
    if (sign_bit) {
        return value | ~mask;
    }
    return value;
}