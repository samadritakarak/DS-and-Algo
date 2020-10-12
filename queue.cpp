#include <iostream>
#define max 100
using namespace std;
class Que
{
	int rear,front;
	int s[max];
public:
	Que()
	{
	rear=-1;
	front=0;
	}
	int pop();
	void push(int);
	void display();

};

int Que::pop()
{
	if(rear<front)
	{
		cout<<"Underflow"<<endl;
		return 40404;
	}
	return s[front++];
}

void Que::push(int item)
{
	if(rear==max-1)
	{
		cout<<"Queue Overflow";
		return;
	}
	s[++rear]=item;
return;
}

void Que::display()
{
	if(rear<front)
	{
		cout<<"Queue is empty\n";
		return;
	}
	for(int i=front;i<=rear;i++)
	cout<<s[i]<<" ";
	cout<<endl;
	return;
}
int main()
{
	Que S;
	cout<<"1.Push\t2.Pop\t3.Display\t4.Exit\n";
	int ch;
	do
	{
		cout<<"Enter your choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				int n;
				cout<<"Enter the number to be pushed ";
				cin>>n;
				S.push(n);
				break;
			case 2:
				int val;
				val=S.pop();
				if (val!=40404)
					cout<<"Popped element is "<<val<<endl;
				break;
			case 3:
				S.display();
		}
	}while(ch!=4);
return 0;
}
