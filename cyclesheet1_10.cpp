/*
Create a class which maintains information like username, password, age, mailid, phone number, accepted friends 
list, etc.,. Declare a friend function inside the class.  Create 3 users such that the first user is friend with
 2 and 3 (update friend llist of 1 with user names of 2 and 3). If the user1 logs in, he should see the personal 
 information of 2 and 3, likewise 2 and 3 should see personal info of 1. However, 2 can't see the personal information
  of 3 and vise versa. 
*/
#include<iostream>
#include<string.h>
using namespace std;

class base
{
	public:
	char name[50];
	char password[50];
	int age;
	char id[100];
	long phnno;

		void input()
		{
			cout<<"enter name"<<endl;
			cin>>name;
			cout<<"enter age"<<endl;
			cin>>age;
			cout<<"enter id"<<endl;
			cin>>id;
			cout<<"enter phno"<<endl;
			cin>>phnno;
			cout<<"enter password"<<endl;
			cin>>password;
		}
}x;
class person2;
class person3;
class person1:public base
{
	public:
		person1()
		{
			input();
		}
		friend void acc(person2 b,person3 c);
};

class person2:public base
{
	public:
		person2()
		{
			input();
		}
		friend void acc(person1 a);
};

class person3:public base
{
	public:
		person3()
		{
			input();
		}
		friend void acc(person1 a);
};

void acc(person1 a)
{
	cout<<"\nFRIENDS\n"<<endl;
	cout<<"name: "<<a.name<<endl;
	cout<<"age:  "<<a.age<<endl;
	cout<<"phnno.:  "<<a.phnno<<endl;
	cout<<"email id:  "<<a.id<<endl;
}

void acc(person2 b,person3 c)
{
	cout<<"\nFRIENDS\n"<<endl;
	cout<<"name: "<<b.name<<endl;
	cout<<"age:  "<<b.age<<endl;
	cout<<"phnno.:  "<<b.phnno<<endl;
	cout<<"email id:  "<<b.id<<endl;
	cout<<"name: "<<c.name<<endl;
	cout<<"age:  "<<c.age<<endl;
	cout<<"phnno.:  "<<c.phnno<<endl;
	cout<<"email id:  "<<c.id<<endl;
}

int main()
{
	char nam[50],paswrd[50];
	person1 p;
	person2 q;
	person3 r;
	int flag;
	char ch;
	do
	{
	cout<<"enter username and password"<<endl;
	cin>>nam>>paswrd;
	if(strcmp(p.name,nam)==0 && strcmp(p.password,paswrd)==0)
	{
		acc(q,r);	
	}
	else if(strcmp(nam,q.name)==0 && strcmp(paswrd,q.password)==0)
	acc(p);
	else if(strcmp(nam,r.name)==0 && strcmp(paswrd,r.password)==0)
	acc(p);
	else
	cout<<"wrong input"<<endl;
	cout<<"do u want to enter again(1=yes and 2=no)"<<endl;
	cin>>flag;
	
}while(flag==1);
	return 0;
}
