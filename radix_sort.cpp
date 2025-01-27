
#include<iostream>

void radix_sort(int A[],int N){
    int *a0 = new int[N];
    int *a1 = new int[N];

    for(int radix = 0; radix < 32; ++radix){// в обычном инте 32 бита(обычно) и мы проходим по каждому биту

        int a0_size = 0;
        int a1_size = 0;

        for (int i = 0; i < N; ++i) {
            if ((A[i] & (1 << radix)) == 0) // вычленяем нужный бит
                a0[a0_size++] = A[i];// если бит равен 0, то кладем в массив a0
            else
                a1[a1_size++] = A[i]; 
        }  
       
        for (int i = 0; i < a0_size; ++i)// копируем обратно в массив A
            A[i] = a0[i];
        for (int i = 0; i < a1_size; ++i)
            A[a0_size + i] = a1[i];
    }

    delete[] a0;// чистим чистим
    delete[] a1;
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
    const int N = 1000;
    int A[N];

    generate_random_array(A,N,100); 
    print_array(A,N);
    radix_sort(A, N);
    print_array(A,N);

    return 0;
}