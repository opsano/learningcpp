#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
    ofstream out("out.txt");
    out << "Hello World";
    out.close();
    return 0;
}
