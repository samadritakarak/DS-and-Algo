#include<iostream>
#define max 100
using namespace std;
int v,step=0;
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
	int size();
	bool empty();

};
bool Que::empty()
{
	if(rear<front)
	return true;
	else
	return false;
}
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
void bfs(int arr[][10],int vis[],int v,Que Q)
{
	step++;
	while(!Q.empty())
	{
		step+=3;
		int w=Q.pop();
		cout<<w+1<<" ";
		
		for(int i=0;i<v;i++)
		{
			step++;
			if(arr[w][i]==1 && vis[i]==0)
			{
				step+=2;
				Q.push(i);
				vis[i]=1;
			}
		}
		step++;
	}
	
	step++;
	
}

int main()
{
	int e,a,b;
	Que Q;
	cout<<"Enter number of vertices and number of edges ";
	cin>>v>>e;
	int arr[10][10];
	int vis[v];
	for(int i=0;i<v;i++)
	{
		vis[i]=0;
		for(int j=0;j<v;j++)
		arr[i][j]=0;
	}
	cout<<"Enter the edges\n";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	cout<<"The bfs order is \n";
		vis[0]=1;
		Q.push(0);
		//cout<<"1 ";
	bfs(arr,vis,v,Q);
	cout<<"\nThe number of steps is "<<step;
return 0;
}
