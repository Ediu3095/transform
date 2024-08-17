/**
 * @ref core
 * @file transform/mat.h
 *
 * @defgroup core_matrix Matrix types
 * @ingroup core
 *
 * Matrix types with @f$C@f$ columns and @f$R@f$ rows where @f$C, R \geq 1@f$. These types have an exhaustive set of operators.
 */

#ifndef TRANSFORM_MAT_H_
#define TRANSFORM_MAT_H_

#include "transform/mat/matcxr.h"

namespace tf {
/** @addtogroup core_matrix
 * @{ */

template <typename T> using Mat1 = Mat<1, 1, T>;  ///< 1x1 matrix of T.
template <typename T> using Mat2 = Mat<2, 2, T>;  ///< 2x2 matrix of T.
template <typename T> using Mat3 = Mat<3, 3, T>;  ///< 3x3 matrix of T.
template <typename T> using Mat4 = Mat<4, 4, T>;  ///< 4x4 matrix of T.

template <typename T> using Mat1x1 = Mat<1, 1, T>;  ///< 1x1 matrix of T.
template <typename T> using Mat1x2 = Mat<1, 2, T>;  ///< 1x2 matrix of T.
template <typename T> using Mat1x3 = Mat<1, 3, T>;  ///< 1x3 matrix of T.
template <typename T> using Mat1x4 = Mat<1, 4, T>;  ///< 1x4 matrix of T.

template <typename T> using Mat2x1 = Mat<2, 1, T>;  ///< 2x1 matrix of T.
template <typename T> using Mat2x2 = Mat<2, 2, T>;  ///< 2x2 matrix of T.
template <typename T> using Mat2x3 = Mat<2, 3, T>;  ///< 2x3 matrix of T.
template <typename T> using Mat2x4 = Mat<2, 4, T>;  ///< 2x4 matrix of T.

template <typename T> using Mat3x1 = Mat<3, 1, T>;  ///< 3x1 matrix of T.
template <typename T> using Mat3x2 = Mat<3, 2, T>;  ///< 3x2 matrix of T.
template <typename T> using Mat3x3 = Mat<3, 3, T>;  ///< 3x3 matrix of T.
template <typename T> using Mat3x4 = Mat<3, 4, T>;  ///< 3x4 matrix of T.

template <typename T> using Mat4x1 = Mat<4, 1, T>;  ///< 4x1 matrix of T.
template <typename T> using Mat4x2 = Mat<4, 2, T>;  ///< 4x2 matrix of T.
template <typename T> using Mat4x3 = Mat<4, 3, T>;  ///< 4x3 matrix of T.
template <typename T> using Mat4x4 = Mat<4, 4, T>;  ///< 4x4 matrix of T.

/** @} */
}  // namespace tf

#endif  // TRANSFORM_MAT_H_
