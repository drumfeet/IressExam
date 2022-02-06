#pragma once
#include "IToyRobot.h"

class ToyRobot :
  public IToyRobot
{
public:
  void SetDirection(Direction direction) { this->direction = direction; }
  Direction GetDirection() { return direction; }
  void SetPosition(Position *position) { this->position = position; }
  Position *GetPosition() { return position; }
  void Place(Position *position, Direction direction);
  Position *GetNextPosition();
  void RotateLeft();
  void RotateRight();
  void Rotate(int rotation_number);

private:
  Direction direction;
  Position *position;
};

