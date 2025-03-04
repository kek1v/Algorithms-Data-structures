#include <iostream>
#include <string>
#include <vector>

const uint32_t P = 257; // простое число для хэширования

// Функция для вычисления хэша строки
uint32_t hash(const std::string& s, int start, int length) {
    uint32_t sum = 0;
    uint32_t factor = 1;
    
    for(int i = start + length - 1; i >= start; i--) {
        sum += s[i] * factor;
        factor *= P;
    }
    return sum;
}

// Функция для поиска подстроки алгоритмом Рабина-Карпа
std::vector<int> rabin_karp(const std::string& text, const std::string& pattern) {
    std::vector<int> occurrences;
    
    if (pattern.empty() || text.empty() || pattern.length() > text.length()) {
        return occurrences;
    }
    
    int M = pattern.length(); // длина паттерна
    int N = text.length();    // длина текста
    
    // Вычисляем хэш паттерна
    uint32_t pattern_hash = hash(pattern, 0, M);
    
    // Вычисляем хэш первого окна в тексте
    uint32_t text_hash = hash(text, 0, M);
    
    // Предварительно вычисляем степень P для эффективного пересчета хэша
    uint32_t pow_p = 1;
    for (int i = 0; i < M - 1; i++) {
        pow_p *= P;
    }
    
    // Проход по тексту
    for (int i = 0; i <= N - M; i++) {
        // Сравниваем хэши
        if (pattern_hash == text_hash) {
            // Дополнительная проверка для исключения коллизий
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                occurrences.push_back(i);
            }
        }
        
        // Вычисляем хэш следующего окна
        if (i < N - M) {
            // Удаляем первый символ старого окна
            text_hash = text_hash - text[i] * pow_p;
            // Сдвигаем окно
            text_hash = text_hash * P + text[i + M];
        }
    }
    
    return occurrences;
}

int main() {
    std::string text, pattern;
    std::getline(std::cin, text);
    std::getline(std::cin, pattern);
    
    std::vector<int> result = rabin_karp(text, pattern);
    
    if (result.empty()) {
        std::cout << "Подстрока не найдена" << std::endl;
    } else {
        std::cout << "Подстрока найдена на позициях: ";
        for (int pos : result) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
