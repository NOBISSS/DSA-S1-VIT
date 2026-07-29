#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

struct node{
    struct node *prev=NULL;
    int data;
    string ch[10];
    struct node *next=NULL;
}*head=NULL,*tail=NULL,*newNode=NULL,*ptr=NULL,*temp=NULL;

struct node *createNode(){
    int val;
    cout<<"Enter Value";
    cin>>val;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;
    for(int i=0;i<val;i++){
        newNode->ch[i]=(65+i);
    }
    return newNode;
}

void insertAtBegin(){
    newNode=createNode();
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void insertAtEnd(){
    newNode=createNode();
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

void display(){
    ptr=head;
    while(ptr!=NULL){
        cout<<" [ "<<ptr->data<<" ( ";
        for(int i=0;i<ptr->data;i++){
            cout<<ptr->ch[i]<<" , ";
        }
        ptr=ptr->next;
        cout<<" ) ] ";
    }
        
}

void menu(){
	cout<<endl<<"1.insert at begin"<<endl;
	cout<<"2.insert at end"<<endl;
	cout<<"3.delete from begin "<<endl;
	cout<<"4.delete from end"<<endl;
	cout<<"5.DISPLAY"<<endl;
}

void deleteAtBegin(){
    if(head==NULL){
        cout<<"There is no need to be display";
    }else if(head==tail){
        free(head);
        head=NULL;
    }else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
    }
}

void deleteAtEnd(){
    if(head==NULL){
        cout<<"There is no need to be display";
    }else if(head==tail){
        free(head);
        head=NULL;
    }else{
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
}

int main(){
    int choice=1;
    while(choice>=1 && choice<=5){
        menu();
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1:insertAtBegin();break;
            case 2:insertAtEnd();break;
            case 3:deleteAtBegin();break;
            case 4:deleteAtEnd();break;
            case 5:display();break;
        }
    } 
    display();
    return 0;
}