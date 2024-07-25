#ifndef TRANSFORM_MAT_FUNC_H_
#define TRANSFORM_MAT_FUNC_H_

#include <cassert>
#include <cmath>

#include "transform/types.h"
#include "transform/mat/mat.h"
#include "transform/vec/vec.h"

namespace tf {

template <usize C, usize R, typename T> constexpr Mat<C - 1, R, T> CutCol(Mat<C, R, T> const& mat, usize col);
template          <usize R, typename T> constexpr Mat<1    , R, T> CutCol(Mat<2, R, T> const& mat, usize col);

template <usize C, usize R, typename T> constexpr Mat<C, R - 1, T> CutRow(Mat<C, R, T> const& mat, usize row);
template          <usize R, typename T> constexpr Mat<1, R - 1, T> CutRow(Mat<1, R, T> const& mat, usize row);
template          <usize R, typename T> constexpr Vec<   R - 1, T> CutRow(Vec<   R, T> const& vec, usize row);
template                   <typename T> constexpr Vec<   1    , T> CutRow(Vec<   2, T> const& vec, usize row);

template <usize C, usize R, typename T> constexpr Mat<C - 1, R - 1, T> CutDown(Mat<C, R, T> const& mat, usize col, usize row);

template <usize R, typename T> constexpr T Minor(Mat<R, R, T> const& mat, usize col, usize row);

template <usize R, typename T> constexpr T Cofactor(Mat<R, R, T> const& mat, usize col, usize row);

template <usize R, typename T> constexpr T Determinant(Mat<R, R, T> const& mat);
template          <typename T> constexpr T Determinant(Mat<1, 1, T> const& mat);

template <usize R, typename T> constexpr Mat<R, R, T> CofactorMatrix(Mat<R, R, T> const& mat);

template <usize C, usize R, typename T> constexpr Mat<C, R, T> Transpose(Mat<R, C, T> const& mat);
template          <usize R, typename T> constexpr Mat<1, R, T> Transpose(Mat<R, 1, T> const& mat);

template <usize R, typename T> constexpr Mat<R, R, T> Inverse(Mat<R, R, T> const& mat);

/************************
 * Function definitions *
 ************************/

template <usize C, usize R, typename T> constexpr Mat<C - 1, R, T> CutCol(Mat<C, R, T> const& mat, usize col) { assert(col < C); return col == 0 ? mat.tail() : Mat<C - 1, R, T>(mat.head(), CutCol(mat.tail(), col - 1)); }
template          <usize R, typename T> constexpr Mat<1    , R, T> CutCol(Mat<2, R, T> const& mat, usize col) { assert(col < 2); return col == 0 ? mat.tail() : Mat<1    , R, T>(mat.head()                             ); }

template <usize C, usize R, typename T> constexpr Mat<C, R - 1, T> CutRow(Mat<C, R, T> const& mat, usize row) { assert(row < R); return Mat<C, R - 1, T>(CutRow(mat.head(), row), CutRow(mat.tail(), row)); }
template          <usize R, typename T> constexpr Mat<1, R - 1, T> CutRow(Mat<1, R, T> const& mat, usize row) { assert(row < R); return Mat<1, R - 1, T>(CutRow(mat.head(), row)                         ); }
template          <usize R, typename T> constexpr Vec<   R - 1, T> CutRow(Vec<   R, T> const& vec, usize row) { assert(row < R); return row == 0 ? vec.tail() : Vec<R - 1, T>(vec.head(), CutRow(vec.tail(), row - 1)); }
template                   <typename T> constexpr Vec<   1    , T> CutRow(Vec<   2, T> const& vec, usize row) { assert(row < 2); return row == 0 ? vec.tail() : Vec<1    , T>(vec.head()                             ); }

template <usize C, usize R, typename T> constexpr Mat<C - 1, R - 1, T> CutDown(Mat<C, R, T> const& mat, usize col, usize row) { assert(col < C && row < R); return CutRow(CutCol(mat, col), row); }

template <usize R, typename T> constexpr T Minor(Mat<R, R, T> const& mat, usize col, usize row) { return Determinant(CutDown(mat, col, row)); }

template <usize R, typename T> constexpr T Cofactor(Mat<R, R, T> const& mat, usize col, usize row) { return std::pow(-1, col + row) * Minor(mat, col, row); }

template <usize R, typename T> constexpr T Determinant(Mat<R, R, T> const& mat) { T result{}; for (usize col = 0; col < R; ++col) result = mat[col][0] * Cofactor(mat, col, 0) + result; return result; }
template          <typename T> constexpr T Determinant(Mat<1, 1, T> const& mat) { return mat[0][0]; }

template <usize R, typename T> constexpr Mat<R, R, T> CofactorMatrix(Mat<R, R, T> const& mat) { Mat<R, R, T> result{}; for (usize col = 0; col < R; ++col) for (usize row = 0; row < R; ++row) result[col][row] = Cofactor(mat, col, row); return result; }

template <usize C, usize R, typename T> constexpr Mat<C, R, T> Transpose(Mat<R, C, T> const& mat) { return Mat<C, R, T>(mat.headr(), Transpose(mat.tailr())); }
template          <usize R, typename T> constexpr Mat<1, R, T> Transpose(Mat<R, 1, T> const& mat) { return Mat<1, R, T>(mat.headr()); }

template <usize R, typename T> constexpr Mat<R, R, T> Inverse(Mat<R, R, T> const& mat) { return static_cast<T>(1) / Determinant(mat) * Transpose(CofactorMatrix(mat)); }

}  // namespace tf

#endif  // TRANSFORM_MAT_FUNC_H_
