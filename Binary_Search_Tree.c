#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    struct node* parent;
    struct node* left;
    struct node* right;
    int val;
}node;

node* create(int n, node* ptr){
    node* temp = (node*)malloc(sizeof(node));
    temp->val = n;
    temp->right=temp->left = NULL;
    temp->parent = ptr;
    return temp;
}

// to create a binary search tree from an array of valus, arr[0] is assumed root, array should have all distinct values
node* tree(int n, int arr[]){
    if (n==0) return NULL;
    node* root = create(arr[0],NULL);
    node* curr;
    for (int i = 1; i<n; i++){
        curr = root;
        bool avail = (arr[i]>curr->val)?((curr->right==NULL)?(true):(false)):((curr->left==NULL)?(true):(false));
        while(!avail){
            curr = (arr[i]>curr->val)?(curr->right):(curr->left);
            avail = (arr[i]>curr->val)?((curr->right==NULL)?(true):(false)):((curr->left==NULL)?(true):(false));
        }
        if (arr[i]>curr->val) curr->right = create(arr[i],curr);
        else curr->left = create(arr[i],curr);
    }
    return root;
}

// to balance a binary tree after making it
node* balance(node* root){
    
}