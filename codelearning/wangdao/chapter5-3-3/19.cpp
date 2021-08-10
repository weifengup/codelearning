#include<iostream>
using std::cout;
using std::endl;

typedef struct tnode{
    int weight;
    struct tnode *left,*right;
    tnode(int data){
        weight=data;
        left=NULL;
        right=NULL;
    }
}tnode;

void getWPL(tnode *root,int level,int &WPL){
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
        WPL+=level*root->weight;
    getWPL(root->left,level+1,WPL);
    getWPL(root->right,level+1,WPL);
}
int main(){
    tnode *root=new tnode(1);
    tnode *n1=new tnode(2);
    tnode *t1l=new tnode(7);
    n1->right=t1l;
    tnode *n2=new tnode(3);
    tnode *n3=new tnode(4);
    tnode *n4=new tnode(5);
    root->left=n1;
    root->right=n2;
    n2->left=n3;
    n2->right=n4;
    int WPL=0;
    getWPL(root,0,WPL);
    cout<<WPL<<endl;
}