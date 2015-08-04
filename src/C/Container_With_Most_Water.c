int min(int i, int j){
	return (i > j)? j : i;
}

int maxArea(int* height, int heightSize) {
    int Area = 0;
    int i = 0;
    int j = heightSize - 1;

    while( i != j){
    	if (min(height[i], height[j]) * (j - i) > Area){
    		Area = min(height[i], height[j]) * (j - i);
    	}

    	if(height[i] > height[j]) j--;
    	else i++;
    }

    return Area;
}

