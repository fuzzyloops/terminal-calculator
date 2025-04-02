#include "functions.hpp"
#include "functions.cpp"

bool finished = false;
std::string command;

int main()
{
    while(!finished)
    {
        std::cout << "\n";
        std::cout << "What would you like to calculate?" << std::endl;
        std::cout << "\n";
        std::cin >> command;
        std::cout << "\n";
        readCommand(command);
        std::cout << "\n";
    }
}