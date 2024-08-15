#include "transform/types.h"
#include "transform/mat.h"
#include "transform/vec.h"
#include "transform/vec/vecn.h"

namespace tf {

// Vec1
template class Vec<1, i8>;
template class Vec<1, i16>;
template class Vec<1, i32>;
template class Vec<1, i64>;
template class Vec<1, u8>;
template class Vec<1, u16>;
template class Vec<1, u32>;
template class Vec<1, u64>;
template class Vec<1, f32>;
template class Vec<1, f64>;

// Vec2
template class Vec<2, i8>;
template class Vec<2, i16>;
template class Vec<2, i32>;
template class Vec<2, i64>;
template class Vec<2, u8>;
template class Vec<2, u16>;
template class Vec<2, u32>;
template class Vec<2, u64>;
template class Vec<2, f32>;
template class Vec<2, f64>;

// Vec3
template class Vec<3, i8>;
template class Vec<3, i16>;
template class Vec<3, i32>;
template class Vec<3, i64>;
template class Vec<3, u8>;
template class Vec<3, u16>;
template class Vec<3, u32>;
template class Vec<3, u64>;
template class Vec<3, f32>;
template class Vec<3, f64>;

// Vec4
template class Vec<4, i8>;
template class Vec<4, i16>;
template class Vec<4, i32>;
template class Vec<4, i64>;
template class Vec<4, u8>;
template class Vec<4, u16>;
template class Vec<4, u32>;
template class Vec<4, u64>;
template class Vec<4, f32>;
template class Vec<4, f64>;

// Mat1
template class Mat<1, 1, f32>;
template class Mat<1, 1, f64>;

// Mat1x2
template class Mat<1, 2, f32>;
template class Mat<1, 2, f64>;

// Mat1x3
template class Mat<1, 3, f32>;
template class Mat<1, 3, f64>;

// Mat1x4
template class Mat<1, 4, f32>;
template class Mat<1, 4, f64>;

// Mat2x1
template class Mat<2, 1, f32>;
template class Mat<2, 1, f64>;

// Mat2
template class Mat<2, 2, f32>;
template class Mat<2, 2, f64>;

// Mat2x3
template class Mat<2, 3, f32>;
template class Mat<2, 3, f64>;

// Mat2x4
template class Mat<2, 4, f32>;
template class Mat<2, 4, f64>;

// Mat3x1
template class Mat<3, 1, f32>;
template class Mat<3, 1, f64>;

// Mat3x2
template class Mat<3, 2, f32>;
template class Mat<3, 2, f64>;

// Mat3
template class Mat<3, 3, f32>;
template class Mat<3, 3, f64>;

// Mat3x4
template class Mat<3, 4, f32>;
template class Mat<3, 4, f64>;

// Mat4x1
template class Mat<4, 1, f32>;
template class Mat<4, 1, f64>;

// Mat4x2
template class Mat<4, 2, f32>;
template class Mat<4, 2, f64>;

// Mat4x3
template class Mat<4, 3, f32>;
template class Mat<4, 3, f64>;

// Mat4
template class Mat<4, 4, f32>;
template class Mat<4, 4, f64>;

}  // namespace tf
