#include<iostream>
#include<cctype>
using namespace std;
const int STACK_SIZE=5;
char vowel_stack[STACK_SIZE],conso_stack[STACK_SIZE];
void insert(string str){
    
    for(int i=0;i<str.length();i++){
        char ch=toupper(str[i]);
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            
            return;
        }
    }

}

int main(){
    string str="";
    cout<<"Enter String";
    cin>>str;
    cout<<str;
    return 0;

}