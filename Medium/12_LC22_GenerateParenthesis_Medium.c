void backtrack(char*** result, int* returnSize, int* capacity, char* currentString, 
               int openCount, int closeCount, int maxPairs, int index) {
    
    if (openCount == maxPairs && closeCount == maxPairs) {
        if (*returnSize == *capacity) {
            *capacity *= 2;
            *result = (char**)realloc(*result, (*capacity) * sizeof(char*));
        }
        
        currentString[index] = '\0'; 
        (*result)[*returnSize] = strdup(currentString); 
        (*returnSize)++;
        return;
    }

    if (openCount < maxPairs) {
        currentString[index] = '(';
        backtrack(result, returnSize, capacity, currentString, openCount + 1, closeCount, maxPairs, index + 1);
    }

    if (closeCount < openCount) {
        currentString[index] = ')';
        backtrack(result, returnSize, capacity, currentString, openCount, closeCount + 1, maxPairs, index + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 16; 
    char** result = (char**)malloc(capacity * sizeof(char*));
    *returnSize = 0;
    
    char* currentString = (char*)malloc((2 * n + 1) * sizeof(char));
    
    backtrack(&result, returnSize, &capacity, currentString, 0, 0, n, 0);
    
    free(currentString);
    
    return result;
}
