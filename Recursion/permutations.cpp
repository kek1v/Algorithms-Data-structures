#include<iostream>

//static buffer is bad to use in recursive functions
// permutations - перестановки (все возможные варианты)

// This function generates all permutations of the numbers from 0 to number - 1
void permutations(int16_t buffer[], int16_t current, int16_t number, bool used[]){
    if(current == number){ // base case
        for(int i = 0; i < number; i++)
            std::cout << buffer[i];
        std::cout << std::endl;
    }else{ // recursive case
        for(int16_t variant = 0; variant < number; variant++){
            if(not used[variant]){// cutting the recursion tree
                buffer[current] = variant;// try variant
                used[variant] = true;// mark as used
                permutations(buffer, current + 1, number, used);// 
                used[variant] = false;
            }
        }
    }
}


int main() {
    uint16_t n;
    std::cout << "Enter lenght to generate all permutations: ";
    std::cin >> n;

    if(n  > 20){ // 20! = 2 432 902 008 176 640 000
        std::cout << "The number is too big, try a number less than 20" << std::endl;
        return -1;
    }else if(n < 1){
        std::cout << "The number is too small, try a number greater than 0" << std::endl;
        return -1;
    }

    int16_t buffer[n];
    bool used[n] = {false}; // all elements it's a zeros!
    permutations(buffer, 0, n, used);
    return 0;
}