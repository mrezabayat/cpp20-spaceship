#include <compare>

namespace mcd {
class Point {
private:
  double m_firstCoord;
  double m_secondCoord;
  double m_thirdCoord;

public:
  Point(const double x = 0, const double y = 0, const double z = 0)
      : m_firstCoord(x), m_secondCoord(y), m_thirdCoord(z) {}

  double &x() { return m_firstCoord; }
  double &y() { return m_secondCoord; }
  double &z() { return m_thirdCoord; }

  double x() const { return m_firstCoord; }
  double y() const { return m_secondCoord; }
  double z() const { return m_thirdCoord; }

  // Before C++ 20
  // bool operator<(const Point& other) const;
  // bool operator>(const Point& other) const;
  // bool operator<=(const Point& other) const;
  // bool operator>=(const Point& other) const;
  // bool operator==(const Point& other) const;
  // bool operator!=(const Point& other) const;
  
  bool operator==(const Point& other) const;
  auto operator<=>(const Point &p) const = default;
};
} // namespace mcd
