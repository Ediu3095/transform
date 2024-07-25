#include <transform/mat/func.h>
#include <transform/mat/matcxr.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(MatTest, Func) {
  Mat1<i32> constexpr kIdentity1 = Mat1<i32>::Identity();
  Mat2<i32> constexpr kIdentity2 = Mat2<i32>::Identity();
  Mat3<i32> constexpr kIdentity3 = Mat3<i32>::Identity();
  Mat4<i32> constexpr kIdentity4 = Mat4<i32>::Identity();

  Mat3<f32> constexpr kIdentityA = Mat3<f32>::Identity() * 2.0F;
  Mat3<f32> constexpr kIdentityB = Mat3<f32>::Identity() * 3.0F;

  Mat3<i32> constexpr kMatA(1, 2, 3, 4, 5, 6, 7, 8, 9);
  Mat3<i32> constexpr kMatB(1, 4, 7, 2, 5, 8, 3, 6, 9);

  EXPECT_EQ(CutDown(kIdentity2, 0, 0), kIdentity1);
  EXPECT_NE(CutDown(kIdentity2, 0, 1), kIdentity1);
  EXPECT_NE(CutDown(kIdentity2, 1, 0), kIdentity1);
  EXPECT_EQ(CutDown(kIdentity2, 1, 1), kIdentity1);
  EXPECT_EQ(CutDown(kIdentity4, 2, 2), kIdentity3);

  EXPECT_EQ(Minor(kIdentity4, 0, 0), 1);
  EXPECT_EQ(Minor(kIdentity4, 1, 0), 0);
  EXPECT_EQ(Minor(kIdentity2 + 1, 0, 0), 2);
  EXPECT_EQ(Minor(kIdentity2 + 1, 1, 0), 1);

  EXPECT_EQ(Cofactor(kIdentity2 + 1, 0, 0),  2);
  EXPECT_EQ(Cofactor(kIdentity2 + 1, 1, 0), -1);

  EXPECT_EQ(Determinant(kIdentity1), 1);
  EXPECT_EQ(Determinant(kIdentity2), 1);
  EXPECT_EQ(Determinant(kIdentity3), 1);
  EXPECT_EQ(Determinant(kIdentity4), 1);
  EXPECT_EQ(Determinant(kIdentityA), 8);
  EXPECT_EQ(Determinant(kIdentityB), 27);
  EXPECT_EQ(Determinant(kIdentityA * kIdentityB),  8 * 27);

  EXPECT_EQ(CofactorMatrix(kIdentity2), kIdentity2);
  EXPECT_EQ(CofactorMatrix(kIdentity3), kIdentity3);
  EXPECT_EQ(CofactorMatrix(kIdentity4), kIdentity4);

  EXPECT_EQ(Transpose(kMatA), kMatB);
  EXPECT_EQ(Transpose(kMatB), kMatA);

  EXPECT_EQ(Inverse(kIdentityA) * kIdentityA, Mat3<f32>(kIdentity3));
  EXPECT_EQ(kIdentityA * Inverse(kIdentityA), Mat3<f32>(kIdentity3));
}

}  // namespace tf::test
