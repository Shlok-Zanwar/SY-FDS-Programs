#include <bits/stdc++.h> 
using namespace std;  


int makePartition(int arr[], int start, int end){
    int i = start-1;
    for(int j=start; j<end; j++){
        if(arr[j] < arr[end]){
            i ++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[end], arr[i]);
    return (i);
}


void quickSort(int arr[], int start, int end){

    if(start < end){
        int part = makePartition(arr, start, end);

        quickSort(arr, start, part-1);
        quickSort(arr, part+1, end);
    }

}


int main(){  
    int i, len;
    cout << "Enter the size of array : ";
    cin >> len;
    int arr[len];
    cout << "Enter the elements of array : ";
    
    for (i = 0; i < len; i++){
        cin >> arr[i];
    }
    
    quickSort(arr, 0, len-1);

    cout << "\nSorted Array : ";

    for (i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    cout << "\n\n";

} 