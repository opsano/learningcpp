#include "myVector.h"
#include <iostream>
#include <sstream>
#include <string>
int main(int argc, char* argv[])
{
    myVector v = myVector(1);
    std::cout << "Heap Vector Console\n";
    std::cout << "Commands:\n";
    std::cout << "  push <int>\n";
    std::cout << "  pop\n";
    std::cout << "  reserve <n>\n";
    std::cout << "  shrink_to_fit\n";
    std::cout << "  clear\n";
    std::cout << "  stats\n";
    std::cout << "  quit\n\n";

    std::string line;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        std::stringstream ss(line);
        std::string cmd;

        ss >> cmd;
        if (cmd == "push")
            {
                int value;
                ss >> value;
                v.push_back(value);
                
            }
        if (cmd == "pop")
            {
                v.pop_back();
                
            }
        if (cmd == "reserve")
            {
                size_t size;
                ss >> size;
                v.reserve(size);
                
            }
        if (cmd == "shrink_to_fit")
            {
                v.shrink_to_fit();
                
            }
        if (cmd == "clear")
            {
                v.clear();
            }
        if (cmd == "stats")
            {
                v.stats();
                continue;
            }
        if (cmd == "quit")
            {
                return 0;
            }
        v.iterate();
        v.stats();
    }
}