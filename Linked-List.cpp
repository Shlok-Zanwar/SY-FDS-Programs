// Singly linked list
// Data : Name, department, int(Id, salary)
// It also verifies if ids are not repeated

#include<iostream>
#include<string>

using namespace std;
typedef struct employee{   
   string name;
   int id;
   string dept;
   int salaray;
   struct employee *next;
}Node;


int checkId(Node *first, int requiredId);
Node *accept(Node *first);
int lengthOfList(Node *first);
void addToStart(Node **first);
void addToEnd(Node **first);
void addToMid(Node **first, int position);
void addNew(Node **first);
void display(Node *first, bool reverse);
void searchId(Node *first);
void deleteId(Node **first);
void recDisplayRev(Node *first);



int main(){
   Node *first = NULL, *temp, *head;
   int cont;

    
   while (true){ 
      cout << "\nEnter Operation : "<< endl;
      cout << "1 : Add new element." << endl;
      cout << "2 : Display list." << endl;
      cout << "3 : Search Id." << endl;
      cout << "4 : Delete Record." << endl;
      cout << "5 : Length of linked list" << endl;
      cout << "6 : Diplay reverse list" << endl;
      cout << "0 : Exit" << endl; 
      cout << "Operation : "; 
      cin >> cont;


      switch (cont){
         case 1:
            addNew(&first);
            break;
         
         case 2:
            display(first, false);
            break;

         case 3: 
            searchId(first);
            break;

         case 4:
            deleteId(&first);
            break;

         case 5:
            cout << "    Length of linked list is = " << lengthOfList(first) << endl;
            break;

         case 6:
            display(first, true);
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


int checkId(Node *first, int requiredId){
   int index = 0;
   while (first != NULL){
      if (first->id == requiredId){
         return index;
      }
      index += 1;
      first = first->next;
   }
   return (-1);
}


Node *accept(Node *first){
   Node *a = new Node();
   int tempId;

   cout << "\n    Enter Id : ";
   cin >> tempId;

   if(checkId(first, tempId) == -1){
      a->id = tempId;
      cout << "    Enter Name : ";
      cin >> a->name;

      cout << "    Enter Department : ";
      cin >> a->dept;
      
      cout << "    Enter salaray : ";
      cin >> a->salaray;
      a->next = NULL;
      return (a);
   }
   else{
       cout << "    Id already exists." << endl;
       return NULL;
   }
   
}


int lengthOfList(Node *first){
   if (first == NULL){
      return 0;
   }
   else{
      int count = 0;
      while (first != NULL){
         count += 1;
         first = first->next;     
      }
      return count;     
   }
}


void addToStart(Node **first){
   Node *temp = accept(*first);
   if(temp != NULL){
      temp->next = *first;
      *first = temp;
   }
}


void addToEnd(Node **first){
   Node *temp;
   temp = *first;
   while(temp->next != NULL){
      temp = temp->next;
   }
   temp->next = accept(*first);  
}


void addToMid(Node **first, int position){
   Node *temp = *first, *store, *check = accept(*first);
   if (check != NULL){
      int count = 0;
      while(count < position-1){
         count ++;
         temp = temp->next;
      }
      store = temp->next;

      temp->next = check;
      temp = temp->next;
      temp->next = store;
   }
}


void addNew(Node **first){

   if (*first == NULL){
      *first = accept(*first);
   }

   else{
      int length = lengthOfList(*first), index = -1;
      while (index < 0 || index > length){
         cout << "    Enter the index at which to be added (0, " << length << ") : ";
         cin >> index;
      }
      if (index == length){
         index = -1;
      }
      
      switch (index){
         case 0:
               addToStart(first);
               break;

         case -1:
               addToEnd(first);
               break;

         default:
               addToMid(first, index);
               break;
      }
   }

    
}


// recursive display reverse
void recDisplayRev(Node *first){
   if(first != NULL){

      recDisplayRev(first->next);

      string str = "    ";
      str += to_string(first->id);
      while (str.length() < 11){
         str += " ";
         
      }
      str += first->name;
      while (str.length() < 31){
         str += " ";
      }

      str += first->dept;
      while (str.length() < 48){
         str += " ";
      }
      
      str += to_string(first->salaray);
      cout << str << endl;
   }
}


void display(Node *first, bool reverse){
   if (first == NULL){
      cout << "\n    List is Empty.\n";
   }
   else{
      cout << "\n\n    Id     Name                Department       Salary" << endl;
      if (reverse){
         recDisplayRev(first);
      }
      else{
         Node *temp = first;
         while (temp != NULL){
            string str = "    ";
            str += to_string(temp->id);
            while (str.length() < 11){
               str += " ";
               
            }
            str += temp->name;
            while (str.length() < 31){
               str += " ";
            }

            str += temp->dept;
            while (str.length() < 48){
               str += " ";
            }
            
            str += to_string(temp->salaray);
            cout << str << endl;

            temp = temp->next;
         }
      }
   }
}


void searchId(Node *first){
   int search;
   cout << "\n    Enter Id    : ";
   cin >> search;
   int getIndex = checkId(first, search);

   if (getIndex == -1){
      cout << "    Id " << search << " dosent exist." << endl;;
   }
   else{
      for (int i = 0; i < getIndex; i++){
         first = first->next;
      }
      cout << "    Name       : " << first->name << endl;
      cout << "    Department : " << first->dept << endl;
      cout << "    Salary     : " << first->salaray <<endl;
   }
   

}


void deleteId(Node **first){  
   int check;
   cout << "\n    Enter Id to be deleted : ";
   cin >> check;
   int index = checkId(*first, check);

   if(index == -1){
      cout << "    Id dosent exists." << endl;
   }
   else{
      switch (index){
         case 0:
            Node *temp0;
            temp0 = *first;
            temp0 = temp0->next;
            delete(*first);
            *first = temp0;
            break;

         default:
            Node *temp, *store, *delStore;
            temp = *first;
            for (int i = 0; i < index-1; i++){
               temp = temp->next;
            }
            delStore = temp->next;
            store = delStore->next;
            temp->next = store;
            delete(delStore);
            break;
      }
      cout << "    Record with Id = '" << check << "' deleted" << endl;
      
   }
   

}

