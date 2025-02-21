#include<iostream>
#include<string>

// Решение задачи "Склеивание строк"
// Время работы: O(n) в отличии от O(n^2) в случае с простым сложением строк в си

int main(){
    std::string hello = "Hello, world! ";
    std::string result;
    std::cout<< hello << std::endl;

    int times_to_concatenate;
    std::cin >> times_to_concatenate;
    for(int i = 0; i < times_to_concatenate; i++){
        result += hello;
    } 

    return 0;
}
