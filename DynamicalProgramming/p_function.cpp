#include<iostream>
#include<vector>
#include<string>

/*

    Алгоритм Кнутта Мориса Пратта
    Его смысл в том что бы быстро найти количество подстрок в строке
    путем определения суфикса который совпадает с префиксом

    к примеру подстрока "a b a c a b a"
                         0 0 1 0 1 2 3 - сумма совпадений префиксов равна 7 (значит тогда когда мы найдем подстроку в строке самым высоким значением будет 7)

    и строка "a c c a b a c b | a b c a b a | c a b a"
              1 0 0 1 2 3 4 0 | 1 2 3 4 5 7 | -> в этом случае сумма совпадений префиксов равна 7
    эта сумма равна сумме префиксов подстроки значит это и есть подстрока

    там где наша функция достигает семерки - везде будет подстрока

*/

std::vector<int> prefix_function_kmp(std::string s){
    int n = s.length();
    std::vector<int> pi(n, 0);

    for(int i = 1;i < n; ++i){
        int k = pi[i - 1]; // берем значение предыдущего элемента

        // пока к не равно 0 и символы не равны 
        // мы проверяем совпадение префикса и суффикса
        // если они не равны то мы уменьшаем значение к для того чтобы проверить совпадение  
        while(k > 0 && s[i] != s[k]){
            k = pi[k - 1];
        }

        if(s[i] == s[k])
            ++k;
        
        pi[i] = k;
    }

    return pi;
}

int main(){

    std::string line;
    getline(std::cin, line);
    std::string tmp;
    getline(std::cin, tmp);

    std::string summary = tmp + "#" + line;
    std::vector<int> pi = prefix_function_kmp(summary);

    int counter = 0;
    for(auto x: pi){
        if(x == tmp.size()){
            counter++;
        }
    }
    std::cout<< " Number of substrings: " << counter << std::endl;

    return 0;
}
