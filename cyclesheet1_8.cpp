/*7. Create an class that stores details about the computer (Assembled/branded, RAM, HDD, processor speed, price etc.,).
Use constructors to initialize the object and a destructor that deducts the count of object each time the object is passed to destroy function.
Also use copy constructor to create a system with the configuration same as that’s of an existing system.(b)*/
#include<iostream>
#include<string.h>
using namespace std;

class computer
{
	int ram,hdd;
	char brand[10];
	float processor_speed;
	int price;
	static int count;
	public:
	computer()
	{
		count++;
		ram=5;
		strcpy(brand,"dell");
		price=500000;
		hdd=500;
		processor_speed=20.5;
	}
	~computer()
	{
		count--;
	}
	void input();
	void output();
	computer(computer & c1)
	{
		ram=c1.ram;
		hdd=c1.hdd;
		strcpy(brand,c1.brand);
		price=c1.price;
		processor_speed=c1.processor_speed;
	}
};

int computer::count;

void computer::input()
{
	cout<<"enter cmp details"<<endl;
	cout<<"enter ram"<<endl;
	cin>>ram;
	cout<<"enter hdd"<<endl;
	cin>>hdd;
	cout<<"enter price"<<endl;
	cin>>price;
	cout<<"enter processor speed"<<endl;
	cin>>processor_speed;
	cout<<"enter brand"<<endl;
	cin>>brand;
}

void computer::output()
{
	cout<<"\n\nDetails"<<endl;
	cout<<"ram: "<<ram<<endl;
	cout<<"hdd: "<<hdd<<endl;
	cout<<"price: "<<price<<endl;
	cout<<"brand: "<<brand<<endl;
	cout<<"processor speed: "<<processor_speed<<endl;
}
int main()
{
	computer c1[50];
	int n,m;
	char ch;
	cout<<"enter how many computers detail u want to add"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter 'a' if u want to add detild or 'c' if u wanna copy"<<endl;
		cin>>ch;
		if(ch=='a')
		c1[i].input();
		else
		{
		cout<<"enter cmputers no. of which u want to copy"<<endl;
		cin>> m;
		if(m<i)
		computer c[i]=c[m];
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<"details of computer"<<i+1<<endl;
		c1[i].output();
	}
	return 0;
}
