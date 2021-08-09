#include <iostream>
using namespace std;
//判断带头节点的循环双链表是否对称
typedef struct deque{
    int data;
    struct deque *prev;
    struct deque *next;
}deque;

bool symmetr(deque *L){
    deque *p=L->next,*q=L->prev;
    while(p!=q&&p!=q->next){
        if(p->data!=q->data)
            return false;
        else{
            p=p->next;
            q=q->prev;
        }
    }
    return true;
}
int main(){
    deque *L=new deque();
    L->data=-1;
    deque *n1=new deque();
    n1->data=1;
    deque *n2=new deque();
    n2->data=3;
    L->next=n1;
    n1->next=n2;
    n2->next=L;
    L->prev=n2;
    n1->prev=L;
    n2->prev=n1;
    cout<<symmetr(L)<<endl;
}