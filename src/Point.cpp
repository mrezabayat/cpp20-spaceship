#include "Point.h"

namespace mcd {
bool Point::operator==(const Point &other) const {
  return m_firstCoord == other.x() && m_secondCoord == other.y() &&
         m_thirdCoord == other.z();
}
} // namespace mcd