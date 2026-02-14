#include<iostream>
using namespace std;
class Account{
	long int accountNo;
	string name;
	int balance;
	public:
		Account(long int ac,string n,int b)
		{
			accountNo=ac;
			name = n;
			balance = b;
		}
		void withdraw(int n)
		{
			if(n>0 && n<balance)
			{
				balance -= n;
				cout<<"balance after withdraw is : "<<balance;
			}else{
				cout<<"Invalid amount or more then balance\n";
			}
		}
		void deposit(int n)
		{
			if(n>0)
			{
				balance += n;
				cout<<"balance after deposit : "<<balance<<endl;
			}else
			{
				cout<<"Invalid amount\n";
			}
		}
		void display(){
			cout<<"Account number is : "<<accountNo<<endl;
			cout<<"Holder Name : "<<name<<endl;
			cout<<"Current balance is : "<<balance<<endl;
		}
};
int main()
{
	Account a1(16477532,"Vivek",5000);
	a1.display();
	a1.deposit(500);
	a1.withdraw(1000);
	return 0;
}