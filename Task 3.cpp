#include<iostream>
using namespace std;
class Employee{
	private:
		string name;
		int empID;
		float baseSalary;
		int hoursWorked;
		public:
		Employee(string n, int id,int salary,int wh)
		{
			name = n;
			empID = id;
			baseSalary = salary;
			hoursWorked = wh;
		}
		void salary()
		{
			if(hoursWorked>40)
			{
				baseSalary *= 1.5;
			}
		}
		void display()
		{
			cout<<"Employee Name is : "<<name<<endl;
			cout<<"ID is : "<<empID<<endl;
			cout<<"Total Salary : "<<baseSalary<<endl;
			cout<<"Work hours are : "<<hoursWorked<<endl;
		}
};
int main()
{
	Employee e1("Vivek",201,10000,69);
	Employee e2("Mahender",202,10000,34);
	e2.salary();
	e2.display();
	e1.salary();
	e1.display();
	return 0;
}