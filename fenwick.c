#include <stdio.h>

int sum(int i,int* t){//function to return the sum [1,i]
    int s = 0;
    while(i){
        s+=t[i];
        s-=s&-s;
    }
}

int range(int a, int b, int* t){//function to return sum [a,b]
    return sum(b,t)-sum(a-1,t);
}

int update(int i, int k, int* t, int n){//function to update value in the tree by adding the difference to right places
    while(i<=n){
        t[i]+=k;
        i+=i&-i;
    }
}

int main(void){
    int n;// number of elements in array
    scanf('%d',&n);
    int arr[n];
    for (int i = 0; i<n; i++) scanf("%d",arr+i);
    int tree[n+1];// the fenwick tree, 1-indexed
    tree[1] = arr[0];
    for (int i = 1; i<n; i++) tree[i+1] = arr[i]+sum(i,tree);// to create the fenwick tree
}