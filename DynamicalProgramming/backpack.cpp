#include<iostream>
#include<vector>
#include<map>
#include <algorithm> 

// represented - представляется

double max_backpack_value(std::vector<std::pair<int,double>> treasures,
                            int backpack_capacity){
    std::vector<std::vector<int>> F; // 2d array of answers

    // make a 2D array K of size (treasures.size()+1)x(backpack_capacity+1)
    F.resize(treasures.size()+1);
    for(int i=0;i<=treasures.size();i++)
        F[i].resize(backpack_capacity+1);

    // fill the array with answers
    for(int i=0;i<=treasures.size();i++) // i - number of treasures
        F[i][0] = 0;
    for(int j=0;j<=backpack_capacity;j++)// j - backpack capacity
        F[0][j] = 0;

    // recursive case
    for(int k = 1; k <= treasures.size(); k++){
        for(int j = 1; j <= backpack_capacity; j++){ 
            if(treasures[k-1].first <= j){// if we can put the k-th treasure in the backpack
                int weight = treasures[k-1].first; // weight of the k-th treasure
                double value = treasures[k-1].second; // value of the k-th treasure
                F[k][j] = std::max(F[k-1][j], static_cast<int>(F[k-1][j-weight] + value)); // max не может принимать разные типы данных, поэтому приводим к int
                // we have two options:
                // 1. we don't put the k-th treasure in the backpack
                // 2. we put the k-th treasure in the backpack

            }else{// if we can't put the k-th treasure in the backpack
                F[k][j] = F[k-1][j]; // we don't put the k-th treasure in the backpack
            }
        }
    }
    
    
    return F[treasures.size()][backpack_capacity];
}

int main(){
    int treasures_count,backpack_capacity;
    std::cout<<"Enter number of treasures: ";
    std::cin>>treasures_count;

    // our treasures are represented as a pair of weight and value
    std::vector<std::pair<int,double>> treasures;
    int weight;
    double value;
    for(int i=0;i<treasures_count;i++){
        std::cout<<"Enter weight and value of item "<<i+1<<": ";
        std::cin>>weight;
        std::cin>>value;
        treasures.push_back(std::make_pair(weight,value));
    }

    std::cout<<"Enter the capacity of the backpack: ";
    std::cin>>backpack_capacity;

    std::cout<<"Max sum of values of treasures that can be put in the backpack: "<<max_backpack_value(treasures,backpack_capacity)<<std::endl;


    return 0;
}