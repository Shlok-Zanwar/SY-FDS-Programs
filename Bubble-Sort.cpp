#include<bits/stdc++.h>
using namespace std;

void displayArr(int arr[], int len){
    for(int i=0; i<len; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
}


void bubbleSort(int arr[], int len){
    int i, j, changes;
    for(i=0; i<len-1; i++){
        changes = 0;
        for(j=0; j < len-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                changes ++;
            }
        }
        cout << "After pass " << (i+1) << " : ";
        displayArr(arr, len);
        if(changes == 0){
            return;
        }
    }
}


int main(){
    int len;
    cout << "Enter the length of the array : ";
    cin >> len;
    int arr[len], i, j, changes;

    cout << "Enter array : ";
    for(i=0; i<len; i++){
        cin >> arr[i];
    }

    cout << "\nArray is     : ";
    displayArr(arr, len);

    bubbleSort(arr, len);

    cout << "\nFinal sorted array is : ";
    displayArr(arr, len);
    cout << endl;

}