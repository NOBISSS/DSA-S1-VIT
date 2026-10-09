#include<iostream>
using namespace std;
int findMax(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void countSort(int arr[],int place,int n){
    int count[10]={0};
    int countLength=10;
    for(int i=0;i<n;i++){
        int digit=(arr[i]/place)%10;
        count[digit]++;
    }

    for(int i=1;i<countLength;i++){
        count[i]=count[i]+count[i-1];
    }

    int output[n];
    for(int j=n-1;j>=0;j--){
        int digit=(arr[j]/place)%10;
        output[count[digit]-1]=arr[j];
        count[digit]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radixSort(int arr[],int n){
    int maxElement=findMax(arr,n);
    for(int place=1;(maxElement/place) > 0;place*=10){
        countSort(arr,place,n);
    }
    cout<<maxElement;
}

int main(){
    int n=8;
    int arr[]={253,192,3,2,10,75,478,88};
    
    cout<<"Before Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    radixSort(arr,n);
    cout<<endl<<"After Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}