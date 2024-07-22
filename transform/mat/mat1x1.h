#ifndef TRANSFORM_MAT_MAT1X1_H_
#define TRANSFORM_MAT_MAT1X1_H_

#include <cassert>

#include "transform/types.h"
#include "transform/mat/mat.h"
#include "transform/vec/vec1.h"

#define C 1
#define R 1

namespace tf {

template <typename T> class Mat<C, R, T> {
 public:
  // --- Types ---
  using ColType       = Vec<R, T>;
  using RowType       = Vec<C, T>;
  using Type          = Mat<C, R, T>;
  using TransposeType = Mat<R, C, T>;
  using ValueType     = T;
  using LengthType    = usize;

 private:
  // --- Data ---
  Vec<R, T> head_;

 public:
  // --- Component access ---
  static constexpr LengthType Length() noexcept { return 1; }

  constexpr Vec<R, T> &      operator[](LengthType idx)       noexcept;
  constexpr Vec<R, T> const& operator[](LengthType idx) const noexcept;

  constexpr Vec<R, T> const& head () const noexcept;  // NOLINT(*-identifier-naming)
  constexpr Vec<C, T> const& headr() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_head (Vec<R, T> const& head) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_headr(Vec<C, T> const& head) noexcept;  // NOLINT(*-identifier-naming)

  // --- Implicit basic constructors ---
  constexpr Mat() noexcept;
  constexpr Mat(Mat const& mat);
  constexpr Mat(Mat&& mat) noexcept = default;

  // --- Explicit basic constructors ---
  constexpr explicit Mat(T sca) noexcept;

  // --- Conversion constructors ---
  template <typename A> explicit constexpr Mat(A sca) noexcept;
  template <typename A> explicit constexpr Mat(Vec<1, A> const& vec) noexcept;

  template <usize N, usize M, typename A> explicit constexpr Mat(Mat<N, M, A> const& mat) noexcept;

  // --- Destructor ---
  inline ~Mat() noexcept = default;

  // --- Unary operators ---
  constexpr Mat<C, R, T>& operator=(Mat const& vec)     = default;
  constexpr Mat<C, R, T>& operator=(Mat&& vec) noexcept = default;
  template <typename U> constexpr Mat<C, R, T>& operator=(Mat<1, 1, U> const& mat);

  template <typename U> constexpr Mat<C, R, T>& operator+=(U sca);
  template <typename U> constexpr Mat<C, R, T>& operator-=(U sca);
  template <typename U> constexpr Mat<C, R, T>& operator*=(U sca);

  template <typename U> constexpr Mat<C, R, T>& operator+=(Mat<1, 1, U> const& mat);
  template <typename U> constexpr Mat<C, R, T>& operator-=(Mat<1, 1, U> const& mat);
  template <typename U> constexpr Mat<C, R, T>& operator*=(Mat<1, 1, U> const& mat);

  constexpr Mat<C, R, T>& operator++();
  constexpr Mat<C, R, T>& operator--();

  constexpr Mat<C, R, T> operator++(int);
  constexpr Mat<C, R, T> operator--(int);
};

// --- Unary operators ---
template <typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat);
template <typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat);

// --- Binary operators ---
template <typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, T sca2);
template <typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, T sca2);
template <typename T> constexpr Mat<C, R, T> operator*(Mat<C, R, T> const& mat1, T sca2);

template <typename T> constexpr Mat<C, R, T> operator+(T sca1, Mat<C, R, T> const& mat2);
template <typename T> constexpr Mat<C, R, T> operator-(T sca1, Mat<C, R, T> const& mat2);
template <typename T> constexpr Mat<C, R, T> operator*(T sca1, Mat<C, R, T> const& mat2);

template <typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);
template <typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);
template <typename T> constexpr Mat<C, R, T> operator*(Mat<C, R, T> const& mat1, Mat<C, C, T> const& mat2);
template <typename T> constexpr Vec<   R, T> operator*(Mat<C, R, T> const& mat1, Vec<C,    T> const& vec2);
template <typename T> constexpr Vec<C,    T> operator*(Vec<   R, T> const& vec1, Mat<C, R, T> const& mat2);

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);
template <typename T> constexpr bool operator!=(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);

// --- Alias ---
template <typename T> using Mat1 = Mat<C, R, T>;

/************************
 * Function definitions *
 ************************/

template <typename T> constexpr Vec<R, T> &      Mat<C, R, T>::operator[](LengthType idx)       noexcept { assert(idx < this->Length()); return this->head_; }
template <typename T> constexpr Vec<R, T> const& Mat<C, R, T>::operator[](LengthType idx) const noexcept { assert(idx < this->Length()); return this->head_; }

