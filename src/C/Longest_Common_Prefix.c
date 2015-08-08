char* longestCommonPrefix(char** strs, int strsSize) {
    char *ret = "";
    char *reference = strs[0];
    int index = 0;

    if (strsSize == 0)
        return ret;
    if (strsSize == 1)
        return reference;
    //use the first string as the reference string and compare
    //all subsequent strings with that one
    while(1) {
        for (int i = 1; i < strsSize; i++) {
            char *toCompare = strs[i];
            //if one of the comparison strings reaches the end,
            //or if they differ from the reference, then end.
            //this condition also includes when the end of
            //the reference string is hit, but want to explicitly
            //look for, otherwise if all the strings are same length
            //it would overrun the buffer
            if (toCompare[index] == '\0' || 
                toCompare[index] != reference[index]) {
                    if (index >= 1) {
                        ret = strdup(reference);
                        ret[index] = '\0';
                    }
                    return ret;
            }
        }
        index++;
    }
}