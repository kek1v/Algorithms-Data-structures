#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Функция для вычисления значения многочлена при заданном x
double evaluate_polynomial(const std::vector<int>& coefficients, int x) {
    double result = 0;
    int n = coefficients.size();
    for (int i = 0; i < n; ++i) {
        result += coefficients[i] * std::pow(x, n - 1 - i);
    }
    return result;
}

// Функция для нахождения целых корней с помощью делителей свободного члена
std::vector<int> find_integer_roots(const std::vector<int>& coefficients) {
    std::vector<int> roots;
    int constant_term = coefficients.back();

    // Перебираем делители свободного члена
    for (int p = -std::abs(constant_term); p <= std::abs(constant_term); ++p) {
        if (p != 0 && constant_term % p == 0) {
            if (evaluate_polynomial(coefficients, p) == 0) {
                roots.push_back(p);
            }
        }
    }
    return roots;
}

int main() {
    int degree;
    std::cout << "Введите степень многочлена: ";
    std::cin >> degree;

    std::vector<int> coefficients(degree + 1);
    std::cout << "Введите коэффициенты многочлена от старшего к младшему: \n";
    for (int i = 0; i <= degree; ++i) {
        std::cin >> coefficients[i];
    }

    std::vector<int> roots = find_integer_roots(coefficients);

    if (!roots.empty()) {
        std::cout << "Целые корни многочлена:\n";
        for (int root : roots) {
            std::cout << root << "\n";
        }
    } else {
        std::cout << "Нет целых корней для данного многочлена.\n";
    }

    return 0;
}

