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
#ifndef FUZZYTRIA_H__
#define FUZZYTRIA_H__

#include <fuzzy/FuzzyBase.h>

namespace fuzzy
{
  class FuzzyBase;

  class FuzzyTriangle : public FuzzyBase
  {
    public:
      void setMiddle(std::vector<float> _middle);
      float getValue(float _value);
    private:
      float m_middle;
  };
}

#endif // FUZZYTRIA
