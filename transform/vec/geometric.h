/**
 * @ref core
 * @file transform/vec/geometric.h
 *
 * @see [GLSL 4.50 specification, section 8.5 Geometric Functions](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.50.pdf)
 *
 * @defgroup core_geometric Geometric functions
 * @ingroup core
 *
 * Provides GLSL geometric functions
 *
 * Operate on vectors as vectors, not component-wise.
 *
 * Include <transform/vec/geometric.h> to use these core features.
 */

#ifndef TRANSFORM_VEC_GEOMETRIC_H_
#define TRANSFORM_VEC_GEOMETRIC_H_

#include "transform/vec/exponential.h"

namespace tf {
/** @addtogroup core_geometric
 * @{ */

/**
 * Returns the sum of the components of a vector @f$x@f$: @f[x_0 + x_1 + \dots@f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 */
template <usize L, typename T> constexpr T sum(Vec<L, T> const& vec);

/**
 * Returns the length of vector @f$x@f$: @f[\sqrt{x_0^2 + x_1^2 + \dots}@f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$x@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/length.xhtml)
 */
template <usize L, typename T> constexpr T length(Vec<L, T> const& vec);

/**
 * Returns the distance between two points @f$p@f$ and @f$q@f$: @f[\textbf{length}(p - q)@f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec1 Value representing @f$p@f$.
 * @param vec2 Value representing @f$q@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/distance.xhtml)
 */
template <usize L, typename T> constexpr T distance(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

/**
 * Returns the dot product of two vectors @f$x@f$ and @f$y@f$: @f[x_0 \cdot y_0 + x_1 \cdot y_1 + \dots@f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec1 Value representing @f$x@f$.
 * @param vec2 Value representing @f$y@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/dot.xhtml)
 */
template <usize L, typename T> constexpr T dot(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

/**
 * Returns the cross product of two vectors @f$x@f$ and @f$y@f$: @f{bmatrix}{x_1 \times y_2 - y_1 \times x_2 \\ x_2 \times y_0 - y_2 \times x_0 \\ x_0 \times
 * y_1 - y_0 \times x_1@f}
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec1 Value representing @f$x@f$.
 * @param vec2 Value representing @f$y@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/cross.xhtml)
 */
template <typename T> constexpr Vec<3, T> cross(Vec<3, T> const& vec1, Vec<3, T> const& vec2);

/**
 * Returns a vector with the same direction as its parameter, @f$v@f$, but with length 1.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec Value representing @f$v@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/normalize.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> normalize(Vec<L, T> const& vec);

/**
 * If @f$\textbf{dot}(N_{ref}, I) < 0@f$ returns @f$N@f$, otherwise returns @f$-N@f$.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec_n Value representing @f$N@f$.
 * @param vec_i Value representing @f$I@f$.
 * @param vec_ref Value representing @f$N_ref@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/faceforward.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> faceforward(Vec<L, T> const& vec_n, Vec<L, T> const& vec_i, Vec<L, T> const& vec_ref);

/**
 * For the incident vector @f$I@f$ and the surface orientation @f$N@f$, returns the reflection direction: @f[I - 2 \cdot \textbf{dot}(N, I) \cdot N@f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec_i Value representing @f$I@f$.
 * @param vec_n Value representing @f$N@f$. It should be normalized to achieve the desired result.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/reflect.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> reflect(Vec<L, T> const& vec_i, Vec<L, T> const& vec_n);

/**
 * For the incident vector @f$I@f$, surface normal @f$N@f$ and the ratio of indices of refraction @f$\eta@f$, returns the refraction vector @f$R@f$: @f[
 * \begin{array}{ll}
 * k & = & 1 - \eta^2 \cdot (1 - \textbf{dot}(N, I)^2) \\
 * R & = & \left\{\begin{array}{ll}
 *         0 \cdot N                                                         & \mbox{if } k < 0 \\
 *         \eta \cdot I - (\eta \cdot \textbf{dot}(N, I) + \sqrt{k}) \cdot N & \mbox{if } k \geq 0
 *         \end{array}\right.
 * \end{array}
 * @f]
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @param vec_i Value representing @f$I@f$. It should be normalized to achieve the desired result.
 * @param vec_n Value representing @f$N@f$. It should be normalized to achieve the desired result.
 * @param eta Value representing @f$\eta@f$.
 * @return constexpr Vec<L, T>
 * @see [GLSL length man page](https://registry.khronos.org/OpenGL-Refpages/gl4/html/refract.xhtml)
 */
template <usize L, typename T> constexpr Vec<L, T> refract(Vec<L, T> const& vec_i, Vec<L, T> const& vec_n, T eta);

/************************
 * Function definitions *
 ************************/

/** @private */
template          <typename T> constexpr T sum(Vec<1, T> const& vec) { return vec.head(); }
template <usize L, typename T> constexpr T sum(Vec<L, T> const& vec) { return vec.head() + sum(vec.tail()); }

template <usize L, typename T> constexpr T length(Vec<L, T> const& vec) {
  return static_cast<T>(sqrt(dot(vec, vec)));
}

template <usize L, typename T> constexpr T distance(Vec<L, T> const& vec1, Vec<L, T> const& vec2) {
  return length(vec2 - vec1);
}

template <usize L, typename T> constexpr T dot(Vec<L, T> const& vec1, Vec<L, T> const& vec2) {
  return sum(vec1 * vec2);
}

template <typename T> constexpr Vec<3, T> cross(Vec<3, T> const& vec1, Vec<3, T> const& vec2) {
  return Vec<3, T>(
    vec1.y() * vec2.z() - vec2.y() * vec1.z(),
    vec1.z() * vec2.x() - vec2.z() * vec1.x(),
    vec1.x() * vec2.y() - vec2.x() * vec1.y()
  );
}

template <usize L, typename T> constexpr Vec<L, T> normalize(Vec<L, T> const& vec) {
  return vec / length(vec);
}

template <usize L, typename T> constexpr Vec<L, T> faceforward(Vec<L, T> const& vec_n, Vec<L, T> const& vec_i, Vec<L, T> const& vec_ref) {
  return dot(vec_ref, vec_i) < T(0) ? vec_n : -vec_n;
}

template <usize L, typename T> constexpr Vec<L, T> reflect(Vec<L, T> const& vec_i, Vec<L, T> const& vec_n) {
  return vec_i - T(2) * dot(vec_n, vec_i) * vec_n;
}

template <usize L, typename T> constexpr Vec<L, T> refract(Vec<L, T> const& vec_i, Vec<L, T> const& vec_n, T eta) {
  T tmp = T(1) - pow(eta, T(2)) * (T(1) - pow(dot(vec_n, vec_i), T(2)));
  return tmp < T(0) ? Vec<L, T>::fill(0) : eta * vec_i - (eta * dot(vec_n, vec_i) + sqrt(tmp)) * vec_n;
}

/** @} */
} // namespace tf

#endif // TRANSFORM_VEC_GEOMETRIC_H_
