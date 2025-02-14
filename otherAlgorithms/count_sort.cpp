#include<iostream>

void count_sort(int A[],int N){
    int F[10] = {0};//пусть наш диапазон чисел [0;9]
    for(int i = 0;i < N;++i)
        F[A[i]]++;//наши частоты
    int i = 0; 

    //перебираю всевозможные значения ключа! (их М штук)
    for(int x = 0;x < 10;++x){
        for(int k = 0;k < F[x];k++){
            A[i] = x;
            ++i;
        }
    }
}

void print_array(int A[],int N){    
    for(int i = 0;i<N-1;++i)
        std::cout<<A[i]<<"\t"; 
    std::cout<<"\n";
}


void generate_random_array(int A[],const int N,int M){    
    for(int i = 0;i < N;++i)
        A[i]=rand()%M;
}

int main(){
    const int N = 10;
    int A[N];
    generate_random_array(A,N,10);
    print_array(A,N);
    count_sort(A, N);
    print_array(A,N);
    return 0;
}
