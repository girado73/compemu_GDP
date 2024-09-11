#include "comp.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

Comp::Comp() {

  // laden der funktionen in commands map als lambdas
  commands["LDAA"] = [this](const int &x) { this->akk = getRam(x); };
  commands["LDAZ"] = [this](const int &x) { this->akk = x; };
  commands["LOAD"] = [this](const int &x) { this->akk = getRam(this->akk); };
  commands["ADDZ"] = [this](const int &x) { this->akk += x; };
  commands["ADDA"] = [this](const int &x) { this->akk += getRam(x); };
  commands["MULZ"] = [this](const int &x) { this->akk *= x; };
  commands["MULA"] = [this](const int &x) { this->akk *= getRam(x); };
  commands["WRA"] = [this](const int &x) { writeRam(x, this->akk); };
  commands["JMP"] = [this](const int &x) { this->cursor = x; };
  commands["JIZ"] = [this](const int &x) {
    if (this->akk == 0)
      jmp(x);
  };
  commands["JIZ"] = [this](const int &x) {
    if (this->akk != 0)
      jmp(x);
  };
  commands["DISPA"] = [this](const int &x) {
    std::cout << this->akk << std::endl;
  };
  commands["STOP"] = [this](const int &x) { exit(0); };
}

Comp::~Comp() {}

void Comp::writeRam(int mem, int val) { this->ram[mem] = val; }
int Comp::getRam(int mem) {
  try {
    return this->ram.at(mem);
  } catch (std::out_of_range e) {
    std::cout << "Der von ihnen gewählte Key: " << mem
              << " ist nicht mit einem Wert belegt" << std::endl;
    return 0;
  }
}

void Comp::loadProgram(
    const std::vector<std::pair<std::string, int>> &newProgram) {
  this->program = newProgram;
};

void Comp::run() {
  while (this->cursor < program.size()) {
    const auto &[command, param] = program[this->cursor];
    if (commands.find(command) != commands.end()) {
      commands[command](param);
      // das funktioniert da die funktionen als lambdas in der hashmap liegen
    } else {
      std::cerr << "Unbekannter Befehl" << command << std::endl;
    }
    cursor++;
  }
};
