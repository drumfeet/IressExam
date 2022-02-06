#include "InputParser.h"

Command InputParser::ParseCommand(std::vector<std::string> raw_input)
{
  if (raw_input[0].compare("PLACE") == 0) { return Place; }
  else if (raw_input[0].compare("MOVE") == 0) { return Move; }
  else if (raw_input[0].compare("LEFT") == 0) { return Left; }
  else if (raw_input[0].compare("RIGHT") == 0) { return Right; }
  else if (raw_input[0].compare("REPORT") == 0) { return Report; }
  else { return Invalid; }
}

void InputParser::ParseCommandParameter(std::vector<std::string> input, Position *position, Direction & direction)
{
  std::string str = input[1];
  size_t pos = str.find(",");
  std::string pos_x = str.substr(0, pos);

  str = str.substr(pos + 1);
  pos = str.find(",");
  std::string pos_y = str.substr(0, pos);

  position->SetPosX(atoi(pos_x.c_str()));
  position->SetPosY(atoi(pos_y.c_str()));
  direction = GetDirectionNum(str.substr(pos + 1));
}

Direction InputParser::GetDirectionNum(std::string str)
{
  if (str.compare("NORTH") == 0) { return North; }
  else if (str.compare("SOUTH") == 0) { return South; }
  else if (str.compare("EAST") == 0) { return East; }
  else if (str.compare("WEST") == 0) { return West; }
}

std::string InputParser::GetDirectionString(Direction direction)
{
  switch (direction)
  {
  case North:
    return "NORTH";
  case South:
    return "SOUTH";
  case East:
    return "EAST";
  case West:
    return "WEST";
  default:
    break;
  }
  return std::string();
}
