#include<iostream>
using namespace std;

int checkTwoSum(int arr[],int n,int target){
    int fnd;
    if(n<2){
        cout<<"Enter Valid Array";
    }else{// [1,2,3,4,5]6
        for(int i=0;i<n;i++){
            fnd=target-arr[i];
            for(int j=i+1;j<n;j++){
                if(arr[j]==fnd){
                    cout<<"Sum of "<<arr[i]<<" and "<<arr[j]<<" is "<<target;
                    return 0;
                }
            }
        }
        cout<<"No Data Found";
    }
    return 0;
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    checkTwoSum(arr,n,6);
    return 0;
}