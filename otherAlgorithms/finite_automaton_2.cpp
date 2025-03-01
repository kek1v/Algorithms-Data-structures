#include<iostream>
#include<string>

enum AutomatonState {
    out_of_word = 0,
    in_word = 1
};

inline bool is_alpha(char symbol){
    return (symbol >= 'a' and symbol <= 'z') or 
           (symbol >= 'A' and symbol <= 'Z');
}

int main(){
    std::string s;
    std::getline(std::cin, s);
    s.push_back(' '); // если в конце строки не будет какого то "не символа" 
                      // то перехода на другое слово не произойдет и программа не подсчиатет помледнее слово\
                
    AutomatonState state = out_of_word;

    int word_len  = 0;
    for(int pos = 0; pos <= s.length();pos++){
        switch(state){
            case out_of_word: 
                if (is_alpha(s[pos])){
                    word_len = 1;
                    state = in_word;
                }else{
                    state = out_of_word;
                }
                break;
            case in_word:
                if (is_alpha(s[pos])){
                    word_len += 1;
                    state = in_word;
                }else{
                    std::cout<<"Word length: "<< word_len << "\n";
                    state = out_of_word;
                }
        }
    }
    return 0;
}