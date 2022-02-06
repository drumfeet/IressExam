#pragma once
#include "IInputParser.h"

class InputParser :
  public IInputParser
{
public:
  Command ParseCommand(std::vector<std::string> raw_input);
  void ParseCommandParameter(std::vector<std::string> input, Position *position, Direction &direction);
  Direction GetDirectionNum(std::string str);
  std::string GetDirectionString(Direction direction);
};

