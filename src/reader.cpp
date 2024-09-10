#include "reader.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

using commands = std::tuple<std::string, int>;
std::list<commands> commandlist;

std::string dropAfter(std::string str, char delimiter) {
  size_t pos = str.find(delimiter);
  if (pos != std::string::npos) {
    return str.substr(0, pos);
  }
  return str;
}

std::vector<std::string> readFile(const std::string &filename) {
  std::vector<std::string> lines;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << filename << std::endl;
    return lines;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::string trim = dropAfter(line, '#');
    if (trim != "") {
      lines.push_back(trim);
    }
  }

  file.close();
  return lines;
}

void read() {
  // Adding tuples to the list
  commandlist.push_back(std::make_tuple("Hello", 3));
  commandlist.push_back(std::make_tuple("World", 2));
  commandlist.emplace_back("C++", 3);

  // Iterating through the list
  for (const auto &item : commandlist) {
    std::cout << "String: " << std::get<0>(item)
              << ", Int: " << std::get<1>(item) << std::endl;
  }
}
