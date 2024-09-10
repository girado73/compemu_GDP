#include <iostream>
#include <list>
#include <tuple>
#include <string>
#include "reader.h"

using commands = std::tuple<std::string, int>;
std::list<commands> commandlist;

void read() {
    // Adding tuples to the list
    commandlist.push_back(std::make_tuple("Hello", 3));
    commandlist.push_back(std::make_tuple("World", 2));
    commandlist.emplace_back("C++", 3);

    // Iterating through the list
    for (const auto& item : commandlist) {
        std::cout << "String: " << std::get<0>(item) 
                  << ", Int: " << std::get<1>(item) << std::endl;
    }

}
