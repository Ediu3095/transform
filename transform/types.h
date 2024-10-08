#ifndef TRANSFORM_TYPES_H_
#define TRANSFORM_TYPES_H_

#include <cstdint>

namespace tf {

using i8    = int8_t;
using i16   = int16_t;
using i32   = int32_t;
using i64   = int64_t;
using isize = std::intmax_t;

using u8    = uint8_t;
using u16   = uint16_t;
using u32   = uint32_t;
using u64   = uint64_t;
using usize = std::uintmax_t;

using f32 = float;
using f64 = double;

}  // namespace tf

#endif  // TRANSFORM_TYPES_H_
