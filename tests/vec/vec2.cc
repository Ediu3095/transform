#include <transform/vec/vec2.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Vec2) {
  Vec2<i32> vec1(2, 3);
  Vec2<i32> vec2(4, 5);  // NOLINT(*-magic-numbers)
  Vec2<bool> vec3(true, false);
  Vec2<bool> vec4(false, true);

  EXPECT_EQ(Vec1<i32>(vec1).x(), 2);
  EXPECT_FLOAT_EQ(Vec1<f32>(vec1).x(), 2.0F);

  EXPECT_EQ(+vec1, Vec2<i32>(+vec1.x(), +vec1.y()));
  EXPECT_EQ(-vec1, Vec2<i32>(-vec1.x(), -vec1.y()));

  EXPECT_EQ(vec1 + 1, Vec2<i32>(vec1.x() + 1, vec1.y() + 1));
  EXPECT_EQ(vec1 - 1, Vec2<i32>(vec1.x() - 1, vec1.y() - 1));
  EXPECT_EQ(vec1 * 1, Vec2<i32>(vec1.x() * 1, vec1.y() * 1));
  EXPECT_EQ(vec1 / 1, Vec2<i32>(vec1.x() / 1, vec1.y() / 1));
  EXPECT_EQ(vec1 % 1, Vec2<i32>(vec1.x() % 1, vec1.y() % 1));

  EXPECT_EQ(1 + vec1, Vec2<i32>(1 + vec1.x(), 1 + vec1.y()));
  EXPECT_EQ(1 - vec1, Vec2<i32>(1 - vec1.x(), 1 - vec1.y()));
  EXPECT_EQ(1 * vec1, Vec2<i32>(1 * vec1.x(), 1 * vec1.y()));
  EXPECT_EQ(1 / vec1, Vec2<i32>(1 / vec1.x(), 1 / vec1.y()));
  EXPECT_EQ(1 % vec1, Vec2<i32>(1 % vec1.x(), 1 % vec1.y()));

  EXPECT_EQ(vec1 + Vec1<i32>(1), Vec2<i32>(vec1.x() + 1, vec1.y() + 1));
  EXPECT_EQ(vec1 - Vec1<i32>(1), Vec2<i32>(vec1.x() - 1, vec1.y() - 1));
  EXPECT_EQ(vec1 * Vec1<i32>(1), Vec2<i32>(vec1.x() * 1, vec1.y() * 1));
  EXPECT_EQ(vec1 / Vec1<i32>(1), Vec2<i32>(vec1.x() / 1, vec1.y() / 1));
  EXPECT_EQ(vec1 % Vec1<i32>(1), Vec2<i32>(vec1.x() % 1, vec1.y() % 1));

  EXPECT_EQ(Vec1<i32>(1) + vec1, Vec2<i32>(1 + vec1.x(), 1 + vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) - vec1, Vec2<i32>(1 - vec1.x(), 1 - vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) * vec1, Vec2<i32>(1 * vec1.x(), 1 * vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) / vec1, Vec2<i32>(1 / vec1.x(), 1 / vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) % vec1, Vec2<i32>(1 % vec1.x(), 1 % vec1.y()));

  EXPECT_EQ(vec1 + vec2, Vec2<i32>(vec1.x() + vec2.x(), vec1.y() + vec2.y()));
  EXPECT_EQ(vec1 - vec2, Vec2<i32>(vec1.x() - vec2.x(), vec1.y() - vec2.y()));
  EXPECT_EQ(vec1 * vec2, Vec2<i32>(vec1.x() * vec2.x(), vec1.y() * vec2.y()));
  EXPECT_EQ(vec1 / vec2, Vec2<i32>(vec1.x() / vec2.x(), vec1.y() / vec2.y()));
  EXPECT_EQ(vec1 % vec2, Vec2<i32>(vec1.x() % vec2.x(), vec1.y() % vec2.y()));

  EXPECT_EQ(~vec1, Vec2<i32>(~vec1.x(), ~vec1.y()));

  EXPECT_EQ(vec1 &  1, Vec2<i32>(vec1.x() &  1, vec1.y() &  1));
  EXPECT_EQ(vec1 |  1, Vec2<i32>(vec1.x() |  1, vec1.y() |  1));
  EXPECT_EQ(vec1 ^  1, Vec2<i32>(vec1.x() ^  1, vec1.y() ^  1));
  EXPECT_EQ(vec1 << 1, Vec2<i32>(vec1.x() << 1, vec1.y() << 1));
  EXPECT_EQ(vec1 >> 1, Vec2<i32>(vec1.x() >> 1, vec1.y() >> 1));

  EXPECT_EQ(1 &  vec1, Vec2<i32>(1 &  vec1.x(), 1 &  vec1.y()));
  EXPECT_EQ(1 |  vec1, Vec2<i32>(1 |  vec1.x(), 1 |  vec1.y()));
  EXPECT_EQ(1 ^  vec1, Vec2<i32>(1 ^  vec1.x(), 1 ^  vec1.y()));
  EXPECT_EQ(1 << vec1, Vec2<i32>(1 << vec1.x(), 1 << vec1.y()));
  EXPECT_EQ(1 >> vec1, Vec2<i32>(1 >> vec1.x(), 1 >> vec1.y()));

  EXPECT_EQ(vec1 &  Vec1<i32>(1), Vec2<i32>(vec1.x() &  1, vec1.y() &  1));
  EXPECT_EQ(vec1 |  Vec1<i32>(1), Vec2<i32>(vec1.x() |  1, vec1.y() |  1));
  EXPECT_EQ(vec1 ^  Vec1<i32>(1), Vec2<i32>(vec1.x() ^  1, vec1.y() ^  1));
  EXPECT_EQ(vec1 << Vec1<i32>(1), Vec2<i32>(vec1.x() << 1, vec1.y() << 1));
  EXPECT_EQ(vec1 >> Vec1<i32>(1), Vec2<i32>(vec1.x() >> 1, vec1.y() >> 1));

  EXPECT_EQ(Vec1<i32>(1) &  vec1, Vec2<i32>(1 &  vec1.x(), 1 &  vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) |  vec1, Vec2<i32>(1 |  vec1.x(), 1 |  vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) ^  vec1, Vec2<i32>(1 ^  vec1.x(), 1 ^  vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) << vec1, Vec2<i32>(1 << vec1.x(), 1 << vec1.y()));
  EXPECT_EQ(Vec1<i32>(1) >> vec1, Vec2<i32>(1 >> vec1.x(), 1 >> vec1.y()));

  EXPECT_EQ(vec1 &  vec2, Vec2<i32>(vec1.x() &  vec2.x(), vec1.y() &  vec2.y()));
  EXPECT_EQ(vec1 |  vec2, Vec2<i32>(vec1.x() |  vec2.x(), vec1.y() |  vec2.y()));
  EXPECT_EQ(vec1 ^  vec2, Vec2<i32>(vec1.x() ^  vec2.x(), vec1.y() ^  vec2.y()));
  EXPECT_EQ(vec1 << vec2, Vec2<i32>(vec1.x() << vec2.x(), vec1.y() << vec2.y()));
  EXPECT_EQ(vec1 >> vec2, Vec2<i32>(vec1.x() >> vec2.x(), vec1.y() >> vec2.y()));

  EXPECT_EQ(vec1, Vec2<i32>(vec1));
  EXPECT_NE(vec1, vec2);

  EXPECT_EQ(vec3 && vec3, Vec2<bool>(true,  false));
  EXPECT_EQ(vec3 && vec4, Vec2<bool>(false, false));
  EXPECT_EQ(vec3 || vec3, Vec2<bool>(true,  false));
  EXPECT_EQ(vec3 || vec4, Vec2<bool>(true,  true));
}

}  // namespace tf::test
