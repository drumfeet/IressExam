#include <iostream>
#include <string>
#include <vector>
#include "ToyTable.h"
#include "InputParser.h"
#include "ToyRobot.h"
#include "ToyCommand.h"

int main()
{
    std::cout << "Input your command!\n";
    bool exit_app = false;

    ToyTable *toy_table = new ToyTable(5, 5);
    ToyRobot *toy_robot = new ToyRobot();
    InputParser *input_parser = new InputParser();
    ToyCommand *toy_command = new ToyCommand(toy_robot, toy_table, input_parser);

    while (!exit_app)
    {
      std::string str;
      std::getline(std::cin, str);

      std::string::size_type pos = str.find(" ");
      std::string command = str.substr(0, pos);
      std::string args = str.substr(pos + 1);
      std::vector<std::string> input = { command, args };

      if (command.compare("EXIT") == 0)
      {
        exit_app = true;
      }
      else
      {
        std::string result = toy_command->ProcessCommand(input);
        if(!result.empty()) { std::cout << result; }
      }
    }
}