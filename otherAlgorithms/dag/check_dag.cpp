#include<iostream>
#include<vector>
#include"graph_storages.hpp"

bool check_DAG(const Oriented_Graph *graph, vertex_t start, std::vector<bool> &used){
    used[start] = true; 
    auto neighbours_list = graph->sets_of_neighbours[start];

    //пытаемся построить цикл из соседей
    for(auto neighbour: neighbours_list){
        if(neighbour == start) continue;
        if(used[neighbour]) return false;
        
        bool is_DAG = check_DAG(graph, neighbour, used);
        if(not is_DAG) return false;
    }
    return true; // граф ацикличен
}

int main(){
    Oriented_Graph g;
    g.input();
    g.print();

    std::vector<bool> used_vertexes;
    used_vertexes.resize(g.vertexes_count,false);
    bool is_DAG = true;

    for(vertex_t v = 0; v < g.vertexes_count; v++){
        if(used_vertexes[v]) continue;
        if(not (is_DAG &= check_DAG(&g, v, used_vertexes))){
            is_DAG = false;
            break;
        }
    }

    if(is_DAG){
        std::cout<<"Граф ацикличен"<< std::endl;
    }else{
        std::cout<<"Граф цикличен"<< std::endl;
    }

    return 0;
}
