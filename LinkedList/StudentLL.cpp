#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct Student{
    int sno,marks[3],total;
    float avg;
    char sname[10];
    struct Student *next;
}*newNode=NULL,*head=NULL,*tail=NULL,*curr=NULL;

Student* createNode(int dsno,const char* dsname,int dmarks[]){
    newNode=(struct Student*)malloc(sizeof(struct Student));
    newNode->sno=dsno;
    strcpy(newNode->sname,dsname);
    newNode->marks[0]=dmarks[0];
    newNode->marks[1]=dmarks[1];
    newNode->marks[2]=dmarks[2];
    newNode->total=dmarks[0]+dmarks[1]+dmarks[2];
    newNode->avg=newNode->total/3.0*100;
    newNode->next=NULL;
    return newNode;
}

void insertAtFirst(int dsno,const char dsname[],int dmarks[]){
    newNode=createNode(dsno,dsname,dmarks);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        newNode->next=head;
        head=newNode;
        
    }
}

void display(){
    curr=head;
    cout<<"PRINTING";
    while(curr!=NULL){
        cout<<curr->sno<<" -> ";
        curr=curr->next;
    }
}

int main(){
    int arr[]={10,20,30};
    insertAtFirst(2,"PA",arr);
    insertAtFirst(3,"PA",arr);
    insertAtFirst(4,"PARTH",arr);
    display();
    return 0;
}