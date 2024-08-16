#ifndef TRANSFORM_MAT_MAT1XR_H_
#define TRANSFORM_MAT_MAT1XR_H_

#include "transform/mat/mat1x1.h"

#define C 1

namespace tf {

template <usize R, typename T> class Mat<C, R, T> {
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
  static constexpr LengthType length() noexcept { return C; }

  constexpr Vec<R, T> &      operator[](LengthType idx)       noexcept;
  constexpr Vec<R, T> const& operator[](LengthType idx) const noexcept;

  [[nodiscard]] constexpr Vec<R, T> const& head() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_head(Vec<R, T> const& head) noexcept;  // NOLINT(*-identifier-naming)

  [[nodiscard]] constexpr Vec<C,        T> headr() const noexcept;  // NOLINT(*-identifier-naming)
  [[nodiscard]] constexpr Mat<C, R - 1, T> tailr() const noexcept;  // NOLINT(*-identifier-naming)

  constexpr void set_headr(Vec<C,        T> const& head) noexcept;  // NOLINT(*-identifier-naming)
  constexpr void set_tailr(Mat<C, R - 1, T> const& tail) noexcept;  // NOLINT(*-identifier-naming)

  // --- Implicit basic constructors ---
  constexpr Mat() noexcept;
  constexpr Mat(Mat const& mat);
  constexpr Mat(Mat&& mat) noexcept = default;

  // --- Explicit basic constructors ---
  constexpr explicit Mat(T sca) noexcept;

  // --- Conversion constructors ---
  template <typename U> explicit constexpr Mat(U sca) noexcept;
  template <typename U, typename... V> explicit constexpr Mat(Vec<R, U> const& head, V /* unused */...) noexcept;

  template                   <usize L, typename U, typename V, typename... W> requires (L < R) explicit constexpr Mat(Vec<L, U> const& head,           V         tail1, W... tail2) noexcept;
  template                   <usize L, typename U, typename V, typename... W> requires (L < R) explicit constexpr Mat(Vec<L, U> const& head,    Vec<1, V> const& tail1, W... tail2) noexcept;
  template          <usize M, usize L, typename U, typename V, typename... W> requires (L < R) explicit constexpr Mat(Vec<L, U> const& head,    Vec<M, V> const& tail1, W... tail2) noexcept;
  template          <usize M, usize L, typename U, typename V, typename... W> requires (L < R) explicit constexpr Mat(Vec<L, U> const& head, Mat<1, M, V> const& tail1, W... tail2) noexcept;
  template <usize N, usize M, usize L, typename U, typename V, typename... W> requires (L < R) explicit constexpr Mat(Vec<L, U> const& head, Mat<N, M, V> const& tail1, W... tail2) noexcept;

  template                   <typename U, typename... V>                  explicit constexpr Mat(          U         head, V... tail) noexcept;
  template          <usize M, typename U, typename... V> requires (M > R) explicit constexpr Mat(   Vec<M, U> const& head, V... tail) noexcept;
  template          <usize M, typename U, typename... V>                  explicit constexpr Mat(Mat<1, M, U> const& head, V... tail) noexcept;
  template <usize N, usize M, typename U, typename... V>                  explicit constexpr Mat(Mat<N, M, U> const& head, V... tail) noexcept;

  // template <usize N, usize M, typename A> explicit constexpr Mat(Mat<N, M, A> const& mat) noexcept;

  // --- Destructor ---
  inline ~Mat() noexcept = default;

  // --- Factory ---
  template <usize N, usize M, typename U> static constexpr Mat<C, R, T> embed(Mat<N, M, U> mat) noexcept { return Mat<C, R, T>(Vec<R, T>(mat.head())); }

  // --- Unary operators ---
  constexpr Mat<C, R, T>& operator=(Mat const& vec)     = default;
  constexpr Mat<C, R, T>& operator=(Mat&& vec) noexcept = default;
  template <typename U> constexpr Mat<C, R, T>& operator=(Mat<C, R, U> const& mat);

  template <typename U> constexpr Mat<C, R, T>& operator+=(U sca);
  template <typename U> constexpr Mat<C, R, T>& operator-=(U sca);
  template <typename U> constexpr Mat<C, R, T>& operator*=(U sca);

  template <typename U> constexpr Mat<C, R, T>& operator+=(Mat<C, R, U> const& mat);
  template <typename U> constexpr Mat<C, R, T>& operator-=(Mat<C, R, U> const& mat);
  template <typename U> constexpr Mat<C, R, T>& operator*=(Mat<C, C, U> const& mat);

  constexpr Mat<C, R, T>& operator++();
  constexpr Mat<C, R, T>& operator--();

  constexpr Mat<C, R, T> operator++(int);
  constexpr Mat<C, R, T> operator--(int);
};

// --- Unary operators ---
template <usize R, typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat);
template <usize R, typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat);

// --- Binary operators ---
template <usize R, typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, T sca2);
template <usize R, typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, T sca2);
template <usize R, typename T> constexpr Mat<C, R, T> operator*(Mat<C, R, T> const& mat1, T sca2);

