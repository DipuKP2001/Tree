#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *left,*right;
}Node;
Node *root=NULL;
void insert(int elem){
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->data=elem;
	newnode->left=NULL;
	newnode->right=NULL;
	if(!root){
		root=newnode;
	}
	else{
		int flag=0;
		Node *ptr=root,*parent=NULL;
		while(ptr!=NULL && flag==0){
			if(elem>ptr->data){
				parent=ptr;
				ptr=ptr->right;
			}
			else if(elem<ptr->data){
				parent=ptr;
				ptr=ptr->left;
			}
			else{
				flag=1;
			}
		}
		if(flag==0){
			if(elem>parent->data){
				parent->right=newnode;
			}
			else{
				parent->left=newnode;
			}
		}
		else{
			printf("Value already exists!!\n");
			return;
		}
	}
}
void preorder(Node *ptr){
	if(!ptr){
		return;
	}
	else{
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	printf("\n");
}
void inorder(Node *ptr){
	if(!ptr){
		return;
	}
	else{
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
	printf("\n");
}
void postorder(Node *ptr){
	if(!ptr){
		return;
	}
	else{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	}
	printf("\n");
}
void traversal(){
	int ch;
	printf("1.Preorder Traversal 2.Inorder Traversal 3.Postorder Traversal\n");
	scanf("%d",&ch);
	Node *temp=root;
	if(ch==1){
		preorder(temp);
	}
	else if(ch==2){
		inorder(temp);
	}
	else if(ch==3){
		postorder(temp);
	}
	else{
		printf("Wrong choice!!\n");
		return;
	}
}
int search(int x){
	if(!root){
		printf("tree is empty!!\n");
		return EOF;
	}
	Node *ptr=root;
	int flag=0;
	while(ptr!=NULL && flag==0){
		if(ptr->data == x){
			flag=1;
		}
		else if(ptr->data>x){
			ptr=ptr->left;
		}
		else{
			ptr=ptr->right;
		}
	}
	return flag;
}
void delete(int d){
	if(!root){
		printf("Tree is empty!!\n");
		return;
	}
	Node *ptr=root,*parent=NULL;
	int flag=0;
	while(ptr!=NULL && flag==0){
		if(ptr->data==d){
			flag=1;
		}
		else if(ptr->data>d){
			parent=ptr;
			ptr=ptr->left;
		}
		else{
			parent=ptr;
			ptr=ptr->right;
		}
	}
	if(flag==0){
		printf("Value not found!!\n");
		return;
	}
	else{
		if(ptr->left==NULL && ptr->right==NULL){
			if(parent->left==ptr){
				parent->left=NULL;
			}
			else{
				parent->right=NULL;
			}
			free(ptr);
		}
		else if(ptr->left!=NULL && ptr->right!=NULL){
			Node *next=ptr->right;
			while(next->left){
				next=next->left;
			}
			ptr->data=next->data;
			free(next);
		}
		else{
			if(parent->left==ptr){
				if(ptr->left==NULL){
					parent->left=ptr->right;
				}
				else{
					parent->left=ptr->left;
				}
			}
			else{
				if(ptr->left==NULL){
					parent->right=ptr->right;
				}
				else{
					parent->right=ptr->left;
				}
			}
		}
	}
}
void main(){
	int ch,x,d;
	while(1){
		printf("Enter your choice: 1.Insertion 2.Deletion 3.Traversal 4.Search 5.Exit \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the value to be inserted:\n");
				scanf("%d",&x);
				insert(x);
				break;
			case 2:
				printf("Enter the value to be deleted:\n");
				scanf("%d",&x);
				delete(x);
				break;
			case 3:
				traversal();
				break;
			case 4:
				printf("Enter the element to be searched:\n");
				scanf("%d",&x);
				if((d=(search(x)))!=EOF){
					if(d==1){
						printf("Element found\n");
					}
					else{
						printf("Elment not found\n");
				
					}
				}
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid choice!!\n");
				continue;
		}
	}
}
