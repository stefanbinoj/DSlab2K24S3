#include <stdio.h>

void CreateMatrix(int a[100][100], int *r, int *c) {
    printf("Enter No. of rows: ");
    scanf("%d", r);
    printf("Enter No. of cols: ");
    scanf("%d", c);
    printf("Enter the elements:\n");
    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c; j++) {
            printf("Enter the element at [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void PrintMatrix(int a[100][100], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d | ", a[i][j]);
        }
        printf("\n");
    }
}

int CreateSparse(int a[100][100], int r, int c, int s[100][3]) {
    int nonzero = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                s[nonzero][0] = i;    // Row index
                s[nonzero][1] = j;    // Column index
                s[nonzero][2] = a[i][j]; // Non-zero value
                nonzero++;
            }
        }
    }
    s[0][0]=r;
    s[0][1]=c;
    s[0][2]=nonzero;

    return nonzero; // Return the count of non-zero elements
}

void PrintSparse(int s[100][3], int tr) {
    printf("Row | Col | Val\n");
    for (int i = 1; i < tr; i++) {
        printf("%3d | %3d | %3d\n", s[i][0], s[i][1], s[i][2]); // Improved formatting
    }
}

void transpose(int s[100][3], int tr) {
    // Transpose the sparse matrix
    int temp[100];  // Temporary array to hold row indices

    for (int i = 0; i < tr; i++) {
        temp[i] = s[i][0]; // Store original row indices
        s[i][0] = s[i][1]; // Set row to column index
        s[i][1] = temp[i]; // Set column to original row index
    }
    
    printf("\nThe Transpose is:\n");
    printf("Row | Col | Val\n");
    for (int i = 0; i < tr; i++) {
        printf("%3d | %3d | %3d\n", s[i][0], s[i][1], s[i][2]); // Printing transposed matrix
    }
}

sumsparse(int s1[100][3],int s2[100][3]){
    
}
  

int main() {
    int a[100][100], b[100][100];
    int r1, c1, r2, c2;

    printf("Details of first matrix:\n");
    CreateMatrix(a, &r1, &c1); // Pass addresses of r1 and c1
    printf("Details of second matrix:\n");
    CreateMatrix(b, &r2, &c2); // Pass addresses of r2 and c2

    printf("First matrix:\n");
    PrintMatrix(a, r1, c1);
    printf("Second matrix:\n");
    PrintMatrix(b, r2, c2);

    int s1[100][3], s2[100][3];
    int tr1 = CreateSparse(a, r1, c1, s1);
    int tr2 = CreateSparse(b, r2, c2, s2);

    printf("Printing first sparse matrix:\n");
    PrintSparse(s1, tr1);

    printf("Printing second sparse matrix:\n");
    PrintSparse(s2, tr2);

    sumsparse(s1,s2);



    printf("The transpose of first  : \n");
    transpose(s1,s1[0][2]);

    printf("The transpose of second  : \n");
    transpose(s2,s2[0][2]);

    return 0;
}
