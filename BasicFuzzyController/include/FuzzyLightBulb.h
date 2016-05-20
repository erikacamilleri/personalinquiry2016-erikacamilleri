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
#ifndef FUZZYLIGHTBULB_H__
#define FUZZYLIGHTBULB_H__

#include <cstdlib>

#include <fuzzy/FuzzyTrapezoid.h>
#include <fuzzy/FuzzyTriangle.h>

class FuzzyLightBulb
{
  public:
    FuzzyLightBulb();
    ~FuzzyLightBulb();
    void fuzzification();
    void inference();
    void defuzzification();
  protected:
  private:
    std::vector<fuzzy::FuzzyBase *> m_fuzzySet;
}

#endif // FUZZYLIGHTBULB
