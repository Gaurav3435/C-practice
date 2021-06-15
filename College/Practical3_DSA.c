#include<stdio.h>
#include<stdlib.h>
 //Gaurav Patil (A-33) Practical -3 DAA
void show(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\n",array[i]); //Gaurav Patil (A-33) Practical -3 DAA
    }
}

void insertsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 //Gaurav Patil (A-33) Practical -3 DAA
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)     //Gaurav Patil (A-33) Practical -3 DAA
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}                       //Gaurav Patil (A-33) Practical -3 DAA
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j]; //Gaurav Patil (A-33) Practical -3 DAA
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r); //Gaurav Patil (A-33) Practical -3 DAA
		merge(arr, l, m, r);
	}
}

  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void heapify(int arr[], int n, int i) { //Gaurav Patil (A-33) Practical -3 DAA
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
      swap(&arr[i], &arr[largest]); //Gaurav Patil (A-33) Practical -3 DAA
      heapify(arr, n, largest);
    }
  }
  void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) { //Gaurav Patil (A-33) Practical -3 DAA
      swap(&arr[0], &arr[i]);
      heapify(arr, i, 0);
    }
  }

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;  //Gaurav Patil (A-33) Practical -3 DAA
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) //Gaurav Patil (A-33) Practical -3 DAA
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void main() //Gaurav Patil (A-33) Practical -3 DAA
{
    int p,*array,size,choice;
    printf("Enter the size of array:\t");
    scanf("%d",&size);
    array=malloc(size*sizeof(int));
    while(p!=0)
    {
    printf("Enter the element in the array:\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&array[i]);     //Gaurav Patil (A-33) Practical -3 DAA
    }
    printf("\n1.show\n2.insert sort\n3.Merge Sort\n4.Quick Sort\n5.Heap Sort\n9.Exit\nEnter the choice:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:show(array,size);break;
        case 2:insertsort(array,size);show(array,size);break;
        case 3:mergeSort(array,0,size-1);show(array,size);break;
        case 4:quickSort(array,0,size-1);show(array,size);break;
        case 5:heapSort(array,size);show(array,size);break;
        case 9:p=0;break;                //Gaurav Patil (A-33) Practical -3 DAA
    }
    }
}

