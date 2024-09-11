#include "reader.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using commands = std::pair<std::string, int>;
std::list<commands> commandlist;

std::string dropAfter(std::string str, char delimiter) {
  size_t pos = str.find(delimiter);
  if (pos != std::string::npos) {
    return str.substr(0, pos);
  }
  return str;
}

std::string trimTrailingWhitespace(const std::string &str) {
  if (str.empty()) {
    return str;
  }

  size_t end = str.find_last_not_of(" \t\n\r\f\v");
  if (end == std::string::npos) {
    // The string consists of only whitespace
    return "";
  }

  return str.substr(0, end + 1);
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
    std::string trim = trimTrailingWhitespace(dropAfter(line, '#'));
    if (trim != "") {
      // TODO das funktioniert so nicht, wir müssen alles vorm ersten
      // leerzeichen skippen
      lines.push_back(trim.substr(2));
    }
  }

  file.close();
  return lines;
}

std::vector<std::pair<std::string, int>>
linesToProgram(const std::vector<std::string> &lines) {
  std::vector<std::pair<std::string, int>> program;
  for (const std::string &line : lines) {
    size_t spacePos = line.find(' ');
    if (spacePos != std::string::npos) {
      // If there's a space, split the line into command and value
      std::string command = line.substr(0, spacePos);
      int value = std::stoi(line.substr(spacePos + 1));
      program.emplace_back(command, value);
    } else {
      // If there's no space, the whole line is the command and value is 0
      program.emplace_back(line, 0);
    }
  }
  return program;
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
