#include<iostream>

struct node_t{
   int data;
   node_t* next;
};

void go_through(node_t *p){
    while(p!=nullptr){
        std::cout<<p->data<<std::endl;
        p = p->next;
    }
}

int main(){
    node_t* p_begin = new node_t;
    node_t *p = p_begin;

    for(int i = 0;i<5;i++){
        p->data = i+1;
        p->next = new node_t;
        p = p->next;
    }

    p->data = 0;
    p->next = nullptr; 
    go_through(p_begin);

    node_t* current = p_begin;
    while(current!=nullptr){
        node_t* next = current->next;
        delete current;
        current = next;
    }


    return 0;
}
