#ifndef TRANSFORM_TRANSFORM_SPECIAL_H_
#define TRANSFORM_TRANSFORM_SPECIAL_H_

#include <cmath>

#include "transform/mat/func.h"
#include "transform/mat/matcxr.h"
#include "transform/transform/basic.h"
#include "transform/vec/common.h"
#include "transform/vec/geometric.h"
#include "transform/vec/trigonometric.h"
#include "transform/vec/vecn.h"

namespace tf {

// 4.2.1 The Euler Transform
template <typename T> constexpr Mat<4, 4, T> euler(T yaw, T pitch, T roll);
template <typename T> constexpr Mat<4, 4, T> euler(Vec<3, T> const& vec);

// 4.2.2 Extracting Parameters from the Euler Transform
template <typename T> constexpr Vec<3, T> extractFromEuler(Mat<4, 4, T> const& mat);

// 4.2.3 Matrix Decomposition
// ...

// 4.2.4 Rotation about an Arbitrary Axis
template <typename T> constexpr Mat<4, 4, T> rotate(Vec<3, T> const& vec, T rad);

/************************
 * Function definitions *
 ************************/

// 4.2.1 The Euler Transform
template <typename T> constexpr Mat<4, 4, T> euler(T yaw, T pitch, T roll) {
  return rotateZ(roll) * rotateX(pitch) * rotateY(yaw);
}
template <typename T> constexpr Mat<4, 4, T> euler(Vec<3, T> const& vec) {
  return euler(vec.x(), vec.y(), vec.z());
}

// 4.2.2 Extracting Parameters from the Euler Transform
template <typename T> constexpr Vec<3, T> extractFromEuler(Mat<4, 4, T> const& mat) {
  T pitch = asin(mat[1][2]);
  T yaw   = cos(pitch) != 0 ? atan2(-mat[0][2], mat[2][2]) : 0;
  T roll  = cos(pitch) != 0 ? atan2(-mat[1][0], mat[1][1]) : atan2(mat[0][1], mat[0][0]);
  return Vec<3, T>(yaw, pitch, roll);
}

// 4.2.4 Rotation about an Arbitrary Axis
template <typename T> constexpr Mat<4, 4, T> rotate(Vec<3, T> const& vec, T rad) {
  Vec<3, T> tmp = Vec<3, T>(abs(vec.x()), abs(vec.y()), abs(vec.z()));
  Vec<3, T> x_vec = normalize(vec);
  Vec<3, T> y_vec;
  if      (tmp.x() <= tmp.y() && tmp.x() <= tmp.z()) y_vec = normalize(Vec<3, T>(       0, -vec.z(), vec.y()));
  else if (tmp.y() <= tmp.x() && tmp.y() <= tmp.z()) y_vec = normalize(Vec<3, T>(-vec.z(),        0, vec.x()));
  else                                               y_vec = normalize(Vec<3, T>(-vec.y(),  vec.x(),       0));
  Vec<3, T> z_vec = cross(x_vec, y_vec);
  Mat<4, 4, T> transform = changeBasis(x_vec, y_vec, z_vec);
  return transform * rotateX(rad) * transpose(transform);
}

} // namespace tf

#endif // TRANSFORM_TRANSFORM_SPECIAL_H_
