/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
static const char* letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combine(char* digits, int from, int to, char* result, char** combinations, int* index){
	if(from <= to){
		const char* letter = letters[digits[from] - '0'];
		for (int i = 0; i < strlen(letter); ++i)
		{
			result[from] = letter[i];
			combine(digits, from+1, to, result, combinations,index);
		}
	}
	else{
		result[from] = '\0';
		combinations[*index] = malloc(sizeof(strlen(result)));
		strcpy(combinations[*index], result);
		(*index)++;
	}
}

char **letterCombinations(char* digits, int* returnSize){
	if(digits == NULL) return NULL;

	int digitsLength = strlen(digits);

	if( digitsLength == 0) return NULL;

	int returnStrLen = 0;
	*returnSize = 1;
	for (int i = 0; i < digitsLength; ++i)
	{
		int index = (int)(digits[i] - '0');
		if( index >= 2 && index <= 9){
			*returnSize *= strlen(letters[index]);
			returnStrLen++;
		}
	}

	char** combinations = (char**)malloc(sizeof(char*)*(*returnSize));
	char* resultStr = (char*)malloc(sizeof(returnStrLen+1));

	int* index = malloc(sizeof(int));
	*index = 0;

	combine(digits, 0, digitsLength-1, resultStr, combinations, index);
	return combinations;

}