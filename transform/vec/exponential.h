#ifndef TRANSFORM_VEC_EXPONENTIAL_H_
#define TRANSFORM_VEC_EXPONENTIAL_H_

#include <cmath>

#include "transform/types.h"
#include "transform/vec/vecn.h"

namespace tf {

using ::std::pow;
template <usize L, typename T> constexpr Vec<L, T> pow(Vec<L, T> const& base, Vec<L, T> const& exponent);

using ::std::exp;
template <usize L, typename T> constexpr Vec<L, T> exp(Vec<L, T> const& vec);

using ::std::log;
template <usize L, typename T> constexpr Vec<L, T> log(Vec<L, T> const& vec);

using ::std::exp2;
template <usize L, typename T> constexpr Vec<L, T> exp2(Vec<L, T> const& vec);

using ::std::log2;
template <usize L, typename T> constexpr Vec<L, T> log2(Vec<L, T> const& vec);

using ::std::sqrt;
template <usize L, typename T> constexpr Vec<L, T> sqrt(Vec<L, T> const& vec);

template <typename T> constexpr T inversesqrt(T sca);
template <usize L, typename T> constexpr Vec<L, T> inversesqrt(Vec<L, T> const& vec);

/************************
 * Function definitions *
 ************************/

template          <typename T> constexpr Vec<1, T> pow(Vec<1, T> const& base, Vec<1, T> const& exponent) { return Vec<1, T>(pow(base.head(), exponent.head())); }
template <usize L, typename T> constexpr Vec<L, T> pow(Vec<L, T> const& base, Vec<L, T> const& exponent) { return Vec<L, T>(pow(base.head(), exponent.head()), pow(base.tail(), exponent.tail())); }

template          <typename T> constexpr Vec<1, T> exp(Vec<1, T> const& vec) { return Vec<1, T>(exp(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> exp(Vec<L, T> const& vec) { return Vec<L, T>(exp(vec.head()), exp(vec.tail())); }

template          <typename T> constexpr Vec<1, T> log(Vec<1, T> const& vec) { return Vec<1, T>(log(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> log(Vec<L, T> const& vec) { return Vec<L, T>(log(vec.head()), log(vec.tail())); }

template          <typename T> constexpr Vec<1, T> exp2(Vec<1, T> const& vec) { return Vec<1, T>(exp2(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> exp2(Vec<L, T> const& vec) { return Vec<L, T>(exp2(vec.head()), exp2(vec.tail())); }

template          <typename T> constexpr Vec<1, T> log2(Vec<1, T> const& vec) { return Vec<1, T>(log2(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> log2(Vec<L, T> const& vec) { return Vec<L, T>(log2(vec.head()), log2(vec.tail())); }

template          <typename T> constexpr Vec<1, T> sqrt(Vec<1, T> const& vec) { return Vec<1, T>(sqrt(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> sqrt(Vec<L, T> const& vec) { return Vec<L, T>(sqrt(vec.head()), sqrt(vec.tail())); }

template <typename T> constexpr T inversesqrt(T sca) { return static_cast<T>(1) / sca; }
template          <typename T> constexpr Vec<1, T> inversesqrt(Vec<1, T> const& vec) { return Vec<1, T>(inversesqrt(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> inversesqrt(Vec<L, T> const& vec) { return Vec<L, T>(inversesqrt(vec.head()), inversesqrt(vec.tail())); }

}  // namespace tf

#endif  // TRANSFORM_VEC_EXPONENTIAL_H_
