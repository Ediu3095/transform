/**
 * @ref core
 * @file transform/sca.h
 *
 * @defgroup core_scalar Scalar types
 * @ingroup core
 *
 * Aliases for scalar types. These follow Rust's primitive naming style.
 */

#ifndef TRANSFORM_TYPES_H_
#define TRANSFORM_TYPES_H_

#include <cmath>
#include <cstdint>

namespace tf {
/** @addtogroup core_scalar
 * @{ */

using i8    = ::std::int8_t;    ///< 8 bit signed integer.
using i16   = ::std::int16_t;   ///< 16 bit signed integer.
using i32   = ::std::int32_t;   ///< 32 bit signed integer.
using i64   = ::std::int64_t;   ///< 64 bit signed integer.
using isize = ::std::intmax_t;  ///< Largest possible signed integer given the target architecture.

using u8    = ::std::uint8_t;    ///< 8 bit unsigned integer.
using u16   = ::std::uint16_t;   ///< 16 bit unsigned integer.
using u32   = ::std::uint32_t;   ///< 32 bit unsigned integer.
using u64   = ::std::uint64_t;   ///< 64 bit unsigned integer.
using usize = ::std::uintmax_t;  ///< Largest possible unsigned integer given the target architecture.

using f32 = ::std::float_t;   ///< 32 bit floating point number.
using f64 = ::std::double_t;  ///< 64 bit floating point number.

/** @} */
}  // namespace tf

#endif  // TRANSFORM_TYPES_H_
