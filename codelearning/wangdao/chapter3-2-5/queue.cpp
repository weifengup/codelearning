#include<iostream>
using namespace std;
#define maxsize 3

//顺序存储法，建立循环队列，空出一个位置来区分栈空、栈满
typedef struct queue{
    int data[maxsize];
    int front;
    int rear;
    queue(){
        front=rear=0;
    }
}queue;
bool push(queue *q,int x){
    if((q->rear+1)%maxsize==q->front){
        cout<<"队列已满，无法插入"<<endl;
        return false;
    }
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%maxsize;
    return true;
}
bool pop(queue *q,int &x){
    if(q->rear==q->front){
        cout<<"队列为空，无法取出"<<endl;
        return false;
    }
    x=q->data[q->front];
    q->front=(q->front+1)%maxsize;
    return true;
}
int main(){
    queue *q=new queue();
    int x=3;
    push(q,x);
    if(pop(q,x))
        cout<<x<<endl;
}