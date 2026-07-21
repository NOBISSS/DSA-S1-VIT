#include<iostream>
using namespace std;

int arr[5];
int display();
static int arr_filled_size=0;
int insert(){
    if(arr_filled_size>=5){
        cout<<"Array Sized Full,Delete Element for adding another elem";
        return 0;
    }
    int no;
    cout<<"Enter Value";
    cin>>no;
    arr[arr_filled_size++]=no;
    display();
    return 0;
}

int deleteElem(){
    int flag=0;
    int no,i;
    if(arr_filled_size==0){
        cout<<"Nothing has to be deleted";
        return 0;
    }
    cout<<"Enter Value";
    cin>>no;
    for(i=0;i<arr_filled_size;i++){
        
        if(arr[i]==no){
            flag=1;
            for(int j=i;j<arr_filled_size-1;j++){
                arr[j]=arr[j+1];
            }
            arr_filled_size--;
            break;
        }
    }

    if(flag==0){
        cout<<"The Element doesn't found please try with different value"<<endl;
    }
    display();
    return 0;
}

int display(){
    if(arr_filled_size==0){
        cout<<"No Element Found to be display"<<endl;
        return 0;
    }
    cout<<"DISPLAYING ELEMENTS"<<endl;
    for(int i=0;i<arr_filled_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){
    int choice=1;
    while(choice<=3 && choice>=1){
        cout<<"1.INSERTION"<<endl;
        cout<<"2.DELETION"<<endl;
        cout<<"3.DISPLAY"<<endl;
        cout<<"4.EXIT"<<endl;
        cout<<"Enter Your Choice";
        cin>>choice;

        switch(choice){
            case 1:insert();
                    break;
            case 2:deleteElem();
                    break;
            case 3:display();
                    break;

            default:cout<<"Exited From the Program,Thank You!!";
        }
    }
    

    return 0;

}