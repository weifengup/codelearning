#include <iostream>
using namespace std;
//在递增且有序的顺序表中找x，找到了的话与后面元素交换位置，没找到则在相应位置插入x
void swap(int *arr,int pos,int len){
    if(pos+1<len){
        int temp=arr[pos];
        arr[pos]=arr[pos+1];
        arr[pos+1]=temp;
    }
}
void insert(int *arr,int x,int pos,int &len){
    for(int i=len;i>pos;i--){
        arr[i]=arr[i-1];
    }
    len+=1;
    arr[pos]=x;
}
bool binarySearch(int *arr,int len,int x,int &pos){
    int left=0,right=len-1;
    while(left<=right){
        pos=(left+right)/2;
        if(arr[pos]==x)
            return true;
        else if(arr[pos]>x)
            right=pos-1;
        else
            left=pos+1;
    }
    pos=left;
    return false;
}
int main(){
    int arr[20]={1,2,4,6,8,10};
    int pos=-1;
    int len=6;
    int x=7;
    if(binarySearch(arr,len,x,pos))
        swap(arr,pos,len);
    else
        insert(arr,x,pos,len);
    for(int i=0;i<len;i++)
        cout<<arr[i]<<endl;
}