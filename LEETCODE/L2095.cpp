/*
	LEETCODE PROBLEM:2095
	TITLE:DELETE THE MIDDLE NODE OF LL
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
}*head=NULL,*tail=NULL,*newNode=NULL,*ptr=NULL;

struct node* createNode(){
	int val;
	cout<<"Enter Value";
	cin>>val;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=NULL;
	return newNode;
}

void insertNode(){
	newNode=createNode();
	if(head==NULL){
		head=newNode;
		tail=newNode;
	}else{
		tail->next=newNode;
		tail=newNode;
	}
}

void display(){
	if(head==NULL){
		cout<<"THERE IS NO NODE TO BE DISPLAY";
	}else{
		ptr=head;
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
	}
}

void menu(){
	cout<<endl<<"1.INSERT"<<endl;
	cout<<"2.DELETE MID"<<endl;
	cout<<"3.DISPLAY"<<endl;
	cout<<"4.EXIT"<<endl;
	cout<<"Enter Your Choice"<<endl;
}

void deleteMiddleNode(){
	if(head==NULL || head->next==NULL){
		cout<<"Please Enter Nodes";
	}else{
		struct node* prev=head;
		struct node* slow=head;
		struct node* fast=head;
		
		while(fast && fast->next){
			prev=slow;
			slow=slow->next;
			fast=fast->next->next;
		}
		prev->next=slow->next;
		display();		
	}
}

int main(){
	int choice=0;
	while(choice<=3){
		menu();
		cin>>choice;
		switch(choice){
			case 1:insertNode();break;
			case 2:deleteMiddleNode();break;
			case 3:display();break;
			default:cout<<"Please Enter valid choice";
		}
	}
	return 0;
}
