#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char * input = "aabcccddfffffeghiiij";
    int size = strlen(input);

    int count = 1;
    char prev_char = input[0];
    for(int i = 1; i< size; i++) {
        int curr_char = input[i];
        if(curr_char == prev_char) {
            count++;
            continue;
        }
        printf("%c%d", prev_char, count);
        prev_char = curr_char;
        count=1;
    }
    printf("%c%d", prev_char, count);
    return 0;
}