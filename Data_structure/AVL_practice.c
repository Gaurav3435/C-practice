#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data,height;
    struct Node* left;
    struct Node* right;
};

int calH(struct Node* temp)
{
    int lh,rh;
    if(temp==NULL)
    {
        return 0;
    }
    if(temp->left==NULL)
    {
        lh=0;
    }
    else
    {
        lh=1+temp->left->height;
    }
    if(temp->right==NULL)
    {
        rh=0;
    }
    else
    {
        rh=1+temp->right->height;
    }
    if(lh>rh)
    {
        return lh;
    }
    return rh;

}

struct Node * rotateleft(struct Node *x)
{
	struct Node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->height=calH(x);
	y->height=calH(y);

	return(y);
}
struct Node * rotateright(struct Node *x)
{
	struct Node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->height=calH(x);
	y->height=calH(y);

	return(y);
}
struct Node* RR(struct Node*temp)
{
    temp=rotateleft(temp);
    return (temp);
}
struct Node* LL(struct Node*temp)
{
    temp=rotateright(temp);
    return (temp);
}
struct Node* LR(struct Node*temp)
{
    temp->left=rotateright(temp->left);
    temp=rotateright(temp);
    return temp;
}
struct Node* RL(struct Node*temp)
{
    temp->right=rotateright(temp->right);
    temp=rotateleft(temp);
    return temp;
}
int BF(struct Node *T)
{
	int lh,rh;
	if(T==NULL)
		return(0);

	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->height;

	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->height;

	return(lh-rh);
}

struct Node* Insert(struct Node**tree,int ele)
{
    struct Node *ptr=NULL,*temp=(*tree);
    if((*tree)!=NULL)
    {

        if(ele<temp->data)
        {
            temp->left=Insert(&temp->left,ele);
            if(BF(temp)==2)
            {
                    if(ele < temp->left->data)
						temp=LL(temp);
					else
						temp=LR(temp);
            }
        }
        else if(ele>temp->data)
        {
            temp->right=Insert(&temp->right,ele);
            if(BF(temp)==-2)
            {
                    if(ele > temp->right->data)
						temp=RR(temp);
					else
						temp=RL(temp);

            }
        }
    }
    else
    {
        ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->data=ele;
        *tree=ptr;
    }
    temp->height=calH(temp);
    return (temp);
}



struct node* PreorderPrint(struct Node** tree)
{
    struct Node*temp=(*tree);
    if((*tree))
    {
    printf("%d\t",temp->data);
    PreorderPrint(&temp->left);
    PreorderPrint(&temp->right);
    }

}
struct Node* PostOrder(struct Node**tree)
{
    struct Node *temp=(*tree);
    if((*tree))
    {
        PreorderPrint(&temp->left);
        PreorderPrint(&temp->right);
        printf("%d\t",temp->data);
    }
}
struct Node* inorder(struct Node**tree)
{
    struct Node *temp=(*tree);
    if((*tree))
    {
        PreorderPrint(&temp->left);
        printf("%d\t",temp->data);
        PreorderPrint(&temp->right);
    }

}

struct Node* deltree(struct Node** tree)
{

    struct Node* temp=(*tree);
    if ((*tree))
    {
        deltree(&(temp->left));
        deltree(&(temp->right));
        free(temp);
    }
    printf("Deleted!!\n");
    (*tree)=NULL;
}

void main()
{
    int choice,ele;
    struct Node* root=NULL;
    while(choice!=9)
    {
        printf("\n1.Insert \n2.Delete whole tree \n3.Search \n4.Show Preorder\n5.show Postorder \n6.Show Inorder\n9.Exit \nEnter the choice:\t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Emter the element to insert:\t");
                   scanf("%d",&ele);
                   Insert(&root,ele);
                   break;
            case 2:deltree(&root);break;
            case 3:break;
            case 4:PreorderPrint(&root);
                   break;
            case 5:PostOrder(&root);
                   break;
            case 6:inorder(&root);
                   break;
            case 9:choice=9 ;break;
        }

    }
}
