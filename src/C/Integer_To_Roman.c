#include "stdio.h"
#include <string.h>
#include <stdlib.h>

char* intToRoman(int num) {

	char * res = (char *)malloc(sizeof(char)*16);
	char* head = res;

    char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};

    while (num >= 1000) {
        *res++ = 'M';
        num -= 1000;
    }

    strcpy(res, huns[num/100]); res += size[num/100]; num = num % 100;
    strcpy(res, tens[num/10]); res += size[num/10]; num = num % 10;
    strcpy(res, ones[num]); res += size[num];

    *res = '\0';
    return head;
}


int main(){
	int num = 1342;

	char* result = intToRoman(num);

	printf("%s\n", result);

	return 0;
}