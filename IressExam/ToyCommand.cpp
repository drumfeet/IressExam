#include <iostream>
#include <vector>
#include "ToyCommand.h"

ToyCommand::ToyCommand(IToyRobot *toy_robot, IToyTable *toy_table, IInputParser *input_parser) :
  toy_robot(toy_robot),
  toy_table(toy_table),
  input_parser(input_parser)
{
}

std::string ToyCommand::ProcessCommand(std::vector<std::string> input)
{
  Command command = input_parser->ParseCommand(input);
  Position *position = toy_robot->GetPosition();

  if (command != Place && !position ||
    command == Invalid)
  {
    return "Invalid Input!\n";
  }

  switch (command)
  {
  case Place:
  {
    Position *pos = new Position(-1,-1);
    Position pos2(-1, -1);
    Direction direction = {};
    input_parser->ParseCommandParameter(input, pos, direction);

    if (toy_table->IsValidPosition(*pos))
    {
      toy_robot->Place(pos, direction);
    }
    break;
  }
  case Move:
  {
    Position *new_position = toy_robot->GetNextPosition();
    if (toy_table->IsValidPosition(*new_position))
    {
      toy_robot->SetPosition(new_position);
    }
    break;
  }
  case Left:
  {
    toy_robot->RotateLeft();
    break;
  }
  case Right:
  {
    toy_robot->RotateRight();
    break;
  }
  case Report:
  {
    return GetReport();
  }
  default:
    break;
  }

  return std::string();
}

std::string ToyCommand::GetReport()
{
  size_t pos_x = toy_robot->GetPosition()->GetPosX();
  size_t pos_y = toy_robot->GetPosition()->GetPosY();

  std::string direction =
    input_parser->GetDirectionString(toy_robot->GetDirection());

  std::string str =
    std::to_string(pos_x) + "," +
    std::to_string(pos_y) + "," +
    direction + "\n";

  return str;
}
