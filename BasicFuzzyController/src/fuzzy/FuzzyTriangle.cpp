#include <fuzzy/FuzzyTriangle.h>

void fuzzy::FuzzyTriangle::setMiddle(std::vector<float> _middle)
{
  if(_middle.size() > 0)
  {
    m_middle = _middle[0];
  }
}

float fuzzy::FuzzyTriangle::getValue(float _value)
{
  if(_value <= m_left)
  {
    return 0;
  }
  else if(_value < m_middle)
  {
    return (_value - m_left)/(m_middle - m_left);
  }
  else if(_value == m_middle)
  {
    return 1;
  }
  else if(_value < m_right)
  {
    return (m_right - _value)/(m_right - m_middle);
  }
  else
  {
    return 0;
  }
}
