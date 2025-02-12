#include<iostream>

uint64_t (int n){
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
        std::cout<< n <<"\t"<< (n) << std::endl;
    }

    return 0;
}
