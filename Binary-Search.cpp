#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int toSearch, int max){
    int min = 0;
    int center;
    int count = 0;
    while(max > min + 1){
        center = min + (max-min)/2;
        if(toSearch == arr[center]){
            return center;
        }
        else if(toSearch == arr[min]){
            return min;
        }
        else if(toSearch > arr[center]){
            min = center;
        }
        else{
            max = center;
        }
        count ++;
        // cout << count << endl;
    }
    
    return -1;

}
    

int main(){
    int len;
    cout << "Enter the length of the array : ";
    cin >> len;
    int arr[len], i, toSearch, ans;
    char cont = 'y';

    cout << "Enter sorted array : ";
    for(i=0; i<len; i++){
        cin >> arr[i];
    }

    while(cont != 'n'){
        cout << "\nEnter the element to searh : ";
        cin >> toSearch;

        ans = binarySearch(arr, toSearch, len);

        if(ans == -1){
            cout << "Value not found !\n" << endl;
        }
        else{
            cout << "Value found at index " << ans << ".\n" << endl;
        }

        cout << "Do you want to continue (n, any) : ";
        cin >> cont;
    }

}