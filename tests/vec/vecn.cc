#include <transform/vec/vecn.h>

#include <gtest/gtest.h>

namespace tf::test {

template <typename T> using Vec5 = Vec<5, T>;  // NOLINT(*-magic-numbers)
template <typename T> using Vec6 = Vec<6, T>;  // NOLINT(*-magic-numbers)

TEST(VecTest, VecN) {
  Vec6<i32> constexpr kVec0 { };
  Vec6<i32> constexpr kVec1 ( 1,  2,  4,   8,   16,   32);
  Vec6<i32> constexpr kVec2 ( 2,  4,  8,  16,   32,   64);
  Vec6<i32> constexpr kVec3 ( 3,  6, 12,  24,   48,   96);
  Vec6<i32> constexpr kVec4 = Vec6<i32>::Fill(4);
  Vec6<i32> constexpr kVec6 ( 6, 24, 96, 384, 1536, 6144);
  Vec6<i32> constexpr kVec16(16, 32, 64, 128,  256,  512);

  Vec6<i32> vecn(kVec1.tail());

  EXPECT_EQ(vecn[0],  2);
  EXPECT_EQ(vecn[1],  4);
  EXPECT_EQ(vecn[2],  8);
  EXPECT_EQ(vecn[3], 16);
  EXPECT_EQ(vecn[4], 32);
  EXPECT_EQ(vecn[5],  0);

  EXPECT_EQ(vecn = kVec1, kVec1);
  EXPECT_EQ(vecn.head(), 1);
  EXPECT_EQ(vecn.tail(), Vec5<i32>(2, 4, 8, 16, 32));

  EXPECT_EQ(Vec6<f32>(vecn), Vec6<f32>(1.0F, 2.0F, 4.0F, 8.0F, 16.0F, 32.0F));

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
  EXPECT_EQ(vecn  |= kVec1, kVec1);
  EXPECT_EQ(vecn <<= kVec4, kVec16);
  EXPECT_EQ(vecn >>= kVec4, kVec1);
  EXPECT_EQ(vecn  ^= kVec1, kVec0);

  EXPECT_EQ(+kVec2, Vec6<i32>(+kVec2.head(), +kVec2.tail()));
  EXPECT_EQ(-kVec2, Vec6<i32>(-kVec2.head(), -kVec2.tail()));

  EXPECT_EQ(kVec2 + 1, Vec6<i32>(kVec2.head() + 1, kVec2.tail() + 1));
  EXPECT_EQ(kVec2 - 1, Vec6<i32>(kVec2.head() - 1, kVec2.tail() - 1));
  EXPECT_EQ(kVec2 * 1, Vec6<i32>(kVec2.head() * 1, kVec2.tail() * 1));
  EXPECT_EQ(kVec2 / 1, Vec6<i32>(kVec2.head() / 1, kVec2.tail() / 1));
  EXPECT_EQ(kVec2 % 1, Vec6<i32>(kVec2.head() % 1, kVec2.tail() % 1));

  EXPECT_EQ(1 + kVec2, Vec6<i32>(1 + kVec2.head(), 1 + kVec2.tail()));
  EXPECT_EQ(1 - kVec2, Vec6<i32>(1 - kVec2.head(), 1 - kVec2.tail()));
  EXPECT_EQ(1 * kVec2, Vec6<i32>(1 * kVec2.head(), 1 * kVec2.tail()));
  EXPECT_EQ(1 / kVec2, Vec6<i32>(1 / kVec2.head(), 1 / kVec2.tail()));
  EXPECT_EQ(1 % kVec2, Vec6<i32>(1 % kVec2.head(), 1 % kVec2.tail()));

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

  EXPECT_EQ(~kVec2, Vec6<i32>(~kVec2.head(), ~kVec2.tail()));

  EXPECT_EQ(kVec2 &  1, Vec6<i32>(kVec2.head() &  1, kVec2.tail() &  1));
  EXPECT_EQ(kVec2 |  1, Vec6<i32>(kVec2.head() |  1, kVec2.tail() |  1));
  EXPECT_EQ(kVec2 ^  1, Vec6<i32>(kVec2.head() ^  1, kVec2.tail() ^  1));
  EXPECT_EQ(kVec2 << 1, Vec6<i32>(kVec2.head() << 1, kVec2.tail() << 1));
  EXPECT_EQ(kVec2 >> 1, Vec6<i32>(kVec2.head() >> 1, kVec2.tail() >> 1));

  EXPECT_EQ(1 &  kVec2, Vec6<i32>(1 &  kVec2.head(), 1 &  kVec2.tail()));
  EXPECT_EQ(1 |  kVec2, Vec6<i32>(1 |  kVec2.head(), 1 |  kVec2.tail()));
  EXPECT_EQ(1 ^  kVec2, Vec6<i32>(1 ^  kVec2.head(), 1 ^  kVec2.tail()));
  EXPECT_EQ(1 << kVec2, Vec6<i32>(1 << kVec2.head(), 1 << kVec2.tail()));
  EXPECT_EQ(1 >> kVec2, Vec6<i32>(1 >> kVec2.head(), 1 >> kVec2.tail()));

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

  EXPECT_EQ(kVec1  &  kVec2, kVec0);
  EXPECT_EQ(kVec0  |  kVec1, kVec1);
  EXPECT_EQ(kVec1  << kVec4, kVec16);
  EXPECT_EQ(kVec16 >> kVec4, kVec1);
  EXPECT_EQ(kVec1  ^  kVec1, kVec0);

  EXPECT_EQ(kVec1, Vec6<i32>(kVec1));
  EXPECT_NE(kVec1, kVec2);

  Vec6<bool> constexpr kVecffffff(false, false, false, false, false, false);
  Vec6<bool> constexpr kVecftftft(false,  true, false,  true, false,  true);
  Vec6<bool> constexpr kVectftftf( true, false,  true, false,  true, false);
  Vec6<bool> constexpr kVectttttt( true,  true,  true,  true,  true,  true);

  EXPECT_EQ(kVecftftft && kVecffffff, kVecffffff);
  EXPECT_EQ(kVecftftft && kVectttttt, kVecftftft);
  EXPECT_EQ(kVectftftf && kVecffffff, kVecffffff);
  EXPECT_EQ(kVectftftf && kVectttttt, kVectftftf);
  EXPECT_EQ(kVecftftft || kVecffffff, kVecftftft);
  EXPECT_EQ(kVecftftft || kVectttttt, kVectttttt);
  EXPECT_EQ(kVectftftf || kVecffffff, kVectftftf);
  EXPECT_EQ(kVectftftf || kVectttttt, kVectttttt);
}

}  // namespace tf::test
