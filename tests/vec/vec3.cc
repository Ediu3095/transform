#include <transform/vec/vec3.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec3) {
  Vec3<i32> constexpr kVec0{ };
  Vec3<i32> constexpr kVec1(1,  2,    4);
  Vec3<i32> constexpr kVec2(2,  4,    8);
  Vec3<i32> constexpr kVec3(3,  6,   12);
  Vec3<i32> constexpr kVec6(6, 24,   96);
  Vec3<i32> constexpr kVec8(8, 64, 2048);

  Vec3<i32> vecn(kVec1.tail());

  EXPECT_EQ(vecn[0], 2);
  EXPECT_EQ(vecn[1], 4);
  EXPECT_EQ(vecn[2], 0);

  vecn.set_x(kVec1[0]);
  vecn.set_y(kVec1[1]);
  vecn.set_z(kVec1[2]);

  EXPECT_EQ(kVec1.x(), 1);
  EXPECT_EQ(kVec1.y(), 2);
  EXPECT_EQ(kVec1.z(), 4);

  EXPECT_EQ(kVec1.x(), kVec1.r());
  EXPECT_EQ(kVec1.y(), kVec1.g());
  EXPECT_EQ(kVec1.z(), kVec1.b());

  EXPECT_EQ(kVec1.x(), kVec1.s());
  EXPECT_EQ(kVec1.y(), kVec1.t());
  EXPECT_EQ(kVec1.z(), kVec1.p());

  EXPECT_FLOAT_EQ(Vec3<f32>(kVec1).x(), 1.0F);
  EXPECT_FLOAT_EQ(Vec3<f32>(kVec1).y(), 2.0F);
  EXPECT_FLOAT_EQ(Vec3<f32>(kVec1).z(), 4.0F);

  EXPECT_EQ(vecn = kVec1, kVec1);
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

  EXPECT_EQ(vecn = kVec1, kVec1);
  EXPECT_EQ(vecn <<= 2, kVec1 << 2);
  EXPECT_EQ(vecn >>= 2, kVec1);
  EXPECT_EQ(vecn  &= 2, kVec1 & 2);
  EXPECT_EQ(vecn  |= 2, kVec1 & 2 | 2);
  EXPECT_EQ(vecn  ^= 2, kVec0);

  EXPECT_EQ(vecn = kVec1, kVec1);
  EXPECT_EQ(vecn <<= Vec1<i32>(2), kVec1 << 2);
  EXPECT_EQ(vecn >>= Vec1<i32>(2), kVec1);
  EXPECT_EQ(vecn  &= Vec1<i32>(2), kVec1 & 2);
  EXPECT_EQ(vecn  |= Vec1<i32>(2), kVec1 & 2 | 2);
  EXPECT_EQ(vecn  ^= Vec1<i32>(2), kVec0);

  EXPECT_EQ(vecn = kVec1, kVec1);
  EXPECT_EQ(vecn  &= kVec2, kVec0);
  EXPECT_EQ(vecn  |= kVec2, kVec2);
  EXPECT_EQ(vecn <<= kVec2, kVec8);
  EXPECT_EQ(vecn >>= kVec2, kVec2);
  EXPECT_EQ(vecn  ^= kVec2, kVec0);

  EXPECT_EQ(+kVec2, Vec3<i32>(+kVec2.x(), +kVec2.y(), +kVec2.z()));
  EXPECT_EQ(-kVec2, Vec3<i32>(-kVec2.x(), -kVec2.y(), -kVec2.z()));

  EXPECT_EQ(kVec2 + 1, Vec3<i32>(kVec2.x() + 1, kVec2.y() + 1, kVec2.z() + 1));
  EXPECT_EQ(kVec2 - 1, Vec3<i32>(kVec2.x() - 1, kVec2.y() - 1, kVec2.z() - 1));
  EXPECT_EQ(kVec2 * 1, Vec3<i32>(kVec2.x() * 1, kVec2.y() * 1, kVec2.z() * 1));
  EXPECT_EQ(kVec2 / 1, Vec3<i32>(kVec2.x() / 1, kVec2.y() / 1, kVec2.z() / 1));
  EXPECT_EQ(kVec2 % 1, Vec3<i32>(kVec2.x() % 1, kVec2.y() % 1, kVec2.z() % 1));

  EXPECT_EQ(1 + kVec2, Vec3<i32>(1 + kVec2.x(), 1 + kVec2.y(), 1 + kVec2.z()));
  EXPECT_EQ(1 - kVec2, Vec3<i32>(1 - kVec2.x(), 1 - kVec2.y(), 1 - kVec2.z()));
  EXPECT_EQ(1 * kVec2, Vec3<i32>(1 * kVec2.x(), 1 * kVec2.y(), 1 * kVec2.z()));
  EXPECT_EQ(1 / kVec2, Vec3<i32>(1 / kVec2.x(), 1 / kVec2.y(), 1 / kVec2.z()));
  EXPECT_EQ(1 % kVec2, Vec3<i32>(1 % kVec2.x(), 1 % kVec2.y(), 1 % kVec2.z()));

  EXPECT_EQ(kVec2 + Vec1<i32>(1), kVec2 + 1);
  EXPECT_EQ(kVec2 - Vec1<i32>(1), kVec2 - 1);
  EXPECT_EQ(kVec2 * Vec1<i32>(1), kVec2 * 1);
  EXPECT_EQ(kVec2 / Vec1<i32>(1), kVec2 / 1);
  EXPECT_EQ(kVec2 % Vec1<i32>(1), kVec2 % 1);

  EXPECT_EQ(Vec1<i32>(1) + kVec2, 1 + kVec2);
  EXPECT_EQ(Vec1<i32>(1) - kVec2, 1 - kVec2);
  EXPECT_EQ(Vec1<i32>(1) * kVec2, 1 * kVec2);
  EXPECT_EQ(Vec1<i32>(1) / kVec2, 1 / kVec2);
  EXPECT_EQ(Vec1<i32>(1) % kVec2, 1 % kVec2);

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
