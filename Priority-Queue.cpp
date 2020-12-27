#include <bits/stdc++.h>
using namespace std;

struct Node{   
    int data;
    int priority;
    struct Node *next;
};

Node *first = NULL;
Node *last = NULL;


void deleteHighestPrior(){
    if(first == NULL){
        cout << "=> Queue is already empty" << endl;
    }
    else{
        Node *temp = first;
        first = first->next;

        temp->next = NULL;
        delete(temp);

        if(first == NULL){
            last = NULL;
        }
        cout << "=> First element deleted" << endl;
    }

}


void deleteLeastPrior(){
    if(first == NULL){
        cout << "=> Queue is already empty" << endl;
    }
    else{
        if(first->next == NULL){
            Node *temp = first;
            first = NULL;
            last = NULL;

            temp->next = NULL;
            delete(temp);
        }
        else{
            Node *temp = first;
            while(temp->next != last){
                temp = temp->next;
            }
            Node *store = last;
            last = temp;
            last->next = NULL;
            delete(store);
        }
    }
}


void insert(){
    Node *temp = new Node();
    int value, prior;
    cout << "Enter data : ";
    cin >> value;
    cout << "Enter priority : ";
    cin >> prior;

    temp->data = value;
    temp->priority = prior;
    temp->next = NULL;

    if(first == NULL){
        first = temp;
        last = temp;
    }
    else if(first->next == NULL){
        if(temp->priority > first->priority){
            temp->next = first;
            first = temp;
        }
        else{
            first->next = temp;
            last = temp;
        }
    }
    else{
        Node *pt1, *pt2;
        pt1 = first;
        pt2 = first->next;

        if(temp->priority > first->priority){
            temp->next = first;
            first = temp;
        }
        else if(temp->priority <= last->priority){
            last->next = temp;
            last = temp;
        }
        else{
            while(true){
                if(temp->priority > pt2->priority){
                    pt1->next = temp;
                    temp->next = pt2;
                    break;
                }
                pt1 = pt1->next;
                pt2 = pt2->next;
            }
        }
    }


} 


void displayQueue(){
    if(first == NULL){
        cout << "=> Queue is empty" << endl;
    }
    else{
        Node *temp = first;
        cout << "\nData\tPriority" << endl;
        while(temp != NULL){
            cout << temp->data << "\t" << temp->priority << endl;
            temp = temp->next;
        }
    }
}


int main(){
    
    int choice;
    while(true){
        cout << "\nEnter your Choice :-" << endl;
        cout << "1) Insert" << endl;
        cout << "2) Delete Highest priority" << endl;
        cout << "3) Delete Last" << endl;
        cout << "4) Print queue" << endl;
        cout << "0) Exit" << endl;
        cout << "Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteHighestPrior();
                break;

            case 3:
                deleteLeastPrior();
                break;

            case 4:
                displayQueue();
                break;

            case 0:
                exit(0);
                break;
            
            default:
                cout << "\nInvalid Choice, please try again" << endl;
                break;
        }

    }

}
