#include<iostream>

int left_bound(int A[],const int N,int x){//левая граница искомого x
    int left = -1;//A[left] < x
    int right = N;//A[right] >= x
     

    while(right - left > 1){ 
        int middle = (left + right) / 2;
        if(A[middle] < x)
            left = middle;
        else
            right = middle;

    }
    return left;
}

int find(int A[],const int N,int x){//O(log2n) асимптотика
    int left = left_bound(A,N,x);
    int potential_first_index_of_x_in_A = left + 1;
    if(potential_first_index_of_x_in_A < N 
        || A[potential_first_index_of_x_in_A]==x){
        return potential_first_index_of_x_in_A;
    }
    return -1;//x not found
}

int main(){
    const int N = 10;
    int A[] = {1,3,5,6,7,8,9,10};
    int x = 9;

    std::cout<<"left boundary of x: "<<left_bound(A,N,x)<<std::endl;

}


