#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
}*head=NULL,*newNode=NULL,*ptr=NULL,*tail=NULL;

void insertAtBegin();
void insertAtEnd();
void insertAtSrc();
void deleteFromBegin();
void deleteFromEnd();
void deleteFromSrc();
void display();

struct node* createNode(){
	int val;
	cout<<"Enter Value";
	cin>>val;
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=val;
	newNode->next=NULL;
	return newNode;
}

void insertAtBegin(){
	newNode=createNode();
	if(head==NULL){
		head=tail=newNode;
	}else{
		newNode->next=head;
		head=newNode;
	}
}

void insertAtEnd(){
	newNode=createNode();
	if(head==NULL){
		head=tail=newNode;
	}else{
		tail->next=newNode;
		tail=newNode;
	}
}

void display(){
	if(head==NULL){
		cout<<"There is no element to be display";
		return;
	}else{
		ptr=head;
		while(ptr!=NULL){
			cout<<ptr->data<<" -> ";
			ptr=ptr->next;
		}
	}
}

void insertAtSrc(){
	int src;
	cout<<"Enter Value Before You Want to Node";
	cin>>src;
	ptr=head;
	while(ptr->next->data!=src && ptr!=NULL){
		ptr=ptr->next;
	}
	if(ptr->next->data==src){
		newNode=createNode();
		newNode->next=ptr->next;
		ptr->next=newNode;
	}else{
		cout<<"Try Again With Different Value";
	}
}

void reverse(){
	struct node *prev=NULL;
	struct node *curr=head;
	struct node *next=NULL;
	
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		cout<<"1"<<endl;
	}
	while(tail!=NULL){
		cout<<tail->data<<" ";
		tail=tail->next;
	}
}

void menu(){
	cout<<"1.insert at begin"<<endl;
	cout<<"2.insert at end"<<endl;
	cout<<"3.insert at src"<<endl;
	cout<<"4.delete from begin "<<endl;
	cout<<"5.delete from end"<<endl;
	cout<<"6.delete using src"<<endl;
	cout<<"7.DISPLAY";
	cout<<"8.REVERSE";
	cout<<"Enter Your choice"<<endl;
}

int main(){
	int choice=1;
	while(choice>=1 && choice <=7){
		menu();
		cin>>choice;
		switch(choice){
			case 1:insertAtBegin();break;
			case 2:insertAtEnd();break;
			case 3:insertAtSrc();break;
			/*case 4:deleteFromBegin();break;
			case 5:deleteFromEnd();break;
			case 6:deleteFromSrc();break;*/
			case 7:display();break;
			case 8:reverse();break;			
		}
	}
	return 0;
}
