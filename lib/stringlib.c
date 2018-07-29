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

    dest[index] = '\0';

}

char* string_concat(char *str1, char *str2) {
    int length1 = string_length(str1);
    int length2 = string_length(str2);
    int n_length = length1 + length2;
    char *concat = (char*) calloc(n_length, sizeof(char));

    int i = 0;
    
    while((concat[i] = str1[i]) != '\0') {
        i++;
    }
    
    i = 0;
    
    while((concat[length1 + i] = str2[i]) != '\0') {
        i++;
    }

    concat[n_length] = '\0';

    return concat;
}
