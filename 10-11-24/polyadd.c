void create(int poly [],int degree){
    for(int i=degree ; i>=0 ; i--){
        printf("Enter the coeff for %d : ",i);
        scanf("%d",&poly[i]);
    }
}

void display(int poly[] , int degree){
    for(int i=degree; i>=0 ; i--){
        if(i!=degree && poly[i]>0){
            printf(" + ");
        }
        else if (poly[i]<0){
            printf(" - ");
        }
        printf("%d ^^ %d" , poly[i] , i);

    }
}

int add(int poly1[],int poly2[],int degree1 , int degree2){
    int i = 0;
    int j = 0;
    int k = 0;
    int c[100];
    int low = degree1<degree2 ? degree1 : degree2;
    for(int z = 0 ; z<low+1;z++){
        c[i]=poly1[j]+poly2[k];
        i++;
        k++;
        j++;
    }
    while(j < degree1){
        c[i]=poly1[j];
        i++;
        j++;
    }
    while (k< degree2){
        c[i]=poly2[k];
        i++;
        k++;
    }
    return c , k ;
}

int main(){
    int degree1 , degree2 ;
    printf("Enter highest degreee of first polynomial : \n");
    scanf("%d",&degree1);
    printf("Enter highest degreee of second polynomial : \n");
    scanf("%d",&degree2);
    int a[degree1+1];
    int b[degree2+2];
    create(a,degree1);
    create(b,degree2);
    printf("THe poly  :\n");
    display(a,degree1);
    display(b,degree2);
    int c , degree3 = add(a,b,degree1,degree2);
    printf("The sum is : \n");
    display(c,degree3);

    
       
}