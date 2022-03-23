#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    Node * link;
};
struct Queue
{
    Node * front, *rear; //Node dau va Node cuoi
 
};
void Init(Queue &queue)
{
    queue.front =  NULL;
    queue.rear = NULL;
   
}
int Isempty(Queue &queue) {
  if (queue.front==NULL) 
  return true;
   else return false;
}
 Node *createNode(int x) 
{
    Node *p = (Node*) malloc(sizeof(Node));
    p->link = NULL;
    p->data = x;
    return p;
}

void Insert(Queue &queue, int x) 
{
	
    Node *p = createNode(x); 
    if (Isempty(queue))
    {
        queue.front = queue.rear = p; 
    }
    else 
    { 
        queue.rear->link = p;
        queue.rear = p;
    }
  
}
 
int Remove(Queue &queue,int &x) 
{
    if (Isempty(queue)) 
    {
        printf("Hang doi rong !");
        
    }
    else
    {
        int x = queue.front->data;
            queue.front = queue.front->link;
        
    }
}
 void clear(Queue &queue){
	int x;
	while(Isempty(queue)!=1){
		Remove(queue,x);
	}
}
void Input (Queue &queue) 
{
    int i=0; 
    int x;
    do
    {
        i++;
        printf ("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        if (x != 0)Insert(queue,x);
    } while(x != 0 && x>=0); 
}
 
void Output(Queue &queue)
{
    Node *p = queue.front;
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->link;
    }
    printf("\n");
}
int main(){
	int n;
	Queue queue;
    Init(queue);
    printf("\nNhap so am de dung nhap:\n");
    Input(queue);
    Isempty(queue);
    printf("\nIn phan tu da nhap:\n");
    Output(queue);
   
}
