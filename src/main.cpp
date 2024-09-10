#include "comp.h"
#include "reader.h"
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  printf("Hello World\n");
  std::string filename = "Test.com";
  std::vector<std::string> lines = readFile(filename);

  for (std::string &line : lines) {
    std::cout << line << std::endl;
  }

  Comp mycomp = *new Comp();

  mycomp.writeRam(500, 10);

  std::cout << mycomp.getRam(500) << std::endl;
  std::cout << mycomp.getRam(400) << std::endl;

  return 0;
}
