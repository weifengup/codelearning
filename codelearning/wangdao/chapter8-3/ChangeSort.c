#include<stdio.h>
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

void bubbleSort(int arr[],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        int flag=0;
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                k=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=k;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int partition(int arr[],int low,int high){
    int i=low,j=high,k=arr[low];
    while(i<j){
        while(i<j&&arr[j]>=k)  j--;
        if(i<j&&arr[j]<k) arr[i]=arr[j];
        while(i<j&&arr[i]<=k) i++;
        if(i<j&&arr[i>k]) arr[j]=arr[i];
    }
    arr[i]=k;
    return i;
}
void fastSort(int arr[],int low,int high){
    if(low<high){
        int mid=partition(arr,low,high);
        fastSort(arr,low,mid-1);
        fastSort(arr,mid+1,high);
    }
}

int main(){
    int arr[]={7,6,5,4,3,2,1};
    // bubbleSort(arr,ARRSIZE(arr));
    fastSort(arr,0,ARRSIZE(arr)-1);
    int i;
    for(i=0;i<ARRSIZE(arr);i++)
        printf("%d\n",arr[i]);
}