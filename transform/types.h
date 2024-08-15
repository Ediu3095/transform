#ifndef TRANSFORM_TYPES_H_
#define TRANSFORM_TYPES_H_

#include <cstdint>

namespace tf {

using i8    = ::std::int8_t;
using i16   = ::std::int16_t;
using i32   = ::std::int32_t;
using i64   = ::std::int64_t;
using isize = ::std::intmax_t;

using u8    = ::std::uint8_t;
using u16   = ::std::uint16_t;
using u32   = ::std::uint32_t;
using u64   = ::std::uint64_t;
using usize = ::std::uintmax_t;

using f32 = float;
using f64 = double;

}  // namespace tf

#endif  // TRANSFORM_TYPES_H_
