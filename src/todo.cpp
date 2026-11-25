#include <fstream>
#include <string>
#include "todo.h"
#include <vector>

void createList(const std::string& a){
    std::ofstream file(a);
    file << "To-Do list: " << a + ".todo" << std::endl;
}

void addToList(const std::string& a, const std::string& b) {
    std::ifstream file(a);
    std::string line;
    std::vector<std::string> lista;
    while (std::getline(file, line)) {
        lista.push_back(line);
    }

    std::ofstream fileSave(a);

    lista.push_back(b);

    for (const std::string i : lista) {
        fileSave << i << std::endl;
    }
}

bool DeleteList(const std::string& a) {
    if (std::remove(a.c_str()) == 0) {
        return true;
    } else {
        return false;
    }
}