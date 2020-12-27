#include <bits/stdc++.h>
using namespace std;

struct Pizza{
    string phoneNo;
    string order;
    int orderNo;
    int amount;
};

void displayOrderQueue(int noOfElements, Pizza arr[], int frontIndex, int sizeOfArr);
int insertToQueue(Pizza arr[], int rearIndex, int orderOfDay);
void giveSpaces(int num);


int main(){
    int sizeOfArr, choice, i;
    
    int frontIndex = 0, rearIndex = -1, noOfElements = 0, orderOfDay = 0, totalBill = 0;

    cout << "Enter the maximum capacity of orders : ";
    cin >> sizeOfArr;

    Pizza arr[sizeOfArr];

    while(true){
        cout << "\nEnter your Choice :-" << endl;
        cout << "1) Take Order" << endl;
        cout << "2) Deliver first order" << endl;
        cout << "3) Show order queue" << endl;
        cout << "4) Day summary" << endl;
        cout << "0) Exit" << endl;
        cout << "Choice : ";
        
        cin >> choice;

        switch (choice){
            case 1:
                if(noOfElements < sizeOfArr){
                    orderOfDay ++;
                    totalBill += insertToQueue(arr, (rearIndex+1)%sizeOfArr, orderOfDay);
                    rearIndex = (rearIndex+1)%sizeOfArr;
                    noOfElements ++;
                    displayOrderQueue(noOfElements, arr, frontIndex, sizeOfArr);
                }
                else{
                    cout << "\nMaximum order capacity is reached." << endl;
                }
                break;

            case 2:
                if(noOfElements > 0){
                    cout << "\nOrder " << arr[frontIndex].orderNo << " sent out for delivery." << endl;
                    cout << "Order details : " << arr[frontIndex].order << endl;
                    noOfElements --;
                    frontIndex = (frontIndex+1)%sizeOfArr;
                }
                else{
                    cout << "\nThere are no orders present to deliver" << endl;
                }
                break;

            case 3:
                displayOrderQueue(noOfElements, arr, frontIndex, sizeOfArr);
                break;

            case 4:
                cout << "\nReceived " << orderOfDay << " orders today which billed to Rs. " << totalBill << "." << endl;
                break;

            case 0:
                if(noOfElements > 0){
                    cout << "\nYou still have some orders to deliver." << endl;
                    displayOrderQueue(noOfElements, arr, frontIndex, sizeOfArr);
                }
                else{
                    exit(0);
                }
                break;

            default:
                cout << "\nInvalid Choice, please try again." << endl;


        }
    }

}


int insertToQueue(Pizza arr[], int rearIndex, int orderOfDay){
    string phoneNumber;
    char orderDetails[100];
    int amt;
    
    cout << "\nEnter phone number  : ";
    cin >> phoneNumber; 
    cout << "Enter order details : ";
    scanf(" %[^\n]s",orderDetails);
    cout << "Enter amount (cost) : ";
    cin >> amt;
    arr[rearIndex].phoneNo = phoneNumber;
    arr[rearIndex].order = orderDetails;
    arr[rearIndex].amount = amt;
    arr[rearIndex].orderNo = orderOfDay;
    cout << "\nOrder (order no. :- " << orderOfDay << ") noted successfully, new order queue is :-" << endl;

    return amt;
}


void giveSpaces(int num){
    while(num > 0){
        cout << " ";
        num --;
    }
}


void displayOrderQueue(int noOfElements, Pizza arr[], int frontIndex, int sizeOfArr){
    int i;
    // 12 16
    if(noOfElements > 0){
        cout << "\nOrder-no    Phone-no        Bill    Order Detail" << endl;
        for(i=0; i<noOfElements; i++){
            cout << arr[(frontIndex+i)%sizeOfArr].orderNo;
            giveSpaces(12 - to_string(arr[(frontIndex+i)%sizeOfArr].orderNo).length());
            cout << arr[(frontIndex+i)%sizeOfArr].phoneNo;
            giveSpaces(16 - (arr[(frontIndex+i)%sizeOfArr].phoneNo).length());
            cout << arr[(frontIndex+i)%sizeOfArr].amount;
            giveSpaces(8 - to_string(arr[(frontIndex+i)%sizeOfArr].amount).length());
            cout << arr[(frontIndex+i)%sizeOfArr].order << endl;
        }
        cout << endl;
    }
    else{
        cout << "\nNo orders present" << endl;
    }
}
