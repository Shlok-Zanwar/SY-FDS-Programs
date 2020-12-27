#include <iostream>
using namespace std;


typedef struct DoublyLinkedList{
    int data;
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *previous;
} Node;

// global variable for last index
Node *last = NULL;

Node *accept();
int lengthOfList(Node *mainList);
void addToStart(Node **mainList);
void addToEnd(Node **mainList);
void addToMid(Node **mainList, int position);
void addNew(Node **mainList);
void display(Node *mainList);
void displayReverse();
void deleteIndex(Node **mainList);



int main(){
    Node *mainList = NULL;
    int cont;

    while (true){ 
      cout << "\nEnter Operation : "<< endl;
      cout << "1 : Add new element." << endl;
      cout << "2 : Display list." << endl;
      cout << "3 : Display list reverse." << endl;
      cout << "4 : Delete Record." << endl;
      cout << "5 : Length of linked list" << endl;
      cout << "0 : Exit" << endl; 
      cout << "Operation : "; 
      cin >> cont;


      switch (cont){
         case 1:
            addNew(&mainList);
            break;
         
         case 2:
            display(mainList);
            break;

         case 3: 
            displayReverse();
            break;

         case 4:
            deleteIndex(&mainList);
            break;

         case 5:
            cout << "    Length of linked list is = " << lengthOfList(mainList) << endl;
            break;

         case 0:
            cout << "\n    Thank You.\n\n" ;
            exit(0);

         default:
            cout << "    Command didnt match, please try again." << endl;
            break;
      }

      cout << "\n<----------------------------------------------------------->\n";  

   }
}



Node *accept(){
   Node *a = new Node();

   cout << "\n    Enter data : ";
   cin >> a->data;
   a->next = NULL;
   a->previous = NULL;

   return a;
}


int lengthOfList(Node *mainList){
   if (mainList == NULL){
      return 0;
   }
   else{
      int count = 0;
      while (mainList != NULL){
         count += 1;
         mainList = mainList->next;     
      }
      return count;     
   }
}


void addToStart(Node **mainList){
    Node *temp = accept();
    
    temp->next = *mainList;
    
    *mainList = temp;
    
    
}


void addToEnd(Node **mainList){
   Node *temp, *store;
   temp = *mainList;
   while(temp->next != NULL){
      temp = temp->next;
   }
   temp->next = accept();
   store = temp;
   temp = temp->next;
   temp->previous = store;
   last = temp; 
   
}


void addToMid(Node **mainList, int position){
   Node *temp = *mainList, *storeNext, *storePrev, *check = accept();

    int count = 0;
    while(count < position-1){
        count ++;
        temp = temp->next;
    }
    storeNext = temp->next;
    storePrev = temp;

    temp->next = check;
    temp = temp->next;
    temp->next = storeNext;
    temp->previous = storePrev;
}


void addNew(Node **mainList){

   if (*mainList == NULL){
      *mainList = accept();
      last = *mainList;
   }

   else{
      int length = lengthOfList(*mainList), index = -1;
      while (index < 0 || index > length){
         cout << "    Enter the index at which to be added (0, " << length << ") : ";
         cin >> index;
      }
      if (index == length){
         index = -1;
      }
      
      switch (index){
         case 0:
               addToStart(mainList);
               break;

         case -1:
               addToEnd(mainList);
               break;

         default:
               addToMid(mainList, index);
               break;
      }
   }

    
}


void display(Node *mainList){
   if (mainList == NULL){
      cout << "\n    List is Empty.\n";
   }
   else{
      cout << "\n\nData : " << endl;
        int count =0;
        Node *temp = mainList;
        while (temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
            count += 1;
        }
    
   }
}


void displayReverse(){
   if (last == NULL){
      cout << "\n    List is Empty.\n";
   }
   else{
      cout << "\n\nData : " << endl;

         Node *temp = last;
         while (temp != NULL){
            cout << temp->data << endl;
            temp = temp->previous;
         }
    
   }
}


void deleteIndex(Node **mainList){  
    int index, len = lengthOfList(*mainList);
    cout << "Enter the index to be deleted : ";
    cin >> index;

    if(index < 0 || index > len){
        cout << "\nIndex out of range, please try again." << endl;
    }
    else{
        if(index == 0){
            Node *temp0 = *mainList;
            if (len == 1){
                delete(*mainList);
                *mainList = NULL;
                last = NULL;
            }
            else{
                temp0 = temp0->next;
                temp0->previous = NULL;
                
                delete(*mainList);
                *mainList = temp0;
            }
        }
        else{
            Node *temp = *mainList, *storePrev, *storeNext;
            int count = 0;
            while(count < index){
                temp = temp->next;
                count += 1;
            }
            storePrev = temp->previous;
            storeNext = temp->next;
            
            temp->next = NULL;
            temp->previous = NULL;

            delete(temp);
            storePrev->next = storeNext;
            if (index == len-1){
                last = last->previous;
            }
            else{
                storeNext->previous = storePrev;
            }     

        }
        cout << "Deleted" << endl;
    }
    
}
