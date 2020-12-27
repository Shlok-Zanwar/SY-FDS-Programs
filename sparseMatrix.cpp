// Assignment 2

#include <iostream>
using namespace std;


int main (){
    int noOfRows, noOfColumns;
    cout << "Enter number of rows : ";
    cin >> noOfRows;
    cout << "Enter number of columns : ";
    cin >> noOfColumns;
    int sparse[15][3], count = 0, num;

    for (int i = 0; i < noOfRows; i++){
        for (int j = 0; j < noOfColumns; j++){
            cin >> num;
            if (num != 0){
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = num;
                count += 1;
            }
        }   
    }


    int transpose[15][3], method;
    cout << "Enter Method for transpose : \n1 : Simple method \n2 : Fast method" << endl;
    cin >> method;

// 1 for simple method , 2 for fast;
    if(method == 1){

        // Simple Transpose
        cout << "\nCreating transpose by simple method :" << endl;
        int transCount = 0;
        for (int i = 0; i < noOfColumns; i++){
            for (int j = 0; j < count; j++){
                if (sparse[j][1] == i){
                    transpose[transCount][0] = sparse[j][1];
                    transpose[transCount][1] = sparse[j][0];
                    transpose[transCount][2] = sparse[j][2];
                    transCount += 1;
                }
            }    
        }
        

    }

    else{
    // fast time method
        cout << "\nCreating transpose by fast method :" << endl;
        int storeIndex[noOfColumns], arr[noOfColumns];
        
        // removing garbage values
        for (int i = 0; i < count; i++){
            storeIndex[i] = 0;
        }
        
        // getting number of column numbers
        for (int i = 0; i < count; i++){
            storeIndex[sparse[i][1]] += 1;   
        }


        // creating to store index of transpose
        arr[0] = 0;
        for (int i = 1; i < count; i++){
            arr[i] = arr[i-1] + storeIndex[i-1];
            // cout << arr[i] << endl;
        }
        
        // main logic, making transpose
        for (int i = 0; i < count; i++)
        {
            transpose[arr[sparse[i][1]]][0] = sparse[i][1];
            transpose[arr[sparse[i][1]]][1] = sparse[i][0];
            transpose[arr[sparse[i][1]]][2] = sparse[i][2];
            arr[sparse[i][1]] += 1;
        }
    }


    // printing transpose
    for (int i = 0; i < count; i++){
        for (int j = 0; j < 3; j++){
            cout << transpose[i][j] << " ";

        }
        cout << endl;      
    }
    
}

// 4x5

// 0 1 8
// 0 3 5
// 1 2 18
// 2 3 8
// 3 0 7
// 3 4 16