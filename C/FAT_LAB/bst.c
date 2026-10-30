#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int data){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->left=NULL;
    root->data=data;
    root->right=NULL;
    return root;
}
struct node* build(int arr[],struct node* root,int i,int n){
    if(i<n){
        struct node* temp=create(arr[i]);
        root=temp;
        root->left=build(arr,root->left,2*i+1,n);
        root->right=build(arr,root->right,2*i+2,n);
    }
    return root;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}
void postorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d ",root->data);
    }
}

void levelorder(struct node* root){
    struct node** queue=(struct node**)malloc(100*sizeof(struct node));
    int f=0;
    int r=0;
    queue[r++]=root;
    while(f<r){
        struct node* temp=queue[f++];
        printf("%d ",temp->data);
        if(temp->left){
            queue[r++]=temp->left;
        }
        if(temp->right){
            queue[r++]=temp->right;
        }
    }
}
int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return 1+(left>right?left:right);
}
void print_levels(struct node* root,int level,int lr){
    if(root==NULL){
        return;
    }
    if(level==1){
        printf("%d ",root->data);
    }
    else{
        if(lr){
            print_levels(root->left,level-1,lr);
            print_levels(root->right,level-1,lr);
        }
        else{
            print_levels(root->right,level-1,lr);
            print_levels(root->left,level-1,lr);
        }
    }
}
void zizag(struct node* root){
    int h=height(root);
    int lr=1;
    for(int i=1;i<=h;i++)
        printf("Level %d: ",i);
        print_levels(root,i,lr);
        printf("\n");
        lr=!lr;
    }
}
void sum_levels(struct node* root,int level,int *count){
    if(root==NULL){
        return;
    }
    if(level==1){
        (*count)+=root->data;
    }
    else if(level>1){
        sum_levels(root->left,level-1,count);
        sum_levels(root->right,level-1,count);
    }
}
void sum_of_levels(struct node* root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        int count=0;
        printf("Level %d: ",i);
        sum_levels(root,i,&count);
        printf("%d",count);
        printf("\n");
    }
}
int main(){
    int a;
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    struct node* tree=NULL;
    tree=build(arr,tree,0,a);
    zizag(tree);
    printf("\n\n");
    sum_of_levels(tree);
}




#include <stdlib.h>
#include <stdio.h>

struct node {
    char data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* create(char data) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

// Function to insert a node into the BST
struct node* insert(struct node* root, char data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value in the BST
void findmin(struct node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    printf("Minimum value: %c\n", root ? root->data : ' ');
}

// Function to find the maximum value in the BST
void findmax(struct node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    printf("Maximum value: %c", root ? root->data : ' ');
}

int main() {
    int n;
    scanf("%d", &n);  // Number of characters to be inserted into the BST
    getchar();  // Consume the newline character

    struct node* root = NULL;
    for (int i = 0; i < n; i++) {
        char data;
        scanf("%c", &data);
        getchar();  // Consume the space or newline after the character
        root = insert(root, data);  // Insert into the BST
    }

    findmin(root);  // Find and print the minimum value
    findmax(root);  // Find and print the maximum value

    return 0;
}



// delete
