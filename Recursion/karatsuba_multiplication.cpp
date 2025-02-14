#include <iostream>

// код сгенерен gemeni 2.0 flash и доработан
//код работает исправно, но если ввести числа слишком большие, то возможно переполнение

// я думаю стоит напомнить себе что асимптотика умножения Карацубы O(n^log2(3)) = O(n^1.585) а обычного умножения O(n^2)

// Функция для вычисления длины числа
int get_length(uint64_t n) {
    int length = 0;
    if (n == 0) {
        return 1;
    }
    while (n > 0) {
        n /= 10;
        length++;
    }
    return length;
}

// Функция для возведения в степень 10
uint64_t power_of_10(int n) {
    uint64_t result = 1;
    for (int i = 0; i < n; i++) {
        result *= 10;
    }
    return result;
}

// Функция для умножения Карацубы
uint64_t karatsuba(uint64_t x, uint64_t y) {
    // Базовый случай: если числа достаточно маленькие, умножаем их напрямую
    if (x < 10 || y < 10) {
        return x * y;
    }

    // 1. Вычисляем длину чисел
    int n = std::max(get_length(x), get_length(y));
    int half_n = (n + 1) / 2;

    // 2. Разбиваем числа на две половины
    uint64_t a = x / power_of_10(half_n);
    uint64_t b = x % power_of_10(half_n);
    uint64_t c = y / power_of_10(half_n);
    uint64_t d = y % power_of_10(half_n);

    // 3. Рекурсивно вычисляем произведения
    uint64_t ac = karatsuba(a, c);
    uint64_t bd = karatsuba(b, d);
    uint64_t ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

    // 4. Собираем результат
    uint64_t result = ac * power_of_10(2 * half_n) + ad_plus_bc * power_of_10(half_n) + bd;
    return result;
}

int main() {
    uint64_t x,y = 0;

    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;

    uint64_t product = karatsuba(x, y);
    std::cout << "Произведение " << x << " и " << y << " равно " << product << std::endl;
    return 0;
}