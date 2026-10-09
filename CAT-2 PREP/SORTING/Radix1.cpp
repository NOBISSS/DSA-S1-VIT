#include<iostream>
using namespace std;

int find(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max < arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void countSort(int arr[],int place,int n){
    int count[10];
    for(int i=0;i<n;i++){
        int digit=(arr[i]/place)%10;
        count[digit]++;
    }

    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }

    int output[n];

    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/place)%10;
        output[count[digit]-1]=arr[i];
        count[digit]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int arr[],int n){
    int maxElement=find(arr,n);
    for(int place=1;maxElement/place>0;place*=10){
        countSort(arr,place,n);
    }

}

int main(){
    int arr[]={253,1,24,2,56,23,89};
    int n=7;

    radixSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}