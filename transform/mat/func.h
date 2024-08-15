#ifndef TRANSFORM_MAT_FUNC_H_
#define TRANSFORM_MAT_FUNC_H_

#include <cassert>
#include <cmath>

#include "transform/types.h"
#include "transform/mat/mat.h"
#include "transform/vec/vec.h"

namespace tf {

template <usize C, usize R, typename T> constexpr Mat<C - 1, R, T> cutCol(Mat<C, R, T> const& mat, usize col);

template <usize C, usize R, typename T> constexpr Mat<C, R - 1, T> cutRow(Mat<C, R, T> const& mat, usize row);

template <usize C, usize R, typename T> constexpr Mat<C - 1, R - 1, T> cutDown(Mat<C, R, T> const& mat, usize col, usize row);

template <usize R, typename T> constexpr T minor(Mat<R, R, T> const& mat, usize col, usize row);

template <usize R, typename T> constexpr T cofactor(Mat<R, R, T> const& mat, usize col, usize row);

template <usize R, typename T> constexpr T determinant(Mat<R, R, T> const& mat);

template <usize R, typename T> constexpr Mat<R, R, T> cofactorMatrix(Mat<R, R, T> const& mat);

template <usize C, usize R, typename T> constexpr Mat<C, R, T> transpose(Mat<R, C, T> const& mat);

template <usize R, typename T> constexpr Mat<R, R, T> inverse(Mat<R, R, T> const& mat);

/************************
 * Function definitions *
 ************************/

template          <usize R, typename T> constexpr Mat<1    , R, T> cutCol(Mat<2, R, T> const& mat, usize col) { assert(col < 2); return col == 0 ? mat.tail() : Mat<1    , R, T>(mat.head()); }
template <usize C, usize R, typename T> constexpr Mat<C - 1, R, T> cutCol(Mat<C, R, T> const& mat, usize col) { assert(col < C); return col == 0 ? mat.tail() : Mat<C - 1, R, T>(mat.head(), cutCol(mat.tail(), col - 1)); }

template                   <typename T> constexpr Vec<   1    , T> cutRow(Vec<   2, T> const& vec, usize row) { assert(row < 2); return row == 0 ? vec.tail() : Vec<1    , T>(vec.head()); }
template          <usize R, typename T> constexpr Vec<   R - 1, T> cutRow(Vec<   R, T> const& vec, usize row) { assert(row < R); return row == 0 ? vec.tail() : Vec<R - 1, T>(vec.head(), cutRow(vec.tail(), row - 1)); }
template          <usize R, typename T> constexpr Mat<1, R - 1, T> cutRow(Mat<1, R, T> const& mat, usize row) { assert(row < R); return Mat<1, R - 1, T>(cutRow(mat.head(), row)); }
template <usize C, usize R, typename T> constexpr Mat<C, R - 1, T> cutRow(Mat<C, R, T> const& mat, usize row) { assert(row < R); return Mat<C, R - 1, T>(cutRow(mat.head(), row), cutRow(mat.tail(), row)); }

template <usize C, usize R, typename T> constexpr Mat<C - 1, R - 1, T> cutDown(Mat<C, R, T> const& mat, usize col, usize row) { assert(col < C && row < R); return cutRow(cutCol(mat, col), row); }

template <usize R, typename T> constexpr T minor(Mat<R, R, T> const& mat, usize col, usize row) { return determinant(cutDown(mat, col, row)); }

template <usize R, typename T> constexpr T cofactor(Mat<R, R, T> const& mat, usize col, usize row) { return static_cast<T>(std::pow(-1, col + row)) * minor(mat, col, row); }

template          <typename T> constexpr T determinant(Mat<1, 1, T> const& mat) { return mat[0][0]; }
template <usize R, typename T> constexpr T determinant(Mat<R, R, T> const& mat) { T result{}; for (usize col = 0; col < R; ++col) result = mat[col][0] * cofactor(mat, col, 0) + result; return result; }

template <usize R, typename T> constexpr Mat<R, R, T> cofactorMatrix(Mat<R, R, T> const& mat) { Mat<R, R, T> result{}; for (usize col = 0; col < R; ++col) for (usize row = 0; row < R; ++row) result[col][row] = cofactor(mat, col, row); return result; }

template          <usize R, typename T> constexpr Mat<1, R, T> transpose(Mat<R, 1, T> const& mat) { return Mat<1, R, T>(mat.headr()); }
template <usize C, usize R, typename T> constexpr Mat<C, R, T> transpose(Mat<R, C, T> const& mat) { return Mat<C, R, T>(mat.headr(), transpose(mat.tailr())); }

template <usize R, typename T> constexpr Mat<R, R, T> inverse(Mat<R, R, T> const& mat) { return static_cast<T>(1) / determinant(mat) * transpose(cofactorMatrix(mat)); }

}  // namespace tf

#endif  // TRANSFORM_MAT_FUNC_H_
