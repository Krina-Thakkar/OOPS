/*6. Synthesize a C++ program that has two classes (one for employee and one for student),
have a separate class for address (with door no, street name, city, state) and reuse address both for employee and student.
Perform insert, delete and display operations by taking choice of person (employee or student) from the user.
Allow user to have more than one address also. (c)*/

#include<iostream>
#include<string.h>
using namespace std;

class employee;
class student;

class address
{
	int door_no;
	char street_name[20];
	char city[20],state[20];
	public:
		friend class employee;
		friend class student;
		void inputa()
		{
			cout<<"enter door no.\n";
			cin>>door_no;
			cout<<"enter strret name\n";
			cin>>street_name;
			cout<<"enter city\n";
			cin>>city;
			cout<<"enter state\n";
			cin>>state;
		}
		void displaya()
		{
			cout<<"doorno.  \n"<<door_no;
			cout<<"street name  \n"<<street_name;
			cout<<"city  \n"<<city;
			cout<<"state  \n"<<state;
		}
};

class employee
{
	char name[20],id[20];
	int a;
	public:
		void input();
		void insert(int ne);
		void del(char (&na)[20],int ne);
		void display();
		char* getname()
		{
			return name;
		}
		
}e[20];

void employee::input()
{
			
			address ad[20];
			cout<<"enter name\n";
			cin>>name;
			cout<<"enter id\n";
			cin>>id;
			cout<<"how many address u want to add\n";
			cin>>a;
			for(int i=0;i<a;i++)
			ad[i].inputa();
}

void employee::insert(int ne)
		{
			int x;
			cout<<"how many employee info u wanna add\n";
			cin>>x;
			for(int i=ne;i<ne+x;i++)
			{
				e[i].input();
			}
		}

void employee::del(char (&nam)[20],int ne)
		{
			for(int i=0;i<ne;i++)
			{
				if(strcmp(e[i].getname(),nam)==0)
				strcpy(e[i].getname(),"DELETED");
			}
//			for(int i=0;i<ne;i++)
//	e[i].display();
		}
		
void employee::display()
		{
			address ad[20];
			cout<<"name:  "<<name;
			cout<<"id:  "<<id;
		    for(int i=0;i<a;i++)
		    ad[i].displaya();
		}		
		
class student
{
	char name[20];
	char branch[20];
	int k;
	public:
		void input();
		void insert(int &);
		void del(char (&na)[20],int ns);
		void display();
		char* getname()
		{
			return name;
		}
}s[20];

void student::input()
{
	address ad[20];
	cout<<"enter name of student\n";
	cin>>name;
	cout<<"enter branch\n";
	cin>>branch;
	cout<<"how mny address u want to add for student\n";
	cin>>k;
	for(int i=0;i<k;i++)
	{
		ad[i].inputa();
	}
}

void student::insert(int &ns)
{
	int j;
	cout<<"how mny students info u want to add\n";
	cin>>j;
	for(int i=ns;i<ns+j;i++)
	s[i].input();
}

void student::del(char (&nam)[20],int ns)
{
	for(int i=0;i<ns;i++)
	{
		if(strcmp(nam,s[i].getname())==0)
		strcpy(s[i].getname(),"DELETED");
		return;
	}
//	for(int i=0;i<ns;i++)
//	s[i].display();
}

void student::display()
{           address ad[20];
            cout<<"name:  "<<name;
			cout<<"branch:  "<<branch;
		    for(int i=0;i<k;i++)
		    ad[i].displaya();
}

int main()
{
	employee em;
	student st;
	int i,j,ne,ns,x,y;
	char nam[20],ch;
	cout<<"\n\nHow many employees\n";
	cin>>ne;
	for(i=0;i<ne;i++)
	{
		cout<<"\n\nEnter the details for employee: "<<i+1<<endl;
		e[i].input();
	}
	cout<<"\n\nHow many students \n";
	cin>>ns;
	for(i=0;i<ns;i++)
	{
		cout<<"\n\nEnter the details of student: "<<i+1<<endl;
	    s[i].input();
	}
	do
	{
	cout<<"MENU"<<endl;
	cout<<"Enter your choice:\n";
	cout<<"1. Employee\n"<<"2. Student\n";
	cin>>y;
    cout<<"1. Insert \n"<<"2. Delete\n"<<"3. Display\n";
	cin>>x;
	switch(y)
	{
		case 1:
		        switch(x)
	        {
	        	case 1:
	        		em.insert(ne);
	        		break;
	        	case 2:
	        		cout<<"Enter the name of which you want to delete information\n";
	        		cin>>nam;
	        		em.del(nam,ne);
	        		break;
	        	case 3:
	        	    for(i=0;i<ne;i++)
	        	    e[i].display();
	        	    break;
	        	default:cout<<"INVALID INPUT!!!";
	        }
	        for(int i=0;i<ne;i++)
	        e[i].display();
	    case 2:
	    		switch(x)
	        {
	        	case 1:
	        		st.insert(ns);
	        		break;
	        	case 2:
	        		cout<<"Enter the name of which you want to delete information\n";
	        		cin>>nam;
	        		st.del(nam,ns);
	        		break;
	        	case 3:
	        	    for(i=0;i<ns;i++)
	        	    s[i].display();
	        	    break;
	        	default:cout<<"INVALID INPUT!!!";
	        }
	        for(int i=0;i<ns;i++)
	        s[i].display();
    }
    cout<<"Want to perform more operations Y for yes or N for no:\n";
    cin>>ch;
}while(ch=='Y'||ch!='N');
    return 0;
}
