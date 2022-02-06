#pragma once
#include "IToyRobot.h"
#include "IToyTable.h"
#include "IInputParser.h"

class ToyCommand
{
public:
  ToyCommand(IToyRobot *toy_robot, IToyTable *toy_table, IInputParser *input_parser);

  std::string ProcessCommand(std::vector<std::string> input);
  std::string GetReport();

private:
  IToyRobot *toy_robot;
  IToyTable *toy_table;
  IInputParser *input_parser;
};

