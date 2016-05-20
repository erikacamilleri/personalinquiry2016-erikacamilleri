/*
  Copyright (C) 2015 Erika Camilleri

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FUZZYBASE_H__
#define FUZZYBASE_H__

#include <cstdlib>
#include <vector>
#include <string>

namespace fuzzy
{
  class FuzzyBase
  {
    public:
      enum Type {TRAPEZOID, TRIANGLE};
      virtual ~FuzzyBase();
      inline void setInterval(const float &_left, const float &_right) { m_left = _left; m_right = _right; }
      virtual void setMiddle(std::vector<float> _middle) = 0;
      inline void setType(Type _type) { m_type = _type; }
      inline Type getType() { return m_type; }
      inline void setName(const std::string &_name) { m_name = _name; }
      inline std::string getName() { return m_name; }
      inline bool isInInterval(const float &_value) { return _value <= m_right && _value >= m_left; }
      virtual float getValue(float _value) = 0;
    protected:
      float m_left;
      float m_right;
      Type m_type;
      std::string m_name;
  };
}

#endif // FUZZYBASE
