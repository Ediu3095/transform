#ifndef TRANSFORM_VEC_VEC4_H_
#define TRANSFORM_VEC_VEC4_H_

#include <cassert>

#include "transform/vec/vec3.h"

#define L 4

namespace tf {

template <typename T> class Vec<L, T> {
 private:
  // --- Data ---
  Vec<L - 1, T> vec_;
  T w_;

 public:
  // --- Types ---
  using ValueType  = T;
  using Type       = Vec<L, T>;
  using LengthType = tf::usize;

  // --- Component access ---
  static constexpr LengthType Length() noexcept { return L; }

  constexpr T& operator[](LengthType idx) noexcept;
  constexpr T const& operator[](LengthType idx) const noexcept;

  constexpr T const& x() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& y() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& z() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& w() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& r() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& g() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& b() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& a() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr T const& s() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& t() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& p() const noexcept;  // NOLINT(*-identifier-naming)
  constexpr T const& q() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_x(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_y(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_z(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_w(T sca) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_r(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_g(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_b(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_a(T sca) noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_s(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_t(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_p(T sca) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_q(T sca) noexcept;  // NOLINT(*-identifier-naming)

  // --- Implicit basic constructors ---
  constexpr Vec() noexcept;
  constexpr Vec(Vec const& vec);
  constexpr Vec(Vec&& vec) noexcept = default;

  // --- Explicit basic constructors ---
  explicit constexpr Vec(T sca) noexcept;
  explicit constexpr Vec(T sca1, T sca2) noexcept;

  // --- Conversion scalar constructors ---  // TODO(ersabajanes): write constructors for Vec4
  template <typename U> explicit constexpr Vec(U sca) noexcept;
  template <typename U> explicit constexpr Vec(Vec<1, U> const& vec) noexcept;

  template <typename A, typename B> explicit constexpr Vec(Vec<2, A> const& vec1, Vec<2, B> const& vec2) noexcept;  // 2, 2

  template <typename A, typename B> explicit constexpr Vec(Vec<3, A> const& vec1,                B sca2) noexcept;  // 3, 1
  template <typename A, typename B> explicit constexpr Vec(Vec<3, A> const& vec1, Vec<1, B> const& vec2) noexcept;

  template <typename A, typename B> explicit constexpr Vec(               A sca1, Vec<3, B> const& vec2) noexcept;  // 1, 3
  template <typename A, typename B> explicit constexpr Vec(Vec<1, A> const& vec1, Vec<3, B> const& vec2) noexcept;

  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<2, A> const& vec1,                B sca2,                C sca3) noexcept;  // 2, 1, 1
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<2, A> const& vec1, Vec<1, B> const& vec2,                C sca3) noexcept;
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<2, A> const& vec1,                B sca2, Vec<1, C> const& vec3) noexcept;
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<2, A> const& vec1, Vec<1, B> const& vec2, Vec<1, C> const& vec3) noexcept;

  template <typename A, typename B, typename C> explicit constexpr Vec(                A sca1, Vec<2, B> const& vec2,                C sca3) noexcept;  // 1, 2, 1
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<1, A>  const& vec1, Vec<2, B> const& vec2,                C sca3) noexcept;
  template <typename A, typename B, typename C> explicit constexpr Vec(                A sca1, Vec<2, B> const& vec2, Vec<1, C> const& vec3) noexcept;
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<1, A>  const& vec1, Vec<2, B> const& vec2, Vec<1, C> const& vec3) noexcept;

  template <typename A, typename B, typename C> explicit constexpr Vec(                A sca1,                B sca2, Vec<2, C> const& vec3) noexcept;  // 1, 1, 2
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<1, A>  const& vec1,                B sca2, Vec<2, C> const& vec3) noexcept;
  template <typename A, typename B, typename C> explicit constexpr Vec(                A sca1, Vec<1, B> const& vec2, Vec<2, C> const& vec3) noexcept;
  template <typename A, typename B, typename C> explicit constexpr Vec(Vec<1, A>  const& vec1, Vec<1, B> const& vec2, Vec<2, C> const& vec3) noexcept;

  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1,                B sca2,                C sca3,                D sca4) noexcept;  // 1, 1, 1, 1
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1,                B sca2,                C sca3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1, Vec<1, B> const& vec2,                C sca3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2,                C sca3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1,                B sca2, Vec<1, C> const& vec3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1,                B sca2, Vec<1, C> const& vec3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1, Vec<1, B> const& vec2, Vec<1, C> const& vec3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2, Vec<1, C> const& vec3,                D sca4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1,                B sca2,                C sca3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1,                B sca2,                C sca3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1, Vec<1, B> const& vec2,                C sca3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2,                C sca3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1,                B sca2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1,                B sca2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(               A sca1, Vec<1, B> const& vec2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept;
  template <typename A, typename B, typename C, typename D> explicit constexpr Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept;

  // --- Conversion vector constructors ---
  template <usize M, typename U> explicit constexpr Vec(Vec<M, U> const& vec) noexcept;

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

// --- Binary atithmetic operators ---
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
template <typename T> using Vec4 = Vec<L, T>;

/************************
 * Function definitions *
 ************************/

// --- Component access ---
template <typename T> constexpr T&       Vec<L, T>::operator[](LengthType idx)       noexcept { assert(idx < this->Length()); return idx == L - 1 ? this->w_ : this->vec_[idx]; }
template <typename T> constexpr T const& Vec<L, T>::operator[](LengthType idx) const noexcept { assert(idx < this->Length()); return idx == L - 1 ? this->w_ : this->vec_[idx]; }

template<typename T> constexpr T const& Vec<L, T>::x() const noexcept { return this->vec_.x(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::y() const noexcept { return this->vec_.y(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::z() const noexcept { return this->vec_.z(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::w() const noexcept { return this->w_; };       // NOLINT(*-identifier-naming)

template<typename T> constexpr T const& Vec<L, T>::r() const noexcept { return this->vec_.x(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::g() const noexcept { return this->vec_.y(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::b() const noexcept { return this->vec_.z(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::a() const noexcept { return this->w(); };      // NOLINT(*-identifier-naming)

template<typename T> constexpr T const& Vec<L, T>::s() const noexcept { return this->vec_.x(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::t() const noexcept { return this->vec_.y(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::p() const noexcept { return this->vec_.z(); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr T const& Vec<L, T>::q() const noexcept { return this->w(); };      // NOLINT(*-identifier-naming)

template<typename T> constexpr void Vec<L, T>::set_x(T sca) noexcept { this->vec_.set_x(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_y(T sca) noexcept { this->vec_.set_y(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_z(T sca) noexcept { this->vec_.set_z(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_w(T sca) noexcept { this->w_ = sca; }         // NOLINT(*-identifier-naming)

template<typename T> constexpr void Vec<L, T>::set_r(T sca) noexcept { this->vec_.set_x(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_g(T sca) noexcept { this->vec_.set_y(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_b(T sca) noexcept { this->vec_.set_z(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_a(T sca) noexcept { this->set_w(sca); }       // NOLINT(*-identifier-naming)

template<typename T> constexpr void Vec<L, T>::set_s(T sca) noexcept { this->vec_.set_x(sca); }  // NOLINT(*-identifier-naming)
template<typename T> constexpr void Vec<L, T>::set_t(T sca) noexcept { this->vec_.set_y(sca); }  // NOLINT(*-identifier-naming)  
template<typename T> constexpr void Vec<L, T>::set_p(T sca) noexcept { this->vec_.set_z(sca); }  // NOLINT(*-identifier-naming)  
template<typename T> constexpr void Vec<L, T>::set_q(T sca) noexcept { this->set_w(sca); }       // NOLINT(*-identifier-naming)  

// --- Implicit basic constructors ---
template <typename T> constexpr Vec<L, T>::Vec() noexcept : vec_(), w_(0) {}
template <typename T> constexpr Vec<L, T>::Vec(Vec const& vec) : vec_(vec), w_(vec[L - 1]) {}

// --- Explicit basic constructors ---
template <typename T> constexpr Vec<L, T>::Vec(T sca) noexcept : vec_(sca), w_(sca) {}
template <typename T> constexpr Vec<L, T>::Vec(T sca1, T sca2) noexcept : vec_(sca1), w_(sca2) {}

// --- Conversion scalar constructors ---
template <typename T> template <typename U> constexpr Vec<L, T>::Vec(               U sca) noexcept : vec_(sca), w_(static_cast<T>(sca))    {}
template <typename T> template <typename U> constexpr Vec<L, T>::Vec(Vec<1, U> const& vec) noexcept : vec_(vec), w_(static_cast<T>(vec[0])) {}

template <typename T> template <typename A, typename B> constexpr Vec<L, T>::Vec(Vec<2, A> const& vec1, Vec<2, B> const& vec2) noexcept : vec_(vec1, vec2[0]), w_(static_cast<T>(vec2[1])) {}

template <typename T> template <typename A, typename B> constexpr Vec<L, T>::Vec(Vec<3, A> const& vec1,                B sca2) noexcept : vec_(vec1), w_(static_cast<T>(sca2))    {}
template <typename T> template <typename A, typename B> constexpr Vec<L, T>::Vec(Vec<3, A> const& vec1, Vec<1, B> const& vec2) noexcept : vec_(vec1), w_(static_cast<T>(vec2[0])) {}

template <typename T> template <typename A, typename B> constexpr Vec<L, T>::Vec(               A sca1, Vec<3, B> const& vec2) noexcept : vec_(sca1, vec2[0], vec2[1]), w_(static_cast<T>(vec2[2])) {}
template <typename T> template <typename A, typename B> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<3, B> const& vec2) noexcept : vec_(vec1, vec2[0], vec2[1]), w_(static_cast<T>(vec2[2])) {}

template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<2, A> const& vec1,                B sca2,                C sca3) noexcept : vec_(vec1, sca2), w_(static_cast<T>(sca3))    {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<2, A> const& vec1, Vec<1, B> const& vec2,                C sca3) noexcept : vec_(vec1, vec2), w_(static_cast<T>(sca3))    {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<2, A> const& vec1,                B sca2, Vec<1, C> const& vec3) noexcept : vec_(vec1, sca2), w_(static_cast<T>(vec3[0])) {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<2, A> const& vec1, Vec<1, B> const& vec2, Vec<1, C> const& vec3) noexcept : vec_(vec1, vec2), w_(static_cast<T>(vec3[0])) {}

template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(               A sca1, Vec<2, B> const& vec2,                C sca3) noexcept : vec_(sca1, vec2), w_(static_cast<T>(sca3))    {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<2, B> const& vec2,                C sca3) noexcept : vec_(vec1, vec2), w_(static_cast<T>(sca3))    {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(               A sca1, Vec<2, B> const& vec2, Vec<1, C> const& vec3) noexcept : vec_(sca1, vec2), w_(static_cast<T>(vec3[0])) {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<2, B> const& vec2, Vec<1, C> const& vec3) noexcept : vec_(vec1, vec2), w_(static_cast<T>(vec3[0])) {}

template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(               A sca1,                B sca2, Vec<2, C> const& vec3) noexcept : vec_(sca1, sca2, vec3[0]), w_(static_cast<T>(vec3[1])) {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1,                B sca2, Vec<2, C> const& vec3) noexcept : vec_(vec1, sca2, vec3[0]), w_(static_cast<T>(vec3[1])) {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(               A sca1, Vec<1, B> const& vec2, Vec<2, C> const& vec3) noexcept : vec_(sca1, vec2, vec3[0]), w_(static_cast<T>(vec3[1])) {}
template <typename T> template <typename A, typename B, typename C> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2, Vec<2, C> const& vec3) noexcept : vec_(vec1, vec2, vec3[0]), w_(static_cast<T>(vec3[1])) {}

template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1,                B sca2,                C sca3,                D sca4) noexcept : vec_(sca1, sca2, sca3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1,                B sca2,                C sca3,                D sca4) noexcept : vec_(vec1, sca2, sca3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1, Vec<1, B> const& vec2,                C sca3,                D sca4) noexcept : vec_(sca1, vec2, sca3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2,                C sca3,                D sca4) noexcept : vec_(vec1, vec2, sca3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1,                B sca2, Vec<1, C> const& vec3,                D sca4) noexcept : vec_(sca1, sca2, vec3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1,                B sca2, Vec<1, C> const& vec3,                D sca4) noexcept : vec_(vec1, sca2, vec3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1, Vec<1, B> const& vec2, Vec<1, C> const& vec3,                D sca4) noexcept : vec_(sca1, vec2, vec3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2, Vec<1, C> const& vec3,                D sca4) noexcept : vec_(vec1, vec2, vec3), w_(static_cast<T>(sca4))    {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1,                B sca2,                C sca3, Vec<1, D> const& vec4) noexcept : vec_(sca1, sca2, sca3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1,                B sca2,                C sca3, Vec<1, D> const& vec4) noexcept : vec_(vec1, sca2, sca3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1, Vec<1, B> const& vec2,                C sca3, Vec<1, D> const& vec4) noexcept : vec_(sca1, vec2, sca3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2,                C sca3, Vec<1, D> const& vec4) noexcept : vec_(vec1, vec2, sca3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1,                B sca2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept : vec_(sca1, sca2, vec3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1,                B sca2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept : vec_(vec1, sca2, vec3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(               A sca1, Vec<1, B> const& vec2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept : vec_(sca1, vec2, vec3), w_(static_cast<T>(vec4[0])) {}
template <typename T> template <typename A, typename B, typename C, typename D> constexpr Vec<L, T>::Vec(Vec<1, A> const& vec1, Vec<1, B> const& vec2, Vec<1, C> const& vec3, Vec<1, D> const& vec4) noexcept : vec_(vec1, vec2, vec3), w_(static_cast<T>(vec4[0])) {}

template <typename T> template <usize M, typename U> constexpr Vec<L, T>::Vec(Vec<M, U> const& vec) noexcept : vec_(vec), w_(static_cast<T>(vec[L - 1])) {}

// --- Unary arithmetic operators ---
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator=(Vec<L, U> const& vec) { this->vec_ = vec.vec_; this->w_ = static_cast<T>(vec.w_); return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator+=(U sca) { this->vec_ += static_cast<T>(sca); this->w_ += static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator-=(U sca) { this->vec_ -= static_cast<T>(sca); this->w_ -= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator*=(U sca) { this->vec_ *= static_cast<T>(sca); this->w_ *= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator/=(U sca) { this->vec_ /= static_cast<T>(sca); this->w_ /= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator%=(U sca) { this->vec_ %= static_cast<T>(sca); this->w_ %= static_cast<T>(sca); return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator+=(Vec<1, U> const& vec) { this->vec_ += static_cast<T>(vec[0]); this->w_ += static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator-=(Vec<1, U> const& vec) { this->vec_ -= static_cast<T>(vec[0]); this->w_ -= static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator*=(Vec<1, U> const& vec) { this->vec_ *= static_cast<T>(vec[0]); this->w_ *= static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator/=(Vec<1, U> const& vec) { this->vec_ /= static_cast<T>(vec[0]); this->w_ /= static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator%=(Vec<1, U> const& vec) { this->vec_ %= static_cast<T>(vec[0]); this->w_ %= static_cast<T>(vec[0]); return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator+=(Vec<L, U> const& vec) { this->vec_ += vec.vec_; this->w_ += static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator-=(Vec<L, U> const& vec) { this->vec_ -= vec.vec_; this->w_ -= static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator*=(Vec<L, U> const& vec) { this->vec_ *= vec.vec_; this->w_ *= static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator/=(Vec<L, U> const& vec) { this->vec_ /= vec.vec_; this->w_ /= static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator%=(Vec<L, U> const& vec) { this->vec_ %= vec.vec_; this->w_ %= static_cast<T>(vec.w_); return *this; }

template <typename T> constexpr Vec<L, T>& Vec<L, T>::operator++() { ++this->vec_; ++this->w_; return *this; }
template <typename T> constexpr Vec<L, T>& Vec<L, T>::operator--() { --this->vec_; --this->w_; return *this; }

template <typename T> constexpr Vec<L, T> Vec<L, T>::operator++(int) { Vec<L, T> result(*this); ++(*this); return result; }
template <typename T> constexpr Vec<L, T> Vec<L, T>::operator--(int) { Vec<L, T> result(*this); --(*this); return result; }

// --- Unary bit operators ---
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator&= (U sca) { this->vec_ &=  static_cast<T>(sca); this->w_ &=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator|= (U sca) { this->vec_ |=  static_cast<T>(sca); this->w_ |=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator^= (U sca) { this->vec_ ^=  static_cast<T>(sca); this->w_ ^=  static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator<<=(U sca) { this->vec_ <<= static_cast<T>(sca); this->w_ <<= static_cast<T>(sca); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator>>=(U sca) { this->vec_ >>= static_cast<T>(sca); this->w_ >>= static_cast<T>(sca); return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator&= (Vec<1, U> const& vec) { this->vec_ &=  static_cast<T>(vec[0]); this->w_ &=  static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator|= (Vec<1, U> const& vec) { this->vec_ |=  static_cast<T>(vec[0]); this->w_ |=  static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator^= (Vec<1, U> const& vec) { this->vec_ ^=  static_cast<T>(vec[0]); this->w_ ^=  static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator<<=(Vec<1, U> const& vec) { this->vec_ <<= static_cast<T>(vec[0]); this->w_ <<= static_cast<T>(vec[0]); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator>>=(Vec<1, U> const& vec) { this->vec_ >>= static_cast<T>(vec[0]); this->w_ >>= static_cast<T>(vec[0]); return *this; }

template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator&= (Vec<L, U> const& vec) { this->vec_ &=  vec.vec_; this->w_ &=  static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator|= (Vec<L, U> const& vec) { this->vec_ |=  vec.vec_; this->w_ |=  static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator^= (Vec<L, U> const& vec) { this->vec_ ^=  vec.vec_; this->w_ ^=  static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator<<=(Vec<L, U> const& vec) { this->vec_ <<= vec.vec_; this->w_ <<= static_cast<T>(vec.w_); return *this; }
template <typename T> template <typename U> constexpr Vec<L, T>& Vec<L, T>::operator>>=(Vec<L, U> const& vec) { this->vec_ >>= vec.vec_; this->w_ >>= static_cast<T>(vec.w_); return *this; }

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec) { return vec; }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec) { return Vec<L, T>(-Vec<L - 1, T>(vec), -vec[L - 1]); }

// --- Binary atithmetic operators ---
template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) + sca, vec[L - 1] + sca); }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) - sca, vec[L - 1] - sca); }
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) * sca, vec[L - 1] * sca); }
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) / sca, vec[L - 1] / sca); }
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) % sca, vec[L - 1] % sca); }

template <typename T> constexpr Vec<L, T> operator+(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca + Vec<L - 1, T>(vec), sca + vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator-(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca - Vec<L - 1, T>(vec), sca - vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator*(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca * Vec<L - 1, T>(vec), sca * vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator/(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca / Vec<L - 1, T>(vec), sca / vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator%(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca % Vec<L - 1, T>(vec), sca % vec[L - 1]); }

template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) + vec2[0], vec1[L - 1] + vec2[0]); }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) - vec2[0], vec1[L - 1] - vec2[0]); }
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) * vec2[0], vec1[L - 1] * vec2[0]); }
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) / vec2[0], vec1[L - 1] / vec2[0]); }
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) % vec2[0], vec1[L - 1] % vec2[0]); }

template <typename T> constexpr Vec<L, T> operator+(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] + Vec<L - 1, T>(vec2), vec1[0] + vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator-(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] - Vec<L - 1, T>(vec2), vec1[0] - vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator*(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] * Vec<L - 1, T>(vec2), vec1[0] * vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator/(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] / Vec<L - 1, T>(vec2), vec1[0] / vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator%(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] % Vec<L - 1, T>(vec2), vec1[0] % vec2[L - 1]); }

template <typename T> constexpr Vec<L, T> operator+(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) + Vec<L - 1, T>(vec2), vec1[L - 1] + vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator-(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) - Vec<L - 1, T>(vec2), vec1[L - 1] - vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator*(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) * Vec<L - 1, T>(vec2), vec1[L - 1] * vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator/(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) / Vec<L - 1, T>(vec2), vec1[L - 1] / vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator%(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) % Vec<L - 1, T>(vec2), vec1[L - 1] % vec2[L - 1]); }

// --- Unary bit operators ---
template <typename T> constexpr Vec<L, T> operator~(Vec<L, T> const& vec) { return Vec<L, T>(~Vec<L - 1, T>(vec), ~vec[L - 1]); }

// --- Binary bit operators ---
template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) &  sca, vec[L - 1] &  sca); }
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) |  sca, vec[L - 1] |  sca); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) ^  sca, vec[L - 1] ^  sca); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) << sca, vec[L - 1] << sca); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec, T sca) { return Vec<L, T>(Vec<L - 1, T>(vec) >> sca, vec[L - 1] >> sca); }

template <typename T> constexpr Vec<L, T> operator& (T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca &  Vec<L - 1, T>(vec), sca &  vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator| (T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca |  Vec<L - 1, T>(vec), sca |  vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator^ (T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca ^  Vec<L - 1, T>(vec), sca ^  vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator<<(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca << Vec<L - 1, T>(vec), sca << vec[L - 1]); }
template <typename T> constexpr Vec<L, T> operator>>(T sca, Vec<L, T> const& vec) { return Vec<L, T>(sca >> Vec<L - 1, T>(vec), sca >> vec[L - 1]); }

template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) &  vec2[0], vec1[L - 1] &  vec2[0]); }
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) |  vec2[0], vec1[L - 1] |  vec2[0]); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) ^  vec2[0], vec1[L - 1] ^  vec2[0]); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) << vec2[0], vec1[L - 1] << vec2[0]); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec1, Vec<1, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) >> vec2[0], vec1[L - 1] >> vec2[0]); }

template <typename T> constexpr Vec<L, T> operator& (Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] &  Vec<L - 1, T>(vec2), vec1[0] &  vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator| (Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] |  Vec<L - 1, T>(vec2), vec1[0] |  vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] ^  Vec<L - 1, T>(vec2), vec1[0] ^  vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] << Vec<L - 1, T>(vec2), vec1[0] << vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<1, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(vec1[0] >> Vec<L - 1, T>(vec2), vec1[0] >> vec2[L - 1]); }

template <typename T> constexpr Vec<L, T> operator& (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) &  Vec<L - 1, T>(vec2), vec1[L - 1] &  vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator| (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) |  Vec<L - 1, T>(vec2), vec1[L - 1] |  vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator^ (Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) ^  Vec<L - 1, T>(vec2), vec1[L - 1] ^  vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator<<(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) << Vec<L - 1, T>(vec2), vec1[L - 1] << vec2[L - 1]); }
template <typename T> constexpr Vec<L, T> operator>>(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L, T>(Vec<L - 1, T>(vec1) >> Vec<L - 1, T>(vec2), vec1[L - 1] >> vec2[L - 1]); }

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return Vec<L - 1, T>(vec1) == Vec<L - 1, T>(vec2) && vec1[L - 1] == vec2[L - 1]; }
template <typename T> constexpr bool operator!=(Vec<L, T> const& vec1, Vec<L, T> const& vec2) { return !(vec1 == vec2); }

constexpr Vec<L, bool> operator&&(Vec<L, bool> const& vec1, Vec<L, bool> const& vec2) { return Vec<L, bool>(Vec<L - 1, bool>(vec1) && Vec<L - 1, bool>(vec2), vec1[L - 1] && vec2[L - 1]); }
constexpr Vec<L, bool> operator||(Vec<L, bool> const& vec1, Vec<L, bool> const& vec2) { return Vec<L, bool>(Vec<L - 1, bool>(vec1) || Vec<L - 1, bool>(vec2), vec1[L - 1] || vec2[L - 1]); }

}  // namespace tf

#undef L

#endif  // TRANSFORM_VEC_VEC4_H_
