#include <transform/mat/matcxr.h>

#include <gtest/gtest.h>
#include <transform/vec.h>

namespace tf::test {

template <typename T> using Mat1 = Mat<1, 1, T>;  // NOLINT(*-magic-numbers)
template <typename T> using Mat2 = Mat<2, 2, T>;  // NOLINT(*-magic-numbers)
template <typename T> using Mat3 = Mat<3, 3, T>;  // NOLINT(*-magic-numbers)
template <typename T> using Mat4 = Mat<4, 4, T>;  // NOLINT(*-magic-numbers)

TEST(MatTest, MatCxR) {
  // Mat1<i32> constexpr kMat0{ };
  Mat3<i32> constexpr kMat1 = Mat3<i32>::identity();
  Mat3<i32> constexpr kMat2( 2,  0,  0,  0,  2,  0,  0,  0,  2);
  Mat3<i32> constexpr kMat3( 1,  2,  3,  4,  5,  6,  7,  8,  9);
  Mat3<i32> constexpr kMat4( 2,  4,  6,  8, 10, 12, 14, 16, 18);

  Vec3<i32> constexpr kVecA(1, 0, 0);

  Mat4<i32> constexpr kMatA = Mat4<i32>::embed(kMat1);
  Mat4<i32> constexpr kMatB(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);

  Mat3<i32> matn{};

  matn.set_head(kMat1.head());
  EXPECT_EQ(matn.head(), kMat1.head());

  matn.set_tail(kMat2.tail());
  EXPECT_EQ(matn.tail(), kMat2.tail());

  matn.set_headr(kMat3.headr());
  EXPECT_EQ(matn.headr(), kMat3.headr());

  matn.set_tailr(kMat4.tailr());
  EXPECT_EQ(matn.tailr(), kMat4.tailr());

  EXPECT_FLOAT_EQ(Mat3<f32>(kMat1)[1][1], 1.0F);

  EXPECT_EQ(kMatA, kMatB);
  EXPECT_EQ(Mat2<i32>::embed(kMatA), Mat2<i32>::embed(kMat1));
  EXPECT_EQ(Mat1<i32>::embed(kMatA), Mat1<i32>::embed(kMat1));

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += 2, kMat1 + 2);
  EXPECT_EQ(matn -= 2, kMat1);
  EXPECT_EQ(matn *= 2, kMat2);

  EXPECT_EQ(matn = kMat3, kMat3);
  EXPECT_EQ(matn += kMat3, kMat4);
  EXPECT_EQ(matn -= kMat3, kMat3);
  EXPECT_EQ(matn *= kMat2, kMat4);

  EXPECT_EQ(+kMat2, Mat3<i32>(+kMat2.head(), +kMat2.tail()));
  EXPECT_EQ(-kMat2, Mat3<i32>(-kMat2.head(), -kMat2.tail()));

  EXPECT_EQ(kMat1 + 2, Mat3<i32>(kMat1.head() + 2, kMat1.tail() + 2));
  EXPECT_EQ(kMat1 - 2, Mat3<i32>(kMat1.head() - 2, kMat1.tail() - 2));
  EXPECT_EQ(kMat1 * 2, Mat3<i32>(kMat1.head() * 2, kMat1.tail() * 2));

  EXPECT_EQ(kMat1 + kMat2, kMat1 * 3);
  EXPECT_EQ(kMat4 - kMat3, kMat3);

  EXPECT_EQ(kMat3 * kMat1, kMat3);
  EXPECT_EQ(kMat3 * kMat2, kMat4);
  EXPECT_EQ(kMat3 * kVecA, kMat3.head());
  EXPECT_EQ(kVecA * kMat3, kMat3.headr());
}

}  // namespace tf::test
