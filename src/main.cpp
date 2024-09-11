#include "comp.h"
#include "reader.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: compemu <Filename>" << std::endl;
    exit(1);
  }
  std::string filename = argv[1];
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
