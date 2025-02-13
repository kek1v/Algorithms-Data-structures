#include<iostream>

const int MAX_BINARTY_DIGITS = 100;

void generate_binNumbers(int digits_left_to_generate){
    static int digits_combination[MAX_BINARTY_DIGITS];
    static int top = 0;
    
    if(digits_left_to_generate == 0){
        for(int i = 0; i < top; i++)
            std::cout << digits_combination[i];
        std::cout << std::endl;
    }else{// recursive case
        digits_combination[top++] = 0; // try 0
        generate_binNumbers(digits_left_to_generate - 1);// recursive call to generate the rest of the digits
        top--;

        digits_combination[top++] = 1; // try 1
        generate_binNumbers(digits_left_to_generate - 1);
        top--;
    }
}
int main() {
    int n;
    std::cout << "Enter the number of binary digits: ";
    std::cin >> n;

    generate_binNumbers(n);
    return 0;
}