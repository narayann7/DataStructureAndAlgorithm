#include <bits/stdc++.h>
using namespace std;
//stack using linkedlist only follows add nd delete from start in linkedlist
struct Node
{
	int data;
	Node *next;
}*top=NULL;

Node* newnode(int x)
{
	Node *p;
	p=new Node;
	p->data=x;
	p->next=NULL;
	return(p);
}

void push(Node *q)
{
	if(top==NULL)
		top=q;
	else
	{
		q->next=top;
		top=q;
	}
}

void pop(){
	
	if(top==NULL){
		cout<<"Stack is empty!!";
	}
	else{
		Node* p;
		cout<<"Deleted element is "<<top->data;
		p=top;
		top=top->next;
		free(p);
	}
}
//code contributed by: narayan
//git: narayann7
//email: laxminarayanreddy432@gmail.com

void display()
{
	Node *q;
	q=top;

	if(top==NULL){
		cout<<"Stack is empty!!";
	}
	else{
		while(q!=NULL)
		{
			cout<<q->data<<" ";
			q=q->next;
		}
	}
}

int main()
{
	int ch,x;
	Node *ptr;

	while(1)
	{
		cout<<"\n\n1.Push\n2.Pop\n3.Display\n4.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;

		switch(ch){
			case 1: cout<<"\nEnter data:";
					cin>>x;
					ptr=newnode(x);
					push(ptr);
					break;

			case 2: pop();
					break;

			case 3: display();
					break;

			case 4: exit(0);

			default: cout<<"\nWrong choice!!";
		}
	}

	return 0;
}
