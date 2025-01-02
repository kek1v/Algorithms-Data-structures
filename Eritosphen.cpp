#include<iostream>

int main(){
    int n;
    std::cin>>n;
    bool sieve[n+1];
    
    for(int i = 2;i<=n;++i){
         sieve[i] = true;//заполняем наше решето до предела 
                         //не вклчюая 0 и 1 так как они не простые
    }
    int x=2;
    while(x*x <=n){//found new prime
        if(sieve[x]){
            for(int y = x*x;y<=n;y+=x){
                sieve[y] = false; //composite
            }
        }
        x += 1;
    }

    for(int i = 2;i<n+1;++i){
        if(sieve[i]){
            std::cout<<i<<'\t';
        }
    }

    std::cout<<'\n';
    return 0;

