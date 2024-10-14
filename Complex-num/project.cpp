#include <iostream>
#include <vector>
#include "Complex.h"
#include "Sorting.h"

int main() {
    std::vector<Complex> numbers = {
        Complex(3, 4),
        Complex(1, 2),
        Complex(0, 1),
        Complex(2, 3),
        Complex(5, 1)
    };

    std::cout << "Complex numbers before sorting:" << std::endl;
    for (const auto& num : numbers) {
        num.display();
    }

    sortComplexNumbers(numbers);

    std::cout << "\nComplex numbers after sorting by magnitude:" << std::endl;
    for (const auto& num : numbers) {
        num.display();
    }

    return 0;
}
