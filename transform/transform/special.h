#ifndef TRANSFORM_TRANSFORM_SPECIAL_H_
#define TRANSFORM_TRANSFORM_SPECIAL_H_

#include <cmath>

#include "transform/mat/func.h"
#include "transform/mat/matcxr.h"
#include "transform/transform/basic.h"
#include "transform/vec/func.h"
#include "transform/vec/vec3.h"

namespace tf {

// 4.2.1 The Euler Transform
template <typename T> constexpr Mat4<T> Euler(T yaw, T pitch, T roll);
template <typename T> constexpr Mat4<T> Euler(Vec3<T> const& vec);

// 4.2.2 Extracting Parameters from the Euler Transform
template <typename T> constexpr Vec3<T> ExtractFromEuler(Mat4<T> const& mat);

// 4.2.3 Matrix Decomposition
// ...

// 4.2.4 Rotation about an Arbitrary Axis
template <typename T> constexpr Mat4<T> Rotate(Vec3<T> const& vec, T rad);

/************************
 * Function definitions *
 ************************/

// 4.2.1 The Euler Transform
template <typename T> constexpr Mat4<T> Euler(T yaw, T pitch, T roll) {
  return RotateZ(roll) * RotateX(pitch) * RotateY(yaw);
}
template <typename T> constexpr Mat4<T> Euler(Vec3<T> const& vec) {
  return Euler(vec.x(), vec.y(), vec.z());
}

// 4.2.2 Extracting Parameters from the Euler Transform
template <typename T> constexpr Vec3<T> ExtractFromEuler(Mat4<T> const& mat) {
  T pitch = std::asin(mat[1][2]);
  T yaw   = std::cos(pitch) == 0 ? 0                                : std::atan2(-mat[0][2], mat[2][2]);
  T roll  = std::cos(pitch) == 0 ? std::atan2(mat[0][1], mat[0][0]) : std::atan2(-mat[1][0], mat[1][1]);
  return Vec3<T>(yaw, pitch, roll);
}

// 4.2.4 Rotation about an Arbitrary Axis
template <typename T> constexpr Mat4<T> Rotate(Vec3<T> const& vec, T rad) {
  Vec3<T> tmp = Vec3<T>(std::abs(vec.x()), std::abs(vec.y()), std::abs(vec.z()));
  Vec3<T> x_vec = Normalize(vec);
  Vec3<T> y_vec;
  if      (tmp.x() <= tmp.y() && tmp.x() <= tmp.z()) y_vec = Normalize(Vec3<T>(       0, -vec.z(), vec.y()));
  else if (tmp.y() <= tmp.x() && tmp.y() <= tmp.z()) y_vec = Normalize(Vec3<T>(-vec.z(),        0, vec.x()));
  else                                               y_vec = Normalize(Vec3<T>(-vec.y(),  vec.x(),       0));
  Vec3<T> z_vec = Cross(x_vec, y_vec);
  Mat4<T> transform = ChangeBasis(x_vec, y_vec, z_vec);
  return transform * RotateX(rad) * Transpose(transform);
}

} // namespace tf

#endif // TRANSFORM_TRANSFORM_SPECIAL_H_
