
int *addToList(int *list, int item, int size) {
    list = realloc(list, (size+1)*sizeof(int));
    list[size] = item;
    return list;
}

int *initList(int *list) {
    free(list);
    list = NULL;
    return list;
}

// remove the i-th item from one-dimensional array (i = 0, 1, 2, ...)
int *rmFromList(int *list, int item, int cols) {
    int i=0, k=0;
    if (item < (cols-1)) { //exception when removing the last element
	do{
	    if (i == item) {
		k++;
	    }
	    list[i] = list[k];
	    i++;
	    k++;
	} while (k < cols);
    }
    list = realloc(list, (cols-1)*sizeof(int));
    return list;
}

void switchEle(int *list, int item1, int item2) {
    int tmp = list[item1];
    list[item1] = list[item2];
    list[item2] = tmp;
    return;
}

int **expandList(int **list, int item0, int rows) {
    list = realloc(list, (rows+1)*sizeof(int *));
    list[rows] = malloc(sizeof(int));
    list[rows][0] = item0;
    return list;
}

int **alloc2dArray(int **arr, int rows, int cols) {
    int i;
    arr = malloc(rows*sizeof(int *));
    for (i=0; i<rows; i++) {
	arr[i] = malloc(cols*sizeof(int));
    }
    return arr;
}

int **free2dArray(int **arr, int rows) {
    int i;

    for (i=0; i<rows; i++) {
	free(arr[i]);
	arr[i] = NULL;
    }

    free(arr);
    arr = NULL;
    return arr;
}

void switchRows(int **arr, int row1, int row2, int cols) {
    int i;
    int tmp;
    
    for (i=0; i<cols; i++) {
	tmp = arr[row1][i];
	arr[row1][i] = arr[row2][i];
	arr[row2][i] = tmp;
    }
}

int **rmRow(int **arr, int row0, int *rows) {
    int i=0, k=0;
    int *tmp = arr[row0];
    if (row0 < (*rows-1)) {
	do{
	    if (i == row0) {
		k++;
	    }
	    arr[i] = arr[k];
	    i++;
	    k++;
	} while (k < *rows);
    }
    free(tmp);
    arr = realloc(arr, (*rows-1)*sizeof(int *));
    *rows = *rows - 1;
    return arr;
}

int **rmCol(int **arr, int col0, int rows, int *cols) {
    int i;
    for (i=0; i<rows; i++) {
	arr[i] = rmFromList(arr[i], col0, *cols);
    }
    *cols = *cols - 1;
    return arr;
}

void switchCols(int **arr, int col1, int col2, int rows) {
    int i;
    int tmp;
    
    for (i=0; i<rows; i++) {
	tmp = arr[i][col1];
	arr[i][col1] = arr[i][col2];
	arr[i][col2] = tmp;
    }
}

void print1dArray(int *list, int dim) {
    int i;

    for (i=0; i<dim; i++) {
	printf("%i ", list[i]);
    }
    printf("\n");
}

void print2dArray(int **arr, int rows, int cols) {
    int i, j;

    for (i=0; i<rows; i++) {
	for (j=0; j<cols; j++) {
	    printf("%i ", arr[i][j]);
	}
	printf("\n");
    }
}

void print2dRagged(int **arr, int rows, int *size) {
    int i, j;

    for (i=0; i<rows; i++) {
	for (j=0; j<size[i]; j++) {
	    printf("%i ", arr[i][j]);
	}
	printf("\n");
    }
}

void printAdd2dArray(int **arr, int rows, int cols) {
    int i, j;

    printf("\n");

    for (i=0; i<rows; i++) {
	printf("%p : ", arr[i]);
	for (j=0; j<cols; j++) {
	    printf("%p ", &arr[i][j]);
	}
	printf("\n");
    }
}

int **cpy2dArray(int **arr, int **brr, int rows, int cols) {
    int i, j;
    
    for (i=0; i<rows; i++) {
	for (j=0; j<cols; j++) {
	    brr[i][j] = arr[i][j];
	}
    }
    return brr;
}
