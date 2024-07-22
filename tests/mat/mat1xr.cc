#include <transform/mat/mat1xr.h>

#include <gtest/gtest.h>
#include <transform/vec/vecn.h>

#define C 1
#define R 3

namespace tf::test {

template <typename T> using Mat1xR = Mat<C, R, T>;

TEST(MatTest, Mat1xR) {
  // Mat1<i32> constexpr kMat0{ };
  Mat1xR<i32> constexpr kMat1(1,  2,    4);
  Mat1  <i32> constexpr kMatX(2);
  Mat1xR<i32> constexpr kMat2(2,  4,    8);
  Mat1xR<i32> constexpr kMat3(3,  6,   12);
  Mat1xR<i32> constexpr kMat4(4, 20, 2040);
  Mat1xR<i32> constexpr kMat6(6, 24, 2048);

  Vec<C, i32> constexpr kVecA(2);
  Vec<C, i32> constexpr kVecB(2078);
  // Vec<R, i32> constexpr kVec2(2);
  // Vec<R, i32> constexpr kVec4(4);

  Mat1xR<i32> matn{};

  matn.set_head(kMat1.head());
  EXPECT_EQ(matn[0][0], 1);

  // EXPECT_FLOAT_EQ(Mat1<f32>(kMat1)[0][0], 1.0F);

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += 2, kMat1 + 2);
  EXPECT_EQ(matn -= 2, kMat1);
  EXPECT_EQ(matn *= 2, kMat1 * 2);

  EXPECT_EQ(matn = kMat1, kMat1);
  EXPECT_EQ(matn += kMat2, kMat3);
  EXPECT_EQ(matn -= kMat2, kMat1);
  EXPECT_EQ(matn *= kMatX, kMat2);

  EXPECT_EQ(+kMat2, Mat1xR<i32>(+kMat2.head()));
  EXPECT_EQ(-kMat2, Mat1xR<i32>(-kMat2.head()));

  EXPECT_EQ(kMat1 + 2, Mat1xR<i32>(kMat1.head() + 2));
  EXPECT_EQ(kMat3 * 2, Mat1xR<i32>(kMat1.head() * 2));
  EXPECT_EQ(kMat6 - 2, Mat1xR<i32>(kMat1.head() - 2));


  EXPECT_EQ(kMat1 + kMat2, kMat3);
  EXPECT_EQ(kMat6 - kMat2, kMat4);
  EXPECT_EQ(kMat1 * kMatX, kMat2);
  EXPECT_EQ(kMat1 * kVecA, kMat2.head());
  EXPECT_EQ(kMat3.head() * kMat1, kVecB);
}

}  // namespace tf::test
