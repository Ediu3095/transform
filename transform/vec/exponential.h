/**
 * @ref core
 * @file transform/vec/exponential.h
 *
 * @see [GLSL 4.50 specification, section 8.2 Exponential Functions](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.50.pdf)
 *
 * @defgroup core_exponential Exponential functions
 * @ingroup core
 *
 * Provides GLSL exponential functions
 * 
 * These all operate component-wise. The description is per component.
 *
 * Include <transform/vec/exponential.h> to use these core features.
 */

#ifndef TRANSFORM_VEC_EXPONENTIAL_H_
#define TRANSFORM_VEC_EXPONENTIAL_H_

#include <cmath>

#include "transform/vec/vecn.h"

namespace tf {
/** @addtogroup core_exponential
 * @{ */

using ::std::pow;
/**
 * Returns @f$x@f$ to the @f$y@f$ power i.e. @f$x^y@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param base Value representing @f$x@f$. The `pow` function is defined for input values of `base` defined in the range @f$(-\infty, \infty)@f$.
 * @param exponent Value representing @f$y@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL pow man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/pow.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> pow(Vec<L, T> const& base, Vec<L, T> const& exponent);

using ::std::exp;
/**
 * Returns the natural exponentiation of @f$x@f$ i.e. @f$e^x@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `exp` function is defined for input values of `vec` defined in the range @f$(-\infty, \infty)@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL exp man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/exp.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> exp(Vec<L, T> const& vec);

using ::std::log;
/**
 * Returns the natural logarithm of @f$x@f$ i.e. the value @f$y@f$ which satisfies the equation @f$x=e^y@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `log` function is defined for input values of `vec` defined in the range @f$(0, \infty)@f$.
 * @return constexpr Vec<L, T> 
 * @see [GLSL log man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/log.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> log(Vec<L, T> const& vec);

using ::std::exp2;
/**
 * Returns 2 raised to the @f$x@f$ power i.e. @f$2^x@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `exp2` function is defined for input values of `vec` defined in the range @f$(-\infty, \infty)@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL exp2 man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/exp2.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> exp2(Vec<L, T> const& vec);

using ::std::log2;
/**
 * Returns the base 2 logarithm of @f$x@f$ i.e. the value @f$y@f$ which satisfies the equation @f$x=2^y@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `log2` function is defined for input values of `vec` defined in the range @f$(0, \infty)@f$.
 * @return constexpr Vec<L, T> 
 * @see [GLSL log2 man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/log2.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> log2(Vec<L, T> const& vec);

using ::std::sqrt;
/**
 * Returns the positive square root of @f$x@f$ i.e. @f$\sqrt{x}@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `sqrt` function is defined for input values of `vec` defined in the range @f$[0, \infty)@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL sqrt man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/sqrt.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> sqrt(Vec<L, T> const& vec);

/** @private */
template <typename T> constexpr T inversesqrt(T sca);
/**
 * Returns the reciprocal of the positive square root of @f$x@f$ i.e. @f${1}/{\sqrt{x}}@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `inversesqrt` function is defined for input values of `vec` defined in the range @f$(0, \infty)@f$.
 * @return constexpr T
 * @see [GLSL pow inversesqrt page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/inversesqrt.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> inversesqrt(Vec<L, T> const& vec);

/************************
 * Function definitions *
 ************************/

/** @private */
template          <typename T> constexpr Vec<1, T> pow(Vec<1, T> const& base, Vec<1, T> const& exponent) { return Vec<1, T>(pow(base.head(), exponent.head())); }
template <usize L, typename T> constexpr Vec<L, T> pow(Vec<L, T> const& base, Vec<L, T> const& exponent) { return Vec<L, T>(pow(base.head(), exponent.head()), pow(base.tail(), exponent.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> exp(Vec<1, T> const& vec) { return Vec<1, T>(exp(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> exp(Vec<L, T> const& vec) { return Vec<L, T>(exp(vec.head()), exp(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> log(Vec<1, T> const& vec) { return Vec<1, T>(log(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> log(Vec<L, T> const& vec) { return Vec<L, T>(log(vec.head()), log(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> exp2(Vec<1, T> const& vec) { return Vec<1, T>(exp2(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> exp2(Vec<L, T> const& vec) { return Vec<L, T>(exp2(vec.head()), exp2(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> log2(Vec<1, T> const& vec) { return Vec<1, T>(log2(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> log2(Vec<L, T> const& vec) { return Vec<L, T>(log2(vec.head()), log2(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> sqrt(Vec<1, T> const& vec) { return Vec<1, T>(sqrt(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> sqrt(Vec<L, T> const& vec) { return Vec<L, T>(sqrt(vec.head()), sqrt(vec.tail())); }

template <typename T> constexpr T inversesqrt(T sca) { return static_cast<T>(1) / sqrt(sca); }
/** @private */
template          <typename T> constexpr Vec<1, T> inversesqrt(Vec<1, T> const& vec) { return Vec<1, T>(inversesqrt(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> inversesqrt(Vec<L, T> const& vec) { return Vec<L, T>(inversesqrt(vec.head()), inversesqrt(vec.tail())); }

/** @} */
}  // namespace tf

#endif  // TRANSFORM_VEC_EXPONENTIAL_H_
