#include <iostream>
using namespace std;

typedef struct Polynomial{
    int coeff;
    int power;
    struct Polynomial *next;
    struct Polynomial *prev;
}Node;


Node *last = NULL;

int lenOfList(Node *first);
void addNewToEnd(Node **index, int power, int coeff);
void addPolynomials(Node *poly1, Node *poly2, Node **resultPoly);
void subtractPolynomials (Node *poly1, Node *poly2, Node **resultPoly);
void whereToPut(Node **resultPoly, int power, int coeff);
void display(Node *index);
void displayReverse ();
void multiplyPolynomial (Node *poly1, Node *poly2, Node **resultPoly);
void takeInput(Node **poly, int num);



int main(){
    Node *poly1 = NULL, *poly2 = NULL, *resultPoly = NULL;

    cout << "\n\nAdd polynomials id descending order of power, (a)x^b where a is the coefficient and b is the power.\nThe input will end when you reach the power(0), if you wish to exit at some higher power enter a=0 and b=0.\n\n" << endl;
    takeInput(&poly1, 1);
    takeInput(&poly2, 2);

    cout << "Polynomial 1 : " ;
    display(poly1);
    cout << "\nPolynomial 2 : ";
    display(poly2);

    char method;
    bool notDone = true;
    while (notDone){
        cout << "\n\nEnter Operation (+, -, *) : ";
        cin >> method;
        switch (method){
            case '+':
                addPolynomials(poly1, poly2, &resultPoly);
                notDone = false;
                break;

            case '-':
                subtractPolynomials(poly1, poly2, &resultPoly);
                notDone = false;
                break;

            case '*':
                multiplyPolynomial(poly1, poly2, &resultPoly);
                notDone = false;
                break;

            default:
                cout << "Char didnt match, try again." << endl;
                break;
        }
    }
    cout << "\nResult polynomial : ";
    display(resultPoly);
    cout << "\nReverse           : ";
    displayReverse();
    cout << "\n\n";
}


int lenOfList (Node *first){
    int count = 0;
    while(first != NULL){
        count += 1;
        first = first->next;
    }
    return count;
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


void addPolynomials (Node *poly1, Node *poly2, Node **resultPoly){
    while (poly1 != NULL && poly2 != NULL){
        if(poly1->power > poly2->power){
            addNewToEnd(resultPoly, poly1->power, poly1->coeff);
            poly1 = poly1->next;
        }
        else if(poly2->power > poly1->power){
            addNewToEnd(resultPoly, poly2->power, poly2->coeff);
            poly2 = poly2->next;
        }
        else{
            if((poly1->coeff + poly2->coeff) != 0){
                addNewToEnd(resultPoly, poly1->power, poly1->coeff + poly2->coeff);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
    }
}


void subtractPolynomials (Node *poly1, Node *poly2, Node **resultPoly){
    while (poly1 != NULL && poly2 != NULL){
        if(poly1->power > poly2->power){
            addNewToEnd(resultPoly, poly1->power, poly1->coeff);
            poly1 = poly1->next;
        }
        else if(poly2->power > poly1->power){
            addNewToEnd(resultPoly, poly2->power, (poly2->coeff)*(-1));
            poly2 = poly2->next;
        }
        else{
            if((poly1->coeff - poly2->coeff) != 0){
                addNewToEnd(resultPoly, poly1->power, poly1->coeff - poly2->coeff);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        
    }
}


void whereToPut (Node **resultPoly, int power, int coeff){
    Node *temp1 = *resultPoly, *temp2 = temp1->next;
    // int count = 1;
    
    while(true){
        if (temp2->power == power){
            temp2->coeff += coeff;
            if(temp2->coeff == 0){
                temp1->next = temp2->next;
                if(temp2->next != NULL){
                    (temp2->next)->prev = temp1;
                }
                temp2->next = NULL;
                temp2->prev = NULL;
                delete(temp2);
            }
            return;
        }
        
        else if(power < temp1->power && power > temp2->power){
            Node *mid = new Node();
            mid->coeff = coeff;
            mid->power = power;
            mid->next = temp2;
            mid->prev = temp1;
            
            temp1->next = mid;
            temp2->prev = mid;
            return;
        }

        if (temp2->next == NULL){
            addNewToEnd(resultPoly, power, coeff);
            return;
        }

        // count ++;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

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


void displayReverse (){
    Node *temp = last;
    while (temp != NULL){
        cout << "(" << temp->coeff << ")X^" << temp->power ;
        temp = temp->prev;
        if (temp != NULL){
            cout << " + ";
        }
    }
    
}


void multiplyPolynomial (Node *poly1, Node *poly2, Node **resultPoly){
    int count = 0;
    Node *tempPoly1 = poly1, *tempPoly2;

    while (tempPoly1 != NULL){
        tempPoly2 = poly2;
        while (tempPoly2 != NULL){
            
            if((tempPoly1->coeff)*(tempPoly2->coeff) != 0){
                if (lenOfList(*resultPoly) <= 1){
                    addNewToEnd(resultPoly, (tempPoly1->power + tempPoly2->power), (tempPoly1->coeff)*(tempPoly2->coeff));
                }
                else{
                    whereToPut(resultPoly, (tempPoly1->power + tempPoly2->power), (tempPoly1->coeff)*(tempPoly2->coeff));
                }
            }
            
// cout << "multiplying " << tempPoly1->power << " and " << tempPoly2->power << endl;
            tempPoly2 = tempPoly2->next;
        }
        tempPoly1 = tempPoly1->next;
    }
    

}


void takeInput (Node **poly, int num){
    int power = -1, coeff, check = -1;
    cout << "Enter polynomial" << num << "(a x^b) (To finish put the coefficient and power (0,0) : " << endl;
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



//  3x^5 + 4x^3 + 0x^0
//  6x^4 0^0