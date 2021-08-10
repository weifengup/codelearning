#include<iostream>
using namespace std;

//一个满二叉树，给出前序序列，写出对应后序队列
void get_post(int pre[],int l1,int h1,int post[],int l2,int h2){
    if(l1<=h1){
        post[h2]=pre[l1];
        //由于是满二叉树，一半一定为整数
        int half=(h1-l1)/2;
        get_post(pre,l1+1,l1+half,post,l2,l2+half-1);
        get_post(pre,l1+half+1,h1,post,l2+half,h2-1);
    }
}
int main(){
    int pre[]={1,2,4,5,3,6,7};
    int post[7];
    get_post(pre,0,6,post,0,6);
    for(int i=0;i<7;i++)
        cout<<post[i]<<endl;

}