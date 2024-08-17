/**
 * @ref core
 * @file transform/vec.h
 *
 * @defgroup core_vector Vector types
 * @ingroup core
 *
 * Vector types with @f$L@f$ components where @f$L \geq 1@f$. These types have an exhaustive set of operators.
 */

#ifndef TRANSFORM_VEC_H_
#define TRANSFORM_VEC_H_

#include "transform/vec/vecn.h"

namespace tf {
/** @addtogroup core_vector
 * @{ */

template <typename T> using Vec1 = Vec<1, T>;  ///< 1 component vector of T.
template <typename T> using Vec2 = Vec<2, T>;  ///< 2 component vector of T.
template <typename T> using Vec3 = Vec<3, T>;  ///< 3 component vector of T.
template <typename T> using Vec4 = Vec<4, T>;  ///< 4 component vector of T.

/** @} */
}  // namespace tf

#endif  // TRANSFORM_VEC_H_
