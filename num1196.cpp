#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    size_t prepodDatesCount = 0;
    std::cin >> prepodDatesCount;
    if (prepodDatesCount <= 0) {
        return -1;
    }
    std::vector<int> prepodDates;
    prepodDates.resize(prepodDatesCount);
    for (size_t i = 0; i < prepodDatesCount; ++i) {
        int prepodDate;
        std::cin >> prepodDate;
        prepodDates[i] = prepodDate;
    }
    size_t studentDatesCount = 0;
    std::cin >> studentDatesCount;
    if (studentDatesCount <= 0) {
        return -1;
    }
    int count = 0;
    for (size_t i = 0; i < studentDatesCount; ++i) {
        int studentDate;
        std::cin >> studentDate;
        if (studentDate >= prepodDates.front() &&
            studentDate <= prepodDates.back() &&
            std::binary_search(prepodDates.begin(), prepodDates.end(), studentDate)) {
            ++count;
        }
    }
    std::cout << count << std::endl;
    return 0;
}
