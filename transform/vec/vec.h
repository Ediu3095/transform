#ifndef TRANSFORM_VEC_VEC_H_
#define TRANSFORM_VEC_VEC_H_

#include "transform/sca.h"

namespace tf {
/** @addtogroup core_vector
 * @{ */

/**
 * L component vector of T.
 *
 * @tparam L An integer greater than 0 that qualifies the dimension of the vector.
 * @tparam T Scalar type.
 * @see [GLSL 4.50 specification, section 4.1.5 Vectors](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.50.pdf)
 */
template <usize L, typename T> class Vec;

/** @} */
}  // namespace tf

#endif  // TRANSFORM_VEC_VEC_H_
