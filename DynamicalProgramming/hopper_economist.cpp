#include<iostream>

/*
    ЗАДАЧА ЗАКЛЮЧАЕТСЯ В СЛЕДУЮЩЕМ:
    Есть n точек, где n >= 1 и n <= 100.
    Каждая точка имеет свою стоимость.
    Нужно найти минимальную стоимость, чтобы добраться из точки 1 в точку n.
    При этом можно пропускать точки, но нельзя пропускать две подряд.
    Например, если n = 4 и стоимость точек [1, 2, 3, 4] = [1, 100, 1, 1],
    то минимальная стоимость будет 3, так как мы можем пропустить вторую точку и дойти до 4-ой точки.
*/

// решение через динамическое программирование выгоднее чем решение через рекурсию
// потому что такое решение больше оптимизировано и более понятно
// мы четко видим математическую формулу нашей задачи
int min_cost(int n, int price[]){

    int cost[n+1];
    cost[1] = price[1];
    cost[2] = price[1] + price[2];

    for(int i = 3; i <= n; i++){
        cost[i] = price[i] + std::min(cost[i-1], cost[i-2]); // math formula of our task
    }

    // print path
    std::cout<<"Min cost path(reversed): [";
    int current = n;
    std::cout<<current<<" ";
    while(current > 1){
        if(cost[current-1] < cost[current-2])
            current = current - 1;
        else if(cost[current-1] > cost[current-2])
            current = current - 2;
        else
            throw -1; // if we have two ways with the same cost
        std::cout<<current<<" ";
    }
    std::cout<<"]\n";


    return cost[n];
}

int main(){
    int n;
    std::cout<<"Hopper economist wants to go from point 1 to point n.\nEnter n: "<<std::endl;
    std::cin>>n;

    if(n < 1 || n > 100){
        std::cout<<"Invalid input"<<std::endl;
        return -1;
    }

    int price[n];
    for(int i = 1; i <= n; i++){
        std::cout<<"Enter price for point "<<i<<": ";
        std::cin>>price[i];
    }

    std::cout<<"Minimum cost to go from point 1 to point n is: "<<min_cost(n, price)<<std::endl;
    return 0;
}
