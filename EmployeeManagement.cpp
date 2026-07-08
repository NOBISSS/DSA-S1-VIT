/*
    Devloper:Parth Chauhan
    DOC:08-07-2026
    Subject:Learning Structure
    
    Planning:
        Sub:Employee Management System using Structure
        
        structure contains:
            empID,empName,yearsOfExp,salary
        Input:
            User has to give empID,empName,yearsOfExp,salary
        Conditions:
            If the years of Experience is greater then 5,increase current salary with +5000,
            If the years of Experience is greater then 10,increase current salary with +10000
*/
#include<iostream>
using namespace std;
#define MAX_EMP_SIZE 5
#define MAX_EMP_NAME_SIZE 10
//prototype
struct Employee{
    int empId;
    char empName[MAX_EMP_NAME_SIZE];
    int yearsOfExp;
    float salary;
}e[MAX_EMP_SIZE];

int display(Employee* obj);

int display(Employee* obj){
    cout<<"EMPLOYEE ID:"<<obj->empId<<endl;
    cout<<"EMPLOYEE NAME:"<<obj->empName<<endl;
    cout<<"EMPLOYEE YOE:"<<obj->yearsOfExp<<endl;
    cout<<"EMPLOYEE Salary:"<<obj->salary<<endl;
    return 0;
}

int main(){
    int n;//purpose:how many emp user wants to add
    Employee *ep=e;//base address will assigned to ep pointer

    cout<<"Enter Number Of Employee You Wants to Add ";
    cin>>n;
    if(n>MAX_EMP_SIZE){
        cout<<"only "<<MAX_EMP_SIZE<<" can added at a time"<<endl;
        cout<<"Enter Number Of Employee You Wants to Add ";
        cin>>n;
    }
    for(int i=0;i<n;i++){
        cout<<"Enter Employee ID :";
        cin>>(ep+i)->empId;
        cout<<"Enter Employee Name :";
        cin>>(ep+i)->empName;
        cout<<"Enter Employee Years Of Experince :";
        cin>>(ep+i)->empName;
        cout<<"Enter Employee Salary :";
        cin>>(ep+i)->salary;
    }

    cout<<"Displaying Employee Records :";
    
    for(int i=0;i<n;i++){
        display((ep+i));
    }

}