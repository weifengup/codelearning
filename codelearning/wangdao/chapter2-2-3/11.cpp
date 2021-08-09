#include <iostream>
using namespace std;
//找出两个等长的升序顺序表的中位数
//方法一，o(n)
int center(int *A,int *B,int L){
    int i=0,j=0,k=0,temp;
    while(i<L&&j<L){
        if(A[i]<=B[j])
            temp=A[i++];
        else if(A[i]>B[j])
            temp=B[j++];
        k++;
        if(k==L)
            return temp;
    }
    return -1;
}
//方法二 o(log2n)
//由于A和B是有序的数列，找两个数列整合成新的有序数列后的中位数，该方法的思想类似二分查找
//A的中位数a，B的中位数b
//若a=b,则显然，a就是整合后的中位数
//若a<b,则整合后的中位数在a的后半部分和b的前半部分之间
//若a>b，则整合后的中位数在a的前半部分和b的后半部分之间
int center2(int *A,int *B,int L){
    //分别设两个数组的左端点，右端点，和中点
    int s1=0,e1=L-1,m1,s2=0,e2=L-1,m2;
    while(s1!=e1||s2!=e2){
        m1=(s1+e1)/2;
        m2=(s2+e2)/2;
        if(A[m1]==B[m2])
            return A[m1];
        else if(A[m1]<B[m2]){
            //如果当前子列有奇数个元素
            if((e1-s1+1)%2==1){
                //取A的后半部分和B的前半部分，要加中间的点
                s1=m1;
                e2=m2;
            }
            //如果有偶数个，由于采用了地板除，故中间端点取的是偏左的
            //如取abcd的后半段和efgh的前半段，中间端点分别是b和ff
            //故取后半段的不取中间端点，即s1=m1+1，取cd
            //取前半段的取中间端点，即e2=m2,取ef
            else{
                s1=m1+1;
                e2=m2;
            }
        }
        else{
            if((e1-s1+1)%2==1){
                e1=m1;
                s2=m2;
            }
            else{
                e1=m1;
                s2=m2+1;
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}
int main(){
    int A[]={11,13,15,17,19};
    int B[]={2,4,6,8,20};
    int L=5;
    cout<<center2(A,B,L);
}