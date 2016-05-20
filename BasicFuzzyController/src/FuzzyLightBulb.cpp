#include <FuzzyLightBulb.h>

FuzzyLightBulb::FuzzyLightBulb()
{
  // temp middle values in vector
  std::vector<float> middle_values;

  // init the fuzzy set
  fuzzy::FuzzyBase *lowKey = new fuzzy::FuzzyTrapezoid();
  lowKey->setInterval(-5, 30);
  middle_values.push_back(0);
  middle_values.push_back(20);
  lowKey->setMiddle(middle_values);
  lowKey->setType(fuzzy::FuzzyBase::TRAPEZOID);
  lowKey->setName("lowkey");

  fuzzy::FuzzyBase *neutralKey = new fuzzy::FuzzyTriangle();
  neutralKey->setInterval(25, 45);
  middle_values.clear();
  middle_values.push_back(35);
  neutralKey->setMiddle(middle_values);
  neutralKey->setType(fuzzy::FuzzyBase::TRIANGLE);
  neutralKey->setName("neutralkey");

  fuzzy::FuzzyBase *highKey = new fuzzy::FuzzyTrapezoid();
  highKey->setInterval(40, 75);
  middle_values.clear();
  middle_values.push_back(50);
  middle_values.push_back(70);
  highKey->setMiddle(middle_values);
  highKey->setType(fuzzy::FuzzyBase::TRAPEZOID);
  highKey->setName("highkey");

  m_fuzzySet.push_back(lowKey);
  m_fuzzySet.push_back(neutralKey);
  m_fuzzySet.push_back(highKey);

  // set up fuzzy matrix of fuzzy rules
  m_fuzzyRules.insert(std::pair<std::string, Command>("lowkey_lowkey", Command::NOCHANGE));
  m_fuzzyRules.insert(std::pair<std::string, Command>("lowkey_neutralkey", Command::BRIGHTEN));
  m_fuzzyRules.insert(std::pair<std::string, Command>("lowkey_highkey", Command::BRIGHTEN));
  m_fuzzyRules.insert(std::pair<std::string, Command>("neutralkey_lowkey", Command::DIM));
  m_fuzzyRules.insert(std::pair<std::string, Command>("neutralkey_neutralkey", Command::NOCHANGE));
  m_fuzzyRules.insert(std::pair<std::string, Command>("neutral_highkey", Command::BRIGHTEN));
  m_fuzzyRules.insert(std::pair<std::string, Command>("highkey_lowkey", Command::DIM));
  m_fuzzyRules.insert(std::pair<std::string, Command>("highkey_neutralkey", Command::DIM));
  m_fuzzyRules.insert(std::pair<std::string, Command>("highkey_highkey", Command::NOCHANGE));
}

FuzzyLightBulb::~FuzzyLightBulb()
{
  // clear pointers
  if(!m_fuzzySet.empty())
  {
    for(auto &f : m_fuzzySet)
    {
      delete f;
    }
  }
  m_fuzzySet.clear();
}

void FuzzyLightBulb::setTarget(const Target &_target)
{
  switch(_target)
  {
    case Target::LOWKEY: m_target = "lowkey"; break;
    case Target::NEUTRALKEY: m_target = "neutralkey"; break;
    case Target::HIGHKEY: m_target = "highkey"; break;
    default: m_target = "neutralkey"; break;
  }
}

void FuzzyLightBulb::fuzzification()
{
  m_degLowKey = m_fuzzySet[0]->getValue(m_input);
  m_degNeutralKey = m_fuzzySet[1]->getValue(m_input);
  m_degHighKey = m_fuzzySet[2]->getValue(m_input);
}

void FuzzyLightBulb::inference()
{

}

void FuzzyLightBulb::defuzzification()
{

}
