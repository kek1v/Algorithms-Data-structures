#include<iostream>
#include<vector>
#include<set>
#include<map>

typedef int32_t vertex_t;
typedef std::set<vertex_t> SetOfVertexes;

class Graph_type1{
public:
        uint64_t vertexes_count;
        std::set<std::pair<vertex_t,vertex_t>> Set_Of_Edges;

        Graph_type1(){
            vertexes_count = 0;
        }

        void input(){
            std::cin >> vertexes_count;
            Set_Of_Edges.clear();
                for(vertex_t i = 0; i < vertexes_count; i++){
                    vertex_t a, b;
                    std::cin >> a >> b;
                    Set_Of_Edges.insert(std::make_pair(a,b));
               }

        }

        void print(){
            std::cout << "vetrex count = "<< vertexes_count<<std::endl;
            for(auto edge: Set_Of_Edges){
                std::cout<<"(" << edge.first << ", " << edge.second << ")";
            }  
            std::cout<<"\n";
        }
};


int main(){
    Graph_type1 g1;
    g1.input();
    g1.print();

    return 0;
}

