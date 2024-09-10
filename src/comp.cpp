#include "comp.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

Comp::Comp() {}

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
