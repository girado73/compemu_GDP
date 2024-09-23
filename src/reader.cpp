#include "reader.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 * Erstelle ein Synonym fuer die Command Pairs
 */
using commands = std::pair<std::string, int>;

/**
 * Droppe in str alle zeichen nach delimiter
 *
 * @param str Der zu bearbeitende String
 * @param delimiter Der gewaehlte delimiter
 *
 * @return gibt den neuen String zurueck
 */
std::string dropAfter(std::string str, char delimiter) {
  size_t pos = str.find(delimiter);
  if (pos != std::string::npos) {
    return str.substr(0, pos);
  }
  return str;
}

/**
 * Loesche alle whitespaces nach dem letzten Zeichen
 *
 * @param str Der zu bearbeitende String
 *
 * @return gibt den neuen String zurueck
 */
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

/**
 * Loesche alle Nummern vor den Befehlen
 * Wir brauchen keine Nummern da wir den Index des Vectors benutzen
 *
 * @param input Der zu bearbeitende String
 *
 * @return gibt den neuen String zurueck
 */
std::string removeBeforeFirstSpace(std::string input) {

  // Überprüfen, ob der erste Buchstabe ein Großbuchstabe ist
  if (!input.empty() && std::isupper(input[0])) {
    return input; // Wenn ja, gib den ursprünglichen String zurück
  }

  size_t spacePos = input.find(' ');
  if (spacePos != std::string::npos) {
    return input.substr(spacePos + 1);
  }
  return input; // Wenn kein Leerzeichen gefunden wurde, gib den ursprŸnglichen
                // String zurŸck
}

/**
 * Ließt die gegebene Datei ein und speichert die Zeilen in einem Vector
 *
 * @param filename Name der Datei welche eingelesen werden soll
 * @return gibt den Eingelesenen Vector zurueck
 */
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
      // TODO das funktioniert so nicht, wir mÃ¼ssen alles vorm ersten
      // leerzeichen skippen
      lines.push_back(removeBeforeFirstSpace(trim));
    }
  }

  file.close();
  return lines;
}

/**
 * Parse den Stringvector in Vector<pair<string, int>>
 *
 * @param lines Einen Stringvector der Dateizeilen
 * @return einen Vector aus String Int Pairs
 */
std::vector<commands> linesToProgram(const std::vector<std::string> &lines) {
  std::vector<commands> program;
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
