#ifndef TRANSFORM_MAT_MAT_H_
#define TRANSFORM_MAT_MAT_H_

#include "transform/sca.h"

namespace tf {
/** @addtogroup core_matrix
 * @{ */

/**
 * CxR matrix of T.
 *
 * @tparam C An integer greater than 0 that qualifies the columns of the matrix.
 * @tparam R An integer greater than 0 that qualifies the rows of the matrix.
 * @tparam T Scalar type.
 * @see [GLSL 4.60 specification, section 4.1.6 Matrices](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.60.html#basic-types)
 */
template <usize C, usize R, typename T> class Mat;

/** @} */
}  // namespace tf

#endif  // TRANSFORM_MAT_MAT_H_
