#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <functional>
#include <limits>

const auto lastNamesInString = 3;

int getStringsCount() {
    int result;
    std::cin >> result;
    std::string ignoreString;
    std::getline(std::cin, ignoreString);
    return result;
}

std::vector<std::vector<std::string>> getStrings(int stringsCount) {
    std::vector<std::vector<std::string>> resultStrings;
    for (auto i = 0; i < stringsCount; ++i) {
        std::vector<std::string> currentStrings;
        for (auto j = 0; j < lastNamesInString; ++j) {
            std::string lastName;
            std::cin >> lastName;
            currentStrings.emplace_back(lastName);
        }
        resultStrings.emplace_back(currentStrings);
        std::string ignoreString;
        std::getline(std::cin, ignoreString);
    }
    return resultStrings;
}

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    const std::string rootItem = "Isenbaev";
    std::map<std::string, int> result{};
    auto relationStringsCount = getStringsCount();
    if (relationStringsCount <= 0) {
        return -1;
    }
    std::vector<std::vector<std::string>> relationStrings = getStrings(relationStringsCount);
    std::unordered_map<std::string, std::vector<std::string>> relations;
    for (const auto &relation: relationStrings) {
        for (const auto &name: relation) {
            auto found = relations.find(name);
            auto predicate = [&name](const std::string &deps) {
                return deps != name;
            };
            if (found == relations.end()) {
                std::vector<std::string> dependencies(relation.size() - 1);
                std::copy_if(relation.begin(), relation.end(), dependencies.begin(), predicate);
                relations[name] = dependencies;
            } else {
                std::copy_if(relation.begin(), relation.end(), std::back_inserter(found->second), predicate);
            }
        }
    }
    std::function<void(const std::string, int)> relationsToMap = [&relations, &relationsToMap, &result] (const std::string &name, int level = 0) -> void {
        auto found = result.find(name);
        if (found == result.end() || found->second > level) {
            result[name] = level;
        } else if (found != result.end()) {
            return;
        }
        for (const auto &dependency : relations[name]) {
            relationsToMap(dependency, level + 1);
        }
    };
    if (relations.find(rootItem) != relations.end()) {
        relationsToMap(rootItem, 0);
    }
    for (const auto &item : relations) {
        if (auto found = result.find(item.first); found == result.end()) {
            result[item.first] = -1;
        }
    }
    for (const auto &item : result) {
        std::cout << item.first << " ";
        if (item.second == -1) {
            std::cout << "undefined" << std::endl;
            continue;
        }
        std::cout << item.second << std::endl;
    }
    return 0;
}
