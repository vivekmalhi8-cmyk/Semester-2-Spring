#include<iostream>
using namespace std;
int main()
{
	int marks[]={87,56,78,98,89};
	int Total=0;
	float Average;
	cout << "Enter marks for 5 subjects:"<<endl;
	for(int i=0; i<5; i++)
	{
		cout<<"Subject "<<i+1<<" "<<marks[i]<<endl;
		Total += marks[i];
	}
	cout <<"Total Marks: "<<Total<<endl;
	Average = Total/5.0;
	cout << "Average Marks: "<<Average<<endl;
	if(Average < 50)
	{
		cout <<"Result: FAIL"<<endl;
	}else
	{
		cout <<"Result: PASS"<<endl;
	}
}