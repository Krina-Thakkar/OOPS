#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

	static int balance= 0;
	static int pin= 1111;
	
class savingacc
{
	char name[50];
	//long int phnno;
	int accno;

	public:
		char date[50];
		savingacc()
		{
			strcpy(name,"NULL");
			//phnno=3123331;
			accno=0;
			balance=0;
		}
/*		savingacc(savingacc &s)
		{
			phnno=s.phnno;
			accno=s.accno;
			strcpy(name,s.name);
		}*/
	//	void pinchange(int);
		int withdrawl(int);
		int deposit(int);
		void statementprint();
		void input();
}s1;

void savingacc::input()
{
	cout<<setw(20)<<"enter detais"<<endl;
	cout<<"enter account owner's name:  "<<endl;
	cin>>name;
	cout<<"enter account name:  "<<endl;
	cin>>accno;
}

int savingacc::withdrawl(int w)
{
	if(balance<w)
	cout<<"insufficient balance"<<endl;
	else
	{
		balance=balance-w;
	}
	return balance;
}

int savingacc::deposit(int d)
{
	balance=balance+d;
	return balance;
}

void savingacc::statementprint()
{
	cout<<"balance:  "<<balance;
	cout<<"date:  "<<date;
	cout<<"account owner:  "<<name;
//	cout<<"deposited:  "<<s1.deposit(int d);
//	cout<<"withdrawl:  "<<s1.withdrawl(w);
}

/*void savingacc::pinchange(int pin_no)
{   
    int pn;
    //if(accno==account_no)
    //{
	if(pin=pin_no)
	{
	cout<<"enter new pin no: "<<endl;
	cin>>pn;
	cout<<"pin changed successfuly"<<endl;
	}
	//}
	return pn;
}*/
int main()
{
	savingacc s[50];
	int l,ch,i=0;
	char a;
	s1.input();
	do
	{
		cout<<"enter pin for verification"<<endl;
		cin>>l;
		if(pin==l)
		{
			cout<<"enter date:  "<<endl;
			cin>>s1.date;
			cout<<setw(15)<<"MENU"<<endl;
			cout<<"enter your choice"<<endl;
			cout<<"1 withdrawl \n2 deposit \n3 pin change"<<endl;
			cin>>ch;
			switch(ch)
			{
				int amt;
				case 1:
					cout<<"enter amount to be withdrawn"<<endl;
					cin>>amt;
					s[i].withdrawl(amt);
					break;
				case 2:
					cout<<"enter amt to b deposited"<<endl;
					cin>>amt;
					s[i].deposit(amt);
					break;
				case 3:
					int x;
					cout<<"enter old pin"<<endl;
					cin>>l;
					if(pin==l)
					{
						cout<<"enter new pin"<<endl;
						cin>>x;
						pin=x;
					}
					else
					cout<<"wrong pin"<<endl;
					break;
				default:
					cout<<"invalid input"<<endl;
			}
	cout<<"Want to perform more operation enter Y for yes or N for no\n\n";
	cin>>a;
	i++;
}
	else
	{
	cout<<"you entered wrong pin no."<<endl;
    }
	
	}while(a=='y' || a!='n');
	cout<<setw(20)<<"ACCOUNT SUMMARY"<<endl;
	for(int j=0;j<i;j++)
	s[j].statementprint();
	return 0;
}
