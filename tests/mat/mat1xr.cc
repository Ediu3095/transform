#include <transform/mat/mat1xr.h>

#include <gtest/gtest.h>
#include <transform/mat/matcxr.h>
#include <transform/vec/vecn.h>

namespace tf::test {

template <typename T> using Mat3x1 = Mat<1, 3, T>;

TEST(MatTest, Mat1xR) {
  // Mat1<i32> constexpr kMat0{ };
  Mat1  <i32> constexpr kMatX(2);
  Mat3  <i32> constexpr kMatY(2, 0, 0, 0, 2, 0, 0, 0, 2);
  Mat3x1<i32> constexpr kMat1(1,  2,  4);
  Mat3x1<i32> constexpr kMat2(2,  4,  8);
  Mat3x1<i32> constexpr kMat3(3,  6, 12);
  Mat3x1<i32> constexpr kMat4(4, 20, 88);
  Mat3x1<i32> constexpr kMat6(6, 24, 96);

  Vec1<i32> constexpr kVecA(2);
  Vec1<i32> constexpr kVecB(126);
  
  Mat3x1<i32> matn{};

  matn.set_head(kMat1.head());
  EXPECT_EQ(matn.head(), kMat1.head());

  // matn.set_tail(kMat2.tail());
  // EXPECT_EQ(matn.tail(), kMat2.tail());

  matn.set_headr(kMat3.headr());
  EXPECT_EQ(matn.headr(), kMat3.headr());

  matn.set_tailr(kMat4.tailr());
  EXPECT_EQ(matn.tailr(), kMat4.tailr());

  EXPECT_FLOAT_EQ(Mat3x1<f32>(kMat1)[0][1], 2.0F);

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += 2, kMat1 + 2);
  EXPECT_EQ(matn -= 2, kMat1);
  EXPECT_EQ(matn *= 2, kMat1 * 2);

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += kMat2, kMat3);
  EXPECT_EQ(matn -= kMat2, kMat1);
  EXPECT_EQ(matn *= kMatX, kMat2);

  EXPECT_EQ(+kMat2, Mat3x1<i32>(+kMat2.head()));
  EXPECT_EQ(-kMat2, Mat3x1<i32>(-kMat2.head()));

  EXPECT_EQ(kMat1 + 2, Mat3x1<i32>(kMat1.head() + 2));
  EXPECT_EQ(kMat1 - 2, Mat3x1<i32>(kMat1.head() - 2));
  EXPECT_EQ(kMat1 * 2, Mat3x1<i32>(kMat1.head() * 2));

  EXPECT_EQ(kMat1 + kMat2, kMat3);
  EXPECT_EQ(kMat6 - kMat2, kMat4);

  EXPECT_EQ(kMatY * kMat1, kMat2);
  EXPECT_EQ(kMat1 * kVecA, kMat2.head());
  EXPECT_EQ(kMat3.head() * kMat2, kVecB);
}

}  // namespace tf::test
