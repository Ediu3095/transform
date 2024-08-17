/**
 * @ref core_glsl
 * @file transform/glsl/trigonometric.h
 *
 * @see [GLSL 4.60 specification, section 8.1 Angle and Trigonometry Functions](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.60.html#angle-and-trigonometry-functions)
 *
 * @defgroup core_glsl_trigonometric Angle and trigonometry functions
 * @ingroup core_glsl
 *
 * Provides GLSL angle and trigonometry functions
 *
 * Function parameters specified ad `angle` are assumed to be in units of radians.
 *
 * These all operate component-wise. The description is per component.
 *
 * Include <transform/glsl/trigonometric.h> to use these core features.
 */

#ifndef TRANSFORM_GLSL_TRIGONOMETRIC_H_
#define TRANSFORM_GLSL_TRIGONOMETRIC_H_

#include <cmath>
#include <numbers>

#include "transform/vec.h"

namespace tf {
/** @addtogroup core_glsl_trigonometric
 * @{ */

/** @private */
template <typename T> constexpr T radians(T degrees);
/**
 * Converts `degrees` to radians i.e. @f$\frac{\pi}{180} \cdot degrees@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param degrees The quantity, in degrees, to be converted to radians.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/radians.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> radians(Vec<L, T> const& degrees);

/** @private */
template <typename T> constexpr T degrees(T radians);
/**
 * Converts `radians` to degrees i.e. @f$\frac{180}{\pi} \cdot radians@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param radians The quantity, in radians, to be converted to degrees.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/degrees.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> degrees(Vec<L, T> const& radians);

using ::std::sin;
/**
 * Returns the trigonometric sine of `angle`.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param angle The quantity, in radians, of which to return the sine.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/sin.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> sin(Vec<L, T> const& angle);

using ::std::cos;
/**
 * Returns the trigonometric cosine of `angle`.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param angle The quantity, in radians, of which to return the cosine.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/cos.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> cos(Vec<L, T> const& angle);

using ::std::tan;
/**
 * Returns the trigonometric tangent of `angle`.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param angle The quantity, in radians, of which to return the tangent.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/tan.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> tan(Vec<L, T> const& angle);

using ::std::asin;
/**
 * Returns the angle whose trigonometric sine is @f$x@f$. The range of values returned is @f$[-\frac{\pi}{2},\frac{\pi}{2}]@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `asin` function is defined for input values of `vec` in the range @f$[-1, 1]@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/asin.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> asin(Vec<L, T> const& vec);

using ::std::acos;
/**
 * Returns the angle whose trigonometric cosine is @f$x@f$. The range of values returned is @f$[0, \pi]@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `acos` function is defined for input values of `vec` in the range @f$[-1, 1]@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/acos.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> acos(Vec<L, T> const& vec);

using ::std::atan;
/**
 * Returns the angle whose trigonometric tangent is @f$x@f$. The range of values returned is @f$[-\frac{\pi}{2},\frac{\pi}{2}]@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$. The `atan` function is defined for input values of `vec` in the range @f$[-1, 1]@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/atan.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> atan(Vec<L, T> const& vec);

using ::std::atan2;
/**
 * Returns the angle whose trigonometric tangent is @f$\frac{y}{x}@f$. The range of values returned is @f$[-\pi,\pi]@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec_y Value representing @f$y@f$. The `atan2` function is defined for input values of `vec_y` in the range @f$[-1, 1]@f$.
 * @param vec_x Value representing @f$x@f$. The `atan2` function is defined for input values of `vec_x` in the range @f$[-1, 1]@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/atan.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> atan2(Vec<L, T> const& vec_y, Vec<L, T> const& vec_x);

using ::std::sinh;
/**
 * Returns the hyperbolic sine of @f$x@f$: @f[\frac{e^x - e^{-x}}{2}@f].
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param angle Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/sinh.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> sinh(Vec<L, T> const& angle);

using ::std::cosh;
/**
 * Returns the hyperbolic cosine of @f$x@f$: @f[\frac{e^x + e^{-x}}{2}@f].
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param angle Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/cosh.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> cosh(Vec<L, T> const& angle);

using ::std::tanh;
/**
 * Returns the hyperbolic tangent of @f$x@f$: @f[\frac{\textbf{sinh}(x)}{\textbf{cosh}(x)}@f].
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param angle Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/tanh.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> tanh(Vec<L, T> const& angle);

using ::std::asinh;
/**
 * Returns the arc hyperbolic sine of @f$x@f$ i.e. the inverse function of ::tf::sinh.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/asinh.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> asinh(Vec<L, T> const& vec);

using ::std::acosh;
/**
 * Returns the arc hyperbolic cosine of @f$x@f$ i.e. the inverse function of ::tf::cosh.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/acosh.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> acosh(Vec<L, T> const& vec);

using ::std::atanh;
/**
 * Returns the arc hyperbolic tangent of @f$x@f$ i.e. the inverse function of ::tf::tanh.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/atanh.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> atanh(Vec<L, T> const& vec);

/************************
 * Function definitions *
 ************************/

template <typename T> constexpr T radians(T degrees) { return degrees * ::std::numbers::pi_v<T> / T(180); }  // NOLINT(*-magic-numbers)
/** @private */
template          <typename T> constexpr Vec<1, T> radians(Vec<1, T> const& degrees) { return Vec<1, T>(radians(degrees.head())); }
template <usize L, typename T> constexpr Vec<L, T> radians(Vec<L, T> const& degrees) { return Vec<L, T>(radians(degrees.head()), radians(degrees.tail())); }

template <typename T> constexpr T degrees(T radians) { return radians / ::std::numbers::pi_v<T> * T(180); }  // NOLINT(*-magic-numbers)
/** @private */
template          <typename T> constexpr Vec<1, T> degrees(Vec<1, T> const& radians) { return Vec<1, T>(degrees(radians.head())); }
template <usize L, typename T> constexpr Vec<L, T> degrees(Vec<L, T> const& radians) { return Vec<L, T>(degrees(radians.head()), degrees(radians.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> sin(Vec<1, T> const& angle) { return Vec<1, T>(sin(angle.head())); }
template <usize L, typename T> constexpr Vec<L, T> sin(Vec<L, T> const& angle) { return Vec<L, T>(sin(angle.head()), sin(angle.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> cos(Vec<1, T> const& angle) { return Vec<1, T>(cos(angle.head())); }
template <usize L, typename T> constexpr Vec<L, T> cos(Vec<L, T> const& angle) { return Vec<L, T>(cos(angle.head()), cos(angle.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> tan(Vec<1, T> const& angle) { return Vec<1, T>(tan(angle.head())); }
template <usize L, typename T> constexpr Vec<L, T> tan(Vec<L, T> const& angle) { return Vec<L, T>(tan(angle.head()), tan(angle.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> asin(Vec<1, T> const& vec) { return Vec<1, T>(asin(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> asin(Vec<L, T> const& vec) { return Vec<L, T>(asin(vec.head()), asin(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> acos(Vec<1, T> const& vec) { return Vec<1, T>(acos(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> acos(Vec<L, T> const& vec) { return Vec<L, T>(acos(vec.head()), acos(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> atan(Vec<1, T> const& vec) { return Vec<1, T>(atan(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> atan(Vec<L, T> const& vec) { return Vec<L, T>(atan(vec.head()), atan(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> atan2(Vec<1, T> const& vec_y, Vec<1, T> const& vec_x) { return Vec<1, T>(atan2(vec_y.head(), vec_x.head())); }
template <usize L, typename T> constexpr Vec<L, T> atan2(Vec<L, T> const& vec_y, Vec<L, T> const& vec_x) { return Vec<L, T>(atan2(vec_y.head(), vec_x.head()), atan2(vec_y.tail(), vec_x.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> sinh(Vec<1, T> const& angle) { return Vec<1, T>(sinh(angle.head())); }
template <usize L, typename T> constexpr Vec<L, T> sinh(Vec<L, T> const& angle) { return Vec<L, T>(sinh(angle.head()), sinh(angle.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> cosh(Vec<1, T> const& angle) { return Vec<1, T>(cosh(angle.head())); }
template <usize L, typename T> constexpr Vec<L, T> cosh(Vec<L, T> const& angle) { return Vec<L, T>(cosh(angle.head()), cosh(angle.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> tanh(Vec<1, T> const& angle) { return Vec<1, T>(tanh(angle.head())); }
template <usize L, typename T> constexpr Vec<L, T> tanh(Vec<L, T> const& angle) { return Vec<L, T>(tanh(angle.head()), tanh(angle.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> asinh(Vec<1, T> const& vec) { return Vec<1, T>(asinh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> asinh(Vec<L, T> const& vec) { return Vec<L, T>(asinh(vec.head()), asinh(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> acosh(Vec<1, T> const& vec) { return Vec<1, T>(acosh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> acosh(Vec<L, T> const& vec) { return Vec<L, T>(acosh(vec.head()), acosh(vec.tail())); }

/** @private */
template          <typename T> constexpr Vec<1, T> atanh(Vec<1, T> const& vec) { return Vec<1, T>(atanh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> atanh(Vec<L, T> const& vec) { return Vec<L, T>(atanh(vec.head()), atanh(vec.tail())); }

/** @} */
}  // namespace tf

#endif  // TRANSFORM_GLSL_TRIGONOMETRIC_H_
