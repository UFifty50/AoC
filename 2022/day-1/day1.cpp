#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ranges>


int main() {
    std::ifstream input("input.txt");
    std::vector<int> calVec;
    std::string tmp;
    int cals = 0;
    
    while (std::getline(input, tmp)) {
        if (tmp == "") {
            calVec.push_back(cals);
            cals = 0;
        } else cals += stoi(tmp);
    }

    std::ranges::sort(calVec, std::greater<>());

    std::cout << calVec[0] + calVec[1] + calVec[2] << std::endl;
}
