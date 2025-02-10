#include<iostream>

// вычипсления фибоначи через рекурсию это не оптимально
// так как сложность такого вычисления O(fib(n))
uint64_t fib_recursive(int n){
    if(n <= 1){// base case
        return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// in dynamic programming style
uint64_t fib_dynamic(int n){
    uint64_t fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2]; // our formula
    }
    return fib[n];
}

int main(){

    for(int n = 0; n < 60;n++){
        std::cout<< n <<"\t"<< fib_dynamic(n) << std::endl;
    }

    return 0;
}