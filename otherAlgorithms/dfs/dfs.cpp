#include<iostream>
#include<vector>
#include"graph_storages.hpp"

void just_dfs(const Graph_type3 *graph, vertex_t start, std::vector<bool> used){
    used[start] = true; 
    auto neighbours_list = graph->sets_of_neighbours[start];

    std::cout << start << " ";
    for(auto neighbour: neighbours_list){
        if(not used[neighbour]){
            just_dfs(graph, neighbour, used);
        }
    }
    std::cout << std::endl;
}

int main(){
    Graph_type3 g;
    g.input();
    g.print();

    std::cout<< "Enter start vertex: ";
    vertex_t start;
    std::cin >> start;

    std::vector<bool> used_vertexes;
    used_vertexes.resize(g.vertexes_count,false);
    just_dfs(&g, start, used_vertexes);

    return 0;
}
