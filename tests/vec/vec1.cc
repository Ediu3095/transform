#include <transform/vec/vec1.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec1) {
  Vec1<i32> vec1(2);
  Vec1<i32> vec2(4);
  Vec1<bool> vec3(true);
  Vec1<bool> vec4(false);

  EXPECT_EQ(Vec1<i32>(vec1).x(), 2);
  EXPECT_FLOAT_EQ(Vec1<f32>(vec1).x(), 2.0F);

  EXPECT_EQ(+vec1, Vec1<i32>(+vec1.x()));
  EXPECT_EQ(-vec1, Vec1<i32>(-vec1.x()));

  EXPECT_EQ(vec1 + 1, Vec1<i32>(vec1.x() + 1));
  EXPECT_EQ(vec1 - 1, Vec1<i32>(vec1.x() - 1));
  EXPECT_EQ(vec1 * 1, Vec1<i32>(vec1.x() * 1));
  EXPECT_EQ(vec1 / 1, Vec1<i32>(vec1.x() / 1));
  EXPECT_EQ(vec1 % 1, Vec1<i32>(vec1.x() % 1));

  EXPECT_EQ(1 + vec1, Vec1<i32>(1 + vec1.x()));
  EXPECT_EQ(1 - vec1, Vec1<i32>(1 - vec1.x()));
  EXPECT_EQ(1 * vec1, Vec1<i32>(1 * vec1.x()));
  EXPECT_EQ(1 / vec1, Vec1<i32>(1 / vec1.x()));
  EXPECT_EQ(1 % vec1, Vec1<i32>(1 % vec1.x()));

  EXPECT_EQ(vec1 + vec2, Vec1<i32>(vec1.x() + vec2.x()));
  EXPECT_EQ(vec1 - vec2, Vec1<i32>(vec1.x() - vec2.x()));
  EXPECT_EQ(vec1 * vec2, Vec1<i32>(vec1.x() * vec2.x()));
  EXPECT_EQ(vec1 / vec2, Vec1<i32>(vec1.x() / vec2.x()));
  EXPECT_EQ(vec1 % vec2, Vec1<i32>(vec1.x() % vec2.x()));

  EXPECT_EQ(~vec1, Vec1<i32>(~vec1.x()));

  EXPECT_EQ(vec1 &  1, Vec1<i32>(vec1.x() &  1));
  EXPECT_EQ(vec1 |  1, Vec1<i32>(vec1.x() |  1));
  EXPECT_EQ(vec1 ^  1, Vec1<i32>(vec1.x() ^  1));
  EXPECT_EQ(vec1 << 1, Vec1<i32>(vec1.x() << 1));
  EXPECT_EQ(vec1 >> 1, Vec1<i32>(vec1.x() >> 1));

  EXPECT_EQ(1 &  vec1, Vec1<i32>(1 &  vec1.x()));
  EXPECT_EQ(1 |  vec1, Vec1<i32>(1 |  vec1.x()));
  EXPECT_EQ(1 ^  vec1, Vec1<i32>(1 ^  vec1.x()));
  EXPECT_EQ(1 << vec1, Vec1<i32>(1 << vec1.x()));
  EXPECT_EQ(1 >> vec1, Vec1<i32>(1 >> vec1.x()));

  EXPECT_EQ(vec1 &  vec2, Vec1<i32>(vec1.x() &  vec2.x()));
  EXPECT_EQ(vec1 |  vec2, Vec1<i32>(vec1.x() |  vec2.x()));
  EXPECT_EQ(vec1 ^  vec2, Vec1<i32>(vec1.x() ^  vec2.x()));
  EXPECT_EQ(vec1 << vec2, Vec1<i32>(vec1.x() << vec2.x()));
  EXPECT_EQ(vec1 >> vec2, Vec1<i32>(vec1.x() >> vec2.x()));

  EXPECT_EQ(vec1, Vec1<i32>(vec1));
  EXPECT_NE(vec1, vec2);

  EXPECT_TRUE((vec3 && vec3).x());
  EXPECT_FALSE((vec3 && vec4).x());
  EXPECT_TRUE((vec4 || vec3).x());
  EXPECT_FALSE((vec4 || vec4).x());
}

}  // namespace tf::test
