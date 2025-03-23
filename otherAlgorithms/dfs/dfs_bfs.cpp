#include<iostream>
#include<vector>
#include"graph_storages.hpp"
#include<deque>

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


void just_bfs(const Graph_type3 *graph, vertex_t start, std::vector<bool> fired){
    std::deque<vertex_t> firing_list;
    firing_list.push_back(start);
    fired[start] = true;

    std::cout << start << std::endl;
    while(not fired.empty()){
        vertex_t current = firing_list.front();
        firing_list.pop_front();

        auto neighbours_list = graph->sets_of_neighbours[current];
        for(auto neighbour: neighbours_list){
            if(not fired[neighbour]){
                fired[neighbour] = true;
                firing_list.push_back(neighbour);
            }
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
    just_bfs(&g, start, used_vertexes);

    return 0;
}
