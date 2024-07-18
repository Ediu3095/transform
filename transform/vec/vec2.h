#ifndef TRANSFORM_VEC_VEC2_H_
#define TRANSFORM_VEC_VEC2_H_

#include <cassert>

#include "transform/vec/vec1.h"

#define L 2

namespace tf {

template <typename T> class Vec<L, T> {
 private:
  // --- Data ---
  T head_;
  Vec<L - 1, T> tail_;

 public:
  // --- Types ---
  using ValueType  = T;
  using Type       = Vec<L, T>;
  using LengthType = usize;

  // --- Component access ---
  static constexpr LengthType Length() noexcept { return L; }

  constexpr T& operator[](LengthType idx) noexcept;
  constexpr T const& operator[](LengthType idx) const noexcept;

  constexpr T const& head() const noexcept;              // NOLINT(*-identifier-naming)
  constexpr Vec<L - 1, T> const& tail() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& x() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& r() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& s() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& y() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& g() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& t() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_head(T head) noexcept;                     // NOLINT(*-identifier-naming)
  constexpr void set_tail(Vec<L - 1, T> const& tail) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_x(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_r(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_s(T sca) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_y(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_g(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_t(T sca) noexcept;  // NOLINT(*-identifier-naming)

  // --- Implicit basic constructors ---
  constexpr Vec() noexcept;
  constexpr Vec(Vec const& vec);
  constexpr Vec(Vec&& vec) noexcept = default;

  // --- Explicit basic constructors ---
  explicit constexpr Vec(T sca) noexcept;
  explicit constexpr Vec(Vec<1, T> const& vec) noexcept;

  // --- Conversion constructors ---
  template          <typename A, typename B, typename... C> explicit constexpr Vec(       A         head,        B         tail1, C... tail2) noexcept;
  template <usize M, typename A, typename B, typename... C> explicit constexpr Vec(       A         head, Vec<M, B> const& tail1, C... tail2) noexcept;
  template          <typename A, typename B, typename... C> explicit constexpr Vec(Vec<1, A> const& head,        B         tail1, C... tail2) noexcept;
  template <usize M, typename A, typename B, typename... C> explicit constexpr Vec(Vec<1, A> const& head, Vec<M, B> const& tail1, C... tail2) noexcept;
  template <usize M, typename A,             typename... B> explicit constexpr Vec(Vec<M, A> const& head,                         B... tail)  noexcept;

  // --- Destructor ---
  inline ~Vec() noexcept = default;

  // --- Unary arithmetic operators ---
  constexpr Vec<L, T>& operator=(Vec const& vec)     = default;
  constexpr Vec<L, T>& operator=(Vec&& vec) noexcept = default;
  template <typename U> constexpr Vec<L, T>& operator=(Vec<L, U> const& vec);

  template <typename U> constexpr Vec<L, T>& operator+=(U sca);
  template <typename U> constexpr Vec<L, T>& operator-=(U sca);
  template <typename U> constexpr Vec<L, T>& operator*=(U sca);
  template <typename U> constexpr Vec<L, T>& operator/=(U sca);
  template <typename U> constexpr Vec<L, T>& operator%=(U sca);

  template <typename U> constexpr Vec<L, T>& operator+=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator-=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator*=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator/=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator%=(Vec<1, U> const& vec);

  template <typename U> constexpr Vec<L, T>& operator+=(Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator-=(Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator*=(Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator/=(Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator%=(Vec<L, U> const& vec);

  constexpr Vec<L, T>& operator++();
  constexpr Vec<L, T>& operator--();

  constexpr Vec<L, T> operator++(int);
  constexpr Vec<L, T> operator--(int);

  // --- Unary bit operators ---
  template <typename U> constexpr Vec<L, T>& operator&= (U sca);
  template <typename U> constexpr Vec<L, T>& operator|= (U sca);
  template <typename U> constexpr Vec<L, T>& operator^= (U sca);
  template <typename U> constexpr Vec<L, T>& operator<<=(U sca);
  template <typename U> constexpr Vec<L, T>& operator>>=(U sca);

  template <typename U> constexpr Vec<L, T>& operator&= (Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator|= (Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator^= (Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator<<=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator>>=(Vec<1, U> const& vec);

  template <typename U> constexpr Vec<L, T>& operator&= (Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator|= (Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator^= (Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator<<=(Vec<L, U> const& vec);
  template <typename U> constexpr Vec<L, T>& operator>>=(Vec<L, U> const& vec);
};

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec);

// --- Binary arithmetic operators ---
template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec, T sca);

template <typename T> constexpr Vec<L, T> operator+(T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator-(T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator*(T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator/(T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator%(T sca, Vec<L, T> const& vec);

template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec1, Vec<1, T> const& vec2);

template <typename T> constexpr Vec<L, T> operator+(Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator-(Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator*(Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator/(Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator%(Vec<1, T> const& vec1, Vec<L, T> const& vec2);

template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

// --- Unary bit operators ---
template <typename T> constexpr Vec<L, T> operator~(Vec<L, T> const& vec);

// --- Binary bit operators ---
template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec, T sca);
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec, T sca);

template <typename T> constexpr Vec<L, T> operator& (T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator| (T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator^ (T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator<<(T sca, Vec<L, T> const& vec);
template <typename T> constexpr Vec<L, T> operator>>(T sca, Vec<L, T> const& vec);

template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec1, Vec<1, T> const& vec2);

template <typename T> constexpr Vec<L, T> operator& (Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator| (Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator^ (Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator<<(Vec<1, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator>>(Vec<1, T> const& vec1, Vec<L, T> const& vec2);

template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<L, T> const& vec1, Vec<L, T> const& vec2);
template <typename T> constexpr bool operator!=(Vec<L, T> const& vec1, Vec<L, T> const& vec2);

constexpr Vec<L, bool> operator&&(Vec<L, bool> const& vec1, Vec<L, bool> const& vec2);
constexpr Vec<L, bool> operator||(Vec<L, bool> const& vec1, Vec<L, bool> const& vec2);

// --- Alias ---
template <typename T> using Vec2 = Vec<L, T>;

/************************
 * Function definitions *
 ************************/

// --- Component access ---
template <typename T> constexpr T&       Vec<L, T>::operator[](LengthType idx)       noexcept { assert(idx < this->Length()); return idx == 0 ? this->head_ : this->tail_[idx - 1]; }
template <typename T> constexpr T const& Vec<L, T>::operator[](LengthType idx) const noexcept { assert(idx < this->Length()); return idx == 0 ? this->head_ : this->tail_[idx - 1]; }

template <typename T> constexpr            T  const& Vec<L, T>::head() const noexcept { return this->head_; }  // NOLINT(*-identifier-naming)
template <typename T> constexpr Vec<L - 1, T> const& Vec<L, T>::tail() const noexcept { return this->tail_; }  // NOLINT(*-identifier-naming)

template <typename T> constexpr T const& Vec<L, T>::x() const noexcept { return this->head(); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr T const& Vec<L, T>::r() const noexcept { return this->head(); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr T const& Vec<L, T>::s() const noexcept { return this->head(); }  // NOLINT(*-identifier-naming)

template <typename T> constexpr T const& Vec<L, T>::y() const noexcept { return this->tail_.x(); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr T const& Vec<L, T>::g() const noexcept { return this->tail_.x(); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr T const& Vec<L, T>::t() const noexcept { return this->tail_.x(); }  // NOLINT(*-identifier-naming)

template <typename T> constexpr void Vec<L, T>::set_head(T head)                    noexcept { this->head_ = head; };  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<L, T>::set_tail(Vec<L - 1, T> const& tail) noexcept { this->tail_ = tail; };  // NOLINT(*-identifier-naming)

template <typename T> constexpr void Vec<L, T>::set_x(T sca) noexcept { this->set_head(sca); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<L, T>::set_r(T sca) noexcept { this->set_head(sca); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<L, T>::set_s(T sca) noexcept { this->set_head(sca); }  // NOLINT(*-identifier-naming)

template <typename T> constexpr void Vec<L, T>::set_y(T sca) noexcept { this->tail_.set_x(sca); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<L, T>::set_g(T sca) noexcept { this->tail_.set_x(sca); }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Vec<L, T>::set_t(T sca) noexcept { this->tail_.set_x(sca); }  // NOLINT(*-identifier-naming)

// --- Implicit basic constructors ---
template <typename T> constexpr Vec<L, T>::Vec() noexcept : head_(), tail_() {}
template <typename T> constexpr Vec<L, T>::Vec(Vec const& vec) : head_(vec.head()), tail_(vec.tail()) {}

// --- Explicit basic constructors ---
template <typename T> constexpr Vec<L, T>::Vec(       T         sca) noexcept : head_(sca       ), tail_(sca) {}
template <typename T> constexpr Vec<L, T>::Vec(Vec<1, T> const& vec) noexcept : head_(vec.head()), tail_(   ) {}

// --- Conversion constructors ---
template <typename T> template          <typename A, typename B, typename... C> constexpr Vec<L, T>::Vec(       A         head,        B         tail1, C... tail2) noexcept : head_(head       ), tail_(Vec<1, B>(tail1), tail2...) {}
template <typename T> template <usize M, typename A, typename B, typename... C> constexpr Vec<L, T>::Vec(       A         head, Vec<M, B> const& tail1, C... tail2) noexcept : head_(head       ), tail_(tail1,            tail2...) {}
template <typename T> template          <typename A, typename B, typename... C> constexpr Vec<L, T>::Vec(Vec<1, A> const& head,        B         tail1, C... tail2) noexcept : head_(head.head()), tail_(Vec<1, B>(tail1), tail2...) {}
template <typename T> template <usize M, typename A, typename B, typename... C> constexpr Vec<L, T>::Vec(Vec<1, A> const& head, Vec<M, B> const& tail1, C... tail2) noexcept : head_(head.head()), tail_(tail1,            tail2...) {}
template <typename T> template <usize M, typename A,             typename... B> constexpr Vec<L, T>::Vec(Vec<M, A> const& head,                         B... tail)  noexcept : head_(head.head()), tail_(head.tail(),       tail...) {}

// --- Unary arithmetic operators ---
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator=(Vec<L, U> const& vec) { this->head_ = static_cast<T>(vec.head()); this->tail_ = vec.tail(); return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator+=(U sca) { this->head_ += static_cast<T>(sca); this->tail_ += sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator-=(U sca) { this->head_ -= static_cast<T>(sca); this->tail_ -= sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator*=(U sca) { this->head_ *= static_cast<T>(sca); this->tail_ *= sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator/=(U sca) { this->head_ /= static_cast<T>(sca); this->tail_ /= sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator%=(U sca) { this->head_ %= static_cast<T>(sca); this->tail_ %= sca; return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator+=(Vec<1, U> const& vec) { return *this += vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator-=(Vec<1, U> const& vec) { return *this -= vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator*=(Vec<1, U> const& vec) { return *this *= vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator/=(Vec<1, U> const& vec) { return *this /= vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator%=(Vec<1, U> const& vec) { return *this %= vec.head(); }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator+=(Vec<L, U> const& vec) { this->head_ += static_cast<T>(vec.head()); this->tail_ += vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator-=(Vec<L, U> const& vec) { this->head_ -= static_cast<T>(vec.head()); this->tail_ -= vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator*=(Vec<L, U> const& vec) { this->head_ *= static_cast<T>(vec.head()); this->tail_ *= vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator/=(Vec<L, U> const& vec) { this->head_ /= static_cast<T>(vec.head()); this->tail_ /= vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator%=(Vec<L, U> const& vec) { this->head_ %= static_cast<T>(vec.head()); this->tail_ %= vec.tail(); return *this; }

template <typename T> constexpr Vec<L, T>& Vec<L, T>::operator++() { ++this->head_; ++this->tail_; return *this; }
template <typename T> constexpr Vec<L, T>& Vec<L, T>::operator--() { --this->head_; --this->tail_; return *this; }

template <typename T> constexpr Vec<L, T> Vec<L, T>::operator++(int) { Vec<L, T> result(*this); ++(*this); return result; }
template <typename T> constexpr Vec<L, T> Vec<L, T>::operator--(int) { Vec<L, T> result(*this); --(*this); return result; }

// --- Unary bit operators ---
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator&= (U sca) { this->head_ &=  static_cast<T>(sca); this->tail_ &=  sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator|= (U sca) { this->head_ |=  static_cast<T>(sca); this->tail_ |=  sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator^= (U sca) { this->head_ ^=  static_cast<T>(sca); this->tail_ ^=  sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator<<=(U sca) { this->head_ <<= static_cast<T>(sca); this->tail_ <<= sca; return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator>>=(U sca) { this->head_ >>= static_cast<T>(sca); this->tail_ >>= sca; return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator&= (Vec<1, U> const& vec) { return *this &=  vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator|= (Vec<1, U> const& vec) { return *this |=  vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator^= (Vec<1, U> const& vec) { return *this ^=  vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator<<=(Vec<1, U> const& vec) { return *this <<= vec.head(); }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator>>=(Vec<1, U> const& vec) { return *this >>= vec.head(); }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator&= (Vec<L, U> const& vec) { this->head_ &=  static_cast<T>(vec.head()); this->tail_ &=  vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator|= (Vec<L, U> const& vec) { this->head_ |=  static_cast<T>(vec.head()); this->tail_ |=  vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator^= (Vec<L, U> const& vec) { this->head_ ^=  static_cast<T>(vec.head()); this->tail_ ^=  vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator<<=(Vec<L, U> const& vec) { this->head_ <<= static_cast<T>(vec.head()); this->tail_ <<= vec.tail(); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator>>=(Vec<L, U> const& vec) { this->head_ >>= static_cast<T>(vec.head()); this->tail_ >>= vec.tail(); return *this; }

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec) { return vec; }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec) { return Vec<L, T>(-vec.head(), -vec.tail()); }

// --- Binary arithmetic operators ---
template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() + sca, vec.tail() + sca); }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() - sca, vec.tail() - sca); }
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() * sca, vec.tail() * sca); }
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() / sca, vec.tail() / sca); }
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() % sca, vec.tail() % sca); }

template <typename T> constexpr Vec<L, T> operator+(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca + vec.head(), sca + vec.tail()); }
template <typename T> constexpr Vec<L, T> operator-(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca - vec.head(), sca - vec.tail()); }
template <typename T> constexpr Vec<L, T> operator*(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca * vec.head(), sca * vec.tail()); }
template <typename T> constexpr Vec<L, T> operator/(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca / vec.head(), sca / vec.tail()); }
template <typename T> constexpr Vec<L, T> operator%(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca % vec.head(), sca % vec.tail()); }

template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 + vec2.head(); }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 - vec2.head(); }
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 * vec2.head(); }
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 / vec2.head(); }
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 % vec2.head(); }

template <typename T> constexpr Vec<L, T> operator+(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() + vec2; }
template <typename T> constexpr Vec<L, T> operator-(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() - vec2; }
template <typename T> constexpr Vec<L, T> operator*(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() * vec2; }
template <typename T> constexpr Vec<L, T> operator/(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() / vec2; }
template <typename T> constexpr Vec<L, T> operator%(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() % vec2; }

template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() + vec2.head(), vec1.tail() + vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() - vec2.head(), vec1.tail() - vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() * vec2.head(), vec1.tail() * vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() / vec2.head(), vec1.tail() / vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() % vec2.head(), vec1.tail() % vec2.tail()); }

// --- Unary bit operators ---
template <typename T> constexpr Vec<L, T> operator~(Vec<L, T> const& vec) { return Vec<L, T>(~vec.head(), ~vec.tail()); }

// --- Binary bit operators ---
template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() &  sca, vec.tail() &  sca); }
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() |  sca, vec.tail() |  sca); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() ^  sca, vec.tail() ^  sca); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() << sca, vec.tail() << sca); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec, T sca) { return Vec<L, T>(vec.head() >> sca, vec.tail() >> sca); }

template <typename T> constexpr Vec<L, T> operator& (T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca &  vec.head(), sca &  vec.tail()); }
template <typename T> constexpr Vec<L, T> operator| (T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca |  vec.head(), sca |  vec.tail()); }
template <typename T> constexpr Vec<L, T> operator^ (T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca ^  vec.head(), sca ^  vec.tail()); }
template <typename T> constexpr Vec<L, T> operator<<(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca << vec.head(), sca << vec.tail()); }
template <typename T> constexpr Vec<L, T> operator>>(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca >> vec.head(), sca >> vec.tail()); }

template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 &  vec2.head(); }
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 |  vec2.head(); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 ^  vec2.head(); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 << vec2.head(); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return vec1 >> vec2.head(); }

template <typename T> constexpr Vec<L, T> operator& (Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() &  vec2; }
template <typename T> constexpr Vec<L, T> operator| (Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() |  vec2; }
template <typename T> constexpr Vec<L, T> operator^ (Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() ^  vec2; }
template <typename T> constexpr Vec<L, T> operator<<(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() << vec2; }
template <typename T> constexpr Vec<L, T> operator>>(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() >> vec2; }

template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() &  vec2.head(), vec1.tail() &  vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() |  vec2.head(), vec1.tail() |  vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() ^  vec2.head(), vec1.tail() ^  vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() << vec2.head(), vec1.tail() << vec2.tail()); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1.head() >> vec2.head(), vec1.tail() >> vec2.tail()); }

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return vec1.head() == vec2.head() && vec1.tail() == vec2.tail(); }
template <typename T> constexpr bool operator!=(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return !(vec1 == vec2); }

constexpr Vec<L, bool> operator&&(Vec<L, bool> const& vec1, Vec<L, bool> const& vec2) { return Vec<L, bool>(vec1.head() && vec2.head(), vec1.tail() && vec2.tail()); }
constexpr Vec<L, bool> operator||(Vec<L, bool> const& vec1, Vec<L, bool> const& vec2) { return Vec<L, bool>(vec1.head() || vec2.head(), vec1.tail() || vec2.tail()); }

}  // namespace tf

#undef L

#endif  // TRANSFORM_VEC_VEC2_H_
