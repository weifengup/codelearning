// Created on iPad.

//从有序顺序表中删除在s与t之间的元素
#include <iostream>
using namespace std;
//方法一
int deletest(int *arr,int s,int t,int len){
    if(s>=t||len==0)
        return -1;
    int k=0;
    for(int i=0;i<len;i++){
        if(arr[i]<s||arr[i]>t)
            arr[k++]=arr[i];
    }
    return k;
}
//方法二：充分利用有序表的条件
int deletest2(int *arr,int s,int t,int len){
    if(s>=t||len==0)
        return -1;
    int i,j;
    for(i=0;i<len&&arr[i]<s;i++);
    if(i==len)
        return i;
    for(j=i;j<len&arr[j]<=t;j++);
    if(j==len)
        return i;
    for(;j<len;i++,j++)
        arr[i]=arr[j];
    return i;
}
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10,11};
    int len=sizeof(arr)/sizeof(arr[0]);
    int num=deletest2(arr,4,8,len);
    for(int i=0;i<num;i++)
        cout<<arr[i]<<endl;
    return 0;
}