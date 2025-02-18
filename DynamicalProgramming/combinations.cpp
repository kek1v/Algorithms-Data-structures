#include<iostream>
#include<vector>

uint64_t combinations_recursive(int i,int j){
    if(i == 1 or j == 1){// base case
        return 1;
    }
    return combinations_recursive(i-1,j) + combinations_recursive(i,j-1);
}

// c style
uint64_t combinations_dynamic(int n,int m){
    uint64_t result = 0;
    uint64_t **K = new uint64_t*[n + 1];

    // memory allocation for K function
    for(int i = 0; i <= n; i++)
        K[i] = new uint64_t[m + 1];

    // base cases
    for(int i = 1; i <= n; i++)
        K[i][1] = 1;
    for(int j = 1; j <= m; j++)
        K[1][j] = 1;

    // recursive case
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++)
            K[i][j] = K[i - 1][j] + K[i][j - 1]; // our formula
    }
    
    result = K[n][m];
    for(int i = 0; i <= n; i++)
        delete K[i];
    delete[] K;
    return result;
}

// c++ style
uint64_t combinations_dynamic2(uint16_t n, uint16_t m){
    std::vector<std::vector<uint64_t>> K;

    // memory allocation for K function
    // resize - устанавливает размер вектора
    K.resize(n + 1);
    for(int i = 0; i <= n; i++)
        K[i].resize(m + 1);

    // base cases
    for(int i = 1; i <= n; i++)
        K[i][1] = 1;
    for(int j = 1; j <= m; j++)
        K[1][j] = 1;

    // recursive case
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++)
            K[i][j] = K[i - 1][j] + K[i][j - 1]; // our formula
    }
    
    return K[n][m];
}

int main(){
    // программе нужно заранее знать количество строк
    const uint16_t N = 500;
    const uint16_t M = 1000;
    std::cout<<"Number of ways to reach the destination is: "<<combinations_dynamic2(N,M)<<std::endl;

    return 0;
}
