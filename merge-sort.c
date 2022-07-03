#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 30000

void merge(int *a, int *w, int n){
    int i,j,k;
    i = 0;
    j = n / 2;
    k = 0;
    while(i<n/2 && j<n){
        if(a[i]<a[j]){
            w[k] = a[i];
            i++;
            k++;
        }else{
            w[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<n/2){
        w[k] = a[i];
        i++;
        k++;
    }
    while(j<n){
        w[k] = a[j];
        j++;
        k++;
    }
    return;
}
  
void merge_sort(int *a,int *w, int n) {
    int mid, i;

    if (n>=2){
      
        mid = n / 2;
    
        merge_sort(a, w, mid);
        merge_sort(&a[mid], w, n-mid);
    
        merge(a, w, n);

        i = 0;
        while(i<n){
            a[i] = w[i];
            i++;
        }
    }
}


void print_array(int *a, int n){
    if(n>0){
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}

int main(void){

    /* variable declaration */
    int my_array[ARRAY_MAX];
    int working[ARRAY_MAX];
    int count = 0;

    /* fill an array from stdin */
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count++;
    }

    merge_sort(my_array,working,count);

    print_array(my_array, count);
    
    return EXIT_SUCCESS;
}

             
