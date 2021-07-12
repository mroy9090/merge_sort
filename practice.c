// merge sort algorithm


#include<stdio.h>
#include<stdlib.h>
#define INF 99999999999

int main(){
    int arr[20],n;
    printf("enter the size for the array:\n");
    scanf("%d",&n);
    printf("enter the element for the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("before sorting\n\n");
    printArr(arr,n);
    mergeSort(arr,0,n-1);
    printf("after sorting\n\n");
    printArr(arr,n);
}

void mergeSort(int arr[],int p,int r){
    int q;
    if(p<r){
        q=((p+r)/2);
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

void merge(int arr[],int p,int q,int r){
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int* L=(int*)malloc((n1+1)*sizeof(int));
    int* R=(int*)malloc((n2+1)*sizeof(int));
    for(int i=0;i<n1;i++){
        L[i]=arr[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[q+j+1];
    }
    L[n1]=INF;
    R[n2]=INF;
    int i=0,j=0;
    for(int k=p; k<=r; k++){
        if(L[i]<R[j]){
             arr[k]=L[i];
             i++;
        }
        else{
            arr [k]=R[j];
             j++;
        }
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
