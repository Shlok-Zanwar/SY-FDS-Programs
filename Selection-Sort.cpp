#include<bits/stdc++.h>
using namespace std;


void displayArr(int arr[], int len){
    for(int i=0; i<len; i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
}


void selectionSort(int arr[], int len){
    int i, j, index, value;

    for(i=0; i<len-1; i++){
        index = i;
        for(j = i+1; j<len; j++){
            if(arr[j] < arr[index]){
                index = j;
            }
        }
        swap(arr[i], arr[index]);
        cout << "After pass " << (i+1) << " : ";
        displayArr(arr, len);
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

    selectionSort(arr, len);

    cout << "\nFinal sorted array is : ";
    displayArr(arr, len);
    cout << endl;


}