#include "comp.h"
#include "reader.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

/**
 * Ließ die Datei aus den Env-args ein, lade das Programm und fuehre es aus
 *
 * @param argc Anzahl der gegebenen Argumente
 * @param argv Die gegebenen Argumente
 */
int main(int argc, char const *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: compemu <Filename>" << std::endl;
    exit(1);
  }
  std::string filename = argv[1];
  std::vector<std::string> lines = readFile(filename);
  auto program = linesToProgram(lines);

  Comp mycomp = *new Comp();

  mycomp.loadProgram(program);
  mycomp.run();

  return 0;
}
