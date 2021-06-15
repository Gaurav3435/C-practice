#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* Insert(struct Node**tree,int ele)
{
    struct Node *ptr=NULL,*temp=(*tree);
    if((*tree)!=NULL)
    {

        if(ele<temp->data)
        {
            Insert(&temp->left,ele);
        }
        else if(ele>temp->data)
        {
            Insert(&temp->right,ele);
        }

    }
    else
    {
        ptr=(struct Node*)malloc(sizeof(struct Node));
        ptr->left=NULL;
        ptr->right=NULL;
        ptr->data=ele;
        *tree=ptr;
        return;

    }
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
