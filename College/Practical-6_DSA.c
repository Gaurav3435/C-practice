#include <stdio.h>                     //Gaurav Patil  (A-33)  DSA Practical-6
#include<stdlib.h>
#define M 3
//Btree -Start
typedef struct _node {
        int    n;
        int              keys[M - 1];//Gaurav Patil  (A-33)  DSA Practical-6
        struct _node *p[M];
} node;
node *root = NULL;

typedef enum KeyStatus {
        Duplicate,
        SearchFailure,//Gaurav Patil  (A-33)  DSA Practical-6
        Success,
        InsertIt,
        LessKeys,
} KeyStatus;

int searchPos(int key, int *key_arr, int n) {
        int pos = 0;
        while (pos < n && key > key_arr[pos])//Gaurav Patil  (A-33)  DSA Practical-6
                pos++;
        return pos;
}

void eatline(void) {
        char c;
        while ((c = getchar()) != '\n');//Gaurav Patil  (A-33)  DSA Practical-6
}
KeyStatus ins(node *ptr, int key, int *upKey, node **newnode) {
        node *newPtr, *lastPtr;
        int pos, i, n, splitPos;
        int newKey, lastKey;
        KeyStatus value;
        if (ptr == NULL) {
                *newnode = NULL;//Gaurav Patil  (A-33)  DSA Practical-6
                *upKey = key;
                return InsertIt;
        }
        n = ptr->n;
        pos = searchPos(key, ptr->keys, n);//Gaurav Patil  (A-33)  DSA Practical-6
        if (pos < n && key == ptr->keys[pos])
                return Duplicate;
        value = ins(ptr->p[pos], key, &newKey, &newPtr);
        if (value != InsertIt)
                return value;
        if (n < M - 1) {
                pos = searchPos(newKey, ptr->keys, n);//Gaurav Patil  (A-33)  DSA Practical-6
                for (i = n; i>pos; i--) {
                        ptr->keys[i] = ptr->keys[i - 1];
                        ptr->p[i + 1] = ptr->p[i];
                }
                ptr->keys[pos] = newKey;
                ptr->p[pos + 1] = newPtr;//Gaurav Patil  (A-33)  DSA Practical-6
                ++ptr->n;
                return Success;
        }
        if (pos == M - 1) {
                lastKey = newKey;
                lastPtr = newPtr;
        }
        else {
                lastKey = ptr->keys[M - 2];//Gaurav Patil  (A-33)  DSA Practical-6
                lastPtr = ptr->p[M - 1];
                for (i = M - 2; i>pos; i--) {
                        ptr->keys[i] = ptr->keys[i - 1];
                        ptr->p[i + 1] = ptr->p[i];
                }
                ptr->keys[pos] = newKey;
                ptr->p[pos + 1] = newPtr;//Gaurav Patil  (A-33)  DSA Practical-6
        }
        splitPos = (M - 1) / 2;
        (*upKey) = ptr->keys[splitPos];

        (*newnode) = (node*)malloc(sizeof(node));
        ptr->n = splitPos;
        (*newnode)->n = M - 1 - splitPos;
        for (i = 0; i < (*newnode)->n; i++) {//Gaurav Patil  (A-33)  DSA Practical-6
                (*newnode)->p[i] = ptr->p[i + splitPos + 1];
                if (i < (*newnode)->n - 1)
                        (*newnode)->keys[i] = ptr->keys[i + splitPos + 1];
                else
                        (*newnode)->keys[i] = lastKey;
        }
        (*newnode)->p[(*newnode)->n] = lastPtr;//Gaurav Patil  (A-33)  DSA Practical-6
        return InsertIt;
}

void insert(int key)
{
        node *newnode;
        int upKey;
        KeyStatus value;
        value = ins(root, key, &upKey, &newnode);//Gaurav Patil  (A-33)  DSA Practical-6
        if (value == Duplicate)
                printf("Key already available\n");
        if (value == InsertIt) {
                node *uproot = root;
                root = (node*)malloc(sizeof(node));
                root->n = 1;
                root->keys[0] = upKey;
                root->p[0] = uproot;//Gaurav Patil  (A-33)  DSA Practical-6
                root->p[1] = newnode;
        }
}

//B tree- End

  //Heap Sort -Start
  void swap(int *a, int *b) {
    int temp = *a;//Gaurav Patil  (A-33)  DSA Practical-6
    *a = *b;
    *b = temp;
  }

  void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;//Gaurav Patil  (A-33)  DSA Practical-6

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]);//Gaurav Patil  (A-33)  DSA Practical-6
      heapify(arr, n, largest);
    }
  }
  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }
  void printArray(int arr[], int n) {//Gaurav Patil  (A-33)  DSA Practical-6
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

void HeadpSort() {
    int arr[] = {1, 12, 9, 5, 6, 10,4};//Gaurav Patil  (A-33)  DSA Practical-6
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is \n");//Gaurav Patil  (A-33)  DSA Practical-6
    printArray(arr, n);
  }
//Heap Sort -End

//display the b tree-Start
void display(node *ptr, int blanks) {//Gaurav Patil  (A-33)  DSA Practical-6
        if (ptr) {
                int i;
                for (i = 1; i <= blanks; i++)
                        printf(" ");
                for (i = 0; i < ptr->n; i++)
                        printf("%d ", ptr->keys[i]);
                printf("\n");
                for (i = 0; i <= ptr->n; i++)//Gaurav Patil  (A-33)  DSA Practical-6
                        display(ptr->p[i], blanks + 10);
        }/*End of if*/
}
//Display b tree-End

  int main()
  {
      int choice,key;//Gaurav Patil  (A-33)  DSA Practical-6
      while(choice!=4)
      {

          printf("\nCreation of B tree for M=%d\n1.Insert in B tree\n2.Show B tree\n3.HeapSort\nEnter the Choice:\t",M);
          scanf("%d",&choice);
          switch(choice)
          {
              case 1:printf("Enter the key : ");//Gaurav Patil  (A-33)  DSA Practical-6
                    scanf("%d", &key);
                    eatline();
                    insert(key);
                    break;
              case 2:printf("B-Tree is :\n");
                    display(root, 0);//Gaurav Patil  (A-33)  DSA Practical-6
                    break;
              case 3:HeadpSort();break;
              case 4:break;
          }
      }
  }

