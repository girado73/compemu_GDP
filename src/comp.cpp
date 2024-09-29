#include "comp.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <unordered_map>

/**
 * Erstelle den Compemulator +
 * definiere und lade alle Befehle in die Commands Map
 */
Comp::Comp() {
  // Cursor reset for Tests
  this->cursor = 0;

  this->akk = 0;

  commands["LDAA"] = [this](const int &x) -> void { this->akk = getRam(x); };
  commands["LDAZ"] = [this](const int &x) -> void { this->akk = x; };
  commands["LOAD"] = [this](int) -> void { this->akk = getRam(this->akk); };
  commands["ADDZ"] = [this](const int &x) -> void { this->akk += x; };
  commands["ADDA"] = [this](const int &x) -> void { this->akk += getRam(x); };
  commands["MULZ"] = [this](const int &x) -> void { this->akk *= x; };
  commands["MULA"] = [this](const int &x) -> void { this->akk *= getRam(x); };
  commands["WRA"] = [this](const int &x) -> void { writeRam(x, this->akk); };
  commands["JMP"] = [this](const int &x) -> void { this->cursor = x; };
  commands["JIZ"] = [this](const int &x) -> void {
    if (this->akk == 0)
      this->cursor = x;
  };
  commands["JNZ"] = [this](const int &x) -> void {
    if (this->akk != 0) {
      this->cursor = x; // Directly modify the cursor
    }
  };
  commands["DISPA"] = [this](int) -> void {
    std::cout << this->akk << std::endl;
  };
  commands["STOP"] = [](int) -> void { exit(0); };
  commands["TESTSTOP"] = [this](int) -> void { this->program.clear(); };
}

/**
 * Setze den static Cursor auf 0
 */
int Comp::cursor = 0;

/**
 * Dekonstrukte den Compemulator
 */
Comp::~Comp() {}

/**
 *  Schreibe in die RAM-Map
 *
 *  @param mem Die Memory Adresse in die geschrieben wird
 *  @param val Das Value zur Memory Adresse
 */
void Comp::writeRam(int mem, int val) {
  if (mem > 1000) {
    throw std::out_of_range(
        "Der Ram hat nur 1000 Speicherstellen zur verfügung");
  }
  if (mem < 0) {
    throw std::invalid_argument("Der Ram hat nur Positive Speicherstellen");
  }
  this->ram[mem] = val;
}

/**
 * Gib ein Value aus der RAM-Map zurück
 *
 * @param mem Die passende Memory Adresse
 * @return Den passenden Wert zu Mem
 */
int Comp::getRam(int mem) {
  try {
    return this->ram.at(mem);
  } catch (std::out_of_range e) {
    std::cout << "Der von ihnen gewählte Key: " << mem
              << " ist nicht mit einem Wert belegt" << std::endl;
    return 0;
  }
}

/**
 * Setze den Cursor auf einen bestimmten Wert
 *
 * @param x Der Wert auf den der Cursor gesetzt wird
 */
void Comp::setCursor(int x) {
  if (x < 0) {
    throw std::invalid_argument("Cursor muss größer oder gleich 0 sein");
  } else {
    this->cursor = x;
  }
}

/**
 * Setze den Cursor auf 0
 */
void Comp::resetCursor() { this->cursor = 0; }

/**
 * Gette den Akkumulator (für Tests)
 *
 * @return Den Wert des Akkumulators
 */
int Comp::getAKK() { return this->akk; }

/**
 * Lade das Progamm in den Program Vector
 *
 * @param newProgram Der Pair Vector in welchem die Programmbefehle liegen
 */
void Comp::loadProgram(
    const std::vector<std::pair<std::string, int>> &newProgram) {
  this->program = newProgram;
};

/**
 * Execute das Programm innerhalb des Program Vectors
 */
void Comp::run() {
  while (this->cursor >= 0 && this->cursor < static_cast<int>(program.size())) {
    int old_cursor = this->cursor;
    const auto &[command, param] = program[this->cursor];
    if (commands.find(command) != commands.end()) {
      commands[command](param);
    } else {
      std::cerr << "Unbekannter Befehl: " << command << std::endl;
      exit(1);
    }
    if (this->cursor == old_cursor) {
      // Only increment if the command didn't change the cursor
      this->cursor++;
    }
  }
}
