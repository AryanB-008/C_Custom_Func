#include <stdio.h>

int sum(int i, int* t){// to return sum[1,i], 1 indexed
    int s = 0;
    while(i){
        s += t[i];
        i -= i & -i;
    }
    return s;
}

int range(int a, int b, int* t){// to return sum[a,b], 1 indexed
    return sum(b, t) - sum(a-1, t);
}

void update(int i, int k, int* t, int n){// to update at i, 1 indexed
    while(i <= n){
        t[i] += k;
        i += i & -i;
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", arr+i);
    int tree[n+1];
    for (int i = 0; i <= n; i++) tree[i] = 0;
    for (int i = 0; i < n; i++) update(i+1, arr[i], tree, n);
}