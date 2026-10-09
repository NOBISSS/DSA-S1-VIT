#include<iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left < n && arr[left] > arr[largest]){
        largest=left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}


void heapSort(int arr[],int n){
    //step-1 build Max Heap
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    //step-2 build Max Heap
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}

// void heapSort(int arr[],int n){
//     //step-1 Build Max Heap
//     for(int i=n/2-1;i>=0;i--){
//         heapify(arr,n,i);
//     }

//     //step-2
//     for(int i=n-1;i>0;i--){
//         swap(arr[0],arr[i]);
//         heapify(arr,i,0);
//     }
// }

int main(){
    int arr[]={12,11,13,5,6,7};
    int n=6;

    cout<<"Before Sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    heapSort(arr,n);

    cout<<endl<<"After Sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}