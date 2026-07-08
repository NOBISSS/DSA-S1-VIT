#include<iostream>
using namespace std;
//all constants are declared here
#define MAX_SIZE 3
//prototype
int display(int arr[][MAX_SIZE]);

int rotateArr(int arr[][MAX_SIZE],int RC_CNT){
    int temp;
     for(int i=0;i<MAX_SIZE;i++){
        for(int j=0;j<RC_CNT;j++){//for each array of array
            temp=arr[i][MAX_SIZE-1];

            for(int k=MAX_SIZE-1;k>0;k--){//inner element   
                arr[i][k]=arr[i][k-1];
            }
            arr[i][0]=temp;
        }
    }
    display(arr);
    return 0;
}

int display(int arr[][MAX_SIZE]){
    for(int i=0;i<MAX_SIZE;i++){
        for(int j=0;j<MAX_SIZE;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0; 
}

int main(){
    int RC_CNT=0;
    cout<<"Enter how many rotation you want";
    cin>>RC_CNT;
    int arr[MAX_SIZE][MAX_SIZE]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    //display(arr);
    rotateArr(arr,RC_CNT);
    return 0;
}