#include "transform/vec/vec.h"

namespace tf {

template <typename T> struct Vec<1, T> {
  // --- Types ---
  using ValueType  = T;
  using Type       = Vec<1, T>;
  using LengthType = tf::usize;

  // --- Data ---
  T x;

  // --- Component access ---
  static constexpr LengthType Length() noexcept { return 1; }
  constexpr T& operator[](LengthType index) noexcept;
  constexpr T const& operator[](LengthType index) const noexcept;

  // --- Implicit basic constructors ---
  constexpr Vec() noexcept          = default;
  constexpr Vec(Vec const& vec)     = default;
  constexpr Vec(Vec&& vec) noexcept = default;

  // --- Explicit basic constructors ---
  explicit constexpr Vec(T scalar) noexcept;

  template <typename U> explicit Vec(Vec<1, U> const& vec) noexcept;
  template <typename U> explicit Vec(Vec<2, U> const& vec) noexcept;
  template <typename U> explicit Vec(Vec<3, U> const& vec) noexcept;
  template <typename U> explicit Vec(Vec<4, U> const& vec) noexcept;

  // --- Destructor ---
  inline ~Vec() noexcept = default;


  // --- Unary arithmetic operators ---
  constexpr Vec<1, T>& operator=(Vec const& vec)     = default;
  constexpr Vec<1, T>& operator=(Vec&& vec) noexcept = default;

  template <typename U> constexpr Vec<1, T>& operator=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator+=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator+=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator-=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator-=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator*=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator*=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator/=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator/=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator%=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator%=(Vec<1, U> const& vec);

  constexpr Vec<1, T>& operator++();
  constexpr Vec<1, T>& operator--();
  constexpr Vec<1, T> operator++(int);
  constexpr Vec<1, T> operator--(int);

  // --- Unary bit operators ---
  template <typename U> constexpr Vec<1, T>& operator&=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator&=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator|=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator|=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator^=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator^=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator<<=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator<<=(Vec<1, U> const& vec);
  template <typename U> constexpr Vec<1, T>& operator>>=(U scalar);
  template <typename U> constexpr Vec<1, T>& operator>>=(Vec<1, U> const& vec);
};

// --- Unary arithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec);

// --- Binary atithmetic operators ---
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator+(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator+(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator-(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator-(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator*(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator*(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator/(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator/(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator%(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator%(Vec<1, T> const& vec1, Vec<1, T> const& vec2);

// --- Unary bit operators ---
template <typename T> constexpr Vec<1, T> operator~(Vec<1, T> const& vec);

// --- Binary bit operators ---
template <typename T> constexpr Vec<1, T> operator&(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator&(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator&(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator|(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator|(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator|(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator^(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator^(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator^(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator<<(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator<<(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec, T scalar);
template <typename T> constexpr Vec<1, T> operator>>(T scalar, Vec<1, T> const& vec);
template <typename T> constexpr Vec<1, T> operator>>(Vec<1, T> const& vec1, Vec<1, T> const& vec2);

// --- Boolean operators ---
template <typename T> constexpr bool operator==(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
template <typename T> constexpr bool operator!=(Vec<1, T> const& vec1, Vec<1, T> const& vec2);
constexpr Vec<1, bool> operator&&(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2);
constexpr Vec<1, bool> operator||(Vec<1, bool> const& vec1, Vec<1, bool> const& vec2);

// --- Alias ---
template <typename T> using Vec1 = Vec<1, T>;

}  // namespace tf
