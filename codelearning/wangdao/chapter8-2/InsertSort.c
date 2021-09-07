#include<stdio.h>
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

void InsertSort(int arr[],int n){
    int i,j,k;
    for(i=1;i<n;i++){
        k=arr[i];
        for(j=i-1;j>=0;j--){
            if(k<arr[j])
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=k;
    }
}
void halfInsertSort(int arr[],int n){
    int i,j,k,low,mid,high;
    for(i=1;i<n;i++){
        k=arr[i];
        low=0;high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            if(k<arr[mid])
                high=mid-1;
            else
                low=mid+1;
        }
        for(j=i-1;j>=high+1;j--)
            arr[j+1]=arr[j];
        arr[high+1]=k;
    }
}
void ShellSort(int arr[],int n){
    int dist,i,j,k;
    for(dist=n/2;dist>=1;dist/=2){
        for(i=dist;i<n;i++){
            k=arr[i];
            for(j=i-dist;j>=0;j-=dist){
                if(k<arr[j])
                    arr[j+dist]=arr[j];
                else 
                break;
            }
            arr[j+dist]=k;
        }
    }
}
int main(){
    int arr[]={7,6,5,4,3,2,1};
    // InsertSort(arr,ARRSIZE(arr));
    // halfInsertSort(arr,ARRSIZE(arr));
    ShellSort(arr,ARRSIZE(arr));
    int i;
    for(i=0;i<ARRSIZE(arr);i++)
        printf("%d\n",arr[i]);
}