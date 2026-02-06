#include <stdio.h>
#include <stdlib.h>

// merge sort for array
void merge(int n, int* arr){
    if (n==1) return;
    int* temp = malloc(sizeof(int)*n);
    for (int i = 0; i<n; i++) temp[i] = arr[i];
    merge(n/2,temp);
    merge((n+1)/2,temp+n/2);
    int ptra = 0, ptrb=n/2;
    for (int i = 0; i<n; i++){
        if (ptra<n/2&&ptrb<n) arr[i] = (temp[ptrb]>=temp[ptra])?(temp[ptra++]):(temp[ptrb++]);
        else if (ptra>=n/2) arr[i] = temp[ptrb++];
        else if (ptrb>=n) arr[i] = temp[ptra++];
    }
    free(temp);
}