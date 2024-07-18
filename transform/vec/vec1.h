#ifndef TRANSFORM_VEC_VEC1_H_
#define TRANSFORM_VEC_VEC1_H_

#include <cassert>

#include "transform/vec/vec.h"

namespace tf {

template <typename T> class Vec<1, T> {
 private:
  // --- Data ---
  T head_;

 public:
  // --- Types ---
  using ValueType  = T;
  using Type       = Vec<1, T>;
  using LengthType = usize;

  // --- Component access ---
  static constexpr LengthType Length() noexcept { return 1; }

  constexpr T& operator[](LengthType idx) noexcept;
  constexpr T const& operator[](LengthType idx) const noexcept;

  constexpr T const& head() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& x() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& r() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& s() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_head(T head) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_x(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_r(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_s(T sca) noexcept;  // NOLINT(*-identifier-naming)

  // --- Implicit basic constructors ---
  constexpr Vec() noexcept;
  constexpr Vec(Vec const& vec);
  constexpr Vec(Vec&& vec) noexcept = default;

  // --- Explicit basic constructors ---
  explicit constexpr Vec(T sca) noexcept;

  // --- Conversion constructors ---
  template          <typename A, typename... B> explicit constexpr Vec(       A         head, B... /* unused */) noexcept;
  template <usize M, typename A, typename... B> explicit constexpr Vec(Vec<M, A> const& head, B... /* unused */) noexcept;

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

// --- Binary arithmetic operators ---
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
template <typename T> constexpr T&       Vec<1, T>::operator[](LengthType idx)       noexcept { assert(idx < this->Length()); return this->head_; }
template <typename T> constexpr T const& Vec<1, T>::operator[](LengthType idx) const noexcept { assert(idx < this->Length()); return this->head_; }

template <typename T> constexpr T const& Vec<1, T>::head() const noexcept { return this->head_; };  // NOLINT(*-identifier-naming)

template <typename T> constexpr T const& Vec<1, T>::x() const noexcept { return this->head(); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr T const& Vec<1, T>::r() const noexcept { return this->head(); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr T const& Vec<1, T>::s() const noexcept { return this->head(); }  // NOLINT(*-identifier-naming)

template <typename T> constexpr void Vec<1, T>::set_head(T head) noexcept { this->head_ = head; }  // NOLINT(*-identifier-naming)

template <typename T> constexpr void Vec<1, T>::set_x(T sca) noexcept { this->set_head(sca); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<1, T>::set_r(T sca) noexcept { this->set_head(sca); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<1, T>::set_s(T sca) noexcept { this->set_head(sca); }  // NOLINT(*-identifier-naming)

// --- Implicit basic constructors ---
template <typename T> constexpr Vec<1, T>::Vec() noexcept : head_() {}
template <typename T> constexpr Vec<1, T>::Vec(Vec const& vec) : head_(vec.head_) {}

// --- Explicit basic constructors ---
template <typename T> constexpr Vec<1, T>::Vec(T sca) noexcept : head_(sca) {}

// --- Conversion constructors ---
template <typename T> template          <typename A, typename... B> constexpr Vec<1, T>::Vec(       A         head, B... /* unused */) noexcept : head_(static_cast<T>(head       )) {}
template <typename T> template <usize M, typename A, typename... B> constexpr Vec<1, T>::Vec(Vec<M, A> const& head, B... /* unused */) noexcept : head_(static_cast<T>(head.head())) {}

// --- Unary arithmetic operators ---
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator=(Vec<1, U> const& vec) { this->head_ = static_cast<T>(vec.head()); return *this; }

template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator+=(U sca) { this->head_ += static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator-=(U sca) { this->head_ -= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator*=(U sca) { this->head_ *= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator/=(U sca) { this->head_ /= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator%=(U sca) { this->head_ %= static_cast<T>(sca); return *this; }

template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator+=(Vec<1, U> const& vec) { return *this += vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator-=(Vec<1, U> const& vec) { return *this -= vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator*=(Vec<1, U> const& vec) { return *this *= vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator/=(Vec<1, U> const& vec) { return *this /= vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator%=(Vec<1, U> const& vec) { return *this %= vec.head(); }

template <typename T> constexpr Vec<1, T>& Vec<1, T>::operator++() { ++this->head_; return *this; }
template <typename T> constexpr Vec<1, T>& Vec<1, T>::operator--() { --this->head_; return *this; }

template <typename T> constexpr Vec<1, T> Vec<1, T>::operator++(int) { Vec<1, T> result(*this); ++(*this); return result; }
template <typename T> constexpr Vec<1, T> Vec<1, T>::operator--(int) { Vec<1, T> result(*this); --(*this); return result; }

// --- Unary bit operators ---
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator&= (U sca) { this->head_ &=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator|= (U sca) { this->head_ |=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator^= (U sca) { this->head_ ^=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator<<=(U sca) { this->head_ <<= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator>>=(U sca) { this->head_ >>= static_cast<T>(sca); return *this; }

template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator&= (Vec<1, U> const& vec) { return *this&=  vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator|= (Vec<1, U> const& vec) { return *this|=  vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator^= (Vec<1, U> const& vec) { return *this^=  vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator<<=(Vec<1, U> const& vec) { return *this<<= vec.head(); }
template <typename T> template <typename U> constexpr Vec<1, T>& Vec<1, T>::operator>>=(Vec<1, U> const& vec) { return *this>>= vec.head(); }

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec) { return vec; }
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec) { return Vec<1, T>(-vec.head()); }

// --- Binary arithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() + sca); }
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() - sca); }
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() * sca); }
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() / sca); }
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() % sca); }

template <typename T> constexpr Vec<1, T> operator+(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca + vec.head()); }
template <typename T> constexpr Vec<1, T> operator-(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca - vec.head()); }
template <typename T> constexpr Vec<1, T> operator*(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca * vec.head()); }
template <typename T> constexpr Vec<1, T> operator/(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca / vec.head()); }
template <typename T> constexpr Vec<1, T> operator%(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca % vec.head()); }

template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() + vec2.head()); }
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() - vec2.head()); }
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() * vec2.head()); }
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() / vec2.head()); }
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() % vec2.head()); }

