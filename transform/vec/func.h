#ifndef TRANSFORM_VEC_FUNC_H_
#define TRANSFORM_VEC_FUNC_H_

#include <cmath>

#include "transform/types.h"
#include "transform/vec/vec.h"
#include "transform/vec/vec3.h"

namespace tf {

template <usize L, typename T> constexpr        T  Length   (Vec<L, T> const& vec);
template <usize L, typename T> constexpr Vec<L, T> Normalize(Vec<L, T> const& vec);
template <usize L, typename T> constexpr        T  Sum      (Vec<L, T> const& vec);

template          <typename T> constexpr Vec<3, T> Cross   (Vec<3, T> const& vec1, Vec<3, T> const& vec2);
template <usize L, typename T> constexpr        T  Dot     (Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <usize L, typename T> constexpr        T  Distance(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

/************************
 * Function definitions *
 ************************/

template <usize L, typename T> constexpr        T  Length   (Vec<L, T> const& vec) { return static_cast<T>(std::sqrt(Dot(vec, vec))); }
template <usize L, typename T> constexpr Vec<L, T> Normalize(Vec<L, T> const& vec) { return vec / Length(vec); }
template          <typename T> constexpr        T  Sum      (Vec<1, T> const& vec) { return vec.head(); }
template <usize L, typename T> constexpr        T  Sum      (Vec<L, T> const& vec) { return vec.head() + Sum(vec.tail()); }

template          <typename T> constexpr Vec<3, T> Cross   (Vec<3, T> const& vec1, Vec<3, T> const& vec2) { return Vec<3, T>(vec1.y() * vec2.z() - vec1.z() * vec2.y(), vec1.z() * vec2.x() - vec1.x() * vec2.z(), vec1.x() * vec2.y() - vec1.y() * vec2.x()); }
template <usize L, typename T> constexpr        T  Dot     (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Sum(vec1 * vec2); }
template <usize L, typename T> constexpr        T  Distance(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Length(vec2 - vec1); }

}  // namespace tf

#endif  // TRANSFORM_VEC_FUNC_H_
