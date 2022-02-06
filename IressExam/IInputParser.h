#pragma once
#include <vector>
#include <string>
#include "Defs.h"
#include "Position.h"

class IInputParser
{
public:
  virtual Command ParseCommand(std::vector<std::string> raw_input) = 0;
  virtual void ParseCommandParameter(std::vector<std::string> input, Position *position, Direction &direction) = 0;
  virtual Direction GetDirectionNum(std::string str) = 0;
  virtual std::string GetDirectionString(Direction direction) = 0;
};

