#include<stdio.h>
#include<stdlib.h>
void create(int a[10][10] , int row , int col ){
    for (int i = 0 ; i<row ; i++){
        for(int j= 0 ; j<col ; j++){
            printf("Enter the term at [%3d] [%5d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    } 
}

void display(int a[10][10] , int row , int col){
    for (int i = 0 ; i<row ; i++){
        printf("\n");
        for(int j= 0 ; j<col ; j++){
            printf("%3d ",a[i][j]);
        }
    } 
}

int create_tup(int a[10][10], int row , int col , int tup[100][3]){
    int tr=0 , tc=0 , cnz=0 ; 
    for (int i = 0 ; i<row ; i++){
        for(int j= 0 ; j<col ; j++){
            if(a[i][j]!=0){
                cnz++;
                tup[cnz][0]=i;
                tup[cnz][1]=j;
                tup[cnz][2]=a[i][j];
            }
        }
    }
    tup[0][0]=row;
    tup[0][1]=col;
    tup[0][2]=cnz;
    tr=cnz+1;
    return tr ;
}

void print_tuple(int mat_tup[100][3],int tr){
    int i,j;
  printf("\nrows--- columns--- values");
    for(i=0;i<tr;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            printf("%d\t",mat_tup[i][j]);
        }
    }
}

void transpose(int tup[100][3]){
    int cnz = tup[0][2];
    int temo[100];
    for(int i =0 ; i <cnz;i++){
        temo[i]=tup[i][0];
    }
    printf("\nThe Transpose is\n");

    for(int i=0 ; i<cnz;i++){
        tup[i][0]=tup[i][1];
        tup[i][1]=temo[i];
    }
    for(int i=0;i<cnz+1;i++)
    {
        printf("\n");
        for(int j=0;j<3;j++)
        {
            printf("%d  ",tup[i][j]);
        }
    }
}

void add(int tup1[100][3],int tup2[100][3]){
    if(tup1[0][0]==tup2[0][0] && tup1[0][1]==tup2[0][1]){
        int tr1=tup1[0][2];
        int tr2 =  tup2[0][2];
        int tr = tr1+tr2;
        int tup[100][3];
        int i =1,j=1,k=1;
        while(i<tr1 && j<tr2){
            if(tup1[i][0]==tup2[j][0] && tup1[i][1]==tup2[j][1]){
                tup[k][0]=tup1[i][0];
                tup[k][1]=tup1[i][1];
                tup[k][2]=tup1[i][2]+tup2[j][2];
                i++,j++,k++;
            }
            else if(tup1[i][0]<tup2[j][0]){
                tup[k][0]=tup1[i][0];
                tup[k][1]=tup1[i][1];
                tup[k][2]=tup1[i][2];
                i++;k++;
                }
            else{
                tup[k][0]=tup2[j][0];
                tup[k][1]=tup2[j][1];
                tup[k][2]=tup2[j][2];
                j++;k++;
                }
                       
           }
        while(i<=tr1){
                tup[k][0]=tup1[i][0];
                tup[k][1]=tup1[i][1];
                tup[k][2]=tup1[i][2];
                i++;k++; 
        }
        while(j<=tr2)
        {
             tup[k][0]=tup2[j][0];
                tup[k][1]=tup2[j][1];
                tup[k][2]=tup2[j][2];
                j++;k++;
        }
        tup[0][0]=tup1[0][0];
        tup[0][1]=tup1[0][1];
        tup[0][2]=k-1;
        printf("\nThe sum is:\n");
         for(i=0;i<k;i++)
    {
        printf("\n");
        for(j=0;j<3;j++)
        {
            
            printf("%d  ",tup[i][j]);
        }
    }

    }
    else{
        printf("Add is not possible \n");
    }
}

int main() {
    int row1, col1;
    int a[10][10];  // Maximum size of 10x10 for this example

    // Get the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &row1);
    printf("Enter the number of columns: ");
    scanf("%d", &col1);

    // Create and fill the matrix
    create(a, row1, col1);


    int row2, col2;
    int b[10][10];  // Maximum size of 10x10 for this example

    // Get the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &row2);
    printf("Enter the number of columns: ");
    scanf("%d", &col2);

    // Create and fill the matrix
    create(b, row2, col2);




    display(a, row1, col1);

    int tup1[100][3];
    int tr1 = create_tup(a,row1,col1,tup1);
    print_tuple(tup1,tr1);    
    // Display the matrix
    display(b, row2, col2);

    int tup2[100][3];
    int tr2 = create_tup(b,row2,col2,tup2);
    print_tuple(tup2,tr2);

    add(tup1,tup2);



    transpose(tup1);
    transpose(tup2);

    return 0;
}