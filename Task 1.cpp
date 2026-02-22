#include<iostream>
using namespace std;
class Restaurant;
class Order;
class Customer{
	string name;
	public:
		Customer(string name)
		{
		this->name=name;
		}
		string getname()
		{
			return name;
		}
		void PlaceOrder(Restaurant* r,string food);
};
class Restaurant{
	string name;
	public:
		Restaurant(string name)
		{
			this->name = name;
		}
		string getName()
		{
			return name;
		}
		void takeOrder(Order* o);
};
class Order{
	public:
	static int count;
	int id;
	string restaurant;
	string customer;
	string foodItem;
	Restaurant *r;
	Customer *c;
		Order(Restaurant *r,Customer *c,string foodItem)
		{
			this->customer = c->getname();
			this->restaurant = r->getName();
			this->foodItem = foodItem;
			count++;
			this->id=1000+count;
		}
		void print()
		{
			cout<<"Order #"<<id<<": "<<foodItem<<" for "<<customer<<" from "<<restaurant<<endl;
		}
};
int Order::count=0;
void Customer::PlaceOrder(Restaurant* r,string food)
{
	cout<<r->getName()<<" making: "<<food<<endl;
}
void Restaurant::takeOrder(Order* o)
{
	cout<<o->customer<<" placed order at "<<name<<endl;
}
int main()
{
	Restaurant r1("Pizza Heaven");
	Restaurant r2("Taco Fiesta");
	Customer c1("Alice");
	Customer c2("Bob");
	Order o1(&r1,&c1,"Pepperoni Pizza");
	Order o2(&r2,&c2,"Burito");
	cout<<"\n=== PLACING ORDERS ===\n";
	r1.takeOrder(&o1);
	r2.takeOrder(&o2);
	r2.takeOrder(&o1);
	cout<<"\n=== ORDER DETAILS ===\n";
	o1.print();
	o2.print();
	cout<<"\n=== RESTAURANT STATUS ===\n";
	c1.PlaceOrder(&r1,"Pepperoni Pizza");
	c2.PlaceOrder(&r2,"Burrito");
	cout<<"\n=== AFTER ORDERS ARE GONE ===\n";
	cout<<"Customer Still exist: "<<o1.customer<<endl;;
	cout<<"Restaurant still exists: "<<o2.restaurant<<endl;
	return 0;
}