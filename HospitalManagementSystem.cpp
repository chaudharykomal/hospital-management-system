/*You are required to implement a simplified hospital management system in C++ to manage patients , doctors , and their appointments. The system should allow
adding new patients and doctors , scheduling appointments , and  viewing  the details of patients , doctors, and scheduled appointments.*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pid;
int did;

class Patient{
    public:
    string name;
    string gender;
    int age ;
    int ID;
    Patient(string n , int a, string g){
        ID = pid ;
        pid++;
        name = n;
        age = a;
        gender = g;
    }
};
class Doctor{
    public:
    string name;
    string gender;
    int age ;
    int ID;
    Doctor(string n , int a, string g){
        ID= did ;
        did++;
        name = n;
        age = a;
        gender = g;
    }
};
class Appointment{
public:
int patientID;
int doctorID;
string Date;

Appointment(int p, int d, string date){
    Date = date;
    patientID=p;
    doctorID=d;
    }
};
vector<Patient> allPatients;
vector<Doctor> allDoctors;
vector<Appointment> allAppointments;

bool isPatientpresent(int id){
    bool ans = false;
    for(int i =0; i<allPatients.size();i++){
        if(allPatients[i].ID==id){
            ans = true;
        }
    }
    return ans;
}

bool isDoctorpresent(int id){
    bool ans = false;
    for(int i =0; i<allDoctors.size();i++){
        if(allDoctors[i].ID==id){
            ans = true;
        }
    }
    return ans;
}
void addpatient(){
string n, g;
int a;
cout<<"Give the patient name"<<endl;
cin>>n;
cout<<"Give the patient age"<<endl;
cin>>a;
cout<<"Give the patient gender"<<endl;
cin>>g;
Patient temp(n, a , g);
allPatients.push_back(temp);
}
void adddoctor(){
string n, g;
int a;
cout<<"Give the patient name"<<endl;
cin>>n;
cout<<"Give the patient age"<<endl;
cin>>a;
cout<<"Give the patient gender"<<endl;
cin>>g;
Patient temp(n, a , g);
allPatients.push_back(temp);
}
void ScheduleAppointments(){
int patientID;
int doctorID;
string Date;
cout<<" Give the patient ID:"<<endl;
cin>>patientID;
cout<<" Give the doctor ID:"<<endl;
cin>>doctorID;
cout<<" Give the date in DD-MM-YYYY :"<<endl;
cin>>Date;

if(isPatientpresent(patientID)==false || isDoctorpresent(doctorID)==false){
    cout<<" Invalid Patient ID or Doctor ID"<<endl;
    cout<<"Appointment Scheduled unsucessfull"<<endl;
    return ;
}

Appointment temp(patientID, doctorID, Date);
allAppointments.push_back(temp);
}
void viewpatient(){
for(int i =0 ; i<allPatients.size();i++){
    cout<<"Patient"<<allPatients[i].name<<endl;
}
cout<<endl;
cout<<endl;
cout<<endl;

}
void viewdoctor(){
for(int i =0; i<allDoctors.size();i++){
    cout<<"Patient Name:" <<allDoctors[i].name<<endl;
}
}
void viewAppointments(){
for(int i =0; i<allAppointments.size();i++){
    cout<<"patient id" <<allAppointments[i].patientID<<"has appointment with Doctor ID:"<<allAppointments[i].doctorID<<"on Date:"<<allAppointments[i].Date<<endl;
}
}

int main(){
    pid = 1;
    did = 1;
    int choice;
    Patient p ("komal chaudhary", 21,"M");
cout<<p.ID<<endl;
    do{
        cout<<"1. Add Patients"<<endl;
        cout<<"2. Add Doctors"<<endl;
        cout<<"3. Schedule Appointments"<<endl;
        cout<<"4. View Patients"<<endl;
        cout<<"5. View Doctors"<<endl;
        cout<<"6.View Appointments"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>choice;

        switch(choice){
        case 1:
        addpatient();
          break;
        case 2:
        adddoctor();
          break;
        case 3:
        ScheduleAppointments();
          break;
        case 4:
        viewpatient();
          break;
        case 5:
        viewdoctor();
          break;
        case 6:
        viewAppointments();
          break;
        default:
          cout<<"Invalid Choice"<<endl;
          cout<<endl;
          cout<<endl;
          cout<<endl;
        }
     
    }while(choice!=0);
    return 0;
}