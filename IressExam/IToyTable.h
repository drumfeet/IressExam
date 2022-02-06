#pragma once
#include "Position.h"

class IToyTable
{
public:
  virtual bool IsValidPosition(Position position) = 0;
};