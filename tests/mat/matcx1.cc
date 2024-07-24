#include <transform/mat/matcx1.h>

#include <gtest/gtest.h>
#include <transform/mat/matcxr.h>
#include <transform/vec/vecn.h>

namespace tf::test {

template <typename T> using Mat3x1 = Mat<3, 1, T>;
template <typename T> using Mat1x3 = Mat<1, 3, T>;

TEST(MatTest, MatCx1) {
  // Mat1<i32> constexpr kMat0{ };
  Mat3  <i32> constexpr kMatX(2, 0, 0, 0, 2, 0, 0, 0, 2);
  Mat1x3<i32> constexpr kMaty(1, 1, 1);
  Mat3  <i32> constexpr kMatY(1, 1, 1, 2, 2, 2, 4, 4, 4);
  Mat3x1<i32> constexpr kMat1(1,  2,  4);
  Mat3x1<i32> constexpr kMat2(2,  4,  8);
  Mat3x1<i32> constexpr kMat3(3,  6, 12);
  Mat3x1<i32> constexpr kMat4(4, 20, 88);
  Mat3x1<i32> constexpr kMat6(6, 24, 96);

  Vec1<i32> constexpr kVecA(42);
  Vec1<i32> constexpr kVecB(2);

  Mat3x1<i32> matn{};

  matn.set_head(kMat1.head());
  EXPECT_EQ(matn.head(), kMat1.head());

  matn.set_tail(kMat2.tail());
  EXPECT_EQ(matn.tail(), kMat2.tail());

  matn.set_headr(kMat3.headr());
  EXPECT_EQ(matn.headr(), kMat3.headr());

  // matn.set_tailr(kMat4.tailr());
  // EXPECT_EQ(matn.tailr(), kMat4.tailr());
  EXPECT_FLOAT_EQ(Mat3x1<f32>(kMat1)[1][0], 2.0F);

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += 2, kMat1 + 2);
  EXPECT_EQ(matn -= 2, kMat1);
  EXPECT_EQ(matn *= 2, kMat1 * 2);

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += kMat2, kMat3);
  EXPECT_EQ(matn -= kMat2, kMat1);
  EXPECT_EQ(matn *= kMatX, kMat2);

  EXPECT_EQ(+kMat2, Mat3x1<i32>(+kMat2.head(), +kMat2.tail()));
  EXPECT_EQ(-kMat2, Mat3x1<i32>(-kMat2.head(), -kMat2.tail()));

  EXPECT_EQ(kMat1 + 2, Mat3x1<i32>(kMat1.head() + 2, kMat1.tail() + 2));
  EXPECT_EQ(kMat1 - 2, Mat3x1<i32>(kMat1.head() - 2, kMat1.tail() - 2));
  EXPECT_EQ(kMat1 * 2, Mat3x1<i32>(kMat1.head() * 2, kMat1.tail() * 2));

  EXPECT_EQ(kMat1 + kMat2, kMat3);
  EXPECT_EQ(kMat6 - kMat2, kMat4);

  EXPECT_EQ(kMaty * kMat1, kMatY);
  EXPECT_EQ(kMat1 * kMat2.headr(), kVecA);
  EXPECT_EQ(kVecB * kMat1, kMat2.headr());
}

}  // namespace tf::test
