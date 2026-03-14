#include <stdio.h> //segment tree for min queries
#include <stdlib.h>
#include <limits.h>
int min(int a, int b){return (a<b)?(a):(b);}

int* build(int n, int* arr){
    int* t = (int*)malloc(sizeof(int)*2*n);
    for (int i = 2*n-1; i>0; i--){
        if (i>=n) t[i] = arr[i-n];
        else t[i] = min(t[2*i],t[2*i+1]);
    }
    return t;
}

void update(int* t, int i, int val, int n){// i is 0 indexed
    i+=n;
    t[i] = val;
    while(i>1){
        i/=2;
        if (t[i]==min(t[2*i],t[2*i+1])) break;
        else t[i] = min(t[2*i],t[2*i+1]);
    }
}

int range(int* t, int n, int a, int b){// to give minimum [a,b], 0 indexed
    int m = INT_MAX;
    a+=n,b+=n;
    while(a<b){
        if((a&1)==1) m = min(m,t[a++]);
        if((b&1)==0) m = min(m,t[b--]);
        a/=2;
        b/=2;
    }
    return m;
}

int main(void){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i<n; i++) scanf("%d",arr+i);
    int* t= build(n,arr);
}