/*Create a C++ program that takes employee details like ID, first name, last name,
age and address. Create a class for student {name, course, regular/parttime, address}. Use
friend function to check that a student with same name and address can’t be a regular
student as well as an employee.*/

#include<iostream>
#include<string.h>
using namespace std;

class student;
class employee
{
	char id[50];
	char fn[50];
	char ln[50];
	int age;
	char address[50];
	public:
	void input()
	{
		cout<<"enter details of employee"<<endl;
		cout<<"id: "<<endl;
		cin>>id;
		cout<<"first name\n";
		cin>>fn;
		cout<<"last name\n";
		cin>>ln;
		cout<<"age\n";
		cin>>age;
		cout<<"address\n";
	    cin>>address;
	}	
	friend void check(student &,employee &);
};

class student
{
	char name[50];
	char course[50];
    //regular or parttime
	char address[50];
	public:
		void input()
		{
		cout<<"enter details of student"<<endl;
		cout<<"name: "<<endl;
		cin>>name;
		cout<<"course: \n";
		cin>>course;
		cout<<"address\n";
		cin>>address;	
		}
		friend void check(student &,employee &);
};

void check(student &s,employee &e)
{
	if((strcmp(s.name,e.fn)==0) && (strcmp(s.address,e.address)==0))
	{
		cout<<"not a regular student\n";
	}
	else
	cout<<"\nregular student"<<endl;
}

int main()
{
	student s1;
	employee e1;
	e1.input();
	s1.input();
	check(s1,e1);
	return 0;
}
