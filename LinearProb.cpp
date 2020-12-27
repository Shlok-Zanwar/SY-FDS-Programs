#include <bits/stdc++.h> 
using namespace std;  


struct linearProbing{
    int number = 0;
    int next = -1;
};


void add(linearProbing arr[]);
void search(linearProbing arr[]);
void display(linearProbing arr[]);


int main(){

    linearProbing arr[10];
    display(arr);

    int choice, count = 0;

    while(true){
        cout << "\nEnter operation :-" << endl;
        cout << "1) Add" << endl;
        cout << "2) search" << endl;
        cout << "3) display" << endl;
        cout << "0) Exit" << endl;
        cout << "Choice : ";

        cin >> choice;

        switch(choice){
            case 1:
                if(count < 10){
                    add(arr);
                    count ++;
                }
                else{
                    cout << "\nList is full." << endl;
                }
                break;

            case 2:
                search(arr);
                break;

            case 3:
                display(arr);
                break;

            case 0: 
                exit(0);

            default:
                cout << "Invalid input, please try again." << endl;
                break;
        }

    }


}


void add(linearProbing arr[]){
    int data;
    cout << "\n=>    Enter number to add : ";
    cin >> data;

    int toStore = data%10, sameModIndex;
    bool sameModFound = false;

    while(true){
        if(arr[toStore].number == 0){
            arr[toStore].number = data;
            if(sameModFound){
                arr[sameModIndex].next = toStore;
            }
            break;
        }
        else if(arr[toStore].number % 10 == data%10){
            sameModFound = true;
            if(arr[toStore].next == -1){
                sameModIndex = toStore;
                toStore = (toStore + 1) % 10;
            }
            else{
                toStore = arr[toStore].next;
            }
        }
        else{
            toStore = (toStore + 1) % 10;
        }
    }
    

}


void search(linearProbing arr[]){
    int toSearch, total = 1;
    cout << "=>    Enter number to search : ";
    cin >> toSearch;

    int find = toSearch % 10;

    if(arr[find].number == 0){
        cout << "=>     " << toSearch << " is not present in the list, searched 1 time(s)." << endl;
        return;
    }

    while(arr[find].number % 10 != (toSearch % 10)){
        if(arr[find].number == 0){
            cout << "=>     " << toSearch << " is not present in the list, searched " << total << " time(s)." << endl;
            return;
        }
        find = (find + 1)%10;
        total ++;
        if(total == 10){
            cout << "=>     " << toSearch << " is not present in the list, searched " << total << " time(s)." << endl;
            return;
        }
    }

    while(true){
        if(arr[find].number == toSearch){
            cout << "=>    " << toSearch << " is present in the list, searched " << total << " time(s)." << endl;
            return;
        }
        else{
            if(arr[find].next == -1){
                cout << "=>     " << toSearch << " is not present in the list, searched " << total << " time(s)." << endl;
                return;
            }
            else{
                find = arr[find].next;
            }
        }
        total ++;
    }

}


void display(linearProbing arr[]){
    int i;

    cout << "Index\tData\tNext\n" << endl;
    for(i=0; i<10; i++){
        cout << i << "\t" << arr[i].number << "\t" << arr[i].next << endl;
    }
}





//  ----------------------------------------------------------------------------------------------------------






// void display(int arr[]){
//     int i;
//     cout << "Index\tData" << endl;
//     for(i=0; i<10; i++){
//         cout << i << "\t" << arr[i] << endl;
//     }
// }


// void add(int arr[]){
//     int toAdd;
//     cout << "Enter data : ";
//     cin >> toAdd;

//     int location = toAdd % 10;

//     while(arr[location] != 0){
//         location = (location + 1) % 10; 
//     }

//     arr[location] = toAdd;

// }


// void search(int arr[]){
//     int toSearch;
//     cout << "Enter data : ";
//     cin >> toSearch;

//     int location = toSearch % 10, total = 1;

//     while(arr[location] != 0){
//         if(arr[location] == toSearch){
//             cout << "Data is present, time required to search is O(" << total << ") ." << endl;
//             return;
//         }

//         location = (location + 1)%10;

//         if(location == toSearch % 10){
//             break;
//         }
//         total ++;
//     }

//     cout << "Data is not present, time required to search is O(" << total << ") ." << endl;

// }


// int main(){
//     int arr[10] = {0};

//     int choice, count = 0;

//     while(true){
//         cout << "\nEnter operation :-" << endl;
//         cout << "1) Add" << endl;
//         cout << "2) search" << endl;
//         cout << "3) display" << endl;
//         cout << "0) Exit" << endl;
//         cout << "Choice : ";

//         cin >> choice;

//         switch(choice){
//             case 1:
//                 if(count < 10){
//                     add(arr);
//                     count ++;
//                 }
//                 else{
//                     cout << "\nList is full." << endl;
//                 }
//                 break;

//             case 2:
//                 search(arr);
//                 break;

//             case 3:
//                 display(arr);
//                 break;

//             case 0: 
//                 exit(0);

//             default:
//                 cout << "Invalid input, please try again." << endl;
//                 break;
//         }

//     }


// }
