#include <bits/stdc++.h>
using namespace std;

void insertToQueue(int arr[], int rearIndex){
    int toAdd;
    cout << "Enter Data : ";
    cin >> toAdd; 
    arr[rearIndex] = toAdd;
}

int main(){
    int sizeOfArr = 5, arr[sizeOfArr], choice, i;
    int frontIndex = 0, rearIndex = -1, noOfElements = 0;

    while(true){
        cout << "\nEnter your Choice :-" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete" << endl;
        cout << "3) Print" << endl;
        cout << "0) Exit" << endl;
        cout << "Choice : ";
        
        cin >> choice;

        switch (choice){
            case 1:
                if(noOfElements < sizeOfArr){
                    insertToQueue(arr, (rearIndex+1)%sizeOfArr);
                    rearIndex ++;
                    noOfElements ++;
                }
                else{
                    cout << "Queue is full." << endl;
                }
                break;

            case 2:
                if(noOfElements > 0){
                    noOfElements --;
                    frontIndex = (frontIndex+1)%sizeOfArr;
                }
                else{
                    cout << "Queue is already empty." << endl;
                }
                break;

            case 3:
                if(noOfElements > 0){
                    cout << "Queue is : ";
                    for(i=0; i<noOfElements; i++){
                        cout << arr[(frontIndex+i)%sizeOfArr] << " ";
                    }
                    cout << endl;
                }
                else{
                    cout << "Queue is empty" << endl;
                }
                break;

            case 0:
                exit(0);

            default:
                cout << "Invalid Choice, please try again." << endl;


        }
    }

}