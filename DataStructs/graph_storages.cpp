#include<iostream>
#include<vector>
#include<set>
#include<map>

typedef int32_t vertex_t;
typedef std::set<vertex_t> SetOfVertexes;

class AbstractGraph{
public:
    uint64_t vertexes_count = 0;
    uint64_t edges_number = 0;
    virtual void input() = 0;
    virtual void print() = 0;

};

// через множество рёбер
class Graph_type1: public AbstractGraph{
public:
        std::set<std::pair<vertex_t,vertex_t>> Set_Of_Edges;

        void input(){
            std::cin >> vertexes_count;
            std::cin >> edges_number;
            Set_Of_Edges.clear();
                for(vertex_t i = 0; i < edges_number; i++){
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

// через матрицу смежности
class Graph_type2: public AbstractGraph{
public:
        std::vector<std::vector<bool>> matrix;

        void input(){
            std::cin >> vertexes_count;
            matrix.resize(vertexes_count);
            for(auto &line:matrix){
                line.resize(vertexes_count,false);
            }

            std::cin >> edges_number;
            for(vertex_t i = 0; i < edges_number; i++){
                vertex_t a, b;
                std::cin >> a >> b;
                matrix[a][b] = 1;
                matrix[b][a] = 1;
            }
        }

        void print(){
            std::cout << "vetrex count = "<< vertexes_count<<std::endl;

            for(vertex_t a = 0; a < vertexes_count; a++){
                for(vertex_t b = 0; b < vertexes_count; b++){
                    std::cout<< matrix[a][b] << " ";
                }  
                std::cout<<"\n";
            } 
        }
};

int main(){
    Graph_type2 g;
    g.input();
    g.print();

    return 0;
}