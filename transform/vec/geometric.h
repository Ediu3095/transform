#ifndef TRANSFORM_VEC_GEOMETRIC_H_
#define TRANSFORM_VEC_GEOMETRIC_H_

#include <cmath>

#include "transform/types.h"
#include "transform/vec/vec.h"
#include "transform/vec/vec3.h"

namespace tf {

template <usize L, typename T> constexpr T sum(Vec<L, T> const& vec);

template <usize L, typename T> constexpr T length(Vec<L, T> const& vec);

template <usize L, typename T> constexpr T distance(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

template <usize L, typename T> constexpr T dot(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

template <typename T> constexpr Vec<3, T> cross(Vec<3, T> const& vec1, Vec<3, T> const& vec2);

template <usize L, typename T> constexpr Vec<L, T> normalize(Vec<L, T> const& vec);

/************************
 * Function definitions *
 ************************/

template          <typename T> constexpr T sum(Vec<1, T> const& vec) { return vec.head(); }
template <usize L, typename T> constexpr T sum(Vec<L, T> const& vec) { return vec.head() + sum(vec.tail()); }

template <usize L, typename T> constexpr T length(Vec<L, T> const& vec) { return static_cast<T>(std::sqrt(dot(vec, vec))); }

template <usize L, typename T> constexpr T distance(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return length(vec2 - vec1); }

template <usize L, typename T> constexpr T dot(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return sum(vec1 * vec2); }

template <typename T> constexpr Vec<3, T> cross(Vec<3, T> const& vec1, Vec<3, T> const& vec2) { return Vec<3, T>(vec1.y() * vec2.z() - vec1.z() * vec2.y(), vec1.z() * vec2.x() - vec1.x() * vec2.z(), vec1.x() * vec2.y() - vec1.y() * vec2.x()); }

template <usize L, typename T> constexpr Vec<L, T> normalize(Vec<L, T> const& vec) { return vec / length(vec); }

} // namespace tf

#endif // TRANSFORM_VEC_GEOMETRIC_H_