template <usize R, typename T> constexpr Mat<C, R, T> operator+(T sca1, Mat<C, R, T> const& mat2);
template <usize R, typename T> constexpr Mat<C, R, T> operator-(T sca1, Mat<C, R, T> const& mat2);
template <usize R, typename T> constexpr Mat<C, R, T> operator*(T sca1, Mat<C, R, T> const& mat2);

template <usize R, typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);
template <usize R, typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);

template <usize N, usize R, typename T> constexpr Mat<C, N, T> operator*(Mat<R, N, T> const& mat1, Mat<C, R, T> const& mat2);
template          <usize R, typename T> constexpr Vec<   R, T> operator*(Mat<C, R, T> const& mat1, Vec<C,    T> const& vec2);
template          <usize R, typename T> constexpr Vec<C,    T> operator*(Vec<   R, T> const& vec1, Mat<C, R, T> const& mat2);

// --- Boolean operators ---
template <usize R, typename T> constexpr bool operator==(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);
template <usize R, typename T> constexpr bool operator!=(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2);

/************************
 * Function definitions *
 ************************/

// --- Component access ---
template <usize R, typename T> constexpr Vec<R, T> &      Mat<C, R, T>::operator[]([[maybe_unused]] LengthType idx)       noexcept { assert(idx < this->length()); return this->head_; }
template <usize R, typename T> constexpr Vec<R, T> const& Mat<C, R, T>::operator[]([[maybe_unused]] LengthType idx) const noexcept { assert(idx < this->length()); return this->head_; }

template <usize R, typename T> constexpr Vec<R, T> const& Mat<C, R, T>::head() const noexcept { return this->head_; }  // NOLINT(*-identifier-naming)

template <usize R, typename T> constexpr void Mat<C, R, T>::set_head(Vec<R, T> const& head) noexcept { this->head_ = head; }  // NOLINT(*-identifier-naming)

template <usize R, typename T> constexpr Vec<C,        T> Mat<C, R, T>::headr() const noexcept { return Vec<C,        T>(this->head_.head()); }  // NOLINT(*-identifier-naming)
template <usize R, typename T> constexpr Mat<C, R - 1, T> Mat<C, R, T>::tailr() const noexcept { return Mat<C, R - 1, T>(this->head_.tail()); }  // NOLINT(*-identifier-naming)

template <usize R, typename T> constexpr void Mat<C, R, T>::set_headr(Vec<C,        T> const& head) noexcept { this->head_.set_head(head.head()); }  // NOLINT(*-identifier-naming)
template <usize R, typename T> constexpr void Mat<C, R, T>::set_tailr(Mat<C, R - 1, T> const& tail) noexcept { this->head_.set_tail(tail.head()); }  // NOLINT(*-identifier-naming)

// --- Implicit basic constructors ---
template <usize R, typename T> constexpr Mat<C, R, T>::Mat() noexcept : head_() {}
template <usize R, typename T> constexpr Mat<C, R, T>::Mat(Mat const& mat) : head_(mat.head_) {}

// --- Explicit basic constructors ---
template <usize R, typename T> constexpr Mat<C, R, T>::Mat(T sca) noexcept : head_(sca) {}

// --- Conversion constructors ---
template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>::Mat(U sca) noexcept : head_(static_cast<T>(sca)) {}
template <usize R, typename T> template <typename U, typename... V> constexpr Mat<C, R, T>::Mat(Vec<R, U> const& head, V /* unused */...) noexcept : head_(head) {}

template <usize R, typename T> template                   <usize L, typename U, typename V, typename... W> requires (L < R) constexpr Mat<C, R, T>::Mat(Vec<L, U> const& head,           V         tail1, W... tail2) noexcept : Mat(Vec<L + 1, U>(head , static_cast<U>(tail1       )),               tail2...) {}
template <usize R, typename T> template                   <usize L, typename U, typename V, typename... W> requires (L < R) constexpr Mat<C, R, T>::Mat(Vec<L, U> const& head,    Vec<1, V> const& tail1, W... tail2) noexcept : Mat(Vec<L + 1, U>(head , static_cast<U>(tail1.head())),               tail2...) {}
template <usize R, typename T> template          <usize M, usize L, typename U, typename V, typename... W> requires (L < R) constexpr Mat<C, R, T>::Mat(Vec<L, U> const& head,    Vec<M, V> const& tail1, W... tail2) noexcept : Mat(Vec<L + 1, U>(head , static_cast<U>(tail1.head())), tail1.tail(), tail2...) {}
template <usize R, typename T> template          <usize M, usize L, typename U, typename V, typename... W> requires (L < R) constexpr Mat<C, R, T>::Mat(Vec<L, U> const& head, Mat<1, M, V> const& tail1, W... tail2) noexcept : Mat(Vec<L + 1, U>(head),                tail1.head()  ,               tail2...) {}
template <usize R, typename T> template <usize N, usize M, usize L, typename U, typename V, typename... W> requires (L < R) constexpr Mat<C, R, T>::Mat(Vec<L, U> const& head, Mat<N, M, V> const& tail1, W... tail2) noexcept : Mat(Vec<L + 1, U>(head),                tail1.head()  , tail1.tail(), tail2...) {}

