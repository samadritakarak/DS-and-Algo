#include<iostream>
using namespace std;
class Llist
{
	int info;
	Llist *next;
	public:
	void display(Llist*);
	Llist* insertbegin(int , Llist*);
	Llist* insertend(int, Llist*);
	Llist* insertafter(int,int,Llist*);
	Llist* deletebegin(Llist*);
	Llist* deleteend(Llist*);
	Llist* deleteele(int,Llist*);
};

void Llist::display(Llist *start)
{
	if(start==NULL)
	{
		cout<<"Empty Linked List\n";
		return;
	}
	Llist *cur;
	cur=start;
	while(cur!=NULL)
	{
		cout<<cur->info<<" ";
		cur=cur->next;
	}
	cout<<endl;
	return;
}

Llist* Llist::insertbegin(int item,Llist *start)
{
	Llist *temp=new Llist();
	temp->info=item;
	temp->next=start;
	start=temp;
	return start;
}

Llist* Llist::insertend(int item,Llist *start)
{
	Llist *temp=new Llist();
	temp->info=item;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
		return start;
	}
	Llist *cur=start;
	while(cur->next!=NULL)
	cur=cur->next;
	cur->next=temp;
	return start;
}

Llist* Llist::insertafter(int val1,int val2,Llist *start)
{
//assuming value already exists somewhere in the list
	Llist *temp=new Llist();
	temp->info=val1;
	temp->next=NULL;
	Llist *cur=start;
	while(cur->info!=val2)
		cur=cur->next;
	temp->next=cur->next;
	cur->next=temp;
	return start;
}

Llist* Llist::deletebegin(Llist* start)
{
	if(start==NULL)
	{
		cout<<"Empty Linked List"<<endl;
		return start;
	}
	Llist *temp=new Llist();
	temp=start;
	Llist *cur=start->next;
	delete start;
	start=cur;
	return start;
}

Llist* Llist::deleteend(Llist *start)
{
	if(start==NULL)
	{
		cout<<"Empty Linked List"<<endl;
		return start;
	}
	if(start->next==NULL)
	{
	delete start;
	start=NULL;
	return start;
	}
	Llist *temp=new Llist();
	Llist *cur=start;
	while(cur->next->next!=NULL)
		cur=cur->next;
	temp=cur->next;
	delete temp;
	cur->next=NULL;
	return start;
}

Llist* Llist::deleteele(int val,Llist *start)
{
	if(start->info==val)
	{
		start=deletebegin(start);
		return start;
	}
	Llist *cur=start;
	while(cur->next->info!=val)
	cur=cur->next;
	Llist *temp=new Llist();
	temp=cur->next;
	cur->next=cur->next->next;
	delete temp;
	return start;
}

int main()
{
	Llist L,*start=NULL;
	int ch,val,ele;
	cout<<"1.Display\t2.Insert at beginning\t3.Insert at end\t4.Insert after\t5.Delete from beginning\t6.Delete from end\t7.Delete element\t8.Exit "<<endl;
	do
	{
		cout<<"Enter your choice ";
		cin>>ch;

		switch(ch)
		{
		case 1:
			L.display(start);
			break;
		case 2:
			cout<<"Enter value to be enterred ";
			cin>>val;
			start=L.insertbegin(val,start);
			break;
		case 3:
			cout<<"Enter value to be enterred ";
			cin>>val;
			start=L.insertend(val,start);
			break;
		case 4:
			cout<<"Enter value to be enterred and after which element ";
			cin>>val>>ele;
			start=L.insertafter(val,ele,start);
			break;
		case 5:
			start=L.deletebegin(start);
			break;
		case 6:
			start=L.deleteend(start);
			break;
		case 7:
			cout<<"Insert value to be deleted ";
			cin>>val;
			start=L.deleteele(val,start);
			break;
		}
	}while(ch!=8);
	return 0;
}
