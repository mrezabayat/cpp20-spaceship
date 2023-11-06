#include "Line.h"

#include <compare>

#include <gtest/gtest.h>

namespace mcd {
TEST(Point, SpaceshipOperator) {
  Point origin;
  Point pointA(0., 1., 0.);
  Point pointB(0., 0., 1.);
  Point pointC;

  ASSERT_EQ(origin <=> pointA, std::partial_ordering::less);
  ASSERT_EQ(pointA <=> pointB, std::partial_ordering::greater);
  ASSERT_EQ(pointC <=> origin, std::partial_ordering::equivalent);
}

TEST(FundamentalTypes, ReturnType) {
  int x = 3;
  int y = 4;
  ASSERT_EQ(x <=> y, std::strong_ordering::less);

  double q = 17.3;
  double p = 32.8;
  ASSERT_EQ(p <=> q, std::partial_ordering::greater);

  ASSERT_EQ(std::string("hello") <=> "hello", std::strong_ordering::equal);
}

TEST(Line, Comparison) {
  Line l1(Point(), Point(1.));
  Line l2(Point(), Point(-1., 1.));
  Line l3(Point(), Point(1., -1.));

  ASSERT_EQ(l1 <=> l2, std::partial_ordering::less);
  ASSERT_EQ(l2 <=> l3, std::partial_ordering::equivalent);
}

} // namespace mcd
