//Get the 2D matrix from the user the array is reference name,store each 2D array in linked list node perform the following operation
//i)Check whether particular friend name is available/present
//ii)print the longest name & shortest name length
//iii)print all nodes name that is available diagnol
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//prototypes
struct node* createNode();
void createList();
void displayList(int nodeId);

int nodeIdCounter=100;
struct node{
	int nodeId;
	string **matrix;
	int rows,cols;
	node *next;
}*head=NULL,*tail=NULL,*newNode=NULL,*temp=NULL;

struct node* createNode(){
	int row=0,col=0;
	newNode=new node;
	newNode->nodeId=nodeIdCounter++;
	cout<<"LIST ID:"<<newNode->nodeId<<endl;
	cout<<"Enter Rows";
	cin>>newNode->rows;
	cout<<endl<<"Enter Cols";
	cin>>newNode->cols;
	
	newNode->matrix=new string*[newNode->rows];
	for(int i=0;i<newNode->rows;i++){
		newNode->matrix[i]=new string[newNode->cols];
		for(int j=0;j<newNode->cols;j++){
			cout<<"Enter Name for ["<<i<<"]"<<"["<<j<<"]:";
			cin>>newNode->matrix[i][j];
		}
	}
	newNode->next=NULL;
	return newNode;
}

void createList(){
	newNode=createNode();
	if(head==NULL){
		head=newNode;
		tail=newNode;
	}else{
		tail->next=newNode;
		tail=newNode;
	}
}

void displayList(int nodeId){
	int flag=0;
	if(head==NULL){
		cout<<"There is no node to be display";
		return;
	}
	
	temp=head;
	
	while(temp!=NULL){
		if(temp->nodeId==nodeId){
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==1){
		cout<<"Node ID:"<<temp->nodeId;
		cout<<"Matrix of"<<temp->rows<<"x"<<temp->cols<<endl;
		cout<<"Names:"<<endl;
		for(int i=0;i<temp->rows;i++){
			for(int j=0;j<temp->cols;j++){
				cout<<temp->matrix[i][j]<<" | ";
			}
			cout<<endl;
		}
	}else{
		cout<<"Please Enter Valid ID";
	}
}

void menu(){
	cout<<endl<<"1.Create List"<<endl;
	cout<<"2.Display List"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter Your Choice"<<endl;
}

int main(){
	int choice=1;
	while(choice!=0 && choice!=3){
		menu();
		cin>>choice;
		
		switch(choice){
			case 1:createList();break;
			case 2:displayList(100);break;
			case 3:exit(0);
			default:cout<<"Please Enter Valid Choice";
		}
	}
	return 0;
}

