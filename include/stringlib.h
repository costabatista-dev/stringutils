#ifndef _STRINGLIB1_
#define _STRINGLIB1_
/*========================================================================
======================== function: string_cmp ============================
A function to compare if two strings have the same content (are equal)
@param_0: The first string to be compared  
@param_1: The second string to be compared
@return: It returns 0 if the two given string are equal
@return: It returns 1 if the first string is higher than the second one
@return: It returns -1 if the second string is lesser than the second one
==========================================================================*/
int string_cmp(char *, char *);

/*========================================================================
======================== function: string_length =========================
A function to get the size of a string
@param_0: The inputted string to be measured
@return: It returns the length of the inputted string (int)
==========================================================================*/
int string_length(char *);

/*========================================================================
======================== function: string_copy ============================
A function to copy a string from a source to a destiny
@param_0: The destiny string that will be receive content from another one
@param_0: The string source that will be copied.
==========================================================================*/
void string_copy(char *, char *);

#endif