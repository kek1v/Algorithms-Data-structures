#include<iostream>
/*
    i - начальный стержень
    k - на какой перекладываем
    n - количество дисков
*/
void hanoi_towers(int i,int k,int n){
    if(n == 1)
        std::cout<<"Move disk 1 from "<<i<<" to "<<k<<"\n";
    else{
        int tmp = 6 - i - k;// находим стержень, который не участвует в перекладывании
        hanoi_towers(i, tmp, n - 1);
        std::cout<<"Move disk "<<n<<" from "<<i<<" to "<<k<<"\n";
        hanoi_towers(tmp, k, n - 1);
    }
}
int main(){
    hanoi_towers(1,2,4);
    return 0;
}