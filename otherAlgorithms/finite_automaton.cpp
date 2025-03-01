#include<iostream>
#include<string>

// goto - плохая штука, но в реализации алгоритма конечного автомата это норм

bool is_alpha(char symbol){
    return (symbol >= 'a' and symbol <= 'z') or 
           (symbol >= 'A' and symbol <= 'Z');
}

int main(){
    std::string s;
    std::getline(std::cin, s);
    s.push_back(" "); // если в конце строки не будет какого то "не символа" 
                      // то перехода на другое слово не произойдет и программа не подсчиатет помледнее слово
                      
    int word_len  = 0;
    int pos = 0;
out_of_word: // <-- метки
    if(pos >= s.length()) goto the_end;
    if (is_alpha(s[pos])){
        pos++;
        word_len = 1;
        goto in_word;
    }else{
        pos++;
        goto out_of_word;
    }

in_word:
    if(pos >= s.length()) goto the_end;
    if (is_alpha(s[pos])){
        pos++;
        word_len += 1;
        goto in_word;
    }else{
        pos++;
        std::cout<<"Word length: "<< word_len << "\n";
        goto out_of_word;
    }
the_end:
    return 0;
}