template <usize R, typename T> template                   <typename U, typename... V>                  constexpr Mat<C, R, T>::Mat(          U         head, V... tail) noexcept : Mat(Vec<1, U>(head       ),              tail...) {}
template <usize R, typename T> template          <usize M, typename U, typename... V> requires (M > R) constexpr Mat<C, R, T>::Mat(   Vec<M, U> const& head, V... tail) noexcept : Mat(Vec<1, U>(head.head()), head.tail(), tail...) {}
template <usize R, typename T> template          <usize M, typename U, typename... V>                  constexpr Mat<C, R, T>::Mat(Mat<1, M, U> const& head, V... tail) noexcept : Mat(          head.head() ,              tail...) {}
template <usize R, typename T> template <usize N, usize M, typename U, typename... V>                  constexpr Mat<C, R, T>::Mat(Mat<N, M, U> const& head, V... tail) noexcept : Mat(          head.head() , head.tail(), tail...) {}

// template <usize R, typename T> template <usize N, usize M, typename A> constexpr Mat<C, R, T>::Mat(Mat<N, M, A> const& mat) noexcept : head_(mat.head()) {}

// --- Unary operators ---
template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator=(Mat<C, R, U> const& mat) { this->head_ = mat.head(); return *this; };

template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator+=(U sca) { this->head_ += sca; return *this; }
template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator-=(U sca) { this->head_ -= sca; return *this; }
template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator*=(U sca) { this->head_ *= sca; return *this; }

template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator+=(Mat<C, R, U> const& mat) { this->head_ += mat.head(); return *this; }
template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator-=(Mat<C, R, U> const& mat) { this->head_ -= mat.head(); return *this; }
template <usize R, typename T> template <typename U> constexpr Mat<C, R, T>& Mat<C, R, T>::operator*=(Mat<C, C, U> const& mat) { return *this = *this * mat; }

template <usize R, typename T> constexpr Mat<C, R, T>& Mat<C, R, T>::operator++() { ++this->head_; return *this; }
template <usize R, typename T> constexpr Mat<C, R, T>& Mat<C, R, T>::operator--() { --this->head_; return *this; }

template <usize R, typename T> constexpr Mat<C, R, T> Mat<C, R, T>::operator++(int) { Mat<C, R, T> result(*this); ++(*this); return result; }
template <usize R, typename T> constexpr Mat<C, R, T> Mat<C, R, T>::operator--(int) { Mat<C, R, T> result(*this); --(*this); return result; }

// --- Unary operators ---
template <usize R, typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat) { return mat; }
template <usize R, typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat) { return Mat<C, R, T>(-mat.head()); }

// --- Binary operators ---
template <usize R, typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, T sca2) { return Mat<C, R, T>(mat1.head() + sca2); }
template <usize R, typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, T sca2) { return Mat<C, R, T>(mat1.head() - sca2); }
template <usize R, typename T> constexpr Mat<C, R, T> operator*(Mat<C, R, T> const& mat1, T sca2) { return Mat<C, R, T>(mat1.head() * sca2); }

template <usize R, typename T> constexpr Mat<C, R, T> operator+(T sca1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(sca1 + mat2.head()); }
template <usize R, typename T> constexpr Mat<C, R, T> operator-(T sca1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(sca1 - mat2.head()); }
template <usize R, typename T> constexpr Mat<C, R, T> operator*(T sca1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(sca1 * mat2.head()); }

template <usize R, typename T> constexpr Mat<C, R, T> operator+(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(mat1.head() + mat2.head()); }
template <usize R, typename T> constexpr Mat<C, R, T> operator-(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return Mat<C, R, T>(mat1.head() - mat2.head()); }

template <usize N, usize R, typename T> constexpr Mat<C, N, T> operator*(Mat<R, N, T> const& mat1, Mat<C, R, T> const& mat2) { return Mat<C, N, T>(   (mat1 * mat2.head())                     ); }
template          <usize R, typename T> constexpr Vec<   R, T> operator*(Mat<C, R, T> const& mat1, Vec<C,    T> const& vec2) { return Vec<   R, T>(dot(mat1.headr(), vec2), mat1.tailr() * vec2); }
template          <usize R, typename T> constexpr Vec<C,    T> operator*(Vec<   R, T> const& vec1, Mat<C, R, T> const& mat2) { return Vec<C,    T>(dot(vec1,  mat2.head())                     ); }

// --- Boolean operators ---
template <usize R, typename T> constexpr bool operator==(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return mat1.head() == mat2.head(); }
template <usize R, typename T> constexpr bool operator!=(Mat<C, R, T> const& mat1, Mat<C, R, T> const& mat2) { return !(mat1 == mat2); }

}  // namespace tf

#undef C

#endif  // TRANSFORM_MAT_MAT1XR_H_
