#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
	int stringSize = strlen(s);

	if(stringSize <= numRows | numRows == 1) return s;
	
	int numBloc = 2 * numRows - 2;
	int index = 0;

    char *res = (char*) malloc(sizeof(char)*(stringSize+1));

   	for (int i = 0; i < numRows ; i++)
   	{
   		for (int j = i; j < stringSize; j+=numBloc)
   		{
   			res[index++] = s[j];

   			if(i != 0 && i != numRows - 1){
   				int k = j + 2 * (numRows - i) - 2;
   				if(k < stringSize) res[index++] = s[k];
   			}
   		}
	}
	
    res[stringSize] = '\0';

    return res;
}

int main(){
    char string[] = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";

    char* res = convert(string, 61);

    printf("The ZigZag string is %s\n",res);
    return 0;
}