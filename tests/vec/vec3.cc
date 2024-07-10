#include <transform/vec/vec3.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec3) {
  Vec3<i32> constexpr kVec0(0,  0,    0);
  Vec3<i32> constexpr kVec1(1,  2,    4);
  Vec3<i32> constexpr kVec2(2,  4,    8);
  Vec3<i32> constexpr kVec3(3,  6,   12);
  Vec3<i32> constexpr kVec6(6, 24,   96);
  Vec3<i32> constexpr kVec8(8, 64, 2048);

  Vec3<i32> vecn(kVec1);

  EXPECT_EQ(Vec3<i32>(vecn).x(), 1);
  EXPECT_EQ(Vec3<i32>(vecn).y(), 2);
  EXPECT_EQ(Vec3<i32>(vecn).z(), 4);

  EXPECT_FLOAT_EQ(Vec3<f32>(vecn).x(), 1.0F);
  EXPECT_FLOAT_EQ(Vec3<f32>(vecn).y(), 2.0F);
  EXPECT_FLOAT_EQ(Vec3<f32>(vecn).z(), 4.0F);

  EXPECT_EQ(vecn += 2, kVec1 + 2);
  EXPECT_EQ(vecn -= 2, kVec1);
  EXPECT_EQ(vecn *= 2, kVec1 * 2);
  EXPECT_EQ(vecn /= 2, kVec1);
  EXPECT_EQ(vecn %= 2, kVec1 % 2);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(vecn += Vec1<i32>(2), kVec1 + 2);
  EXPECT_EQ(vecn -= Vec1<i32>(2), kVec1);
  EXPECT_EQ(vecn *= Vec1<i32>(2), kVec1 * 2);
  EXPECT_EQ(vecn /= Vec1<i32>(2), kVec1);
  EXPECT_EQ(vecn %= Vec1<i32>(2), kVec1 % 2);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(vecn += kVec2, kVec3);
  EXPECT_EQ(vecn *= kVec2, kVec6);
  EXPECT_EQ(vecn /= kVec2, kVec3);
  EXPECT_EQ(vecn %= kVec2, kVec1);
  EXPECT_EQ(vecn -= kVec2, -kVec1);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(++vecn, kVec1 + 1);
  EXPECT_EQ(vecn++, kVec1 + 1);
  EXPECT_EQ(--vecn, kVec1 + 1);
  EXPECT_EQ(vecn--, kVec1 + 1);

  EXPECT_EQ(vecn <<= 2, kVec1 << 2);
  EXPECT_EQ(vecn >>= 2, kVec1);
  EXPECT_EQ(vecn  &= 2, kVec1 & 2);
  EXPECT_EQ(vecn  |= 2, kVec1 & 2 | 2);
  EXPECT_EQ(vecn  ^= 2, kVec0);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(vecn  &= kVec2, kVec0);
  EXPECT_EQ(vecn  |= kVec2, kVec2);
  EXPECT_EQ(vecn <<= kVec2, kVec8);
  EXPECT_EQ(vecn >>= kVec2, kVec2);
  EXPECT_EQ(vecn  ^= kVec2, kVec0);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(+vecn, Vec3<i32>(+vecn.x(), +vecn.y(), +vecn.z()));
  EXPECT_EQ(-vecn, Vec3<i32>(-vecn.x(), -vecn.y(), -vecn.z()));

  EXPECT_EQ(vecn + 1, Vec3<i32>(vecn.x() + 1, vecn.y() + 1, vecn.z() + 1));
  EXPECT_EQ(vecn - 1, Vec3<i32>(vecn.x() - 1, vecn.y() - 1, vecn.z() - 1));
  EXPECT_EQ(vecn * 1, Vec3<i32>(vecn.x() * 1, vecn.y() * 1, vecn.z() * 1));
  EXPECT_EQ(vecn / 1, Vec3<i32>(vecn.x() / 1, vecn.y() / 1, vecn.z() / 1));
  EXPECT_EQ(vecn % 1, Vec3<i32>(vecn.x() % 1, vecn.y() % 1, vecn.z() % 1));

  EXPECT_EQ(1 + vecn, Vec3<i32>(1 + vecn.x(), 1 + vecn.y(), 1 + vecn.z()));
  EXPECT_EQ(1 - vecn, Vec3<i32>(1 - vecn.x(), 1 - vecn.y(), 1 - vecn.z()));
  EXPECT_EQ(1 * vecn, Vec3<i32>(1 * vecn.x(), 1 * vecn.y(), 1 * vecn.z()));
  EXPECT_EQ(1 / vecn, Vec3<i32>(1 / vecn.x(), 1 / vecn.y(), 1 / vecn.z()));
  EXPECT_EQ(1 % vecn, Vec3<i32>(1 % vecn.x(), 1 % vecn.y(), 1 % vecn.z()));

  EXPECT_EQ(vecn + Vec1<i32>(1), vecn + 1);
  EXPECT_EQ(vecn - Vec1<i32>(1), vecn - 1);
  EXPECT_EQ(vecn * Vec1<i32>(1), vecn * 1);
  EXPECT_EQ(vecn / Vec1<i32>(1), vecn / 1);
  EXPECT_EQ(vecn % Vec1<i32>(1), vecn % 1);

  EXPECT_EQ(Vec1<i32>(1) + vecn, 1 + vecn);
  EXPECT_EQ(Vec1<i32>(1) - vecn, 1 - vecn);
  EXPECT_EQ(Vec1<i32>(1) * vecn, 1 * vecn);
  EXPECT_EQ(Vec1<i32>(1) / vecn, 1 / vecn);
  EXPECT_EQ(Vec1<i32>(1) % vecn, 1 % vecn);

  EXPECT_EQ(kVec1 + kVec2, kVec3);
  EXPECT_EQ(kVec3 * kVec2, kVec6);
  EXPECT_EQ(kVec6 / kVec2, kVec3);
  EXPECT_EQ(kVec3 % kVec2, kVec1);
  EXPECT_EQ(kVec1 - kVec2, -kVec1);

  EXPECT_EQ(~kVec2, Vec3<i32>(~kVec2.x(), ~kVec2.y(), ~kVec2.z()));

  EXPECT_EQ(kVec2 &  1, Vec3<i32>(kVec2.x() &  1, kVec2.y() &  1, kVec2.z() &  1));
  EXPECT_EQ(kVec2 |  1, Vec3<i32>(kVec2.x() |  1, kVec2.y() |  1, kVec2.z() |  1));
  EXPECT_EQ(kVec2 ^  1, Vec3<i32>(kVec2.x() ^  1, kVec2.y() ^  1, kVec2.z() ^  1));
  EXPECT_EQ(kVec2 << 1, Vec3<i32>(kVec2.x() << 1, kVec2.y() << 1, kVec2.z() << 1));
  EXPECT_EQ(kVec2 >> 1, Vec3<i32>(kVec2.x() >> 1, kVec2.y() >> 1, kVec2.z() >> 1));

  EXPECT_EQ(1 &  kVec2, Vec3<i32>(1 &  kVec2.x(), 1 &  kVec2.y(), 1 &  kVec2.z()));
  EXPECT_EQ(1 |  kVec2, Vec3<i32>(1 |  kVec2.x(), 1 |  kVec2.y(), 1 |  kVec2.z()));
  EXPECT_EQ(1 ^  kVec2, Vec3<i32>(1 ^  kVec2.x(), 1 ^  kVec2.y(), 1 ^  kVec2.z()));
  EXPECT_EQ(1 << kVec2, Vec3<i32>(1 << kVec2.x(), 1 << kVec2.y(), 1 << kVec2.z()));
  EXPECT_EQ(1 >> kVec2, Vec3<i32>(1 >> kVec2.x(), 1 >> kVec2.y(), 1 >> kVec2.z()));

  EXPECT_EQ(kVec2 &  Vec1<i32>(1), kVec2 &  1);
  EXPECT_EQ(kVec2 |  Vec1<i32>(1), kVec2 |  1);
  EXPECT_EQ(kVec2 ^  Vec1<i32>(1), kVec2 ^  1);
  EXPECT_EQ(kVec2 << Vec1<i32>(1), kVec2 << 1);
  EXPECT_EQ(kVec2 >> Vec1<i32>(1), kVec2 >> 1);

  EXPECT_EQ(Vec1<i32>(1) &  kVec2, 1 &  kVec2);
  EXPECT_EQ(Vec1<i32>(1) |  kVec2, 1 |  kVec2);
  EXPECT_EQ(Vec1<i32>(1) ^  kVec2, 1 ^  kVec2);
  EXPECT_EQ(Vec1<i32>(1) << kVec2, 1 << kVec2);
  EXPECT_EQ(Vec1<i32>(1) >> kVec2, 1 >> kVec2);

  EXPECT_EQ(kVec1 &  kVec2, kVec0);
  EXPECT_EQ(kVec0 |  kVec2, kVec2);
  EXPECT_EQ(kVec2 << kVec2, kVec8);
  EXPECT_EQ(kVec8 >> kVec2, kVec2);
  EXPECT_EQ(kVec2 ^  kVec2, kVec0);

  EXPECT_EQ(kVec1, Vec3<i32>(kVec1));
  EXPECT_NE(kVec1, kVec2);

  Vec3<bool> constexpr kVecfff(false, false, false);
  Vec3<bool> constexpr kVecftf(false,  true, false);
  Vec3<bool> constexpr kVectft( true, false,  true);
  Vec3<bool> constexpr kVecttt( true,  true,  true);

  EXPECT_EQ(kVecftf && kVecfff, kVecfff);
  EXPECT_EQ(kVecftf && kVecttt, kVecftf);
  EXPECT_EQ(kVectft && kVecfff, kVecfff);
  EXPECT_EQ(kVectft && kVecttt, kVectft);
  EXPECT_EQ(kVecftf || kVecfff, kVecftf);
  EXPECT_EQ(kVecftf || kVecttt, kVecttt);
  EXPECT_EQ(kVectft || kVecfff, kVectft);
  EXPECT_EQ(kVectft || kVecttt, kVecttt);
}

}  // namespace tf::test
