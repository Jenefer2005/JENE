#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node *createnode(int data){
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
struct Node *insertnode(struct Node *root,int data)
{
	if(root==NULL){
		return createnode(data);
	}
	else if(data<root->data){
		root->left=insertnode(root->left,data);
	}
	else{
		root->right=insertnode(root->right,data);
	}
	return root;
}
void Inorder(struct Node *root){
	if(root!=NULL){
		Inorder(root->left);
		printf("%d",root->data);
		Inorder(root->right);
	}
}
void Preorder(struct Node *root){
	if(root!=NULL){
		printf("%d",root->data);
		Preorder(root->left);
		Preorder(root->right);
    }
}
void Postorder(struct Node *root){
	if(root!=NULL){
		Postorder(root->left);
		Postorder(root->right);
		printf("%d",root->data);
   }
}
int search(struct Node *root,int key)
{
	if(root==NULL){
		return 0;
	}
	if(root->data==key)
	{
		return 1;
	}
	else if(key<root->data){
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}
}
int main()
{
	struct Node *root=NULL;
	int i,n,value,choice,key;
	printf("Enter number of nodes to be inserted");
	scanf("%d",&n);
	while(1){
		printf("Menu:\n");
		printf("\n1.Insert\n2.Search\n3.Preorder Traversal\n4.Inorder Traversal\n5.Postorder Traversal\n");
        printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter the node values");
				   for(i=0;i<n;i++){
		             scanf("%d",&value);
		             root=insertnode(root,value);
	            	}
					      break;
	        case 2:printf("Enter the element to be searched:");
			       scanf("%d",&key);
				   if(search(root,key)){
				   	    printf("Element %d found in the tree",key);
				   }		    
				   else{
				   	 printf("Element not found");
				   }
				         break;
			case 3:printf("Preorder Traversal:");
			       Preorder(root);
			       printf("\n");
			         break;
			case 4:printf("Inorder Traversal:");
			       Inorder(root);
			       printf("\n");
			         break;
			case 5:printf("Postorder Traversal:");
			       Postorder(root);
			       printf("\n");
			         break;
			case 6:exit(0);
			default :printf("Invalid choice");
    	}
    }
}

