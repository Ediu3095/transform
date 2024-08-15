#include <transform/mat/func.h>
#include <transform/mat/matcxr.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(MatTest, Func) {
  Mat1<i32> constexpr kIdentity1 = Mat1<i32>::identity();
  Mat2<i32> constexpr kIdentity2 = Mat2<i32>::identity();
  Mat3<i32> constexpr kIdentity3 = Mat3<i32>::identity();
  Mat4<i32> constexpr kIdentity4 = Mat4<i32>::identity();

  Mat3<f32> constexpr kIdentityA = Mat3<f32>::identity() * 2.0F;
  Mat3<f32> constexpr kIdentityB = Mat3<f32>::identity() * 3.0F;

  Mat3<i32> constexpr kMatA(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Mat3<i32> constexpr kMatB(1, 4, 7, 2, 5, 8, 3, 6, 9);

  EXPECT_EQ(cutDown(kIdentity2, 0, 0), kIdentity1);
  EXPECT_NE(cutDown(kIdentity2, 0, 1), kIdentity1);
  EXPECT_NE(cutDown(kIdentity2, 1, 0), kIdentity1);
  EXPECT_EQ(cutDown(kIdentity2, 1, 1), kIdentity1);
  EXPECT_EQ(cutDown(kIdentity4, 2, 2), kIdentity3);

  EXPECT_EQ(minor(kIdentity4, 0, 0), 1);
  EXPECT_EQ(minor(kIdentity4, 1, 0), 0);
  EXPECT_EQ(minor(kIdentity2 + 1, 0, 0), 2);
  EXPECT_EQ(minor(kIdentity2 + 1, 1, 0), 1);

  EXPECT_EQ(cofactor(kIdentity2 + 1, 0, 0),  2);
  EXPECT_EQ(cofactor(kIdentity2 + 1, 1, 0), -1);

  EXPECT_EQ(determinant(kIdentity1), 1);
  EXPECT_EQ(determinant(kIdentity2), 1);
  EXPECT_EQ(determinant(kIdentity3), 1);
  EXPECT_EQ(determinant(kIdentity4), 1);
  EXPECT_EQ(determinant(kIdentityA), 8);
  EXPECT_EQ(determinant(kIdentityB), 27);
  EXPECT_EQ(determinant(kIdentityA * kIdentityB),  8 * 27);

  EXPECT_EQ(cofactorMatrix(kIdentity2), kIdentity2);
  EXPECT_EQ(cofactorMatrix(kIdentity3), kIdentity3);
  EXPECT_EQ(cofactorMatrix(kIdentity4), kIdentity4);

  EXPECT_EQ(transpose(kMatA), kMatB);
  EXPECT_EQ(transpose(kMatB), kMatA);

  EXPECT_EQ(inverse(kIdentityA) * kIdentityA, Mat3<f32>(kIdentity3));
  EXPECT_EQ(kIdentityA * inverse(kIdentityA), Mat3<f32>(kIdentity3));
}

}  // namespace tf::test
