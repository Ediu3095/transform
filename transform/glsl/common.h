/**
 * @ref core_glsl
 * @file transform/glsl/common.h
 *
 * @see [GLSL 4.60 specification, section 8.3 Common Functions](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.60.html#common-functions)
 *
 * @defgroup core_glsl_common Common functions
 * @ingroup core_glsl
 *
 * Provides GLSL common functions
 * 
 * These all operate component-wise. The description is per component.
 *
 * Include <transform/glsl/common.h> to use these core features.
 */

#ifndef TRANSFORM_GLSL_COMMON_H_
#define TRANSFORM_GLSL_COMMON_H_

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

#include "transform/vec.h"

namespace tf {
/** @addtogroup core_glsl_common
 * @{ */

using ::std::abs;
/**
 * Returns the absolute value of @f$x@f$ i.e. @f$x@f$ if @f$x \geq 0@f$; otherwise returns @f$-x@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/abs.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> abs(Vec<L, T> const& vec);

/** @private */
template <typename T> constexpr T sign(T sca);
/**
 * Returns 1 if @f$x > 0@f$, 0 if @f$x = 0@f$ or -1 if @f$x < 0@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/sign.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> sign(Vec<L, T> const& vec);

using ::std::floor;
/**
 * Returns a value @f$y@f$ equal to the nearest integer to @f$x@f$ for which @f$y \leq x@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/floor.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> floor(Vec<L, T> const& vec);

using ::std::trunc;
/**
 * Returns a value @f$y@f$ equal to the nearest integer to @f$x@f$ for which @f$|y| \leq |x|@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/trunc.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> trunc(Vec<L, T> const& vec);

using ::std::round;
/**
 * Returns a value @f$y@f$ equal to the nearest integer to @f$x@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/round.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> round(Vec<L, T> const& vec);

using ::std::ceil;
/**
 * Returns a value @f$y@f$ equal to the nearest integer to @f$x@f$ for which @f$y \geq x@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/ceil.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> ceil(Vec<L, T> const& vec);

/** @private */
template <typename T> constexpr T fract(T sca);
/**
 * Returns the fractional part of @f$x@f$ i.e. @f$x - \textbf{floor}(x)@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/fract.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> fract(Vec<L, T> const& vec);

/** @private */
template <typename T> constexpr T mod(T dividend, T divisor);
/**
 * Returns the value of @f$x@f$ modulo @f$y@f$ i.e. @f$x - y \cdot \textbf{floor}(x / y)@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param dividend Value representing @f$x@f$.
 * @param divisor Value representing @f$y@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/mod.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, T divisor);
/** @copydoc ::tf::mod(Vec<L, T> const&, T) */
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, Vec<L, T> const& divisor);

using ::std::min;
/**
 * Returns the minimum of the two parameters i.e. @f$x@f$ if @f$x < y@f$ otherwise @f$y@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param val1 Value representing @f$x@f$.
 * @param val2 Value representing @f$y@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/min.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, T val2);
/** @copydoc ::tf::min(Vec<L, T> const&, T) */
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, Vec<L, T> const& val2);

using ::std::max;
/**
 * Returns the maximum of the two parameters i.e. @f$x@f$ if @f$x > y@f$ otherwise @f$y@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param val1 Value representing @f$x@f$.
 * @param val2 Value representing @f$y@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/max.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, T val2);
/** @copydoc ::tf::max(Vec<L, T> const&, T) */
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, Vec<L, T> const& val2);

using ::std::clamp;
/**
 * Returns the value of @f$x@f$ constrained to the range @f$[x_{min}, x_{max}]@f$ i.e. @f$\textbf{min}(\textbf{max}(x_{min}, x), x_{max})@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param value Value representing @f$x@f$.
 * @param low Value representing @f$x_{min}@f$.
 * @param high Value representing @f$x_{max}@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/clamp.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, T low, T high);
/** @copydoc ::tf::clamp(Vec<L, T> const&, T, T) */
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, Vec<L, T> const& low, Vec<L, T> const& high);

/** @private */
template <typename T, typename U> constexpr T mix(T val1, T val2, U ratio);
/**
 * Returns the linear interpolation between @f$x@f$ and @f$y@f$ using @f$a@f$ to weight between them i.e. @f$x(1 - a) + ya@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param val1 Value representing @f$x@f$.
 * @param val2 Value representing @f$y@f$.
 * @param ratio Value representing @f$a@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/mix.xhtml)
 */
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, U ratio);
/** @copydoc ::tf::mix(Vec<L, T> const&, Vec<L, T> const&, U) */
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, Vec<L, U> const& ratio);

