#include <stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int largest=i, left=2*i+1, right=2*i+2;
    if((left<n)&&(arr[left]>arr[largest]))
        largest=left;
    if((right<n)&&(arr[right]>arr[largest]))
        largest=right;
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
    }

void heap_sort(int arr[],int n){
    int i;
    for(i=n/2-1;i>=0;i--){
       heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int n,i,x,arr[100];
      printf("Enter the number of elements in array :");
      scanf("%d",&n);
      printf("Enter the elements of Array.\n");
    printf("Initial Array : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        //printf("%d, ",arr[i]);
    heap_sort(arr,n);

    printf("\n\nShorted Array : ");
    for(i=0;i<n;i++)
        printf("%d, ",arr[i]);

    return 0;
}
