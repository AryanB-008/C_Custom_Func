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

// traversals in a tree, fill the traversal in an array of appropriate size

int pre(int* arr, int i, node* ptr){
    if (ptr!=NULL){
        arr[i++] = ptr->val;
        i = pre(arr,i,ptr->left);
        i = pre(arr,i,ptr->right);
    }
    return i;
}

int in(int* arr, int i, node* ptr){
    if (ptr!=NULL){
        i = in(arr,i,ptr->left);
        arr[i++] = ptr->val;
        i = in(arr,i,ptr->right);
    }
    return i;
}

int post(int* arr, int i, node* ptr){
    if (ptr!=NULL){
        i = post(arr,i,ptr->left);
        i = post(arr,i,ptr->right);
        arr[i++] = ptr->val;
    }
    return i;
}

// number of nodes in a tree using dfs
int node_count(node* ptr ){
    if (ptr!=NULL) return 1+node_count(ptr->left)+node_count(ptr->right);
    return 0;
}

// to create a balanced bst using a sorted array
node* balanced_tree(int* arr, int l, int r, node* parent){
    if (l>r) return NULL;
    int mid = (r-l)/2+l;
    node* temp = create(arr[mid],parent);
    temp->left = balanced_tree(arr,l,mid-1,temp);
    temp->right = balanced_tree(arr,mid+1,r,temp);
    return temp;
}

// balance a given bst
node* balance(node* root){
    int nodes = node_count(root);
    int arr[nodes];
    in(arr,0,root);
    return balanced_tree(arr,0,nodes-1,NULL);
}