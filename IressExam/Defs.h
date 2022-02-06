#pragma once
#define DIRECTION_LENGTH 4

enum Direction { North, East, South, West };
enum Command
{
  Invalid   = -1,
  Place     = 0,
  Move      = 1,
  Left      = 2,
  Right     = 3,
  Report    = 4
};