template <typename T> constexpr Vec<R, T> const& Mat<C, R, T>::head () const noexcept { return this->head_; }  // NOLINT(*-identifier-naming)
template <typename T> constexpr Vec<C, T> const& Mat<C, R, T>::headr() const noexcept { return this->head_; }  // NOLINT(*-identifier-naming)

template <typename T> constexpr void Mat<C, R, T>::set_head (Vec<R, T> const& head) noexcept { this->head_ = head; }  // NOLINT(*-identifier-naming)
template <typename T> constexpr void Mat<C, R, T>::set_headr(Vec<C, T> const& head) noexcept { this->head_ = head; }  // NOLINT(*-identifier-naming)

template <typename T> constexpr Mat<C, R, T>::Mat() noexcept : head_() {}
template <typename T> constexpr Mat<C, R, T>::Mat(Mat const& mat) : head_(mat.head_) {}

// --- Explicit basic constructors ---
template <typename T> constexpr Mat<C, R, T>::Mat(T sca) noexcept : head_(sca) {}

// --- Conversion constructors ---
template <typename T> template <typename A> constexpr Mat<C, R, T>::Mat(A sca) noexcept : head_(static_cast<T>(sca)) {}
template <typename T> template <typename A> constexpr Mat<C, R, T>::Mat(Vec<1, A> const& vec) noexcept : head_(static_cast<T>(vec.head())) {}

template <typename T> template <usize N, usize M, typename A> constexpr Mat<C, R, T>::Mat(Mat<N, M, A> const& mat) noexcept : head_(mat.head()) {}

// --- Unary operators ---
template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator=(Mat<1, 1, U> const& mat) { this->head_ = mat.head(); return *this; };

template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator+=(U sca) { this->head_ += sca; return *this; }
template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator-=(U sca) { this->head_ -= sca; return *this; }
template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator*=(U sca) { this->head_ *= sca; return *this; }

template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator+=(Mat<1, 1, U> const& mat) { this->head_ += mat.head(); return *this; }
template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator-=(Mat<1, 1, U> const& mat) { this->head_ -= mat.head(); return *this; }
template <typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator*=(Mat<1, 1, U> const& mat) { this->head_ *= mat.head(); return *this; }

template <typename T> constexpr Mat<C, R, T>& Mat<C, R, T>::operator++() { ++this->head_; return *this; }
template <typename T> constexpr Mat<C, R, T>& Mat<C, R, T>::operator--() { --this->head_; return *this; }

template <typename T> constexpr Mat<C, R, T> Mat<C, R, T>::operator++(int) { Mat<C, R, T> result(*this); ++(*this); return result; }
template <typename T> constexpr Mat<C, R, T> Mat<C, R, T>::operator--(int) { Mat<C, R, T> result(*this); --(*this); return result; }

// --- Unary operators ---
template <typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat) { return mat; }
template <typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat) { return Mat<C, R, T>(-mat.head()); }

// --- Binary operators ---
template <typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, T sca2) { return Mat<C, R, T>(mat1.head() + sca2); }
template <typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, T sca2) { return Mat<C, R, T>(mat1.head() - sca2); }
template <typename T> constexpr Mat<C, R, T> operator*(Mat<C, R, T> const& mat1, T sca2) { return Mat<C, R, T>(mat1.head() * sca2); }

template <typename T> constexpr Mat<C, R, T> operator+(T sca1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(sca1 + mat2.head()); }
template <typename T> constexpr Mat<C, R, T> operator-(T sca1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(sca1 - mat2.head()); }
template <typename T> constexpr Mat<C, R, T> operator*(T sca1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(sca1 * mat2.head()); }

template <typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(mat1.head() + mat2.head()); }
template <typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(mat1.head() - mat2.head()); }
template <typename T> constexpr Mat<C, R, T> operator*(Mat<C, R, T> const& mat1, Mat<C, C, T> const& mat2) { return Mat<C, R, T>(mat1.head() * mat2.head()); }
template <typename T> constexpr Vec<   R, T> operator*(Mat<C, R, T> const& mat1, Vec<C,    T> const& vec2) { return Vec<   R, T>(mat1.head() * vec2       ); }
template <typename T> constexpr Vec<C,    T> operator*(Vec<   R, T> const& vec1, Mat<C, R, T> const& mat2) { return Vec<C,    T>(vec1        * mat2.head()); }

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return mat1.head() == mat2.head(); }
template <typename T> constexpr bool operator!=(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return !(mat1 == mat2); }

}  // namespace tf

#undef R
#undef C

#endif  // TRANSFORM_MAT_MAT1X1_H_