/** @private */
template <typename T> constexpr T step(T edge, T value);
/**
 * Returns a step function comparing @f$x@f$ and @f$edge@f$ i.e. 0 if @f$x < edge@f$, otherwise 1.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param edge Value representing @f$edge@f$.
 * @param value Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/step.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> step(T edge, Vec<L, T> const& value);
/** @copydoc ::tf::step(T, Vec<L, T> const&) */
template <usize L, typename T> constexpr Vec<L, T> step(Vec<L, T> const& edge, Vec<L, T> const& value);

/** @private */
template <typename T> constexpr T smoothstep(T edge1, T edge2, T value);
/**
 * Returns smooth Hermite interpolation between 0 and 1 when @f$edge_0 < x < edge_1@f$. This is computed as: @f[
 * t = \textbf{clamp}((x - edge_0) / (edge_1 - edge_0), 0, 1) \\
 * t^2(3 - 2t)
 * @f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param edge1 Value representing @f$edge_0@f$.
 * @param edge2 Value representing @f$edge_1@f$.
 * @param value Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/smoothstep.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> smoothstep(T edge1, T edge2, Vec<L, T> const& value);
/** @copydoc ::tf::smoothstep(T, T, Vec<L, T> const&) */
template <usize L, typename T> constexpr Vec<L, T> smoothstep(Vec<L, T> const& edge1, Vec<L, T> const& edge2, Vec<L, T> const& value);

/************************
 * Function definitions *
 ************************/

