#include "Point.h"

#include <cassert>
#include <compare>
#include <utility>

namespace mcd {
class Line {
private:
  Point m_firstPoint;
  Point m_secondPoint;

public:
  Line(Point start, Point end) : m_firstPoint(start), m_secondPoint(end) {
    assert(m_firstPoint != m_secondPoint);
  }

  double Length() const;
  
  bool operator==(const Line&other) const;
  std::partial_ordering operator<=>(const Line &other) const;
};
} // namespace mcd
