/*BINARY SEARCH
	SORT ALL THE ELEMENT
	DIVIDE AND CONQUER
*/
#include<iostream>
const int MAX_SIZE=10;
using namespace std;

int main(){
	int arr[MAX_SIZE];
	int mid=0;
	int lower_bound=0;
	int higher_bound=MAX_SIZE-1;
	int src=0;
	
	//taking input from the user
	for(int i=0;i<MAX_SIZE;i++){
		cout<<"Enter Element ["<<i<<"]";
		cin>>arr[i];
	}
	
	//sorting all elements
	int temp=0;
	for(int i=0;i<MAX_SIZE;i++){
		for(int j=i+1;j<MAX_SIZE;j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	cout<<"Enter Which Element you want to find:";
	cin>>src;
	int z=0;
	while(lower_bound<=higher_bound){
		z++;
		mid=(lower_bound+higher_bound)/2;
		if(arr[mid]==src){
			cout<<"Element Found "<<mid <<" index" << " MID VALUE "<<arr[mid]<<" ";
			break;
		}else if(arr[mid] > src){
			higher_bound=mid-1;
			//lower_bound+=1;
		}else if(arr[mid] < src){
			lower_bound=mid+1;
			//higher_bound-=1;
		}
	}

	//displaying the sorted values
	for(int i=0;i<MAX_SIZE;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