/** @private */
template          <typename T> constexpr Vec<1, T> abs(Vec<1, T> const& vec) { return Vec<1, T>(abs(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> abs(Vec<L, T> const& vec) { return Vec<L, T>(abs(vec.head()), abs(vec.tail())); }

/** @private */
template <typename T> requires ::std::is_signed<T>::value constexpr T sign(T sca) { return static_cast<T>((T(0) < sca) - (sca < T(0))); }
template <typename T>                                     constexpr T sign(T sca) { return static_cast<T>((T(0) < sca)); }
/** @private */
template          <typename T> constexpr Vec<1, T> sign(Vec<1, T> const& vec) { return Vec<1, T>(sign(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> sign(Vec<L, T> const& vec) { return Vec<L, T>(sign(vec.head()), sign(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> floor(Vec<1, T> const& vec) { return Vec<1, T>(floor(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> floor(Vec<L, T> const& vec) { return Vec<L, T>(floor(vec.head()), floor(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> trunc(Vec<1, T> const& vec) { return Vec<1, T>(trunc(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> trunc(Vec<L, T> const& vec) { return Vec<L, T>(trunc(vec.head()), trunc(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> round(Vec<1, T> const& vec) { return Vec<1, T>(round(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> round(Vec<L, T> const& vec) { return Vec<L, T>(round(vec.head()), round(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> ceil(Vec<1, T> const& vec) { return Vec<1, T>(ceil(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> ceil(Vec<L, T> const& vec) { return Vec<L, T>(ceil(vec.head()), ceil(vec.tail())); }

template          <typename T> constexpr        T  fract(T sca) { return sca - floor(sca); }
/** @private */
template          <typename T> constexpr Vec<1, T> fract(Vec<1, T> const& vec) { return Vec<1, T>(fract(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> fract(Vec<L, T> const& vec) { return Vec<L, T>(fract(vec.head()), fract(vec.tail())); }

/** @private */
template <typename T> requires ::std::is_floating_point<T>::value constexpr T mod(T dividend, T divisor) { return ::std::fmod(dividend, divisor); }
template <typename T>                                             constexpr T mod(T dividend, T divisor) { return dividend % divisor; }
/** @private */
template          <typename T> constexpr Vec<1, T> mod(Vec<1, T> const& dividend, T divisor) { return Vec<1, T>(mod(dividend.head(), divisor)); }
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, T divisor) { return Vec<L, T>(mod(dividend.head(), divisor), mod(dividend.tail(), divisor)); }
/** @private */
template          <typename T> constexpr Vec<1, T> mod(Vec<1, T> const& dividend, Vec<1, T> const& divisor) { return Vec<1, T>(mod(dividend.head(), divisor.head())); }
template <usize L, typename T> constexpr Vec<L, T> mod(Vec<L, T> const& dividend, Vec<L, T> const& divisor) { return Vec<L, T>(mod(dividend.head(), divisor.head()), mod(dividend.tail(), divisor.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> min(Vec<1, T> const& val1, T val2) { return Vec<1, T>(min(val1.head(), val2)); }
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, T val2) { return Vec<L, T>(min(val1.head(), val2), min(val1.tail(), val2)); }
/** @private */
template          <typename T> constexpr Vec<1, T> min(Vec<1, T> const& val1, Vec<1, T> const& val2) { return Vec<1, T>(min(val1.head(), val2.head())); }
template <usize L, typename T> constexpr Vec<L, T> min(Vec<L, T> const& val1, Vec<L, T> const& val2) { return Vec<L, T>(min(val1.head(), val2.head()), min(val1.tail(), val2.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> max(Vec<1, T> const& val1, T val2) { return Vec<1, T>(max(val1.head(), val2)); }
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, T val2) { return Vec<L, T>(max(val1.head(), val2), max(val1.tail(), val2)); }
/** @private */
template          <typename T> constexpr Vec<1, T> max(Vec<1, T> const& val1, Vec<1, T> const& val2) { return Vec<1, T>(max(val1.head(), val2.head())); }
template <usize L, typename T> constexpr Vec<L, T> max(Vec<L, T> const& val1, Vec<L, T> const& val2) { return Vec<L, T>(max(val1.head(), val2.head()), max(val1.tail(), val2.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> clamp(Vec<1, T> const& value, T low, T high) { return Vec<1, T>(clamp(value.head(), low, high)); }
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, T low, T high) { return Vec<L, T>(clamp(value.head(), low, high), clamp(value.tail(), low, high)); }
/** @private */
template          <typename T> constexpr Vec<1, T> clamp(Vec<1, T> const& value, Vec<1, T> const& low, Vec<1, T> const& high) { return Vec<1, T>(clamp(value.head(), low.head(), high.head())); }
template <usize L, typename T> constexpr Vec<L, T> clamp(Vec<L, T> const& value, Vec<L, T> const& low, Vec<L, T> const& high) { return Vec<L, T>(clamp(value.head(), low.head(), high.head()), clamp(value.tail(), low.tail(), high.tail())); }

template <typename T, typename U> constexpr T mix(T val1, T val2, U ratio) { assert(U(0) <= sca3 && sca3 <= U(1)); return static_cast<T>(static_cast<U>(val1) * (U(1) - ratio) + static_cast<U>(val2) * ratio); }
/** @private */
template          <typename T, typename U> constexpr Vec<1, T> mix(Vec<1, T> const& val1, Vec<1, T> const& val2, U ratio) { return Vec<1, T>(mix(val1.head(), val2.head(), ratio)); }
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, U ratio) { return Vec<L, T>(mix(val1.head(), val2.head(), ratio), mix(val1.tail(), val2.tail(), ratio)); }
/** @private */
template          <typename T, typename U> constexpr Vec<1, T> mix(Vec<1, T> const& val1, Vec<1, T> const& val2, Vec<1, U> const& ratio) { return Vec<1, T>(mix(val1.head(), val2.head(), ratio.head())); }
template <usize L, typename T, typename U> constexpr Vec<L, T> mix(Vec<L, T> const& val1, Vec<L, T> const& val2, Vec<L, U> const& ratio) { return Vec<L, T>(mix(val1.head(), val2.head(), ratio.head()), mix(val1.tail(), val2.tail(), ratio.tail())); }

template <typename T> constexpr T step(T edge, T value) { return static_cast<T>(edge <= value); }
/** @private */
template          <typename T> constexpr Vec<1, T> step(T edge, Vec<1, T> const& value) { return Vec<1, T>(step(edge, value.head())); }
template <usize L, typename T> constexpr Vec<L, T> step(T edge, Vec<L, T> const& value) { return Vec<L, T>(step(edge, value.head()), step(edge, value.tail())); }
/** @private */
template          <typename T> constexpr Vec<1, T> step(Vec<1, T> const& edge, Vec<1, T> const& value) { return Vec<1, T>(step(edge.head(), value.head())); }
template <usize L, typename T> constexpr Vec<L, T> step(Vec<L, T> const& edge, Vec<L, T> const& value) { return Vec<L, T>(step(edge.head(), value.head()), step(edge.tail(), value.tail())); }

template <typename T> constexpr T smoothstep(T edge1, T edge2, T value) { T tmp = clamp((value - edge1) / (edge2 - edge1)); return tmp * tmp * (T(3) - T(2) * tmp); }
/** @private */
template          <typename T> constexpr Vec<1, T> smoothstep(T edge1, T edge2, Vec<1, T> const& value) { return Vec<1, T>(smoothstep(edge1, edge2, value.head())); }
template <usize L, typename T> constexpr Vec<L, T> smoothstep(T edge1, T edge2, Vec<L, T> const& value) { return Vec<L, T>(smoothstep(edge1, edge2, value.head()), smoothstep(edge1, edge2, value.tail())); }
/** @private */
template          <typename T> constexpr Vec<1, T> smoothstep(Vec<1, T> const& edge1, Vec<1, T> const& edge2, Vec<1, T> const& value) { return Vec<1, T>(smoothstep(edge1.head(), edge2.head(), value.head())); }
template <usize L, typename T> constexpr Vec<L, T> smoothstep(Vec<L, T> const& edge1, Vec<L, T> const& edge2, Vec<L, T> const& value) { return Vec<L, T>(smoothstep(edge1.head(), edge2.head(), value.head()), smoothstep(edge1.tail(), edge2.tail(), value.tail())); }

/** @} */
} // namespace tf

#endif // TRANSFORM_GLSL_COMMON_H_
