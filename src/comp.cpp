#include "comp.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <unordered_map>

int Comp::cursor = 0;
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
      this->cursor = x;
  };
  commands["JNZ"] = [this](const int &x) {
    std::cout << "JNZ called. akk = " << this->akk << ", jump target = " << x
              << ", current cursor = " << this->cursor << std::endl;
    if (this->akk != 0) {
      std::cout << "Jumping to " << x << std::endl;
      this->cursor = x; // Directly modify the cursor
      std::cout << "Cursor after jump: " << this->cursor << std::endl;
    } else {
      std::cout << "Not jumping (akk == 0)" << std::endl;
    }
  };

  commands["DISPA"] = [this](const int &x) {
    std::cout << this->akk << std::endl;
  };
  commands["STOP"] = [this](const int &x) { this->~Comp(); };
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
  while (this->cursor >= 0 && this->cursor < static_cast<int>(program.size())) {
    std::cout << "Start of loop. Cursor: " << this->cursor << std::endl;
    int old_cursor = this->cursor;
    const auto &[command, param] = program[this->cursor];
    std::cout << "Executing command: " << command << " with param: " << param
              << std::endl;
    if (commands.find(command) != commands.end()) {
      commands[command](param);
    } else {
      std::cerr << "Unbekannter Befehl: " << command << std::endl;
    }
    std::cout << "After execution. Cursor: " << this->cursor << std::endl;
    if (this->cursor == old_cursor) {
      // Only increment if the command didn't change the cursor
      this->cursor++;
    }
    std::cout << "End of loop. Cursor: " << this->cursor << std::endl;
  }
}
