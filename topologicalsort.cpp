#include<iostream>
#include <queue>
using namespace std;
int v;
int main(){
	int e,a,b;
	queue <int> q;
	cout<<"Enter no. of vertices & no. of edges ";
	cin>>v>>e;
	int arr[10][10];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		arr[i][j]=0;
	}
	cout<<"Enter the edges of a directed graph\n";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		arr[a][b]=1;
	}

int s=0;
int indeg[v];
for (int i =0;i<v;i++) {
	indeg[i]=0;
}
for(int i=0;i<v;i++)
{
	for(int j=0;j<v;j++)
  s=s+arr[j][i];
	cout<<"sum of"<<i+1<<" Column is"<<s;
  indeg[i]=s;

  s=0;

  cout<<endl;
}
for(int i = 0; i < v; ++i){
		for(int j = 0; j < v; ++j){
				cout << arr[i][j] << " ";
			}
			cout<<endl;
		}


for (int i = 0; i < v; i++) {
	if(indeg[i]==0)
	q.push(i);
}
while (!q.empty()) {
	int vertex = q.front();
	q.pop();
	cout<<vertex<<"\t";
	for (int i =0 ; i <v ; i++) {
		if (arr[vertex][i]==1) {
			indeg[i]--;
			if(indeg[i]==0)
			q.push(i);
		}
	}
}
cout<<"\n";
}
