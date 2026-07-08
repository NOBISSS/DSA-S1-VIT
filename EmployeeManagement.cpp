/*
    Devloper:Parth Chauhan
    DOC:08-07-2026
    Subject:Learning Structure
    
    Planning:
        About:Employee Management System using Structure
        
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
//all constants are declared here
#define MAX_EMP_SIZE 5
#define MAX_EMP_NAME_SIZE 10
#define YOE_INCREMENT_5000 5
#define YOE_INCREMENT_10000 10

struct Employee{
    int empId;
    char empName[MAX_EMP_NAME_SIZE];
    int yearsOfExp;
    float salary;
}e[MAX_EMP_SIZE];

//prototype
int validateNo(int n);
int setData(int n,Employee* ep);
int display(int n,Employee* obj);

//Functions with body

//function:validateNo check the no with MAX_EMP_SIZE if it lesser or equal then it will allow else program close
int validateNo(int n){
    if(n>MAX_EMP_SIZE){
        cout<<"only "<<MAX_EMP_SIZE<<" can added at a time"<<endl;
        exit(0);
    }
    return 1;
}

//function:setData set the data to the object of the struct
int setData(int n,Employee* ep){
    for(int i=0;i<n;i++){   
        cout<<"Enter Employee ID :";
        cin>>(ep+i)->empId;
        cout<<"Enter Employee Name :";
        cin>>(ep+i)->empName;
        cout<<"Enter Employee Years Of Experince :";
        cin>>(ep+i)->yearsOfExp;
        cout<<"Enter Employee Salary :";
        cin>>(ep+i)->salary;
        if((ep+i)->yearsOfExp > YOE_INCREMENT_10000){
            (ep+i)->salary+=10000;
        }else if((ep+i)->yearsOfExp > YOE_INCREMENT_5000){
            (ep+i)->salary+=5000;
        }
}
    return 0;
}

int display(int n,Employee* obj){
    for(int i=0;i<n;i++)
    {
        cout<<"EMPLOYEE ID:"<<(obj+i)->empId<<endl;
        cout<<"EMPLOYEE NAME:"<<(obj+i)->empName<<endl;
        cout<<"EMPLOYEE YOE:"<<(obj+i)->yearsOfExp<<endl;
        cout<<"EMPLOYEE Salary:"<<(obj+i)->salary<<endl<<endl;
    }
    return 0;
}

int main(){
    int n;//purpose:how many emp user wants to add
    Employee *ep=e;//base address will assigned to ep pointer

    cout<<"Enter Number Of Employee You Wants to Add ";
    cin>>n;
    validateNo(n);
    setData(n,ep);
    display(n,ep);
}