#pragma once
#include "IToyTable.h"

class ToyTable :
  public IToyTable
{
public:
  ToyTable(int rows, int columns);
  bool IsValidPosition(Position position);

private:
  size_t rows;
  size_t columns;
};