#include <iostream>
#define max 100
using namespace std;
class Stck
{
	int top;
	int s[max];
public:
	Stck(){top=-1;}
	int pop();
	void push(int);
	void display();

};

int Stck::pop()
{
	if(top==-1)
	{
		cout<<"Underflow"<<endl;
		return 40404;
	}
	return s[top--];
}

void Stck::push(int item)
{
	if(top==max-1)
	{
		cout<<"Stack Overflow";
		return;
	}
	s[++top]=item;
return;
}

void Stck::display()
{
	if(top==-1)
	{
		cout<<"Stack is empty\n";
		return;
	}
	for(int i=top;i>=0;i--)
	cout<<s[i]<<" ";
	cout<<endl;
	return;
}
int main()
{
	Stck S;
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
				cout<<"Enter the number you want to push ";
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
