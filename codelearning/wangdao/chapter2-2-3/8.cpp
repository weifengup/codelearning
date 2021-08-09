# include <iostream>
using namespace std;

//一个顺序表中存放两个线性表，将数组中两个顺序表的位置互换

void reverse(int *arr,int begin,int end){
    int temp;
    for(int i=0;i<=(end-begin)/2;i++){
        temp=arr[begin+i];
        arr[begin+i]=arr[end-i];
        arr[end-i]=temp;
    }
}
void replace(int *arr,int m,int n){
    reverse(arr,0,m+n-1);
    reverse(arr,0,n-1);
    reverse(arr,n,m+n-1);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    replace(arr,1,8);
    int len=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<len;i++)
        cout<<arr[i]<<endl;
    return 0;
}