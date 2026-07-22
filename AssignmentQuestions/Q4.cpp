#include<iostream>
#define STACK_SIZE 5
using namespace std;

//stack declaration :: OPERATION:PUSH,POP,PEEK,DISPLAY
int e_stack[STACK_SIZE],o_stack[STACK_SIZE],o_top=-1,e_top=-1,n;
//CHOICE 1.PUSH 2.POP 3.PEEK 4.DISPLAY 5.exit

void push(){
    if(o_top<STACK_SIZE || e_top<STACK_SIZE){
        int no;
        cout<<"Enter Value";
        cin>>no;
        
        if(no%2==0){
            if(e_top<STACK_SIZE){
                e_stack[++e_top]=no;
            }
        }else{
            if(o_top<STACK_SIZE){
                o_stack[++o_top]=no;
            }
        }
}
}

int checkStackStatus(int status){
    if(status==-1){
        if(!(e_top<STACK_SIZE || o_top<STACK_SIZE)){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(!(e_top<STACK_SIZE || o_top<STACK_SIZE)){
            return 1;
        }else{
            return 0;
        }
    }
}

void pop(){
    if(checkStackStatus(-1)){
        cout<<"Stack Underflow";
    }else{
        if(checkStackStatus(-1)){
            cout<<"EVEN-STACK Popped element is:"<<e_stack[e_top--];
            cout<<"ODD-STACK Popped element is:"<<o_stack[o_top--];
        }
    }
}

void peek(){
    if(checkStackStatus(-1)){
        cout<<"Stack is Empty";
    }else{
        cout<<"EVEN STACK PEEK ELEMENT:"<<e_stack[e_top]<<endl;
        cout<<"ODD STACK PEEK ELEMENT:"<<o_stack[o_top]<<endl;
    }
}

void menu(){
    cout<<"1.PUSH"<<endl;
    cout<<"2.POP"<<endl;
    cout<<"3.PEEK"<<endl;
    cout<<"4.DISPLAY"<<endl;
    cout<<"5.EXIT"<<endl;
}

void display(){
    if(e_top==-1 || o_top==-1){
        cout<<"Stack is Underflow";
        return;
    }
        cout<<"|EVEN STACK|          |ODD STACK|"<<endl;
    for(int i=0;i<STACK_SIZE;i++){
        cout<<"    "<<e_stack[i]<<"                       "<<o_stack[i]<<endl;
    }

}

int main(){
    int choice=0;
    
    while(choice>=0 &&choice<=4){
        menu();
        cout<<"Enter Your Choice :";
        cin>>choice;
        switch(choice){
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:peek();
                    break;
            case 4:display();
                    break;
            case 5:exit(0);
                    break;
        }
    }
}