void backtrack(int row, int n, int* cols, int* diag1, int* diag2, 
               char** currentBoard, char*** result, int* returnSize) {
    if (row == n) {
        char** boardCopy = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            boardCopy[i] = strdup(currentBoard[i]);
        }
        result[*returnSize] = boardCopy;
        (*returnSize)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        int d1 = row - col + (n - 1); 
        int d2 = row + col;           

        if (cols[col] || diag1[d1] || diag2[d2]) {
            continue;
        }

        currentBoard[row][col] = 'Q';
        cols[col] = diag1[d1] = diag2[d2] = 1;

        backtrack(row + 1, n, cols, diag1, diag2, currentBoard, result, returnSize);

        currentBoard[row][col] = '.';
        cols[col] = diag1[d1] = diag2[d2] = 0;
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int maxSolutions = 500; 
    char*** result = (char***)malloc(maxSolutions * sizeof(char**));
    *returnSize = 0;

    int* cols = (int*)calloc(n, sizeof(int));
    int* diag1 = (int*)calloc(2 * n - 1, sizeof(int));
    int* diag2 = (int*)calloc(2 * n - 1, sizeof(int));

    char** currentBoard = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        currentBoard[i] = (char*)malloc((n + 1) * sizeof(char));
        memset(currentBoard[i], '.', n);
        currentBoard[i][n] = '\0';
    }

    backtrack(0, n, cols, diag1, diag2, currentBoard, result, returnSize);

    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }

    for (int i = 0; i < n; i++) {
        free(currentBoard[i]);
    }
    free(currentBoard);
    free(cols);
    free(diag1);
    free(diag2);

    return result;
}
