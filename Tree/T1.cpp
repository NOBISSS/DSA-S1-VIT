#include<iostream>
#include<stdlib.h>

using namespace std;

struct Tree{
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree* insertNode(struct Tree* root,int value){
    if(root==NULL){
        root=(struct Tree*)malloc(sizeof(struct Tree));
        root->data=value;
        root->left=NULL;
        root->right=NULL;
    }else if(root->data > value){
        root->left=insertNode(root->left,value);
    }else if(root->data < value){
        root->right=insertNode(root->right,value);
    }
    return root;
}

void inOrder(struct Tree *root){
    if(root!=NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void PreOrder(struct Tree *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void PostOrder(struct Tree *root){
    if(root!=NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    struct Tree* root=NULL;
    root=insertNode(root,40);
    insertNode(root,50);
    insertNode(root,10);
    insertNode(root,20);
    insertNode(root,30);
    inOrder(root);
    cout<<endl;
    PreOrder(root);
    cout<<endl;
    PostOrder(root);
    return 0;
}