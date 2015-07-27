#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char* longestPalindrome(char* s) {
    int stringSize;
    int i,j,k;  	
    int max = 1;
    int head = 0;

    stringSize = strlen(s);

    if(s == NULL) return NULL;
    if(stringSize == 1) return s;

    for (i = 0; i < stringSize && (stringSize - i) > max/2;)				 
    {
    	j=i; k=i;

    
    	while( k < stringSize-1  && s[k] == s[k+1]) {k++;}
   		
   		i = k + 1;

   		while( j > 0 && k < stringSize-1 && s[j-1] == s[k+1]) {j--;k++;}

    	
    	if (max < (k - j + 1))
    	{
    		max = k- j + 1;
    		head = j;
    	}
    	//printf("i = %d j = %d k = %d max = %d head = %d Char = %c\n ",i,j,k,max,head,s[i] );

    }

    //printf("Max = %d\n",max );

    char* res = (char *)malloc(sizeof(char) * (max + 1));

    if (res == NULL){
    	printf("Memory allocate fault\n");
    	return NULL;
    }

    for (i = 0; i < max; ++i)
    {
    	res[i] = s[head+i];
    }

    res[max] = '\0';

    return res;
}

int main(){
    char string[] = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";

    char* result;

    result = longestPalindrome(string);

    printf("The Longest Palindrome string is %s\n",result);
    return 0;
}