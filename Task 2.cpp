#include<iostream>
using namespace std;
typedef struct Book{
	int id;
	string title;
	string author;
	float price;
}lib;
void input(lib b1[])
{
    cout <<"Enter Details for 3 books: "<<endl;
    for(int i=0; i<3; i++)
    {
	cin>>b1[i].id;
    cin>>b1[i].title;
    cin>>b1[i].author;
    cin>>b1[i].price;
    }
}
void display(lib b1[])
{
    cout << "Book Details: "<<endl;
    for(int i=0; i<3; i++)
    {
        cout << "Book "<<i+1<<endl;
        cout<<"ID: "<<b1[i].id<<endl;
        cout<<"Title: "<<b1[i].title<<endl;
        cout<<"Author: "<<b1[i].author<<endl;
        cout<<"Price: "<<b1[i].price<<endl;
    }
}
void totalprice(lib b1[])
{
    float total=0;
    for(int i=0; i<3; i++)
    {
        total += b1[i].price;
    }
    cout <<"Total Price of 3 books: "<<total<<endl;
}
int main()
{
	lib b1[3];
    input(b1);
    display(b1);
    totalprice(b1);
}