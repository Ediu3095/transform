#ifndef TRANSFORM_TRANSFORM_BASIC_H_
#define TRANSFORM_TRANSFORM_BASIC_H_

#include <cmath>

#include "transform/mat/matcxr.h"
#include "transform/vec/geometric.h"
#include "transform/vec/trigonometric.h"

namespace tf {

// 4.1.1 Translation
template <typename T> constexpr Mat4<T> translate(T vecx, T vecy, T vecz);
template <typename T> constexpr Mat4<T> translate(Vec3<T> const& vec);

// 4.1.2 Rotation
template <typename T> constexpr Mat4<T> rotateX(T rad);
template <typename T> constexpr Mat4<T> rotateY(T rad);
template <typename T> constexpr Mat4<T> rotateZ(T rad);

// 4.1.3 Scaling
template <typename T> constexpr Mat4<T> scale(T sca);
template <typename T> constexpr Mat4<T> scale(T vecx, T vecy, T vecz);
template <typename T> constexpr Mat4<T> scale(Vec3<T> const& vec);
template <typename T> constexpr Mat4<T> changeBasis(Vec3<T> const& x_vec, Vec3<T> const& y_vec, Vec3<T> const& z_vec);

// 4.1.4 Shearing
template <typename T> constexpr Mat4<T> shearXY(T sca);
template <typename T> constexpr Mat4<T> shearXZ(T sca);
template <typename T> constexpr Mat4<T> shearYX(T sca);
template <typename T> constexpr Mat4<T> shearYZ(T sca);
template <typename T> constexpr Mat4<T> shearZX(T sca);
template <typename T> constexpr Mat4<T> shearZY(T sca);

// 4.1.5 Concatenation of Transforms
// Usually we'll want to apply transforms in the following order: scaling (S), rotation (R) and translation (T).
// Therefore, the composite matrix can be computed as C = TRS.

// 4.1.6 The Rigid-Body Transform
template <typename T> constexpr Mat4<T> lookAt(Vec3<T> const& camera_pos, Vec3<T> const& up_vec, Vec3<T> const& point_pos);

// 4.1.7 Normal Transform
// The traditional answer to transform normal vectors is to use the transposed inverse of the transform. However, the
// full inverse is not necessary, and occasionally cannot be created.

// 4.1.8 Computation of Inverses
// - If a matrix is a single transform or a sequence of simple transforms with given parameters, the inverse can be
//   computed by inverting the parameters.
// - If a matrix is known to be orthogonal (the columns of the matrix are orthonormal vectors), then the inverse is the
//   transpose of the matrix.
// - If nothing is known, then the adjoint method, Cramer's rule, LU decomposition or Gaussian elimination could be used
//   to compute the inverse (`::tf::Inverse` is an implementation of the adjoint method).

/************************
 * Function definitions *
 ************************/

// 4.1.1 Translation
template <typename T> constexpr Mat4<T> translate(T vecx, T vecy, T vecz) { return translate(Vec3<T>(vecx, vecy, vecz)); }
template <typename T> constexpr Mat4<T> translate(Vec3<T> const& vec) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(vec, 1)); }

// 4.1.2 Rotation
template <typename T> constexpr Mat4<T> rotateX(T rad) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, cos(rad), sin(rad), 0), Vec4<T>(0, -sin(rad), cos(rad), 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> rotateY(T rad) { return Mat4<T>(Vec4<T>(cos(rad), 0, -sin(rad), 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(sin(rad), 0, cos(rad), 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> rotateZ(T rad) { return Mat4<T>(Vec4<T>(cos(rad), sin(rad), 0, 0), Vec4<T>(-sin(rad), cos(rad), 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }

// 4.1.3 Scaling
template <typename T> constexpr Mat4<T> scale(T sca) { return scale(sca, sca, sca); }
template <typename T> constexpr Mat4<T> scale(T vecx, T vecy, T vecz) { return scale(Vec3<T>(vecx, vecy, vecz)); }
template <typename T> constexpr Mat4<T> scale(Vec3<T> const& vec) { return Mat4<T>(Vec4<T>(vec.x(), 0, 0, 0), Vec4<T>(0, vec.y(), 0, 0), Vec4<T>(0, 0, vec.z(), 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> changeBasis(Vec3<T> const& x_vec, Vec3<T> const& y_vec, Vec3<T> const& z_vec) { return Mat4<T>(Vec4<T>(x_vec, 0), Vec4<T>(y_vec, 0), Vec4<T>(z_vec, 0), Vec4<T>(0, 0, 0, 1)); }

// 4.1.4 Shearing
template <typename T> constexpr Mat4<T> shearXY(T sca) { return Mat4<T>(Vec4<T>(1, sca, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> shearXZ(T sca) { return Mat4<T>(Vec4<T>(1, 0, sca, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> shearYX(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(sca, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> shearYZ(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, sca, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> shearZX(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(sca, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> shearZY(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, sca, 1, 0), Vec4<T>(0, 0, 0, 1)); }

// 4.1.6 The Rigid-Body Transform
template <typename T> constexpr Mat4<T> lookAt(Vec3<T> const& camera_pos, Vec3<T> const& up_vec, Vec3<T> const& point_pos) { Vec3<T> z_vec = normalize(camera_pos - point_pos); Vec3<T> x_vec = normalize(-cross(z_vec, up_vec)); Vec3<T> y_vec = cross(z_vec, x_vec); return changeBasis(x_vec, y_vec, z_vec) * translate(-camera_pos); }

}  // namespace tf

#endif  // TRANSFORM_TRANSFORM_BASIC_H_
