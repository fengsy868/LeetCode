#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
    int max = 0;
    int stringSize;
    int flag[256];
    int i,j;

    stringSize = strlen(s);
    for (int i = 0; i < stringSize; )
    {
        memset(flag, 0, sizeof(int)*256);
        j = 0;
        printf("-->i = %d\n", i);
        while((i+j) < stringSize && !flag[s[i+j]] == 1)
        {
            flag[s[i+j]] = i + j + 1;
            j++;
            printf("J = %d\n",j );
        }

        if(max < j)
        {
            max = j;
        }
        if((i+j) == stringSize) break;
        i = flag[s[i+j]];
    }    
    return max;
}
int main(){
    char string[] = "abcdefgdqwertyuio";

    int max = lengthOfLongestSubstring(string);

    printf("The Max length is %d\n",max);
    return 0;
}