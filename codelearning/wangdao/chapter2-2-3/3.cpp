// Created on iPad.
//删除线性表中所有值为x的数据元素
#include <iostream>
using namespace std;

//方法一
int deleteX(int *arr,int x,int len){
    int num=0;
    for(int i=0;i<len-num;i++){
        while(i+num<len&&arr[i+num]==x)
            num++;
        if(i+num<len)
            arr[i]=arr[i+num];
    }
    return len-num;
}
//方法二
int deleteX2(int *arr,int x,int len){
    int j=0;
    for(int i=0;i<len;i++){
        if(arr[i]!=x)
            arr[j++]=arr[i];
    }
    return j;
}
int main() {
    int arr[]={0,1,2,1,3,1,1,1};
    int num=deleteX(arr,1,sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<num;i++)
        cout<<arr[i]<<endl;
    return 0;
}