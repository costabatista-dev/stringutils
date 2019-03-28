#include<stdlib.h>
#include<stdio.h>
#ifndef _STRINGUTIL1_
#define _STRINGUTIL1_


/*========================================================================
======================== function: string_cmp ============================
A function to compare if two strings have the same content (are equal)
@param str1: The first string to be compared  
@param str2: The second string to be compared
@return: It returns 0 if the two given string are equal
@return: It returns 1 if the first string is higher than the second one
@return: It returns -1 if the second string is lesser than the second one
==========================================================================*/
int string_cmp(char *str1, char *str2);


/*========================================================================
======================== function: string_ncmp ===========================
A function to compare if two strings have the same content (are equal)
@param str1: The first string to be compared  
@param str2: The second string to be compared
@param n: The number of bytes that will be compared
@return: It returns 0 if the two given string are equal
@return: It returns 1 if the first string is higher than the second one
@return: It returns -1 if the second string is lesser than the second one
==========================================================================*/
int string_ncmp(char *str1, char *str2, int n);


/*========================================================================
======================== function: string_length =========================
A function to get the size of a string
@param str: The inputted string to be measured
@return: It returns the length of the inputted string (int)
==========================================================================*/
int string_length(char *str);


/*========================================================================
======================== function: string_copy ===========================
A function to copy a string from a source to a destiny
@param dest: The destiny string that will be receive content from another one
@param src: The string source that will be copied
==========================================================================*/
void string_copy(char *dest, char *src);


/*========================================================================
======================== function: string_ncopy ==========================
A function to copy a string from a source to a destiny
@param dest: The destiny string that will be receive content from another one
@param src: The string source that will be copied
@param n: The number of bytes to be copied
==========================================================================*/
void string_ncopy(char *dest, char *src, int n);


/*========================================================================
===================== function: string_concat ============================
A function to concatenate two given strings
@param str1: First string, it'll be putted at the begining of the resultant string
@param str2: Second string, it'll be putted at the end of the resultant string
@return: A string that's the result of concatenation of second string
at the end of the first string
==========================================================================*/
char* string_concat(char *str1, char *str2);


/*========================================================================
===================== function: string_nconcat ===========================
A function to concatenate two given strings
@param str1: First string, it'll be putted at the begining of the resultant string
@param str2: Second string, it'll be putted at the end of the resultant string
@param n: The number of bytes of src that will be putted at the end of dest
@return: A string that's the result of concatenation of second string
at the end of the first string
==========================================================================*/
char* string_nconcat(char *dest, char *src, int n);


/*========================================================================
===================== function: string_init_cut ==========================
A function to cut a string from the begining until a given index (inclusive)
@param str: A string that will be cutted from the begining
@param index: a index to cut the inputted string
@return: A string that's the result of cut n char from the begining.
==========================================================================*/
char* string_init_cut(char *str, int index);


/*========================================================================
===================== function: string_end_cut ==========================
A function to cut a string from a given index (inclusive) until it ends
@param str: A string that will be cutted from the begining
@param index: a index to cut the inputted string
@return: A string that's the result of cut n char from a index to he end.
==========================================================================*/
char* string_end_cut(char *src, int index);


/*========================================================================
===================== function: substring_at_be ==========================
A function to get a substring through a begin index and a end index, given
a string
@param str: A source string
@param begin: An int that indicates the inital index of the substring (inclusive)
@param end: An int that indicates the end index of the substring (inclusive)
@return: It returns a substring that correspond the given indexes
==========================================================================*/
char* substring_at_be(char *str, int begin, int end);


/*========================================================================
===================== function: string_trim ==============================
A function to remove whitespaces from beginind and end from a string
@param: a source string
==========================================================================*/
void string_trim(char *src);


/*========================================================================
===================== function: append_to_string =========================
A function to append a char to a given string
@param: a char to append at the end of a string
@param: a string to receive a char at the end of it
@return: It returns a new string which has the char parameter as the last character
==========================================================================*/
char* append_char_to_string(char character, char *string);


/*========================================================================
===================== function: str_begins_with ==========================
A function to verify whether a string begins with a prefix.
@param: a prefix to verify
@param: a string to be verified
@return: it returns 1 if it's true else 0
==========================================================================*/
int string_begins_with(char* prefix, char *str);


/*========================================================================
===================== function: string_contains_str ======================
A function to determine if a string contains a sequence of char.
@param: a string to be verified.
@param: a sequence to be searched in the given string
@return: it returns 1 if the string be found, else returns 0
==========================================================================
*/
int string_contains_str(char* str, char* sequence);

int string_contains_char(char* str, char c);

/*========================================================================
===================== function: string_cut_first_occurrence ==============
A function to cut the first occurrence of a sequence in a given string.
@param: a string to be cutted.
@param: a sequence to be removed from a given string.
@return: it returns a string withou the first occurrence of the given sequence of char
==========================================================================
*/
char* string_cut_first_occurrence(char* str, char* sequence);


/*========================================================================
===================== function: string_first_char_occur ==================
@param: a string to be verified.
@param: a sequence to be searched in the given string
@return: it returns a pointer to the first appearence of a given sequence.
==========================================================================
*/
char* string_first_sequence_occur(char* str, char* sequence);


/*========================================================================
===================== function: string_last_sequence_occur ===============
@param: a string to be verified.
@param: a sequence to be searched in the given string
@return: it returns a pointer to the last appearence of a given sequence.
==========================================================================
*/
char* string_last_sequence_occur(char* str, char* sequence);

int* string_char_occurrences(char* str, char c);
int string_number_occurrences(char* str, char c);

char* get_file_content(char* file_path);

char** string_split_index(char* str, int index); //finished.
char** string_split_sequence(char* str, char* sequence);
char** string_split_char(char* str, char c);
char** get_file_divided_by_lines(char* file_path);

#endif
