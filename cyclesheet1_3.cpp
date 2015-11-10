/*3. Create a class that holds the details of the mobile phone like brand, imei, no of sim
cards, phone numbers etc.,.
Allow user to login with their mobile no. Use a function that sends a message from that
mobile. Maintain the details of the message as a static member inside the send message
function and display each time all the messages sent from that mobile. (b)*/
#include<iostream>
#include<string.h>
using namespace std;

class mob
{
	char brand[10];
	char message[20][20];
	static char mess[20][20];
	long phno1,phno2;
	long imei;
	int no_of_sim,x;
	public:
		mob()
		{
			no_of_sim=0;
			
		}
		void input();
		void login(mob m[],long,int);
		void sendmessage(long,long);
		void history(mob m[],int,long);
};

char mob::mess[20][20];

void mob::input()
{
                  cout<<"Enter the brand\n";
                  cin>>brand;
                  cout<<"Enter the imei number\n";
                  cin>>imei;
                  cout<<"How many sim\n";
                  cin>>no_of_sim;
                  cout<<"Enter the one mobile number\n";
                  cin>>phno1; 
                  if(no_of_sim==2)
                  {
                              cout<<"Enter the second mobile number\n";
                              cin>>phno2;
                  }
}
void mob::login(mob m[],long p1,int n)
{
	long p2;
	for(int i=0;i<n;i++)                         
	{   
		if(m[i].phno1==p1 || m[i].phno2==p1)
		{
		cout<<"Login Successful"<<endl;
		cout<<"enter mobile no. to which u want to send message"<<endl;
		cin>>p2;
		sendmessage(p1,p2);
		return;
		}
		cout<<"wrong phone no. maa"<<endl;
	}
}

void mob::sendmessage(long p1,long p2)
{
	int n;
	cout<<"enter how many msg u wan to send"<<endl;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cin.getline(message[i],100);
		strcpy(mess[x],message[i]);
		x++;
	}
	cout<<"ur msg is sent"<<endl;
}

void mob::history(mob m[],int n,long p1)
{
	long m1;
	cout<<"enter mobile no. of which u want history"<<endl;
	cin>>m1;
	for(int i=0;i<n;i++)
	{
		if(m[i].phno1==m1 || m[i].phno2==m1)
		{
			if(m1==p1)
			{
			/*cout<<"sent"<<endl;
			else
			cout<<"received"<<endl;*/
			for(int j=0;j<x;j++)
			cout<<mess[j]<<endl;
			}
		}
		else
		cout<<"wrong ph no"<<endl;
	}
}

int main()
{
	mob mobile[20],mo1;
	int n;
	char ch;
	long p1;
	cout<<"how many mobiles"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter details of "<<i+1<<"mobile"<<endl;
		mobile[i].input();
	}
	do
	{
		cout<<"enter mbile no with which u want to send message"<<endl;
		cin>>p1;
		mo1.login(mobile,p1,n);
		cout<<"\nYou want to Send more messages from different mobile number Y for yes or N for no\n";
        cin>>ch;
}while(ch=='Y'||ch!='N');
		mo1.history(mobile,n,p1);
		return 0;
}
