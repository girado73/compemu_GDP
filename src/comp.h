#include <cstddef>
#include <functional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Comp {
private:
  int akk;
  std::unordered_map<int, int> ram; // hashmap weil schneller als array

  static int cursor; // cursor beschreibt zeile im code in welcher wir gerade
                     // sind kann static sein weil wir eh nur einen Comp haben

  std::vector<std::pair<std::string, int>> program;
  std::unordered_map<std::string, std::function<void(const int x)>> commands;
  void setCursor(int x);

public:
  Comp();
  ~Comp();
  void writeRam(int mem, int val); // wrapper für key value creation
  int getRam(int mem);             // wraper für hashmap getter
  void loadProgram(const std::vector<std::pair<std::string, int>> &newProgram);
  void run();
  int getAKK();
  void resetCursor();
};
#pragma once
