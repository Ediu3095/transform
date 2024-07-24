#include <transform/mat/mat1x1.h>

#include <gtest/gtest.h>
#include <transform/vec/vec1.h>

namespace tf::test {

TEST(MatTest, Mat1x1) {
  // Mat1<i32> constexpr kMat0{ };
  Mat1<i32> constexpr kMat1(1);
  Mat1<i32> constexpr kMat2(2);
  Mat1<i32> constexpr kMat3(3);
  Mat1<i32> constexpr kMat4(4);
  Mat1<i32> constexpr kMat6(6);

  Vec1<i32> constexpr kVec2(2);
  Vec1<i32> constexpr kVec4(4);

  Mat1<i32> matn{};

  matn.set_head(kMat1.head());
  EXPECT_EQ(matn.head(), kMat1.head());

  // matn.set_tail(kMat2.tail());
  // EXPECT_EQ(matn.tail(), kMat2.tail());

  matn.set_headr(kMat3.headr());
  EXPECT_EQ(matn.headr(), kMat3.headr());

  // matn.set_tailr(kMat4.tailr());
  // EXPECT_EQ(matn.tailr(), kMat4.tailr());

  EXPECT_FLOAT_EQ(Mat1<f32>(kMat1)[0][0], 1.0F);

  EXPECT_EQ(matn =  kMat1, kMat1);
  EXPECT_EQ(matn += 2, kMat3);
  EXPECT_EQ(matn *= 2, kMat6);
  EXPECT_EQ(matn -= 2, kMat4);

  EXPECT_EQ(matn =  kMat1, kMat1);
  EXPECT_EQ(matn += kMat2, kMat3);
  EXPECT_EQ(matn *= kMat2, kMat6);
  EXPECT_EQ(matn -= kMat2, kMat4);

  EXPECT_EQ(+kMat2, Mat1<i32>(+kMat2.head()));
  EXPECT_EQ(-kMat2, Mat1<i32>(-kMat2.head()));

  EXPECT_EQ(kMat1 + 2, kMat3);
  EXPECT_EQ(kMat3 * 2, kMat6);
  EXPECT_EQ(kMat6 - 2, kMat4);

  EXPECT_EQ(kMat1 + kMat2, kMat3);
  EXPECT_EQ(kMat6 - kMat2, kMat4);

  EXPECT_EQ(kMat3 * kMat2, kMat6);
  EXPECT_EQ(kMat2 * kVec2, kVec4);
  EXPECT_EQ(kVec2 * kMat2, kVec4);
}

}  // namespace tf::test
