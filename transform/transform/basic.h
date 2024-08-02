#ifndef TRANSFORM_TRANSFORM_BASIC_H_
#define TRANSFORM_TRANSFORM_BASIC_H_

#include <cmath>

#include "transform/mat/matcxr.h"
#include "transform/vec/func.h"

namespace tf {

// 4.1.1 Translation
template <typename T> constexpr Mat4<T> Translate(T vecx, T vecy, T vecz);
template <typename T> constexpr Mat4<T> Translate(Vec3<T> const& vec);

// 4.1.2 Rotation
template <typename T> constexpr Mat4<T> RotateX(T rad);
template <typename T> constexpr Mat4<T> RotateY(T rad);
template <typename T> constexpr Mat4<T> RotateZ(T rad);

// 4.1.3 Scaling
template <typename T> constexpr Mat4<T> Scale(T sca);
template <typename T> constexpr Mat4<T> Scale(T vecx, T vecy, T vecz);
template <typename T> constexpr Mat4<T> Scale(Vec3<T> const& vec);
template <typename T> constexpr Mat4<T> ChangeBasis(Vec3<T> const& x_vec, Vec3<T> const& y_vec, Vec3<T> const& z_vec);

// 4.1.4 Shearing
template <typename T> constexpr Mat4<T> ShearXY(T sca);
template <typename T> constexpr Mat4<T> ShearXZ(T sca);
template <typename T> constexpr Mat4<T> ShearYX(T sca);
template <typename T> constexpr Mat4<T> ShearYZ(T sca);
template <typename T> constexpr Mat4<T> ShearZX(T sca);
template <typename T> constexpr Mat4<T> ShearZY(T sca);

// 4.1.5 Concatenation of Transforms
// Usually we'll want to apply transforms in the following order: scaling (S), rotation (R) and translation (T).
// Therefore, the composite matrix can be computed as C = TRS.

// 4.1.6 The Rigid-Body Transform
template <typename T> constexpr Mat4<T> LookAt(Vec3<T> const& camera_pos, Vec3<T> const& up_vec, Vec3<T> const& point_pos);

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
template <typename T> constexpr Mat4<T> Translate(T vecx, T vecy, T vecz) { return Translate(Vec3<T>(vecx, vecy, vecz)); }
template <typename T> constexpr Mat4<T> Translate(Vec3<T> const& vec) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(vec, 1)); }

// 4.1.2 Rotation
template <typename T> constexpr Mat4<T> RotateX(T rad) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, std::cos(rad), std::sin(rad), 0), Vec4<T>(0, -std::sin(rad), std::cos(rad), 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> RotateY(T rad) { return Mat4<T>(Vec4<T>(std::cos(rad), 0, -std::sin(rad), 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(std::sin(rad), 0, std::cos(rad), 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> RotateZ(T rad) { return Mat4<T>(Vec4<T>(std::cos(rad), std::sin(rad), 0, 0), Vec4<T>(-std::sin(rad), std::cos(rad), 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }

// 4.1.3 Scaling
template <typename T> constexpr Mat4<T> Scale(T sca) { return Scale(sca, sca, sca); }
template <typename T> constexpr Mat4<T> Scale(T vecx, T vecy, T vecz) { return Scale(Vec3<T>(vecx, vecy, vecz)); }
template <typename T> constexpr Mat4<T> Scale(Vec3<T> const& vec) { return Mat4<T>(Vec4<T>(vec.x(), 0, 0, 0), Vec4<T>(0, vec.y(), 0, 0), Vec4<T>(0, 0, vec.z(), 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> ChangeBasis(Vec3<T> const& x_vec, Vec3<T> const& y_vec, Vec3<T> const& z_vec) { return Mat4<T>(Vec4<T>(x_vec, 0), Vec4<T>(y_vec, 0), Vec4<T>(z_vec, 0), Vec4<T>(0, 0, 0, 1)); }

// 4.1.4 Shearing
template <typename T> constexpr Mat4<T> ShearXY(T sca) { return Mat4<T>(Vec4<T>(1, sca, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> ShearXZ(T sca) { return Mat4<T>(Vec4<T>(1, 0, sca, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> ShearYX(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(sca, 1, 0, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> ShearYZ(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, sca, 0), Vec4<T>(0, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> ShearZX(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(sca, 0, 1, 0), Vec4<T>(0, 0, 0, 1)); }
template <typename T> constexpr Mat4<T> ShearZY(T sca) { return Mat4<T>(Vec4<T>(1, 0, 0, 0), Vec4<T>(0, 1, 0, 0), Vec4<T>(0, sca, 1, 0), Vec4<T>(0, 0, 0, 1)); }

// 4.1.6 The Rigid-Body Transform
template <typename T> constexpr Mat4<T> LookAt(Vec3<T> const& camera_pos, Vec3<T> const& up_vec, Vec3<T> const& point_pos) { Vec3<T> z_vec = Normalize(camera_pos - point_pos); Vec3<T> x_vec = Normalize(-Cross(z_vec, up_vec)); Vec3<T> y_vec = Cross(z_vec, x_vec); return ChangeBasis(x_vec, y_vec, z_vec) * Translate(-camera_pos); }

}  // namespace tf

#endif  // TRANSFORM_TRANSFORM_BASIC_H_
