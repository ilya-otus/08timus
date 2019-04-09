#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    size_t commandsCount = 0;
    std::cin >> commandsCount;
    if (commandsCount <= 0) {
        return -1;
    }
    std::vector<std::string> commands;
    commands.resize(commandsCount);
    for (size_t i = 0; i < commandsCount; ++i) {
        std::cin >> commands[i];
    }
    std::vector<std::string> result;
    for (const auto &command : commands) {
        if (std::find(result.begin(), result.end(), command) == result.end()) {
            if (std::count(commands.begin(), commands.end(), command) > 1) {
                result.emplace_back(command);
            }
        }
    }
    for (const auto &r : result) {
        std::cout << r << std::endl;
    }
    return 0;
}
