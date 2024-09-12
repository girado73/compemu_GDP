#include "comp.h"
#include <cassert>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

class tests {
public:
  tests();
  tests(tests &&) = default;
  tests(const tests &) = default;
  tests &operator=(tests &&) = default;
  tests &operator=(const tests &) = default;
  ~tests();
  void run_tests();

private:
  void ldaa_test();
  void ldaz_test();
  void load_test();

  void addz_test();
  void adda_test();

  void mulz_test();
  void mula_test();

  void wra_test();

  void jmp_test();
  void jiz_test();
  void jnz_test();

  void dispa_test();
  void stop_test();

  void printFunction(std::string funcname);
};

tests::tests() {}

tests::~tests() {}

void tests::printFunction(std::string funcname) {
  std::cout << "Testing Function :" << funcname << std::endl;
  ;
};

void tests::ldaa_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 500));
  program.push_back(std::make_pair("WRA", 5));
  program.push_back(std::make_pair("LDAA", 5));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 500);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::ldaz_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 700));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 700);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::load_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 300));
  program.push_back(std::make_pair("WRA", 5));
  program.push_back(std::make_pair("LDAZ", 5));
  program.push_back(std::make_pair("LOAD", 5));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 300);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::addz_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 700));
  program.push_back(std::make_pair("ADDZ", 1));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 701);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::adda_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 200));
  program.push_back(std::make_pair("WRA", 5));
  program.push_back(std::make_pair("LDAZ", 1));
  program.push_back(std::make_pair("ADDA", 5));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 201);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::mulz_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 600));
  program.push_back(std::make_pair("MULZ", 2));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 1200);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::mula_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 200));
  program.push_back(std::make_pair("WRA", 5));
  program.push_back(std::make_pair("LDAZ", 2));
  program.push_back(std::make_pair("MULA", 5));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 400);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::wra_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 800));
  program.push_back(std::make_pair("WRA", 5));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getRam(5) == 800);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::jmp_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 800));
  program.push_back(std::make_pair("JMP", 3));
  program.push_back(std::make_pair("ADDZ", 5)); // wir springen hier drüber
  program.push_back(std::make_pair("ADDZ", 10));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 810);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::jiz_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 900));
  program.push_back(std::make_pair("JIZ", 3));
  program.push_back(
      std::make_pair("STOP", 0)); // wir springen nicht hier drüber
  program.push_back(std::make_pair("ADDZ", 10));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 900);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::jnz_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 900));
  program.push_back(std::make_pair("JNZ", 3));
  program.push_back(std::make_pair("STOP", 0)); // wir springen hier drüber
  program.push_back(std::make_pair("ADDZ", 10));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 910);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::stop_test() {
  Comp testcomp;
  printFunction(__func__);
  std::vector<std::pair<std::string, int>> program;
  program.push_back(std::make_pair("LDAZ", 900));
  program.push_back(std::make_pair("STOP", 0)); // wir stoppen hier
  program.push_back(std::make_pair("ADDZ", 10));
  testcomp.loadProgram(program);
  testcomp.run();
  std::cout << "AKK: " << testcomp.getAKK() << std::endl;
  assert(testcomp.getAKK() == 900);
  std::cout << "Assertation Succeeded " << std::endl;
  std::cout << "---------------------\n" << std::endl;
}

void tests::run_tests() {
  ldaa_test();
  ldaz_test();
  load_test();
  addz_test();
  adda_test();
  mulz_test();
  mula_test();
  wra_test();
  jmp_test();
  jiz_test();
  jnz_test();
  stop_test();
}

int main(int argc, char *argv[]) {
  tests tests = *new class tests();

  tests.run_tests();
  return 0;
}
