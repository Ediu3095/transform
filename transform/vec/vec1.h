#ifndef TRANSFORM_VEC_VEC1_H_
#define TRANSFORM_VEC_VEC1_H_

#include <cassert>

#include "transform/vec/vec.h"

namespace tf {

template <typename T> class Vec<1, T> {
 private:
  // --- Data ---
  T x_;

 public:
  // --- Types ---
  using ValueType  = T;
  using Type       = Vec<1, T>;
  using LengthType = tf::usize;

  // --- Component access ---
  static constexpr LengthType Length() noexcept { return 1; }

  constexpr T& operator[](LengthType idx) noexcept;
  constexpr T const& operator[](LengthType idx) const noexcept;

  constexpr T const& x() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& r() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& s() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_x(T sca) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_r(T sca) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_s(T sca) noexcept;  // NOLINT(*-identifier-naming)

  // --- Implicit basic constructors ---
  constexpr Vec() noexcept;
  constexpr Vec(Vec const& vec);
  constexpr Vec(Vec&& vec) noexcept = default;

  // --- Explicit basic constructors ---
  explicit constexpr Vec(T sca) noexcept;

  // --- Conversion scalar constructors ---
  template <typename U> explicit constexpr Vec(U sca) noexcept;

  // --- Conversion vector constructors ---
  template <usize M, typename U> explicit constexpr Vec(Vec<M, U> const& vec) noexcept;

  // --- Destructor ---
  inline ~Vec() noexcept = default;


  // --- Unary arithmetic operators ---
  constexpr Vec<1, T>& operator=(Vec const& vec)     = default;
  constexpr Vec<1, T>& operator=(Vec&& vec) noexcept = default;
  template <typename U> constexpr Vec<1, T>& operator=(Vec<1, U> const& vec);

  template <typename U> constexpr Vec<1, T>& operator+=(U sca);
  template <typename U> constexpr Vec<1, T>& operator-=(U sca);
  template <typename U> constexpr Vec<1, T>& operator*=(U sca);
  template <typename U> constexpr Vec<1, T>& operator/=(U sca);
  template <typename U> constexpr Vec<1, T>& operator%=(U sca);

  template <typename U> constexpr Vec<1, T>& operator+=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator-=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator*=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator/=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator%=(Vec<1, U> const& vec);

  constexpr Vec<1, T>& operator++();
  constexpr Vec<1, T>& operator--();

  constexpr Vec<1, T> operator++(int);
  constexpr Vec<1, T> operator--(int);

  // --- Unary bit operators ---
  template <typename U> constexpr Vec<1, T>& operator&=(U sca);
  template <typename U> constexpr Vec<1, T>& operator|=(U sca);
  template <typename U> constexpr Vec<1, T>& operator^=(U sca);
  template <typename U> constexpr Vec<1, T>& operator<<=(U sca);
  template <typename U> constexpr Vec<1, T>& operator>>=(U sca);

  template <typename U> constexpr Vec<1, T>& operator&=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator|=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator^=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator<<=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator>>=(Vec<1, U> const& vec);
};

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec);

// --- Binary atithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec, T sca);

