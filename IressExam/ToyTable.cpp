#include "ToyTable.h"

ToyTable::ToyTable(int rows, int columns)
{
  this->columns = columns;
  this->rows = rows;
}

bool ToyTable::IsValidPosition(Position position)
{
  size_t pos_x = position.GetPosX();
  size_t pos_y = position.GetPosY();
  bool is_valid =
    pos_x < columns && pos_x >= 0 &&
    pos_y < rows && pos_y >= 0;

  return is_valid;
}
