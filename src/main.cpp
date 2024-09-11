#include "comp.h"
#include "reader.h"
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::string filename = "Test.com";
  std::vector<std::string> lines = readFile(filename);
  auto program = linesToProgram(lines);

  /*
  for (std::string &line : lines) {
    std::cout << line << std::endl;
  }
  for (const auto &[command, param] : program) {
    std::cout << "command: " << command << "\nparam: " << param << std::endl;
  }
  */
  Comp mycomp = *new Comp();

  mycomp.loadProgram(program);
  mycomp.run();

  return 0;
}
