#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "todo.h"

int main() {
    std::cout << "Hello in your TO DO list!" << std::endl;
    // Variable declaration
    int choice {0};
    while (choice != 6) {

        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - print your list" << std::endl;
        std::cout << "2 - create your list" << std::endl;
        std::cout << "3 - update your list" << std::endl;
        std::cout << "4 - delete your list" << std::endl;
        std::cout << "5 - show your lists" << std::endl;
        std::cout << "6 - exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {

                int rows {0};

                std::string read_file;
                std::cout << "Your filename: ";
                std::cin >> read_file;

                std::ifstream file(read_file + ".todo");

                if (!file) {
                    std::cout << "File not found!" << std::endl;
                    break;
                }
                std::cout << "======= YOUR FILE ======" << std::endl;
                std::string line;
                std::vector<std::string> lista;
                while (std::getline(file, line)) {
                    lista.push_back(line);
                }

                for (size_t i = 0; i < lista.size(); i++) {
                    std::cout << i + 1 << ". " << lista[i] << std::endl;
                }

                std::cout << "======= END FILE =======" << std::endl;

                break;
            }
            case 2: {
                std::string create_file;
                std::cout << "Your filename: ";
                std::cin >> create_file;
                createList(create_file + ".todo");
                break;
            }
            case 3: {
                std::string update_file;
                std::string text;

                std::cout << "Your filename: ";
                std::cin >> update_file;

                std::cout << "Your text: ";
                std::cin.ignore();
                std::getline(std::cin, text);

                addToList(update_file + ".todo", text);
                break;
            }
            case 4: {
                std::string delete_file;
                std::cout << "Your filename: ";
                std::cin >> delete_file;
                const bool status = DeleteList(delete_file + ".todo");
                if (status) {
                    std::cout << "Removed successfully" << std::endl;
                } else {
                    std::cout << "Removed unsuccessfully" << std::endl;
                }
                break;
            }
            case 5: {
                std::system("find . -name \"*.todo\"");
                break;
            }
        }
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}