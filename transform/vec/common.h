#ifndef TRANSFORM_VEC_COMMON_H_
#define TRANSFORM_VEC_COMMON_H_

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

#include "transform/types.h"
#include "transform/vec/vecn.h"

namespace tf {

using ::std::abs;
template <usize L, typename T> constexpr Vec<L, T> abs(Vec<L, T> const& vec);

template <typename T> constexpr T sign(T sca);
template <usize L, typename T> constexpr Vec<L, T> sign(Vec<L, T> const& vec);

using ::std::floor;
template <usize L, typename T> constexpr Vec<L, T> floor(Vec<L, T> const& vec);

using ::std::trunc;
template <usize L, typename T> constexpr Vec<L, T> trunc(Vec<L, T> const& vec);

using ::std::round;
template <usize L, typename T> constexpr Vec<L, T> round(Vec<L, T> const& vec);

using ::std::ceil;
template <usize L, typename T> constexpr Vec<L, T> ceil(Vec<L, T> const& vec);

template <typename T> constexpr T fract(T sca);
template <usize L, typename T> constexpr Vec<L, T> fract(Vec<L, T> const& vec);

template <typename T> constexpr T mod(T dividend, T divisor);
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, T divisor);
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, Vec<L, T> const& divisor);

using ::std::min;
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, T val2);
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, Vec<L, T> const& val2);

using ::std::max;
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, T val2);
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, Vec<L, T> const& val2);

using ::std::clamp;
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, T low, T high);
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, Vec<L, T> const& low, Vec<L, T> const& high);

template <typename T, typename U> constexpr T mix(T val1, T val2, U ratio);
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, U ratio);
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, Vec<L, U> const& ratio);

template <typename T> constexpr T step(T edge, T value);
template <usize L, typename T> constexpr Vec<L, T> step(T edge, Vec<L, T> const& value);
template <usize L, typename T> constexpr Vec<L, T> step(Vec<L, T> const& edge, Vec<L, T> const& value);

template <typename T> constexpr T smoothstep(T edge1, T edge2, T value);
template <usize L, typename T> constexpr Vec<L, T> smoothstep(T edge1, T edge2, Vec<L, T> const& value);
template <usize L, typename T> constexpr Vec<L, T> smoothstep(Vec<L, T> const& edge1, Vec<L, T> const& edge2, Vec<L, T> const& value);

/************************
 * Function definitions *
 ************************/

