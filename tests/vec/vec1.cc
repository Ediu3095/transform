#include <transform/vec/vec1.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec1) {
  Vec1<i32> constexpr kVec0(0);
  Vec1<i32> constexpr kVec1(1);
  Vec1<i32> constexpr kVec2(2);
  Vec1<i32> constexpr kVec3(3);
  Vec1<i32> constexpr kVec6(6);
  Vec1<i32> constexpr kVec8(8);

  Vec1<i32> vecn(kVec1);

  EXPECT_EQ(Vec1<i32>(vecn).x(), 1);

  EXPECT_FLOAT_EQ(Vec1<f32>(vecn).x(), 1.0F);

  EXPECT_EQ(vecn += 2, kVec3);
  EXPECT_EQ(vecn *= 2, kVec6);
  EXPECT_EQ(vecn /= 2, kVec3);
  EXPECT_EQ(vecn %= 2, kVec1);
  EXPECT_EQ(vecn -= 2, -kVec1);
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

  EXPECT_EQ(vecn  &= 2, kVec0);
  EXPECT_EQ(vecn  |= 2, kVec2);
  EXPECT_EQ(vecn <<= 2, kVec8);
  EXPECT_EQ(vecn >>= 2, kVec2);
  EXPECT_EQ(vecn  ^= 2, kVec0);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(vecn  &= kVec2, kVec0);
  EXPECT_EQ(vecn  |= kVec2, kVec2);
  EXPECT_EQ(vecn <<= kVec2, kVec8);
  EXPECT_EQ(vecn >>= kVec2, kVec2);
  EXPECT_EQ(vecn  ^= kVec2, kVec0);
  EXPECT_EQ(vecn = kVec1, kVec1);

  EXPECT_EQ(+vecn, Vec1<i32>(+vecn.x()));
  EXPECT_EQ(-vecn, Vec1<i32>(-vecn.x()));

  EXPECT_EQ(vecn + 1, Vec1<i32>(vecn.x() + 1));
  EXPECT_EQ(vecn - 1, Vec1<i32>(vecn.x() - 1));
  EXPECT_EQ(vecn * 1, Vec1<i32>(vecn.x() * 1));
  EXPECT_EQ(vecn / 1, Vec1<i32>(vecn.x() / 1));
  EXPECT_EQ(vecn % 1, Vec1<i32>(vecn.x() % 1));

  EXPECT_EQ(1 + vecn, Vec1<i32>(1 + vecn.x()));
  EXPECT_EQ(1 - vecn, Vec1<i32>(1 - vecn.x()));
  EXPECT_EQ(1 * vecn, Vec1<i32>(1 * vecn.x()));
  EXPECT_EQ(1 / vecn, Vec1<i32>(1 / vecn.x()));
  EXPECT_EQ(1 % vecn, Vec1<i32>(1 % vecn.x()));

  EXPECT_EQ(kVec1 + kVec2, kVec3);
  EXPECT_EQ(kVec3 * kVec2, kVec6);
  EXPECT_EQ(kVec6 / kVec2, kVec3);
  EXPECT_EQ(kVec3 % kVec2, kVec1);
  EXPECT_EQ(kVec1 - kVec2, -kVec1);

  EXPECT_EQ(~kVec2, Vec1<i32>(~kVec2.x()));

  EXPECT_EQ(kVec2 &  1, Vec1<i32>(kVec2.x() &  1));
  EXPECT_EQ(kVec2 |  1, Vec1<i32>(kVec2.x() |  1));
  EXPECT_EQ(kVec2 ^  1, Vec1<i32>(kVec2.x() ^  1));
  EXPECT_EQ(kVec2 << 1, Vec1<i32>(kVec2.x() << 1));
  EXPECT_EQ(kVec2 >> 1, Vec1<i32>(kVec2.x() >> 1));

  EXPECT_EQ(1 &  kVec2, Vec1<i32>(1 &  kVec2.x()));
  EXPECT_EQ(1 |  kVec2, Vec1<i32>(1 |  kVec2.x()));
  EXPECT_EQ(1 ^  kVec2, Vec1<i32>(1 ^  kVec2.x()));
  EXPECT_EQ(1 << kVec2, Vec1<i32>(1 << kVec2.x()));
  EXPECT_EQ(1 >> kVec2, Vec1<i32>(1 >> kVec2.x()));

  EXPECT_EQ(kVec1 &  kVec2, kVec0);
  EXPECT_EQ(kVec0 |  kVec2, kVec2);
  EXPECT_EQ(kVec2 << kVec2, kVec8);
  EXPECT_EQ(kVec8 >> kVec2, kVec2);
  EXPECT_EQ(kVec2 ^  kVec2, kVec0);

  EXPECT_EQ(kVec1, Vec1<i32>(kVec1));
  EXPECT_NE(kVec1, kVec2);

  Vec1<bool> constexpr kVect(true);
  Vec1<bool> constexpr kVecf(false);

  EXPECT_TRUE ((kVect && kVect).x());
  EXPECT_FALSE((kVect && kVecf).x());
  EXPECT_TRUE ((kVecf || kVect).x());
  EXPECT_FALSE((kVecf || kVecf).x());
}

}  // namespace tf::test
