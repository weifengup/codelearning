#include<iostream>
using namespace std;
//给定一个整数序列A，A中的每一个元素的大小均大于等于0，且小于n，如果A中有超过
//ｎ/2个的元素的值为x，则x为A的主元素，否则返回-1

//时间复杂度o(n),空间复杂度o(n)
int findMainElem(int *A,int n){
    int *arr=new int[n];
    int max=n/2;
    for(int i=0;i<n;i++)
        arr[i]=0;
    for(int i=0;i<n;i++){
        arr[A[i]]+=1;
        if(arr[A[i]]>max)
            return A[i];
    }
    return -1;
}
//时间复杂度o(n),空间复杂度o(1)
int findMainElem2(int *A,int n){
    int key=A[0],num=1;
    for(int i=1;i<n;i++){
        if(A[i]==key)
            num++;
        else{
            if(num>0)
                num--;
            else{
                num=1;
                key=A[i];
            }
        }
    }
    //当num大于0的时候可能有主元素
    if(num>0){
        num=0;
        for(int i=0;i<n;i++)
            if(A[i]==key)
                num++;
        if(num>n/2)
            return key;
        else return -1;
    }
    else
    return -1;
}
int main(){
    int A[]={0,5,5,3,5,7,5,5};
    int A2[]={0,5,5,3,5,1,5,7};
    int n1=sizeof(A)/sizeof(A[0]);
    int n2=sizeof(A2)/sizeof(A2[0]);
    cout<<findMainElem2(A,n1)<<endl;
    cout<<findMainElem2(A2,n2)<<endl;
}