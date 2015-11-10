/* create a class id_card that maintains details of id card.
perform insert,update,delete and display operation through functions that takes input through refrence parameter */

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class idcard
{
	char name[50];
	char regno[50];
	char branch[50];
	public:
		char* getregno()
		{
			return regno;
		}
		void input();
		void insert(int &);
		void update();
		void del(char (&re)[50],int &);
		void display();
}id[20];

void idcard :: input()
{
	cout<<"enter name";
	cin>>name;
	cout<<"enter regno";
	cin>>regno;
	cout<<"enter branch";
	cin>>branch;
}

void idcard::display()
{
	if(strcmp(regno,"DELETED")!=0)
	{
		cout<<"reg no: "<<regno<<endl;
		cout<<"name: "<<name<<endl;
		cout<<"branch: "<<branch<<endl;
	}
}

void idcard::insert(int &n)
{
	int a;
	cout<<"how many id card u want to insert more"<<endl;
	cin>>a;
	for(int i=n;i<a+n;i++)
	{
		cout<<"Enter details of "<<i+1<<" Student\n";
		id[i].input();
		cout<<"Inserted information is\n";
		id[i].display();
	}

}

void idcard::update()
{
	int x;
	char nam[50],bran[50];
	cout<<"wat info u want to update"<<endl;
	cout<<endl<<setw(15)<<"UPDATE MENU"<<endl;
	cout<<"1. name\n2. branch\n";
	cin>>x;
	switch(x)
	{
		case 1:
			cout<<"enter new name"<<endl;
			cin>>nam;
			strcpy(name,nam);
			cout<<"\nupdated info\n";
			display();
			break;
		case 2:
			cout<<"enter new branch"<<endl;
			cin>>bran;
			strcpy(branch,bran);
			cout<<"\nupdated info\n";
			display();
			break;
			default:
				cout<<"invalid input"<<endl;
	}
}

void idcard::del(char (&reg)[50],int &n)
{
	
	for(int i=0;i<n;i++)
	{
		if(strcmp(id[i].getregno(),reg)==0)
		strcpy(id[i].getregno(),"DELETED");
		return;
	}
	cout<<"reg no doesnt exist"<<endl;
}

int main()
{
	idcard card;
	int n,choice,a=0;
	char reg[50],ch;
	cout<<"for how mny students u wanna enter details"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		id[i].input();
	}
	do{
	cout<<setw(15)<<"MENU"<<endl;
	cout<<"1 insert\n2 update\n3 delete\n"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			card.insert(n);
			break;
		case 2:
			cout<<"enter regno of which u want to make changes"<<endl;
			cin>>reg;
			for(int i=0;i<n;i++)
			{
				if(strcmp(id[i].getregno(),reg)==0)
				{
			      id[i].update();
			      a=i;
			    }
			}
				if(a==-1)
				cout<<"wrong reg no"<<endl;
		        break;
		case 3:
			cout<<"enter regno u want to delete"<<endl;
			cin>>reg;
			card.del(reg,n);
			break;
	/*	case4:
			for(idisplay();
			break; */
	/*	case4:
			cout<<"wrong input"<<endl;
			break;*/
		default:
			cout<<"invalid input"<<endl;
			break;
	}
	for(int i=0;i<n;i++)
	{
		id[i].display();
	}
	cout<<"Do want to make more changes Y for yes or N for no\n";
    cin>>ch;
    }while(ch=='Y'||ch!='N');
return 0;	
}
