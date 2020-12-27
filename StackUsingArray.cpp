#include <bits/stdc++.h>
using namespace std;

void appendNew(int arr[], int position);

int main(){
    int arr[10];
    int total = -1;
    int task;

    while (true){
        cout << "\nEnter operation :- " << endl;
        cout << "1) Append" << endl;
        cout << "2) Pop" << endl;
        cout << "3) Top" << endl;
        cout << "0) Exit" << endl;
        cout << "Choice : ";
        cin >> task;

        switch(task){
            case 1:
                
                if(total >= 9){
                    cout << "Stack is full" << endl;
                    break;
                }
                total ++;
                appendNew(arr, total);
                break;

            case 2:
                if(total == -1){
                    cout << "=> Stack is already empty." << endl;
                }
                else{
                    cout << "=> Top element '" << arr[total] << "' popped." << endl;
                    total --;
                }
                break;

            case 3:
                if(total == -1){
                    cout << "=> Stack is empty." << endl;
                }
                else{
                    cout << "=> Top elemet is '" << arr[total] << "'." << endl;
                }
                break;

            case 0:
                exit(0);

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }

    }

}

void appendNew(int arr[], int position){
    int data;
    cout << "Enter the data : ";
    cin >> data;
    arr[position] = data;
}