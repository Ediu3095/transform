#include <transform/vec/vec4.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec4) {
  Vec4<i32> constexpr kVec0{ };
  Vec4<i32> constexpr kVec1(1,  2,    4,       8);
  Vec4<i32> constexpr kVec2(2,  4,    8,      16);
  Vec4<i32> constexpr kVec3(3,  6,   12,      24);
  Vec4<i32> constexpr kVec6(6, 24,   96,     384);
  Vec4<i32> constexpr kVec8(8, 64, 2048, 1048576);

  Vec4<i32> vecn(2, 4);

  EXPECT_EQ(vecn[0], 2);
  EXPECT_EQ(vecn[1], 4);
  EXPECT_EQ(vecn[2], 0);
  EXPECT_EQ(vecn[3], 0);

  vecn.set_x(kVec1[0]);
  vecn.set_y(kVec1[1]);
  vecn.set_z(kVec1[2]);
  vecn.set_w(kVec1[3]);

  EXPECT_EQ(vecn.x(), 1);
  EXPECT_EQ(vecn.y(), 2);
  EXPECT_EQ(vecn.z(), 4);
  EXPECT_EQ(vecn.w(), 8);

  EXPECT_EQ(vecn.x(), vecn.r());
  EXPECT_EQ(vecn.y(), vecn.g());
  EXPECT_EQ(vecn.z(), vecn.b());
  EXPECT_EQ(vecn.w(), vecn.a());

  EXPECT_EQ(vecn.x(), vecn.s());
  EXPECT_EQ(vecn.y(), vecn.t());
  EXPECT_EQ(vecn.z(), vecn.p());
  EXPECT_EQ(vecn.w(), vecn.q());

  EXPECT_FLOAT_EQ(Vec4<f32>(vecn).x(), 1.0F);
  EXPECT_FLOAT_EQ(Vec4<f32>(vecn).y(), 2.0F);
  EXPECT_FLOAT_EQ(Vec4<f32>(vecn).z(), 4.0F);
  EXPECT_FLOAT_EQ(Vec4<f32>(vecn).w(), 8.0F);

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
  EXPECT_EQ(vecn  |= 2, (kVec1 & 2) | 2);
  EXPECT_EQ(vecn  ^= 2, kVec0);

  EXPECT_EQ(vecn = kVec1, kVec1);
  EXPECT_EQ(vecn <<= Vec1<i32>(2), kVec1 << 2);
  EXPECT_EQ(vecn >>= Vec1<i32>(2), kVec1);
  EXPECT_EQ(vecn  &= Vec1<i32>(2), kVec1 & 2);
  EXPECT_EQ(vecn  |= Vec1<i32>(2), (kVec1 & 2) | 2);
  EXPECT_EQ(vecn  ^= Vec1<i32>(2), kVec0);

  EXPECT_EQ(vecn = kVec1, kVec1);
  EXPECT_EQ(vecn  &= kVec2, kVec0);
  EXPECT_EQ(vecn  |= kVec2, kVec2);
  EXPECT_EQ(vecn <<= kVec2, kVec8);
  EXPECT_EQ(vecn >>= kVec2, kVec2);
  EXPECT_EQ(vecn  ^= kVec2, kVec0);

  EXPECT_EQ(+kVec2, Vec4<i32>(+kVec2.x(), +kVec2.y(), +kVec2.z(), +kVec2.w()));
  EXPECT_EQ(-kVec2, Vec4<i32>(-kVec2.x(), -kVec2.y(), -kVec2.z(), -kVec2.w()));

  EXPECT_EQ(kVec2 + 1, Vec4<i32>(kVec2.x() + 1, kVec2.y() + 1, kVec2.z() + 1, kVec2.w() + 1));
  EXPECT_EQ(kVec2 - 1, Vec4<i32>(kVec2.x() - 1, kVec2.y() - 1, kVec2.z() - 1, kVec2.w() - 1));
  EXPECT_EQ(kVec2 * 1, Vec4<i32>(kVec2.x() * 1, kVec2.y() * 1, kVec2.z() * 1, kVec2.w() * 1));
  EXPECT_EQ(kVec2 / 1, Vec4<i32>(kVec2.x() / 1, kVec2.y() / 1, kVec2.z() / 1, kVec2.w() / 1));
  EXPECT_EQ(kVec2 % 1, Vec4<i32>(kVec2.x() % 1, kVec2.y() % 1, kVec2.z() % 1, kVec2.w() % 1));

  EXPECT_EQ(1 + kVec2, Vec4<i32>(1 + kVec2.x(), 1 + kVec2.y(), 1 + kVec2.z(), 1 + kVec2.w()));
  EXPECT_EQ(1 - kVec2, Vec4<i32>(1 - kVec2.x(), 1 - kVec2.y(), 1 - kVec2.z(), 1 - kVec2.w()));
  EXPECT_EQ(1 * kVec2, Vec4<i32>(1 * kVec2.x(), 1 * kVec2.y(), 1 * kVec2.z(), 1 * kVec2.w()));
  EXPECT_EQ(1 / kVec2, Vec4<i32>(1 / kVec2.x(), 1 / kVec2.y(), 1 / kVec2.z(), 1 / kVec2.w()));
  EXPECT_EQ(1 % kVec2, Vec4<i32>(1 % kVec2.x(), 1 % kVec2.y(), 1 % kVec2.z(), 1 % kVec2.w()));

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

  EXPECT_EQ(~kVec2, Vec4<i32>(~kVec2.x(), ~kVec2.y(), ~kVec2.z(), ~kVec2.w()));

  EXPECT_EQ(kVec2 &  1, Vec4<i32>(kVec2.x() &  1, kVec2.y() &  1, kVec2.z() &  1, kVec2.w() &  1));
  EXPECT_EQ(kVec2 |  1, Vec4<i32>(kVec2.x() |  1, kVec2.y() |  1, kVec2.z() |  1, kVec2.w() |  1));
  EXPECT_EQ(kVec2 ^  1, Vec4<i32>(kVec2.x() ^  1, kVec2.y() ^  1, kVec2.z() ^  1, kVec2.w() ^  1));
  EXPECT_EQ(kVec2 << 1, Vec4<i32>(kVec2.x() << 1, kVec2.y() << 1, kVec2.z() << 1, kVec2.w() << 1));
  EXPECT_EQ(kVec2 >> 1, Vec4<i32>(kVec2.x() >> 1, kVec2.y() >> 1, kVec2.z() >> 1, kVec2.w() >> 1));

  EXPECT_EQ(1 &  kVec2, Vec4<i32>(1 &  kVec2.x(), 1 &  kVec2.y(), 1 &  kVec2.z(), 1 &  kVec2.w()));
  EXPECT_EQ(1 |  kVec2, Vec4<i32>(1 |  kVec2.x(), 1 |  kVec2.y(), 1 |  kVec2.z(), 1 |  kVec2.w()));
  EXPECT_EQ(1 ^  kVec2, Vec4<i32>(1 ^  kVec2.x(), 1 ^  kVec2.y(), 1 ^  kVec2.z(), 1 ^  kVec2.w()));
  EXPECT_EQ(1 << kVec2, Vec4<i32>(1 << kVec2.x(), 1 << kVec2.y(), 1 << kVec2.z(), 1 << kVec2.w()));
  EXPECT_EQ(1 >> kVec2, Vec4<i32>(1 >> kVec2.x(), 1 >> kVec2.y(), 1 >> kVec2.z(), 1 >> kVec2.w()));

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

  EXPECT_EQ(kVec1, Vec4<i32>(kVec1));
  EXPECT_NE(kVec1, kVec2);

  Vec4<bool> constexpr kVecffff(false, false, false, false);
  Vec4<bool> constexpr kVecftft(false,  true, false,  true);
  Vec4<bool> constexpr kVectftf( true, false,  true, false);
  Vec4<bool> constexpr kVectttt( true,  true,  true,  true);

  EXPECT_EQ(kVecftft && kVecffff, kVecffff);
  EXPECT_EQ(kVecftft && kVectttt, kVecftft);
  EXPECT_EQ(kVectftf && kVecffff, kVecffff);
  EXPECT_EQ(kVectftf && kVectttt, kVectftf);
  EXPECT_EQ(kVecftft || kVecffff, kVecftft);
  EXPECT_EQ(kVecftft || kVectttt, kVectttt);
  EXPECT_EQ(kVectftf || kVecffff, kVectftf);
  EXPECT_EQ(kVectftf || kVectttt, kVectttt);
}

}  // namespace tf::test
