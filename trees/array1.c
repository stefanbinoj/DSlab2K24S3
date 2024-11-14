#include<stdio.h>
int max =15;
char  arr []= { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0', '\0', 'J', '\0', 'K', 'L'};


int get_right(int index){
    if(arr[index]!='\0' && (2*index)+2<=max){
        return (2*index)+2;
    }
    return -1;
}

int get_left(int index){
    if(arr[index]!='\0' && (2*index)+1<=max){
        return (2*index)+1;
    }
    return -1;
}

void preorder(int index){
    if(index>=0 && arr[index]!='\0'){
        printf("%c ",arr[index]);
        preorder(get_left(index));
        preorder(get_right(index));
    }
}


void postorder(int index){
    if(index>=0 && arr[index]!='\0'){
        postorder(get_left(index));
        postorder(get_right(index));
        printf("%c ",arr[index]);
    }
}


void inorder(int index){
    if(index>=0 && arr[index]!='\0'){
        inorder(get_left(index));
        printf("%c ",arr[index]);
        inorder(get_right(index));
    }
}

int main()
{
printf("Preorder:\n");
preorder(0);
printf("\nPostorder:\n");
postorder(0);
printf("\nInorder:\n");
inorder(0);
printf("\n");
return 0;
}