#include<iostream>
using namespace std;
class MedicationEntry{
	public:
	string Drugname;
	int dose;
	int timeGiven;
	MedicationEntry(string Drugname,int dose,int timeGiven)
	{
		this->dose = dose;
		this->Drugname = Drugname;
		this->timeGiven = timeGiven;
	}
};
class VitalSignCheck{
	public:
	float temperature;
	int heartRate;
	string timeCheck;
	VitalSignCheck(float temperature,int heartRate,string timeCheck)
	{
		this->temperature = temperature;
		this->heartRate = heartRate;
		this->timeCheck = timeCheck;
	}
};
class DiagnosisNote{
	public:
	string noteText;
	string doctorName;
	string date;
	DiagnosisNote(string noteText,string doctorName,string date)
	{
		this->date = date;
		this->noteText = noteText;
		this->doctorName = doctorName;
	}
};
class Patient{
	public:
	int id;
	string name;
	string dob;
	MedicationEntry med;
	VitalSignCheck vital;
	DiagnosisNote dignos;
	Patient(int id,string name,string dob,string dna,int d,int tg,float t,int h,string check,string nt,string dn,string date):med(dna,d,tg),dignos(nt,dn,date),vital(t,h,check)
	{
		this->name = name;
		this->id = id;
		this->dob = dob;
	}
	void show()
	{
		cout<<"Patient Name : "<<name<<endl;
		cout<<"ID : "<<id<<endl;
		cout<<"Date of Birth : "<<dob<<endl;
		cout<<"\n=== Medication Report ===\n";
		cout<<"Drug Name : "<<med.Drugname<<endl;
		cout<<"How many times : "<<med.dose<<endl;
		cout<<"For "<<med.timeGiven<<" days\n";
		cout<<"\n=== Vital Sign Report ===\n";
		cout<<"Body Temperature : "<<vital.temperature<<endl;
		cout<<"Heart rate : "<<vital.heartRate<<endl;
		cout<<"It have checked at "<<vital.timeCheck<<endl;
		cout<<"\n=== Diagnosis Report ===\n";
		cout<<"Doctor Name : "<<dignos.doctorName<<endl;
		cout<<"Have Written : "<<dignos.noteText<<endl;
		cout<<"At that Date : "<<dignos.date<<endl;
	}
	~Patient()
	{
		cout<<"All records are deleting here of #"<<id<<endl;
	}
};
int main()
{
	Patient p1(102,"Mahender","28/04/2007","paracetamol",2,15,37.7,89,"morning","Alwat take medicine twice a day","Vivek","12/07/026");
	p1.show();
	return 0;
}