#pragma once
#include "Position.h"
#include "Defs.h"

class IToyRobot
{
public:
  virtual void SetDirection(Direction direction) = 0;
  virtual Direction GetDirection() = 0;
  virtual void SetPosition(Position *position) = 0;
  virtual Position *GetPosition() = 0;
  virtual void Place(Position *position, Direction direction) = 0;
  virtual Position *GetNextPosition() = 0;
  virtual void RotateLeft() = 0;
  virtual void RotateRight() = 0;
  virtual void Rotate(int rotation_number) = 0;
};

