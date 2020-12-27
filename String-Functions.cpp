#include<iostream>
using namespace std;


class UsingPointer{
    public:
        int length(char *str1){
            int len = 0;
            while(*str1 != '\0'){
                len += 1;
                str1 +=1;
            }
            return len;
        }


        void copy(char *str1, char *str2){
            while (*str1 != '\0'){
                *str2 = *str1;
                str2 ++;
                str1 ++;
            }
            *str2 = '\0';       
        }  


        void concat(char *str1, char *str2){
            while (*str1 != '\0'){
                str1 ++;
            }
            while (*str2 != '\0'){
                *str1 = *str2;
                str1 ++;
                str2 ++;
            }
            *str1 = '\0'; 
        }


        void compare(char *str1, char *str2){
            int lenOf1 = length(str1), lenOf2 = length(str2);
            if (lenOf1 == lenOf2){
                while (*str1 != '\0' || *str2 != '\0'){
                    if (*str1 > *str2){
                        cout << "String 1 is greater than string 2." << endl; 
                        return;
                    }
                    else if (*str2 > *str1){
                        cout << "String 2 is greater than string 1." << endl;
                        return;
                    }
                    else{
                        str1 ++ ;
                        str2 ++;
                    }                                        
                }
                cout << "Both strings are equal." << endl;
                
            }
            else if (lenOf1 > lenOf2) {
                cout << "String 1 is greater than string 2." << endl;                
            }
            else{
                cout << "String 2 is greater than string 1." << endl;
            }
                                    
        }


        void reverse(char *str1, char *str2){
            for (int i = length(str1)-1; i >=0 ; i--){
                *str2 = *(str1 + i);
                str2 ++;
            }
            *str2 = '\0';
        }

};


class withoutUsingPointer{
    public:
        int length(char str1[50]){
            int len = 0;
            while(str1[len] != '\0'){
                len += 1;
            }
            return len;
        }


        void copy(char str1[50], char str2[50]){
            int i=0;
            while (str1[i] != '\0'){
                str2[i] = str1[i];
                i ++ ;
            }
            str2[i] = '\0';
            cout << "Copied string (without using pointer) = " << str2 << endl;       
        }  


        void concat(char str1[50], char str2[50]){
            int i=0, j=0;
            while (str1[i] != '\0'){
                i ++ ;
            }
            while (str2[j] != '\0'){
                str1[i] = str2[j];
                i ++ ;
                j ++ ;
            }
            str1[i] = '\0';
            cout << "Concatenated string (without using pointers) = " << str1 << endl; 

        }


        void compare(char str1[50], char str2[50]){
            int lenOf1 = length(str1), lenOf2 = length(str2);
            int i = 0;
            if (lenOf1 == lenOf2){
                while (str1[i] != '\0' || str2[i] != '\0'){
                    if (str1[i] > str2[i]){
                        cout << "String 1 is greater than string 2." << endl; 
                        return;
                    }
                    else if (str2[i] > str1[i]){
                        cout << "String 2 is greater than string 1." << endl;
                        return;
                    }
                    else{
                        i ++ ;
                    }                                        
                }
                cout << "Both strings are equal." << endl;
                
            }
            else if (lenOf1 > lenOf2) {
                cout << "String 1 is greater than string 2." << endl;                
            }
            else{
                cout << "String 2 is greater than string 1." << endl;
            }
                                    
        }


        void reverse(char str1[50]){
            char str2[50];
            int j=0;
            for (int i = length(str1)-1; i >=0 ; i--){
                str2[j] = str1[i];
                j ++ ;
            }
            str2[j] = '\0';
            cout << "Reverse of string (without using pointers) '" << str1 << "' is '" << str2 << "'.\n";
        }
};




int main(){
    int operation, method;
    char str1[50], str2[50];
    UsingPointer withPointer;
    withoutUsingPointer withoutPointer;
    while(true){
        cout << "\nEnter the action to perform:\n1 : Length \n2 : Copy \n3 : Concat (string 1 + string 2) \n4 : Compare \n5 : Reverse \n0 : Exit\n\nChoice : ";
        cin >> operation;

        // for exiting
        if (operation == 0){
            cout << "Thank You !" << endl ;
            exit (0);
        }
        // validating
        if (operation > 5 || operation < 0){
            cout << "Invalid Command, please try again" << endl;
            continue;
        }

        cout << "Enter string 1 : ";
        cin >> str1;

        if(operation == 3 || operation == 4){
            cout << "Enter string 2 : ";
            cin >> str2;
        }
        
        cout << "\nEnter method (1 -> using pointer), (any other number for without pointer) : ";
        cin >> method;
        cout << "\n";
// incrementing operations by 10 for without pointer method for switch case.
        if (method == 1){
            operation += 10;
        }
        

        switch (operation){
            // Cases without pointers
            case 1:
                // length
                cout << "Length of string (without using pointer) = " << withoutPointer.length(str1) << endl;
                break;

            case 2:
                // copy
                withoutPointer.copy(str1, str2);
                break;

            case 3:
                // concat
                withoutPointer.concat(str1, str2);
                // cout << str1;
                break;

            case 4:
                //compare
                withoutPointer.compare(str1, str2);
                break;

            case 5:
                // reverse
                withoutPointer.reverse(str1);
                break;


            // Cases with pointer
            case 11:
                // length with ptr
                cout << "Length of string (using pointer) = " << withPointer.length(str1) << endl;        
                break;

            case 12:
                // copy with ptr
                withPointer.copy(str1, str2);
                cout << "Copied string (using pointer) = " << str2 << endl;
                break;

            case 13:
                // concat with ptr
                withPointer.concat(str1, str2);
                cout << "Concatenated string (using pointers) = " << str1 << endl;
                break;

            case 14:
                // compare with ptr
                withPointer.compare(str1, str2);
                break;

            case 15:
                // reverse with ptr
                withPointer.reverse(str1, str2);
                cout << "Reverse of string (using pointers) '" << str1 << "' is '" << str2 << "'.\n";
                break;
            
        }

        cout << "\n<--------------------------------------------------------------------------->\n";

    }


}
