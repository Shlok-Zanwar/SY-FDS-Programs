// Assignment 3

#include <bits/stdc++.h>
#include<string>
using namespace std;


struct studentData{
    int roll_no;
    string name;
    float marks;
};


int checkRollNo (int roll_no, studentData *index, int count){
    for (int i = 0; i < count; i++){
        if (index->roll_no == roll_no){
            return i;
        }
        index += 1;
    }
    return -1;
};


bool addRecord (studentData *index, int count){
    int checkRoll;
    cout << "\nEnter roll number : ";
    cin >> checkRoll;
    
    if (checkRollNo (checkRoll, index, count) == -1){
        index += count;

        index->roll_no = checkRoll;

        cout << "Enter marks : ";
        cin >> index->marks;    

        cout << "Enter name : " ;
        string name;
        // getline(cin, name);
        cin >> name;
        index->name = name;

        return true;
    }
    else{
        cout << "Roll number already exists, please try again." << endl;
        return false;
    }
};


void displayData (studentData arr[], int count){
    cout << "\nRoll No    Name                Marks" << endl;


    for (int i = 0; i < count; i++){

        if(arr[i].roll_no > 0){
            string strRoll = " ";
            strRoll += to_string(arr[i].roll_no);

            while (strRoll.length() < 11)
            {
                strRoll += " ";
            }
            
            
            cout << strRoll << arr[i].name;
            for (int space = arr[i].name.length(); space < 20; space++){
                cout << " ";
            }
            cout << arr[i].marks << endl;
        }
    }
}


void searchRollNo(studentData arr[], int count){
    cout << "\nEnter roll number : ";
    int checkRoll, i;
    cin >> checkRoll;
    
    int index = checkRollNo(checkRoll, arr, count);
    if (index == -1){
        cout << "Record Not found." << endl;
    } 
    else{
        cout << "Name : " << arr[index].name << endl;
        cout << "Marks : " << arr[index].marks << endl;
    }

}


void deleteRecord(studentData *index, int count){
    cout << "\nEnter the roll number to be deleted : ";
    int checkRoll;
    cin >> checkRoll;
    int toDelete = checkRollNo (checkRoll, index, count);
    if (toDelete != -1){
        index += toDelete;
        index->roll_no = -1;
        cout << "Roll number '" << checkRoll << "' record deleted." << endl; 
    }
    else{
        cout << "Roll number '"<< checkRoll << "' dosent exist." << endl;
    }
    
}


int main(){
    struct studentData arr[30];
    vector <studentData> abc;

    arr[0].name = "Shlok Zanwar";
    arr[0].roll_no = 1;
    arr[0].marks = 10;

    arr[1].name = "Rohan Gupta";
    arr[1].roll_no = 2;
    arr[1].marks = 9.5;

    arr[2].name = "Sidd Jain";
    arr[2].roll_no = 3;
    arr[2].marks = 9;

    arr[3].name = "Rishi Shrimali";
    arr[3].roll_no = 4;
    arr[3].marks = 8.5;

    arr[4].name = "Aditya Gambhir";
    arr[4].roll_no = 5;
    arr[4].marks = 8;

    int count = 5;

    while (true){

        cout << "\nEnter operation you want to perform : " << endl;
        cout << "1 : Add new record" << endl;
        cout << "2 : Display all record" << endl;
        cout << "3 : Search record" << endl;
        cout << "4 : Delete a record" << endl;
        cout << "0 : Quit" << endl;

        int task;
        cin >> task;

        switch (task){
            case 1:
                if (addRecord(arr, count)){
                    count += 1;
                }
                
                break;

            case 2:
                displayData(arr, count);
                break;

            case 3:
                searchRollNo(arr, count);
                break;

            case 4:
                deleteRecord(arr, count);
                break;

            case 0:
                cout << "\nThank You !" << endl; 
                exit(0);
                break;    
            
            default:
                cout << "\nInvalid Input, please try again." << endl;
                break;
        }
        cout << "\n<---------------------------------------------->\n";
    }
}
