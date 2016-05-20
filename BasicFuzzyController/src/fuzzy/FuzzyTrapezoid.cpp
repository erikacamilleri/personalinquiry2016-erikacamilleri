#include <fuzzy/FuzzyTrapezoid.h>

void fuzzy::FuzzyTrapezoid::setMiddle(std::vector<float> _middle)
{
  if(_middle.size() >= 2)
  {
    m_middleLeft = _middle[0];
    m_middleRight = _middle[1];
  }
}

float fuzzy::FuzzyTrapezoid::getValue(float _value)
{
  if(_value <= m_left)
  {
    return 0;
  }
  else if(_value < m_middleLeft)
  {
    return (_value - m_left)/(m_middleLeft - m_left);
  }
  else if(_value <= m_middleRight)
  {
    return 1;
  }
  else if(_value < m_right)
  {
    return (m_right - _value)/(m_right - m_middleRight);
  }
  else
  {
    return 0;
  }
}
