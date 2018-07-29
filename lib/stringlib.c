#include "../include/stringlib.h"


int string_cmp(char *str1, char *str2) {
    int i = 0;
    while(str1[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
        else i++;
    }
    return 0;     
}

int string_length(char* str) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
}

void string_copy(char *dest, char *src) {
    int index = 0;
    
    while((dest[index] = src[index]) != '\0') {
        index++;
    }

}