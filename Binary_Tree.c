#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* parent;
    struct node* left;
    struct node* right;
    int val;
}node;

node* create(int n){
    node* temp = (node*)malloc(sizeof(node));
    temp->val = n;
    temp->left=temp->right=temp->parent=NULL;
    return temp;
}

// arr is an array, where the value at ith index tell the index of parent node for i, i=-1 denotes root node
node* createTree(int n, int arr[]){
    if (n==0) return NULL;
    node* root = NULL;
    node* tree[n];
    for (int i = 0; i<n; i++) tree[i] = create(i);
    for (int i = 0; i<n; i++){
        if (arr[i]==-1) root = tree[i];
        else{
            tree[i]->parent = tree[arr[i]];
            if (tree[arr[i]]->left==NULL) tree[arr[i]]->left = tree[i];
            else tree[arr[i]]->right = tree[i];
        }
    }
    return root;
}