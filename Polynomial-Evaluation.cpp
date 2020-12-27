#include <bits/stdc++.h>
using namespace std;

typedef struct Polynomial{
    int coeff;
    int power;
    struct Polynomial *next;
    struct Polynomial *prev;
}Node;

Node *last = NULL;


void takeInput(Node **poly);
void display(Node *index);
void evaluate(Node *index, int value);
void deleteAll(Node **poly);

int main(){
    Node *poly1 = NULL;

    cout << "\n\nAdd polynomials id descending order of power, (a)x^b where a is the coefficient and b is the power.\nThe input will end when you reach the power(0), if you wish to exit at some higher power enter a=0 and b=0.\n\n" << endl;
    takeInput(&poly1);

    cout << "Polynomial is : " ;
    display(poly1);

    while(true){
        cout << "\n\nEnter the number to evaluate : ";
        int value;
        cin >> value;

        evaluate(poly1, value);

        int toContinue;
        cout << "\nDo you want to continue (0 => exit)  (1 => continue) (2 => change polynomial) : ";
        cin >> toContinue;
        if(toContinue == 0){
            break;
        }
        else if(toContinue == 2){
            deleteAll(&poly1);
            poly1 = NULL;
            last = NULL;
            takeInput(&poly1);
        }

    }

}


void deleteAll(Node **poly){
    Node *temp = *poly, *store = temp->next;
    while (temp != NULL){
        store = temp->next;

        temp->next = NULL;
        temp->prev = NULL;
        temp = NULL;
        delete(temp);

        temp = store;
    }
}


void evaluate(Node *index, int value){
    int sum = 0;
    while(index != NULL){
        sum = sum + (pow(value, index->power))*index->coeff;
        index = index->next;
    }

    cout << "The evaluation is " << sum << endl;

}


void display (Node *index){
    while (index != NULL){
        cout << "(" << index->coeff << ")X^" << index->power ;
        index = index->next;
        if (index != NULL){
            cout << " + ";
        }
    }
    // cout << " = 0" << endl;
}


void addNewToEnd (Node **index, int power, int coeff){
    Node *a = new Node();
    a->coeff = coeff;
    a->power = power;
    a->next = NULL;
    a->prev = NULL;

    if(*index == NULL){
        *index = a;
        last = a;
    }
    else{
        Node *temp = *index; 
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = a;
        a->prev = temp;
        last = a;
    }
}


void takeInput (Node **poly){
    int power = -1, coeff, check = -1;
    cout << "Enter polynomial (a x^b) (To finish put the coefficient and power (0,0) : " << endl;
    while (power != 0){
        cout << "    a : ";
        cin >> coeff;
        cout << "    b : ";
        cin >> power;
        
        // verification of descending order and non-negative power
        if(power < 0){
            cout << "\nERROR, negative powers not allowed.\n\n";
            exit(0);
        }

        if(check == -1){
            check = power;
        }
        else{
            if(power >= check){
                cout << "\nERROR, descending order not found.\n\n";
                exit(0);
            }
            else{
                check = power;
            }
        }

        addNewToEnd(poly, power, coeff);
        cout << "\n";
    }
}