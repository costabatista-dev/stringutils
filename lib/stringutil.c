#include<stringutil.h>


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


int string_length(char *str) {
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


char* string_init_cut(char *str, int index) {
    int length = string_length(str);
    char* new_str = substring_at_be(str, index, length - 1);
    return new_str;
}


char* string_end_cut(char *src, int index) {
     char* new_str = substring_at_be(src, 0, index);
     new_str[index] = '\0';
     return new_str;
}


char* substring_at_be(char *str, int begin, int end) {
    int length = end - begin + 1;
    char *sub = (char*) calloc(length, sizeof(char));

    int i = 0;
    while(i < length) {
        sub[i] = str[i+begin];
        i++;
    }
    sub[i] = '\0';
    
    return sub;
}


char* string_nconcat(char *dest, char *src, int n) {
    int length = string_length(dest) + n;
    char *new_str = (char *) calloc(length, sizeof(char));
    int i = 0;

    while((new_str[i] = dest[i]) != '\0') {
        i++;
    }
    int j = i;
    for(i = 0; i < n; i++) {
        new_str[j+i] = src[i];
    }
    new_str[j+i] = '\0';

    return new_str;
}


void string_ncopy(char *dest, char *src, int n) {
    int i;

    for(i = 0; i < n; i++) {
        dest[i] = src[i];
    }

    dest[n] = '\0';    
}


int string_ncmp(char *str1, char *str2, int n) {
     int i = 0;
    while(str1[i] != '\0' && i < n) {
        if (str1[i] != str2[i]) {
            return str1[i] > str2[i] ? 1 : -1;
        }
        else i++;
    }
    return 0;  

}


void string_trim(char *src) {
    int length = string_length(src);
    int i = 0;
    
    while(src[i] != '\0' && (src[i] == ' ' || src[i] == '\t' || src[i] == '\n')) {
        i++;
    }
    string_init_cut(src, (i-1));
    length = string_length(src);
    i = length -1;
    while((src[i] == ' ' || src[i] == '\t' || src[i] == '\n')) {
        i--;
    }
    src[i + 1] = '\0';
}


char* append_char_to_string(char character, char *string) {
    char *new_str = (char*) calloc(1, sizeof(char));
    new_str[0] = character;
    return string_concat(string, new_str);
}


int string_begins_with(char* prefix, char* str) {
    int length = string_length(prefix);
    int count;

    for(count = 0; count < length; count++) {
        if(prefix[count] != str[count]) return 0;
    }
    return 1;
}


int string_contains(char* str, char* sequence) {
	int size = string_length(str);
	int seq_size = string_length(sequence);
	
	if(seq_size > size) return 0;

	int i,j;
	for(i = 0; i < size; i++) {
		j = 0;
		if(str[i] == sequence[j]) {
			while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
			if(j == seq_size) return 1;
		}
	}
	return 0;
}


char* string_cut_first_occurrence(char* str, char* sequence) {
    if(string_contains(str, sequence) < 0) return NULL;
    int i,j;
    int size = string_length(str);
	int seq_size = string_length(sequence);
    int begin_index, end_index;
    for(i = 0; i < size; i++) {
		j = 0;
		if(str[i] == sequence[j]) {
            begin_index = i;
			while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
            end_index = i;
            if(j == seq_size - 1) {
                break;
            }
			
		}
	}
    char* first = (char*) calloc(begin_index+1, sizeof(char));
    string_ncopy(first, str, begin_index);

    char* second = (char*) calloc(string_length(str) - end_index, sizeof(char));
    second = substring_at_be(str, end_index, string_length(str) - 1);

    char* result = (char*) calloc(string_length(first) + string_length(second), sizeof(char));
    result = string_concat(first, second);
    free(first);
    free(second);
    return result; 
}


char* string_first_sequence_occur(char* str, char* sequence) {
    int size = string_length(str);
	int seq_size = string_length(sequence);
	
	if(seq_size > size) return NULL;

	int i,j, begin;
    char* p; 
	for(i = 0; i < size; i++) {
		j = 0;
        begin = i;
		if(str[i] == sequence[j]) {
            while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
            if(j == seq_size) {
                p = &str[begin];
                return p;
            }
		}
	}
    return NULL;
}


char* string_last_sequence_occur(char* str, char* sequence) {
    if(string_contains(str, sequence) < 1) return NULL;
    int size = string_length(str);
	int seq_size = string_length(sequence);
	
	if(seq_size > size) return NULL;

	int i,j, begin;
    char* p; 
	for(i = 0; i < size; i++) {
		j = 0;
        begin = i;
		if(str[i] == sequence[j]) {
            while(j < seq_size &&  str[i] == sequence[j]) {
				j++;
				i++;
			}
            if(j == seq_size) {
                p = &str[begin];
            }
		}
	}
	return p;
}
