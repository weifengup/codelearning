#include<iostream>
using namespace std;
#define maxsize 3

typedef struct queue{
    int data[maxsize];
    int front;
    int rear;
    int tag;
    queue(){
        front=0;
        rear=0;
        tag=0;
    }
}queue;

bool push(queue *q,int x){
    if(q->front==q->rear&&q->tag==1){
        cout<<"队列已满，插入失败"<<endl;
        return false;
    }
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%maxsize;
    q->tag=1;
    return true;
}
bool pop(queue *q,int &x){
    if(q->front==q->rear&&q->tag==0){
        cout<<"队列为空，取出失败"<<endl;
        return false;
    }
    x=q->data[q->front];
    q->front=(q->front+1)%maxsize;
    q->tag=0;
    return true;
}
int main(){
    queue *q=new queue();
    int x=1;
    push(q,x);
    if(pop(q,x))
        cout<<x<<endl;
}