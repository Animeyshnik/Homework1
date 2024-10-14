#include "Sorting.h"

void sortComplexNumbers(std::vector<Complex>& numbers) {
    bool swapped;
    for (size_t i = 0; i < numbers.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < numbers.size() - i - 1; j++) {
            if (numbers[j].abs() > numbers[j + 1].abs()) {
                std::swap(numbers[j], numbers[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
