#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>


bool isLetter(char l) {
    return (l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z');
}

void part1() {
    std::ifstream file("input.txt");
    std::string line;
    std::map<int, std::vector<int>> crates;

    while (std::getline(file, line)) {
        char on, tw, th, fo, fi, si, se, ei, ni;
        sscanf(line.c_str(), "[%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]", &on, &tw, &th, &fo, &fi, &si, &se, &ei, &ni);
        std::cout << on << " " << tw << " " << th << " " << fo <<  " " << fi <<  " " << si <<  " " << se <<  " " << ei <<  " " << ni << std::endl;
    }
}

int main() {
    part1();
}
