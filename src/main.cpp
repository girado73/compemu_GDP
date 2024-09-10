#include "reader.h"
#include <iostream>
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
  return 0;
}
