#include <stdio.h>
#include <stdlib.h>

struct btree{
    struct btree* left;
    int data;
    struct btree* right;
};
struct btree* createNode(int ele){
    struct btree* root=(struct btree*)malloc(sizeof(struct btree));
    root->left=NULL;
    root->data=ele;
    root->right=NULL;
    return root;
}
void preorder(struct btree* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct btree* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct btree* p=createNode(2);
    struct btree* p1=createNode(3);
    struct btree* p2=createNode(4);
    struct btree* p3=createNode(5);
    struct btree* p4=createNode(6);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p3->left=p4;
    preorder(p);
    printf("\n");
    postorder(p);




}