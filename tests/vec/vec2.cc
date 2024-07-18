#include <transform/vec/vec2.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec2) {
  Vec2<i32> constexpr kVec0{ };
  Vec2<i32> constexpr kVec1(1,  2);
  Vec2<i32> constexpr kVec2(2,  4);
  Vec2<i32> constexpr kVec3(3,  6);
  Vec2<i32> constexpr kVec6(6, 24);
  Vec2<i32> constexpr kVec8(8, 64);

  Vec2<i32> vecn(kVec1.tail());

  EXPECT_EQ(vecn[0], 2);
  EXPECT_EQ(vecn[1], 0);

  vecn.set_x(kVec1[0]);
  vecn.set_y(kVec1[1]);

  EXPECT_EQ(vecn.x(), 1);
  EXPECT_EQ(vecn.y(), 2);

  EXPECT_EQ(vecn.x(), vecn.r());
  EXPECT_EQ(vecn.y(), vecn.g());

  EXPECT_EQ(vecn.x(), vecn.s());
  EXPECT_EQ(vecn.y(), vecn.t());

  EXPECT_FLOAT_EQ(Vec2<f32>(kVec1).x(), 1.0F);
  EXPECT_FLOAT_EQ(Vec2<f32>(kVec1).y(), 2.0F);

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

  EXPECT_EQ(+kVec2, Vec2<i32>(+kVec2.x(), +kVec2.y()));
  EXPECT_EQ(-kVec2, Vec2<i32>(-kVec2.x(), -kVec2.y()));

  EXPECT_EQ(kVec2 + 1, Vec2<i32>(kVec2.x() + 1, kVec2.y() + 1));
  EXPECT_EQ(kVec2 - 1, Vec2<i32>(kVec2.x() - 1, kVec2.y() - 1));
  EXPECT_EQ(kVec2 * 1, Vec2<i32>(kVec2.x() * 1, kVec2.y() * 1));
  EXPECT_EQ(kVec2 / 1, Vec2<i32>(kVec2.x() / 1, kVec2.y() / 1));
  EXPECT_EQ(kVec2 % 1, Vec2<i32>(kVec2.x() % 1, kVec2.y() % 1));

  EXPECT_EQ(1 + kVec2, Vec2<i32>(1 + kVec2.x(), 1 + kVec2.y()));
  EXPECT_EQ(1 - kVec2, Vec2<i32>(1 - kVec2.x(), 1 - kVec2.y()));
  EXPECT_EQ(1 * kVec2, Vec2<i32>(1 * kVec2.x(), 1 * kVec2.y()));
  EXPECT_EQ(1 / kVec2, Vec2<i32>(1 / kVec2.x(), 1 / kVec2.y()));
  EXPECT_EQ(1 % kVec2, Vec2<i32>(1 % kVec2.x(), 1 % kVec2.y()));

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

  EXPECT_EQ(~kVec2, Vec2<i32>(~kVec2.x(), ~kVec2.y()));

  EXPECT_EQ(kVec2 &  1, Vec2<i32>(kVec2.x() &  1, kVec2.y() &  1));
  EXPECT_EQ(kVec2 |  1, Vec2<i32>(kVec2.x() |  1, kVec2.y() |  1));
  EXPECT_EQ(kVec2 ^  1, Vec2<i32>(kVec2.x() ^  1, kVec2.y() ^  1));
  EXPECT_EQ(kVec2 << 1, Vec2<i32>(kVec2.x() << 1, kVec2.y() << 1));
  EXPECT_EQ(kVec2 >> 1, Vec2<i32>(kVec2.x() >> 1, kVec2.y() >> 1));

  EXPECT_EQ(1 &  kVec2, Vec2<i32>(1 &  kVec2.x(), 1 &  kVec2.y()));
  EXPECT_EQ(1 |  kVec2, Vec2<i32>(1 |  kVec2.x(), 1 |  kVec2.y()));
  EXPECT_EQ(1 ^  kVec2, Vec2<i32>(1 ^  kVec2.x(), 1 ^  kVec2.y()));
  EXPECT_EQ(1 << kVec2, Vec2<i32>(1 << kVec2.x(), 1 << kVec2.y()));
  EXPECT_EQ(1 >> kVec2, Vec2<i32>(1 >> kVec2.x(), 1 >> kVec2.y()));

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

  EXPECT_EQ(kVec1, Vec2<i32>(kVec1));
  EXPECT_NE(kVec1, kVec2);

  Vec2<bool> constexpr kVectf(true, false);
  Vec2<bool> constexpr kVecft(false, true);
  Vec2<bool> constexpr kVectt(true, true);
  Vec2<bool> constexpr kVecff(false, false);

  EXPECT_EQ(kVectf && kVectf, kVectf);
  EXPECT_EQ(kVectf && kVecft, kVecff);
  EXPECT_EQ(kVecft || kVectf, kVectt);
  EXPECT_EQ(kVecft || kVecft, kVecft);
}

}  // namespace tf::test
