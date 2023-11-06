#include "Line.h"

#include <cmath>

namespace mcd {
double Line::Length() const {
  const double xDiff = m_firstPoint.x() - m_secondPoint.x();
  const double yDiff = m_firstPoint.y() - m_secondPoint.y();
  const double zDiff = m_firstPoint.z() - m_secondPoint.z();

  return std::sqrt(xDiff * xDiff + yDiff * yDiff + zDiff * zDiff);
}

bool Line::operator==(const Line& other) const {
    return fabs(Length() - other.Length()) < 1e-9; 
}

std::partial_ordering Line::operator<=>(const Line &other) const {
    return Length() <=> other.Length();
}
} // namespace mcd
