#include "ToyRobot.h"

void ToyRobot::Place(Position *position, Direction direction)
{
  this->position = position;
  this->direction = direction;
}

Position * ToyRobot::GetNextPosition()
{
  Position *new_position = new Position(position->GetPosX(), position->GetPosY());

  switch (direction)
  {
  case North:
  {
    new_position->SetPosY(position->GetPosY() + 1);
    break;
  }
  case South:
  {
    new_position->SetPosY(position->GetPosY() - 1);
    break;
  }
  case East:
  {
    new_position->SetPosX(position->GetPosX() + 1);
    break;
  }
  case West:
  {
    new_position->SetPosX(position->GetPosX() - 1);
    break;
  }
  default:
    break;
  }

  return new_position;
}

void ToyRobot::RotateLeft()
{
  Rotate(-1);
}

void ToyRobot::RotateRight()
{
  Rotate(1);
}

void ToyRobot::Rotate(int rotation_number)
{
  Direction new_direction = {};
  int direction_num = GetDirection();

  if(direction_num + rotation_number < 0)
  {

    new_direction = (Direction)(DIRECTION_LENGTH - 1);
  }
  else
  {
    int index = ((int)(direction_num + rotation_number)) % DIRECTION_LENGTH;
    new_direction = (Direction)index;
  }

  direction = new_direction;
}