// --- Unary bit operators ---
template <typename T> constexpr Vec<1, T> operator~(Vec<1, T> const& vec) { return Vec<1, T>(~vec.head()); }

// --- Binary bit operators ---
template <typename T> constexpr Vec<1, T> operator& (Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() &  sca); }
template <typename T> constexpr Vec<1, T> operator| (Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() |  sca); }
template <typename T> constexpr Vec<1, T> operator^ (Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() ^  sca); }
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() << sca); }
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec, T sca) { return Vec<1, T>(vec.head() >> sca); }

template <typename T> constexpr Vec<1, T> operator& (T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca &  vec.head()); }
template <typename T> constexpr Vec<1, T> operator| (T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca |  vec.head()); }
template <typename T> constexpr Vec<1, T> operator^ (T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca ^  vec.head()); }
template <typename T> constexpr Vec<1, T> operator<<(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca << vec.head()); }
template <typename T> constexpr Vec<1, T> operator>>(T sca, Vec<1, T> const& vec) { return Vec<1, T>(sca >> vec.head()); }

template <typename T> constexpr Vec<1, T> operator& (Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() &  vec2.head()); }
template <typename T> constexpr Vec<1, T> operator| (Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() |  vec2.head()); }
template <typename T> constexpr Vec<1, T> operator^ (Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() ^  vec2.head()); }
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() << vec2.head()); }
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return Vec<1, T>(vec1.head() >> vec2.head()); }

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return (vec1.head() == vec2.head()); }
template <typename T> constexpr bool operator!=(Vec<1, T> const& vec1, Vec<1, T> const& vec2) { return !(vec1 == vec2); }

constexpr Vec<1, bool> operator&&(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2) { return Vec<1, bool>(vec1.head() && vec2.head()); }
constexpr Vec<1, bool> operator||(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2) { return Vec<1, bool>(vec1.head() || vec2.head()); }

}  // namespace tf

#endif  // TRANSFORM_VEC_VEC1_H_
