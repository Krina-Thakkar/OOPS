/*6. Synthesize a C++ program that has two classes (one for employee and one for student),
have a separate class for address (with door no, street name, city, state) and reuse address both for employee and student.
Perform insert, delete and display operations by taking choice of person (employee or student) from the user.
Allow user to have more than one address also. (c)*/
using namespace std;
#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
class employee;
class student;
class address{
	int doorNo;
	char street[10],city[10],state[10];
	public:
		friend employee;
		friend student;
		void inputA();
		void outputA();
};
void address::inputA()
{
	cout<<"Door no.:\n";
	cin>>doorNo;
	cout<<"Street:\n";
	cin>>street;
	cout<<"City:\n";
	cin>>city;
	cout<<"State:\n";
	cin>>state;
}
void address::outputA()
{
	cout<<"Door no.: "<<doorNo<<endl;
	cout<<"Street: "<<street<<endl;
	cout<<"City: "<<city<<endl;
	cout<<"State: "<<state<<endl;
}
class employee{
	char nameE[15],post[15];
	int ageE,aE;
	public:
		void inputE();
		void displayE();
		void insertE(int );
		void delE(employee *,char [],int );
}emp[20];
void employee::inputE()
{
	address addE[10];
	cout<<"Name of employee:\n";
	cin>>nameE;
	cout<<"Post of employee:\n";
	cin>>post;
	cout<<"Age:";
	cin>>ageE;
	cout<<"Number of address:\n";
	cin>>aE;
	for(int i=0;i<aE;i++)
	{
		cout<<"Enter address: "<<i+1<<endl;
		addE[i].inputA();
	}
}
void employee::insertE(int n)
{
	int i,in;
	cout<<"How many employee information you want to insert:\n";
	cin>>in;
	for(i=n;i<in+n;i++)
	emp[i].inputE();
}
void employee::displayE()
{
	address addE[10];
	if(strcmp(nameE,"DELETED")!=0)
	{
		cout<<"Name: "<<nameE<<endl;
	    cout<<"Post: "<<post<<endl;
	    cout<<"Age: "<<ageE<<endl;
	    for(int i=0;i<aE;i++)
	{
		cout<<"Address: "<<i+1<<endl;
		addE[i].outputA();
	}
	}
}
void employee::delE(employee *em,char nam[],int n)
{
	for(int i=0;i<n;i++)
	if(strcmp(em[i].nameE,nam)==0)
	strcpy(em[i].nameE,"DELETED");
}
class student{
	char nameS[15],branch[10];
	int ageS,aS;
	public:
		void inputS();
		void displayS();
		void insertS(int );
		void delS(student *,char [],int );
}stu[20];
void student::inputS()
{
	address addS[10];
	cout<<"Name of student:\n";
	cin>>nameS;
	cout<<"Branch of student:\n";
	cin>>branch;
	cout<<"Age:";
	cin>>ageS;
	cout<<"Number of addresses:\n";
	cin>>aS;
	for(int i=0;i<aS;i++)
	{
		cout<<"Enter address: "<<i+1<<endl;
		addS[i].inputA();
	}
}
void student::insertS(int n)
{
	int i,in;
	cout<<"How many students information you want to insert:\n";
	cin>>in;
	for(i=n;i<in+n;i++)
	stu[i].inputS();
}
void student::displayS()
{
	address addS[10];
	if(strcmp(nameS,"DELETED")!=0)
	{
		cout<<"Name: "<<nameS<<endl;
		cout<<"Branch: "<<branch<<endl;
		cout<<"Age: "<<ageS<<endl;
		for(int i=0;i<aS;i++)
	{
		cout<<"Address: "<<i+1<<endl;
		addS[i].outputA();
	}
	}
}
void student::delS(student *st,char nam[],int n)
{
	for(int i=0;i<n;i++)
	if(strcmp(st[i].nameS,nam)==0)
	strcpy(st[i].nameS,"DELETED");
}
int main()
{
	employee em;
	student st;
	int i,j,nE,nS,x,y;
	char nam[20],ch;
	cout<<"\n\nHow many employees\n";
	cin>>nE;
	for(i=0;i<nE;i++)
	{
		cout<<"\n\nEnter the details for employee: "<<i+1<<endl;
		emp[i].inputE();
	}
	cout<<"\n\nHow many students \n";
	cin>>nS;
	for(i=0;i<nS;i++)
	{
		cout<<"\n\nEnter the details of student: "<<i+1<<endl;
	    stu[i].inputS();
	}
	do
	{
	cout<<setw(20)<<"MENU"<<endl;
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
	        		em.insertE(nE);
	        		break;
	        	case 2:
	        		cout<<"Enter the name of which you want to delete information\n";
	        		cin>>nam;
	        		em.delE(emp,nam,nE);
	        		break;
	        	case 3:
	        	    for(i=0;i<nE;i++)
	        	    emp[i].displayE();
	        	    break;
	        	default:cout<<"INVALID INPUT!!!";
	        }
	    case 2:
	    		switch(x)
	        {
	        	case 1:
	        		st.insertS(nS);
	        		break;
	        	case 2:
	        		cout<<"Enter the name of which you want to delete information\n";
	        		cin>>nam;
	        		st.delS(stu,nam,nS);
	        		break;
	        	case 3:
	        	    for(i=0;i<nS;i++)
	        	    stu[i].displayS();
	        	    break;
	        	default:cout<<"INVALID INPUT!!!";
	        }
    }
    cout<<"Want to perform more operations Y for yes or N for no:\n";
    cin>>ch;
}while(ch=='Y'||ch!='N');
    //getch();
}
