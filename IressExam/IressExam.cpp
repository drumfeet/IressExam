#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"


int main()
{
    std::cout << "Input!\n";
    bool exit_app = false;
    while (!exit_app)
    {
      std::string str;
      std::getline(std::cin, str);

      std::string::size_type pos = str.find(" ");
      std::string command = str.substr(0, pos);
      std::string args = str.substr(pos + 1);

      if (command.compare("EXIT") == 0)
      {
        exit_app = true;
      }
      else
      {
        std::vector<std::string> input = { command, args };
      }
    }




}


