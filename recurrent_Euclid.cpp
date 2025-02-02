#include<iostream>

int gcd(int a, int b){// наибольший общий делитель(НОД)
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){

    int a,b;
    std::cin>>a>>b;
    std::cout<<gcd(a,b)<<"\n";

    return 0;
}