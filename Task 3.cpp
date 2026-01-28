#include<iostream>
using namespace std;
struct Student{
    int Roll;
    string Name;
    int marks[3];
    float CGPA;
};
void input(struct Student *s[], int n)
{
    
    for(int i=0; i<n; i++)
    {
    	int total=0;
    cout <<"Enter details for Student"<<i+1<<endl;
    cout <<"Roll No: ";
    cin>>s[i]->Roll;
    cout <<"Name: ";
    cin>>s[i]->Name;
    cout <<"Marks (3 subjects): ";
    for(int j=0; j<3; j++)
    {
        cin>>s[i]->marks[j];
        total += s[i]->marks[j];
    }
    s[i]->CGPA = total/30.0;
    cout <<"Calculated CGPA: ";
    cout <<s[i]->CGPA<<endl;
    }
}
void CGPA(struct Student *s[], int n)
{
    cout <<"Students with CGPA >= 3.0:"<<endl;
    for(int i=0; i<n; i++)
    {
        if(s[i]->CGPA >= 3.0)
        {
            cout <<i+1<<". "<<s[i]->Name<<" - CGPA: "<<s[i]->CGPA<<endl;
        }
    }
    float highest=s[0]->CGPA;
    int index =0;
    for(int i=1; i<n; i++)
    {
        if(s[i]->CGPA > highest)
        {
            highest = s[i]->CGPA;
            index = i;
        }
    }
    cout <<"Top Performer: "<<s[index]->Name<<" with CGPA: "<<highest<<endl;
}
int main()
{
    int n;
    cout <<"Enter number of students: ";
    cin>>n;
    Student *s[n];
    for(int i=0;i<n;i++)
    	s[i] = new Student;
    input(s,n);
    CGPA(s,n);
    for(int i=0;i<n;i++)
    	delete s[i];
    return 0;
}