template <typename T> constexpr Vec<1, T> operator+(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator-(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator*(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator/(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator%(T sca, Vec<1, T> const& vec);

template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec1, Vec<1, T> const& vec2);

// --- Unary bit operators ---
template <typename T> constexpr Vec<1, T> operator~(Vec<1, T> const& vec);

// --- Binary bit operators ---
template <typename T> constexpr Vec<1, T> operator&(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator|(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator^(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec, T sca);
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec, T sca);

template <typename T> constexpr Vec<1, T> operator&(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator|(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator^(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator<<(T sca, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator>>(T sca, Vec<1, T> const& vec);

template <typename T> constexpr Vec<1, T> operator&(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator|(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator^(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec1, Vec<1, T> const& vec2);

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr bool operator!=(Vec<1, T> const& vec1, Vec<1, T> const& vec2);

constexpr Vec<1, bool> operator&&(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2);
constexpr Vec<1, bool> operator||(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2);

// --- Alias ---
template <typename T> using Vec1 = Vec<1, T>;

/************************
 * Function definitions *
 ************************/

// --- Component access ---
template <typename T> constexpr T&       Vec<1, T>::operator[](LengthType idx)       noexcept { assert(idx < this->Length()); return this->x(); }
template <typename T> constexpr T const& Vec<1, T>::operator[](LengthType idx) const noexcept { assert(idx < this->Length()); return this->x(); }

template<typename T> constexpr T const& Vec<1, T>::x() const noexcept { return this->x_; }  // NOLINT(*-identifier-naming)

template<typename T> constexpr T const& Vec<1, T>::r() const noexcept { return this->x(); }  // NOLINT(*-identifier-naming)

template<typename T> constexpr T const& Vec<1, T>::s() const noexcept { return this->x(); }  // NOLINT(*-identifier-naming)

template<typename T> constexpr void Vec<1, T>::set_x(T sca) noexcept { this->x_ = sca; }  // NOLINT(*-identifier-naming)

template<typename T> constexpr void Vec<1, T>::set_r(T sca) noexcept { this->set_x(sca); }  // NOLINT(*-identifier-naming)

template<typename T> constexpr void Vec<1, T>::set_s(T sca) noexcept { this->set_x(sca); }  // NOLINT(*-identifier-naming)

// --- Implicit basic constructors ---
template <typename T> constexpr Vec<1, T>::Vec() noexcept : x_(0) {}
template <typename T> constexpr Vec<1, T>::Vec(Vec const& vec) : x_(vec[0]) {}

// --- Explicit basic constructors ---
template <typename T> constexpr Vec<1, T>::Vec(T sca) noexcept : x_(sca) {}

// --- Conversion scalar constructors ---
template <typename T> template <typename U> constexpr Vec<1, T>::Vec(U sca) noexcept : x_(static_cast<T>(sca)) {}

// --- Conversion vector constructors ---
template <typename T> template <usize M, typename U> constexpr Vec<1, T>::Vec(Vec<M, U> const& vec) noexcept : x_(static_cast<T>(vec[0])) {}

// --- Unary arithmetic operators ---
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator=(Vec<1, U> const& vec) { this->x_ = static_cast<T>(vec.x_); return *this; }

template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator+=(U sca) { this->x_ += static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator-=(U sca) { this->x_ -= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator*=(U sca) { this->x_ *= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator/=(U sca) { this->x_ /= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator%=(U sca) { this->x_ %= static_cast<T>(sca); return *this; }

template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator+=(Vec<1, U> const& vec) { this->x_ += static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator-=(Vec<1, U> const& vec) { this->x_ -= static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator*=(Vec<1, U> const& vec) { this->x_ *= static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator/=(Vec<1, U> const& vec) { this->x_ /= static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator%=(Vec<1, U> const& vec) { this->x_ %= static_cast<T>(vec.x_); return *this; }

template <typename T> constexpr Vec<1, T>& Vec<1, T>::operator++() { ++this->x_; return *this; }
template <typename T> constexpr Vec<1, T>& Vec<1, T>::operator--() { --this->x_; return *this; }

template <typename T> constexpr Vec<1, T> Vec<1, T>::operator++(int) { Vec<1, T> result(*this); ++(*this); return result; }
template <typename T> constexpr Vec<1, T> Vec<1, T>::operator--(int) { Vec<1, T> result(*this); --(*this); return result; }

// --- Unary bit operators ---
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator&= (U sca) { this->x_ &=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator|= (U sca) { this->x_ |=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator^= (U sca) { this->x_ ^=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator<<=(U sca) { this->x_ <<= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator>>=(U sca) { this->x_ >>= static_cast<T>(sca); return *this; }

template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator&= (Vec<1, U> const& vec) { this->x_ &=  static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator|= (Vec<1, U> const& vec) { this->x_ |=  static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator^= (Vec<1, U> const& vec) { this->x_ ^=  static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator<<=(Vec<1, U> const& vec) { this->x_ <<= static_cast<T>(vec.x_); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator>>=(Vec<1, U> const& vec) { this->x_ >>= static_cast<T>(vec.x_); return *this; }

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec) { return vec; }
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec) { return Vec<1, T>(-vec[0]); }

// --- Binary atithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] + sca); }
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] - sca); }
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] * sca); }
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] / sca); }
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] % sca); }

template <typename T> constexpr Vec<1, T> operator+(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca + vec[0]); }
template <typename T> constexpr Vec<1, T> operator-(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca - vec[0]); }
template <typename T> constexpr Vec<1, T> operator*(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca * vec[0]); }
template <typename T> constexpr Vec<1, T> operator/(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca / vec[0]); }
template <typename T> constexpr Vec<1, T> operator%(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca % vec[0]); }

template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] + vec2[0]); }
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] - vec2[0]); }
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] * vec2[0]); }
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] / vec2[0]); }
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] % vec2[0]); }

// --- Unary bit operators ---
template <typename T> constexpr Vec<1, T> operator~(Vec<1, T> const& vec) { return Vec<1, T>(~vec[0]); }

// --- Binary bit operators ---
template <typename T> constexpr Vec<1, T> operator& (Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] &  sca); }
template <typename T> constexpr Vec<1, T> operator| (Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] |  sca); }
template <typename T> constexpr Vec<1, T> operator^ (Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] ^  sca); }
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] << sca); }
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec[0] >> sca); }

template <typename T> constexpr Vec<1, T> operator& (T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca &  vec[0]); }
template <typename T> constexpr Vec<1, T> operator| (T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca |  vec[0]); }
template <typename T> constexpr Vec<1, T> operator^ (T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca ^  vec[0]); }
template <typename T> constexpr Vec<1, T> operator<<(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca << vec[0]); }
template <typename T> constexpr Vec<1, T> operator>>(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca >> vec[0]); }

template <typename T> constexpr Vec<1, T> operator& (Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] &  vec2[0]); }
template <typename T> constexpr Vec<1, T> operator| (Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] |  vec2[0]); }
template <typename T> constexpr Vec<1, T> operator^ (Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] ^  vec2[0]); }
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] << vec2[0]); }
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1[0] >> vec2[0]); }

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return (vec1[0] == vec2[0]); }
template <typename T> constexpr bool operator!=(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return !(vec1 == vec2); }

constexpr Vec<1, bool> operator&&(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2) { return Vec<1, bool>(vec1[0] && vec2[0]); }
constexpr Vec<1, bool> operator||(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2) { return Vec<1, bool>(vec1[0] || vec2[0]); }

}  // namespace tf

#endif  // TRANSFORM_VEC_VEC1_H_
