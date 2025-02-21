#include <cstring>
#include <cstdio>
#include <cstdlib>

// ПОЧЕМУ НЕ СТОИТ ИСПОЛЬЗОВАТЬ СИ СТРОКИ:

int main(){

    const char* s = "Hello, world!";
    printf("%s\n", s);
    printf("strlen(s) = %ld\n", strlen(s));

    int times_to_repeat;
    scanf("%d", &times_to_repeat);
    // The buffer_lenght is calculated as the length of the string s multiplied by the number of times we want to repeat it
    // plus one to account for the null terminator
    size_t buffer_lenght = strlen(s) * times_to_repeat + 1;  // buffer_lenght in bytes
    char* buffer = (char*)malloc(buffer_lenght * sizeof(char)); // buffer in bytes
    buffer[0] = '\0'; // Null terminator
    printf("buffer_lenght = %ld\n", buffer_lenght); // potential buffer overflow

    strcat(buffer, s); // Copy the string s to the buffer
    for(int i = 1; i < times_to_repeat; i++){
        // в это моменте strcat каждый раз начинает считать длину строки заново
        // поэтому асимптотика этого алгоритма O(n^2)
        strcat(buffer, s); // Concatenate the string s to the buffer
    }

    free(buffer);
    return 0;
}