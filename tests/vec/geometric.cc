#include <transform/vec/geometric.h>
#include <transform/vec/vecn.h>

#include <gtest/gtest.h>

namespace tf::test {

TEST(VecTest, Func) {
  Vec3<i32> constexpr kVecx(1, 0, 0);
  Vec3<i32> constexpr kVecy(0, 1, 0);
  Vec3<i32> constexpr kVecz(0, 0, 1);

  EXPECT_EQ(length(kVecx * 2), 2);

  EXPECT_EQ(normalize(kVecx * 2), kVecx);

  EXPECT_EQ(sum(kVecx + kVecy + kVecz), 3);

  EXPECT_EQ(cross(kVecx, kVecy), kVecz);

  EXPECT_EQ(dot(kVecx, kVecy), 0);

  EXPECT_EQ(distance(kVecx * 3, kVecy * 4), 5);
}

}  // namespace tf::test
