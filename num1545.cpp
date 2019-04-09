#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    size_t hierogliphCount = 0;
    std::cin >> hierogliphCount;
    if (hierogliphCount <= 0) {
        return -1;
    }
    std::vector<std::string> hierogliphs;
    hierogliphs.resize(hierogliphCount);
    for (size_t i = 0; i < hierogliphCount; ++i) {
        std::cin >> hierogliphs[i];
    }
    char firstSymbol;
    std::cin >> firstSymbol;
    std::vector<std::string> result;
    std::copy_if(hierogliphs.begin(),
                 hierogliphs.end(),
                 std::back_inserter(result),
                 [firstSymbol] (const std::string &h) { return h.at(0) == firstSymbol; });
    for (const auto &r : result) {
        std::cout << r << std::endl;
    }
    return 0;
}
