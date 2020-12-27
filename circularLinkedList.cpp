#include <iostream>
using namespace std;

typedef struct circularLinkedList{
    int data;
    circularLinkedList *next;
}Node;

Node *accept();
void searchData(Node *first);
int lengthOfList(Node *first);
void addNewNode(Node **first);
void giveSpaces(int count);
void display(Node *first);
void recDisplayRev(Node *first, Node *temp, int index);
void deleteNode(Node **first);


int main () {
    Node *first = NULL;
    int cont;

    while (true){
        cout << "\nEnter Operation : "<< endl;
        cout << "1 : Add new element." << endl;
        cout << "2 : Display list." << endl;
        cout << "3 : Display list reverse." << endl;
        cout << "4 : Search data." << endl;
        cout << "5 : Delete Record." << endl;
        cout << "6 : Length of circular linked list" << endl;
        cout << "0 : Exit" << endl; 
        cout << "Operation : "; 
        cin >> cont;
        cout << "\n";

        switch(cont){
            case 1 : 
                addNewNode(&first);
                break;

            case 2 : 
                display(first);
                break;

            case 3 :
                if(first == NULL){
                    cout << "    The list is empty." << endl;
                }
                else{
                    recDisplayRev(first, first, 0);
                }
                break;

            case 4:
                if (first != NULL){
                    searchData(first);
                }
                else{
                    cout << "    Length of list = 0" << endl; 
                }
                break;

            case 5 :
                if (first != NULL){
                    deleteNode(&first);
                }
                else{
                    cout << "    Length of list = 0" << endl; 
                }
                break;

            case 6 : 
                cout << "    Length of list = " << lengthOfList(first) << endl;
                break;

            case 0 :
                cout << "\n    Thank you !!!" << endl;
                exit(0);

            default : 
                cout << "    Invalid option, please try again." << endl;
        }
        // addNewNode(&first);
    }

}


Node *accept(){
    Node *a = new Node();
    cout << "    Enter data : ";
    cin >> a->data;

    return a;
}


void searchData(Node *first){
    Node *temp = first;
    int index = 0, search,  count = 0;

    cout << "    Enter the data you want to search : ";
    cin >> search;

    if(temp->data == search){
        cout << "    Found value = " << search << " at index = " << index << ".\n";
        count += 1;
    }
    while(temp->next != first){
        index += 1;
        temp = temp->next;
        if(temp->data == search){
            cout << "    Found value = " << search << " at index = " << index << ".\n";
            count += 1;
        }
    }

    if(count == 0){
        cout << "    Data = " << search << " is not present in the list." << endl;
    }

}


int lengthOfList(Node *first){
    if(first == NULL){
        return 0;
    }
    else{
        Node *temp = first;
        int count = 1;
        while(first->next != temp){
            count += 1;
            first = first->next;
        }
        return count;
    }
}


void addNewNode(Node **first){
    if(*first == NULL){
        *first = accept();        
        (*first)->next = *first;
    }
    else{
        int len = lengthOfList(*first), posi = -1, index = 1;
        while(posi > len || posi < 0){
            cout << "    Enter position (0, " << len << ") : ";
            cin >> posi;
        }

        Node *temp = *first, *head = *first;
        Node *a = accept();

        if(posi == 0){
            while (temp->next != head){
                temp = temp->next;
            }
            temp->next = a;
            a->next = head;
            *first = a;
        }        
        else{
            while (index < posi){
                head = head->next;
                index += 1;
            }
            temp = head->next;
            head->next = a;
            a->next = temp;
        }

    }
}


void giveSpaces(int count){
    while (count > 0){
        cout << " ";
        count -= 1;
    }
}


void display(Node *first){
    if(first == NULL){
        cout << "    The list is empty." << endl;
    }
    else{
        Node *temp = first;
        int index = 0;
        cout << "    Index  Data" << endl;
        cout << "    " << index << "      " <<  temp->data << endl;

        while (temp->next != first){
            temp = temp->next;
            index += 1;

            cout << "    " << index;
            giveSpaces(7 - to_string(index).length());
            cout << temp->data << endl;
        }
        
    }
}


void recDisplayRev(Node *first, Node *temp, int index){
    if(temp->next != first){
        recDisplayRev(first, temp->next, index+1);
    }

    if(temp->next == first){
        cout << "    Index  Data" << endl;
    }
    cout << "    " << index;
    giveSpaces(7 - to_string(index).length());
    cout << temp->data << endl;
}


void deleteNode(Node **first){
    display(*first);
    int index = -1, len = lengthOfList(*first);
    while (index >= len || index < 0){
        cout << "    Enter Index to be deleted : ";
        cin >> index;
    }

    if(len == 1){
        delete(*first);
        *first = NULL;
        return;
    }

    if(index == 0){
        Node *temp = *first, *second = temp->next;
        while(index < len-1){
            temp = temp->next;
            index += 1;
        }
        temp->next = second;
        delete(*first);
        *first = second;
    }
    else{
        Node *temp = *first, *store;
        int toDelete = 0;
        while (toDelete < index){
            if(toDelete == index-1){
                store = temp;
            }
            temp = temp->next;
            toDelete += 1;
        }
        store->next = temp->next;
        delete(temp);
        
    }
    
}