template          <typename T> constexpr Vec<1, T> abs(Vec<1, T> const& vec) { return Vec<1, T>(abs(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> abs(Vec<L, T> const& vec) { return Vec<L, T>(abs(vec.head()), abs(vec.tail())); }

template <typename T>                                     constexpr T sign(T sca) { return static_cast<T>((static_cast<T>(0) < sca)); }
template <typename T> requires ::std::is_signed<T>::value constexpr T sign(T sca) { return static_cast<T>((static_cast<T>(0) < sca) - (sca < static_cast<T>(0))); }
template          <typename T> constexpr Vec<1, T> sign(Vec<1, T> const& vec) { return Vec<1, T>(sign(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> sign(Vec<L, T> const& vec) { return Vec<L, T>(sign(vec.head()), sign(vec.tail())); }

template          <typename T> constexpr Vec<1, T> floor(Vec<1, T> const& vec) { return Vec<1, T>(floor(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> floor(Vec<L, T> const& vec) { return Vec<L, T>(floor(vec.head()), floor(vec.tail())); }

template          <typename T> constexpr Vec<1, T> trunc(Vec<1, T> const& vec) { return Vec<1, T>(trunc(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> trunc(Vec<L, T> const& vec) { return Vec<L, T>(trunc(vec.head()), trunc(vec.tail())); }

template          <typename T> constexpr Vec<1, T> round(Vec<1, T> const& vec) { return Vec<1, T>(round(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> round(Vec<L, T> const& vec) { return Vec<L, T>(round(vec.head()), round(vec.tail())); }

template          <typename T> constexpr Vec<1, T> ceil(Vec<1, T> const& vec) { return Vec<1, T>(ceil(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> ceil(Vec<L, T> const& vec) { return Vec<L, T>(ceil(vec.head()), ceil(vec.tail())); }

template          <typename T> constexpr        T  fract(T sca) { return sca - floor(sca); }
template          <typename T> constexpr Vec<1, T> fract(Vec<1, T> const& vec) { return Vec<1, T>(fract(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> fract(Vec<L, T> const& vec) { return Vec<L, T>(fract(vec.head()), fract(vec.tail())); }

template <typename T>                                             constexpr T mod(T dividend, T divisor) { return dividend % divisor; }
template <typename T> requires ::std::is_floating_point<T>::value constexpr T mod(T dividend, T divisor) { return ::std::fmod(dividend, divisor); }
template          <typename T> constexpr Vec<1, T> mod(Vec<1, T> const& dividend, T divisor) { return Vec<1, T>(mod(dividend.head(), divisor)); }
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, T divisor) { return Vec<L, T>(mod(dividend.head(), divisor), mod(dividend.tail(), divisor)); }
template          <typename T> constexpr Vec<1, T> mod(Vec<1, T> const& dividend, Vec<1, T> const& divisor) { return Vec<1, T>(mod(dividend.head(), divisor.head())); }
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, Vec<L, T> const& divisor) { return Vec<L, T>(mod(dividend.head(), divisor.head()), mod(dividend.tail(), divisor.tail())); }

template          <typename T> constexpr Vec<1, T> min(Vec<1, T> const& val1, T val2) { return Vec<1, T>(min(val1.head(), val2)); }
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, T val2) { return Vec<L, T>(min(val1.head(), val2), min(val1.tail(), val2)); }
template          <typename T> constexpr Vec<1, T> min(Vec<1, T> const& val1, Vec<1, T> const& val2) { return Vec<1, T>(min(val1.head(), val2.head())); }
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, Vec<L, T> const& val2) { return Vec<L, T>(min(val1.head(), val2.head()), min(val1.tail(), val2.tail())); }

template          <typename T> constexpr Vec<1, T> max(Vec<1, T> const& val1, T val2) { return Vec<1, T>(max(val1.head(), val2)); }
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, T val2) { return Vec<L, T>(max(val1.head(), val2), max(val1.tail(), val2)); }
template          <typename T> constexpr Vec<1, T> max(Vec<1, T> const& val1, Vec<1, T> const& val2) { return Vec<1, T>(max(val1.head(), val2.head())); }
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, Vec<L, T> const& val2) { return Vec<L, T>(max(val1.head(), val2.head()), max(val1.tail(), val2.tail())); }

template          <typename T> constexpr Vec<1, T> clamp(Vec<1, T> const& value, T low, T high) { return Vec<1, T>(clamp(value.head(), low, high)); }
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, T low, T high) { return Vec<L, T>(clamp(value.head(), low, high), clamp(value.tail(), low, high)); }
template          <typename T> constexpr Vec<1, T> clamp(Vec<1, T> const& value, Vec<1, T> const& low, Vec<1, T> const& high) { return Vec<1, T>(clamp(value.head(), low.head(), high.head())); }
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, Vec<L, T> const& low, Vec<L, T> const& high) { return Vec<L, T>(clamp(value.head(), low.head(), high.head()), clamp(value.tail(), low.tail(), high.tail())); }

template <typename T, typename U> constexpr T mix(T val1, T val2, U ratio) { assert(U(0) <= sca3 && sca3 <= U(1)); return static_cast<T>(static_cast<U>(val1) * (U(1) - ratio) + static_cast<U>(val2) * ratio); }
template          <typename T, typename U> constexpr Vec<1, T> mix(Vec<1, T> const& val1, Vec<1, T> const& val2, U ratio) { return Vec<1, T>(mix(val1.head(), val2.head(), ratio)); }
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, U ratio) { return Vec<L, T>(mix(val1.head(), val2.head(), ratio), mix(val1.tail(), val2.tail(), ratio)); }
template          <typename T, typename U> constexpr Vec<1, T> mix(Vec<1, T> const& val1, Vec<1, T> const& val2, Vec<1, U> const& ratio) { return Vec<1, T>(mix(val1.head(), val2.head(), ratio.head())); }
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, Vec<L, U> const& ratio) { return Vec<L, T>(mix(val1.head(), val2.head(), ratio.head()), mix(val1.tail(), val2.tail(), ratio.tail())); }

template <typename T> constexpr T step(T edge, T value) { return static_cast<T>(edge <= value); }
template          <typename T> constexpr Vec<1, T> step(T edge, Vec<1, T> const& value) { return Vec<1, T>(step(edge, value.head())); }
template <usize L, typename T> constexpr Vec<L, T> step(T edge, Vec<L, T> const& value) { return Vec<L, T>(step(edge, value.head()), step(edge, value.tail())); }
template          <typename T> constexpr Vec<1, T> step(Vec<1, T> const& edge, Vec<1, T> const& value) { return Vec<1, T>(step(edge.head(), value.head())); }
template <usize L, typename T> constexpr Vec<L, T> step(Vec<L, T> const& edge, Vec<L, T> const& value) { return Vec<L, T>(step(edge.head(), value.head()), step(edge.tail(), value.tail())); }

template <typename T> constexpr T smoothstep(T edge1, T edge2, T value) { T tmp = clamp((value - edge1) / (edge2 - edge1)); return tmp * tmp * (static_cast<T>(3) - static_cast<T>(2) * tmp); }
template          <typename T> constexpr Vec<1, T> smoothstep(T edge1, T edge2, Vec<1, T> const& value) { return Vec<1, T>(smoothstep(edge1, edge2, value.head())); }
template <usize L, typename T> constexpr Vec<L, T> smoothstep(T edge1, T edge2, Vec<L, T> const& value) { return Vec<L, T>(smoothstep(edge1, edge2, value.head()), smoothstep(edge1, edge2, value.tail())); }
template          <typename T> constexpr Vec<1, T> smoothstep(Vec<1, T> const& edge1, Vec<1, T> const& edge2, Vec<1, T> const& value) { return Vec<1, T>(smoothstep(edge1.head(), edge2.head(), value.head())); }
template <usize L, typename T> constexpr Vec<L, T> smoothstep(Vec<L, T> const& edge1, Vec<L, T> const& edge2, Vec<L, T> const& value) { return Vec<L, T>(smoothstep(edge1.head(), edge2.head(), value.head()), smoothstep(edge1.tail(), edge2.tail(), value.tail())); }

} // namespace tf

#endif // TRANSFORM_VEC_COMMON_H_
