#include "comp.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

Comp::Comp() {}

Comp::~Comp() {}

//-----------------

void Comp::ldaa(int x) { this->akk = getRam(x); }

void Comp::ldaz(int x) { this->akk = x; }

void Comp::load() { this->akk = getRam(this->akk); }

//-----------------

void Comp::addz(int x) { this->akk += x; }
void Comp::adda(int x) { this->akk += getRam(x); }

//-----------------

void Comp::mulz(int x) { this->akk *= x; }
void Comp::mula(int x) { this->akk *= getRam(x); }

//-----------------

void Comp::wra(int x) { writeRam(x, this->akk); }

//-----------------

void Comp::jmp(int x) {
  // TODO hier fehlt auf jeden Fall noch ein überprüfer welcher den jump befehlt
  // vorraussagt und ggf stoppt
  this->cursor = x;
}

void Comp::jiz(int x) {
  if (this->akk == 0) {
    jmp(x);
  }
}

void Comp::jnz(int x) {
  if (this->akk != 0) {
    jmp(x);
  }
}

//-----------------

void Comp::dispa() { std::cout << this->akk << std::endl; }

//-----------------

void Comp::stop() { exit(0); }

//-----------------

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
