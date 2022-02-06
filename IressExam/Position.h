#pragma once
class Position
{
public:
  Position(size_t x, size_t y);
  size_t GetPosX() { return pos_x; }
  void SetPosX(size_t x) { pos_x = x; }
  size_t GetPosY() { return pos_y; }
  void SetPosY(size_t y) { pos_y = y; }

private:
  int pos_x;
  int pos_y;
};

