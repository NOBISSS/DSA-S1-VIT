//COLUMN WISE ROTATION
#include<iostream>
using namespace std;

const int MAX_SIZE=3;
int main(){
    int no=1;
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int rotation_cnt=2;
        for(int i=0;i<MAX_SIZE;i++){
            for(int j=0;j<rotation_cnt;j++){
                int temp=arr[MAX_SIZE-1][i];
                for(int k=MAX_SIZE-1;k>0;k--){
                    arr[k][i]=arr[k-1][i];
                }
                arr[0][i]=temp;
            }
        }
        for(int i=0;i<MAX_SIZE;i++){
            for(int j=0;j<MAX_SIZE;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;

}