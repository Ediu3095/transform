#ifndef TRANSFORM_VEC_TRIGONOMETRIC_H_
#define TRANSFORM_VEC_TRIGONOMETRIC_H_

#include <cmath>
#include <numbers>

#include "transform/types.h"
#include "transform/vec/vecn.h"

namespace tf {

template <typename T> constexpr T radians(T sca);
template <usize L, typename T> constexpr Vec<L, T> radians(Vec<L, T> const& vec);

template <typename T> constexpr T degrees(T sca);
template <usize L, typename T> constexpr Vec<L, T> degrees(Vec<L, T> const& vec);

using ::std::sin;
template <usize L, typename T> constexpr Vec<L, T> sin(Vec<L, T> const& vec);

using ::std::cos;
template <usize L, typename T> constexpr Vec<L, T> cos(Vec<L, T> const& vec);

using ::std::tan;
template <usize L, typename T> constexpr Vec<L, T> tan(Vec<L, T> const& vec);

using ::std::asin;
template <usize L, typename T> constexpr Vec<L, T> asin(Vec<L, T> const& vec);

using ::std::acos;
template <usize L, typename T> constexpr Vec<L, T> acos(Vec<L, T> const& vec);

using ::std::atan;
template <usize L, typename T> constexpr Vec<L, T> atan(Vec<L, T> const& vec);

using ::std::atan2;
template <usize L, typename T> constexpr Vec<L, T> atan2(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

using ::std::sinh;
template <usize L, typename T> constexpr Vec<L, T> sinh(Vec<L, T> const& vec);

using ::std::cosh;
template <usize L, typename T> constexpr Vec<L, T> cosh(Vec<L, T> const& vec);

using ::std::tanh;
template <usize L, typename T> constexpr Vec<L, T> tanh(Vec<L, T> const& vec);

using ::std::asinh;
template <usize L, typename T> constexpr Vec<L, T> asinh(Vec<L, T> const& vec);

using ::std::acosh;
template <usize L, typename T> constexpr Vec<L, T> acosh(Vec<L, T> const& vec);

using ::std::atanh;
template <usize L, typename T> constexpr Vec<L, T> atanh(Vec<L, T> const& vec);

/************************
 * Function definitions *
 ************************/

template <typename T> constexpr T radians(T sca) { return sca * ::std::numbers::pi_v<T> / static_cast<T>(180); }  // NOLINT(*-magic-numbers)
template          <typename T> constexpr Vec<1, T> radians(Vec<1, T> const& vec) { return Vec<1, T>(radians(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> radians(Vec<L, T> const& vec) { return Vec<L, T>(radians(vec.head()), radians(vec.tail())); }

template <typename T> constexpr T degrees(T sca) { return sca / ::std::numbers::pi_v<T> * static_cast<T>(180); }  // NOLINT(*-magic-numbers)
template          <typename T> constexpr Vec<1, T> degrees(Vec<1, T> const& vec) { return Vec<1, T>(degrees(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> degrees(Vec<L, T> const& vec) { return Vec<L, T>(degrees(vec.head()), degrees(vec.tail())); }

template          <typename T> constexpr Vec<1, T> sin(Vec<1, T> const& vec) { return Vec<1, T>(sin(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> sin(Vec<L, T> const& vec) { return Vec<L, T>(sin(vec.head()), sin(vec.tail())); }

template          <typename T> constexpr Vec<1, T> cos(Vec<1, T> const& vec) { return Vec<1, T>(cos(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> cos(Vec<L, T> const& vec) { return Vec<L, T>(cos(vec.head()), cos(vec.tail())); }

template          <typename T> constexpr Vec<1, T> tan(Vec<1, T> const& vec) { return Vec<1, T>(tan(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> tan(Vec<L, T> const& vec) { return Vec<L, T>(tan(vec.head()), tan(vec.tail())); }

template          <typename T> constexpr Vec<1, T> asin(Vec<1, T> const& vec) { return Vec<1, T>(asin(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> asin(Vec<L, T> const& vec) { return Vec<L, T>(asin(vec.head()), asin(vec.tail())); }

template          <typename T> constexpr Vec<1, T> acos(Vec<1, T> const& vec) { return Vec<1, T>(acos(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> acos(Vec<L, T> const& vec) { return Vec<L, T>(acos(vec.head()), acos(vec.tail())); }

template          <typename T> constexpr Vec<1, T> atan(Vec<1, T> const& vec) { return Vec<1, T>(atan(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> atan(Vec<L, T> const& vec) { return Vec<L, T>(atan(vec.head()), atan(vec.tail())); }

template          <typename T> constexpr Vec<1, T> atan2(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(atan2(vec1.head(), vec2.head())); }
template <usize L, typename T> constexpr Vec<L, T> atan2(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(atan2(vec1.head(), vec2.head()), atan2(vec1.tail(), vec2.tail())); }

template          <typename T> constexpr Vec<1, T> sinh(Vec<1, T> const& vec) { return Vec<1, T>(sinh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> sinh(Vec<L, T> const& vec) { return Vec<L, T>(sinh(vec.head()), sinh(vec.tail())); }

template          <typename T> constexpr Vec<1, T> cosh(Vec<1, T> const& vec) { return Vec<1, T>(cosh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> cosh(Vec<L, T> const& vec) { return Vec<L, T>(cosh(vec.head()), cosh(vec.tail())); }

template          <typename T> constexpr Vec<1, T> tanh(Vec<1, T> const& vec) { return Vec<1, T>(tanh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> tanh(Vec<L, T> const& vec) { return Vec<L, T>(tanh(vec.head()), tanh(vec.tail())); }

template          <typename T> constexpr Vec<1, T> asinh(Vec<1, T> const& vec) { return Vec<1, T>(asinh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> asinh(Vec<L, T> const& vec) { return Vec<L, T>(asinh(vec.head()), asinh(vec.tail())); }

template          <typename T> constexpr Vec<1, T> acosh(Vec<1, T> const& vec) { return Vec<1, T>(acosh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> acosh(Vec<L, T> const& vec) { return Vec<L, T>(acosh(vec.head()), acosh(vec.tail())); }

template          <typename T> constexpr Vec<1, T> atanh(Vec<1, T> const& vec) { return Vec<1, T>(atanh(vec.head())); }
template <usize L, typename T> constexpr Vec<L, T> atanh(Vec<L, T> const& vec) { return Vec<L, T>(atanh(vec.head()), atanh(vec.tail())); }

}  // namespace tf

#endif  // TRANSFORM_VEC_TRIGONOMETRIC_H_
