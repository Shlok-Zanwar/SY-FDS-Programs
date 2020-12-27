#include <iostream>
using namespace std;

struct Process{
    char name;
    int arrivalTime;
    int newArrivvalTime;
    
    int burstTime;
    int burstLeft;
    
    int exitTime;
    bool notDone = true;
};


int findShortestSJF(Process *index, int noOfProcess, int time);
int findFirstArrived(Process *index, int noOfProcess, int previous);
bool allNotDone(Process *index, int noOfProcess);
void RR(Process *index, int noOfProcess, int timeQuan);
void FCFS(Process *index, int noOfProcess);
void SJF(Process *index, int noOfProcess);
int isNewReadySTCF(Process *index, int noOfProcess, int time, Process *current);
void STCF(Process *index, int noOfProcess);
void giveSpaces(int count);
void displayTable(Process *index, int noOfProcess);



int main(){
    int method, timeQuan;
    cout << "Enter method : " << endl;
    cout << "1 : First in first out (FIFO)" << endl;
    cout << "2 : Shortest job first (SJF)" << endl;
    cout << "3 : Shortest time to completion first (STCF)" << endl;
    cout << "4 : Round Robbin (RR)" << endl;
    cout << "Choice : ";

    cin >> method; 
    if(method == 4){
        cout << "Enter time quantum : ";
        cin >> timeQuan;
    }

    int noOfProcess;
    cout << "\nEnter number of process : ";
    cin >> noOfProcess;
    Process mainArr[noOfProcess];

    for (int i = 0; i < noOfProcess; i++){
        cout << "Process " << i+1 << " :-" << endl; 
        cout << "    Enter process char (A, B....) : ";
        cin >> mainArr[i].name;
        cout << "    Enter arrival time : ";
        cin >> mainArr[i].arrivalTime;
        cout << "    Enter Burst time : ";
        cin >> mainArr[i].burstTime;
    
        mainArr[i].burstLeft = mainArr[i].burstTime;
        mainArr[i].newArrivvalTime = mainArr[i].arrivalTime;
        cout << "\n\n";
    }

    switch (method){
        case 1:
            FCFS(mainArr, noOfProcess);
            break;
        
        case 2:
            SJF(mainArr, noOfProcess);
            break;

        case 3:
            STCF(mainArr, noOfProcess);
            break;

        case 4:
            RR(mainArr, noOfProcess, timeQuan);
            break;

        default:
            cout << "Invalid input, using FIFO method" << endl;
            FCFS(mainArr, noOfProcess);
            break;
    }
    displayTable(mainArr, noOfProcess);    
}


int findShortestSJF(Process *index, int noOfProcess, int time){
    int count = 0;
    int leastTime, leastIndex = -1;


    for (int i = 0 ; i < noOfProcess; i++){
        if(index->notDone){
            if(index->newArrivvalTime <= time){
                if (count == 0){
                    leastTime = index->burstLeft;
                    leastIndex = i;
                    count ++;
                }
                else{
                    if(leastTime > index->burstLeft){
                        leastTime = index->burstLeft;
                        leastIndex = i;
                    }
                }
            }   
        }
        index += 1;
    }

    return leastIndex;
    
}


int findFirstArrived(Process *index, int noOfProcess, int previous){
    int firstIndex;
    int leastValue;
    int i;
    int count = 0;
    
    index += previous + 1;

    for (i = previous + 1; i < noOfProcess; i++){
        
        if(index->notDone){
            if (count == 0){
                leastValue = index->newArrivvalTime;
                firstIndex = i;
                count ++ ;
            }
            else{
                if (leastValue > index->newArrivvalTime){
                    firstIndex = i;
                    leastValue = index->newArrivvalTime;
                }
            }
        }
        index += 1;
    }

    index -= noOfProcess;

    for (i = 0 ; i < previous + 1; i++){
        if(index->notDone){
            if (count == 0){
                leastValue = index->newArrivvalTime;
                firstIndex = i;
                count ++ ;
            }
            else{
                if (leastValue > index->newArrivvalTime){
                    firstIndex = i;
                    leastValue = index->newArrivvalTime;
                }
            }
        }
        index += 1;
    }

    // cout << firstIndex << "    " << (index-noOfProcess+firstIndex)->newArrivvalTime << endl;

    return firstIndex;
}


bool allNotDone(Process *index, int noOfProcess){
    for (int i = 0; i < noOfProcess; i++){
        if (index->notDone){
            return true;
        }
        index ++;
    }
    return false;
}


void RR(Process *index, int noOfProcess, int timeQuan){
    int time = 0;
    int firstArrived = -1;
    while (allNotDone(index, noOfProcess)){
        firstArrived = findFirstArrived(index, noOfProcess, firstArrived);
        Process *temp = index;
        temp += firstArrived;

// when processor has no process
        if(temp->newArrivvalTime > time){
            time = temp->newArrivvalTime;
        }

        if(temp->burstLeft < timeQuan){
            time += temp->burstLeft;
            temp->burstLeft -= temp->burstLeft;
        }
        else{
            time += timeQuan;
            temp->burstLeft -= timeQuan;
        }

        temp->newArrivvalTime = time;
        if (temp->burstLeft == 0){
            temp->exitTime = time;
            temp->notDone = false;
        }

    }
    

}


void FCFS(Process *index, int noOfProcess){
    int time = 0;
    // int firstArrived = -1;
    while (allNotDone(index, noOfProcess)){
        int firstArrived = findFirstArrived(index, noOfProcess, -1);
        Process *temp = index;
        temp += firstArrived;

        if(temp->arrivalTime > time){
            time = temp->arrivalTime;
        }

        time += temp->burstTime;
        temp->exitTime = time;
        temp->notDone = false;
    }
    cout << "Total time = " << time << endl;
}


void SJF(Process *index, int noOfProcess){
    int time = 0, firstArrived;
    while (allNotDone(index, noOfProcess)){
        firstArrived = findShortestSJF(index, noOfProcess, time);
        Process *temp = index;
        temp += firstArrived;

        if(firstArrived == -1){
            time += 1;
            continue;
        }

        time += temp->burstTime;
        temp->exitTime = time;
        temp->notDone = false;
    }
    
}


int isNewReadySTCF(Process *index, int noOfProcess, int time, Process *current){
    int newIndex = -1;

    for (int i = 0; i < noOfProcess; i++){
        if (index->notDone){
            if (index->newArrivvalTime <= time){
                if(index->burstLeft < current->burstLeft){
                    newIndex = i;
                    break;
                }
            }
            
        }
        index += 1;
    }
    return newIndex;
    
}


void STCF(Process *index, int noOfProcess){
    int time = 0, gotFirst = -1;
    while(gotFirst == -1){
        gotFirst = findShortestSJF(index, noOfProcess, time);
        if(gotFirst == -1){
            time += 1;
        }
    }

    
    while (allNotDone(index, noOfProcess)){
        Process *temp = index;
        temp += gotFirst;
        gotFirst = isNewReadySTCF(index, noOfProcess, time, temp);
        if(gotFirst != -1){
            continue;
        }


        temp->burstLeft -= 1;
        time += 1;
    cout << "exec " << temp->name << endl;
        if (temp->burstLeft == 0){
            temp->exitTime = time;
            temp->notDone = false;

            if(allNotDone(index, noOfProcess)){
                gotFirst = -1;
                while(gotFirst == -1){
                    gotFirst = findShortestSJF(index, noOfProcess, time);
                    if(gotFirst == -1){
                        time += 1;
                    }
                }
            }

        }

        
        
    }
    

}


void giveSpaces(int count){
    for (int i = 0; i < count; i++){
        cout << " ";
    }
}


// 4 10 8 14
void displayTable(Process *index, int noOfProcess){
    float totalTAT = 0, totalWaiting = 0;
    cout << "\nId  Arrival   Burst   Turn-around   Waiting time\n" << endl;
    for (int i = 0; i < noOfProcess; i++){
        cout << index->name << "      " << index->arrivalTime;
        giveSpaces(10 - to_string(index->arrivalTime).length());
        cout << index->burstTime;
        giveSpaces(8 - to_string(index->burstTime).length());
        int tat = index->exitTime - index->arrivalTime;
        cout << tat;
        giveSpaces(14 - to_string(tat).length());
        cout << tat-index->burstTime;

        totalTAT += tat;
        totalWaiting = totalWaiting + tat - index->burstTime;

        index ++;
        cout << "\n";
    }

    float avgTAT = totalTAT/noOfProcess;
    float avgWaiting = totalWaiting/noOfProcess;

    cout << "\nAvg turn around time = " << avgTAT << endl;
    cout << "Avg waiting time = " << avgWaiting << endl << endl << endl;
    
}






// mainArr[0].name = "a";
    // mainArr[0].arrivalTime = 3;
    // mainArr[0].burstTime = 4;
    // mainArr[0].burstLeft = mainArr[0].burstTime;
    // mainArr[0].newArrivvalTime = mainArr[0].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[1].arrivalTime = 5;
    // mainArr[1].burstTime = 3;
    // mainArr[1].burstLeft = mainArr[1].burstTime;
    // mainArr[1].newArrivvalTime = mainArr[1].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[2].arrivalTime = 0;
    // mainArr[2].burstTime = 2;
    // mainArr[2].burstLeft = mainArr[2].burstTime;
    // mainArr[2].newArrivvalTime = mainArr[2].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[3].arrivalTime = 5;
    // mainArr[3].burstTime = 1;
    // mainArr[3].burstLeft = mainArr[3].burstTime;
    // mainArr[3].newArrivvalTime = mainArr[3].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[4].arrivalTime = 4;
    // mainArr[4].burstTime = 3;
    // mainArr[4].burstLeft = mainArr[4].burstTime;
    // mainArr[4].newArrivvalTime = mainArr[4].arrivalTime;


        // mainArr[0].name = "a";
    // mainArr[0].arrivalTime = 0;
    // mainArr[0].burstTime = 5;
    // mainArr[0].burstLeft = mainArr[0].burstTime;
    // mainArr[0].newArrivvalTime = mainArr[0].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[1].arrivalTime = 1;
    // mainArr[1].burstTime = 3;
    // mainArr[1].burstLeft = mainArr[1].burstTime;
    // mainArr[1].newArrivvalTime = mainArr[1].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[2].arrivalTime = 2;
    // mainArr[2].burstTime = 1;
    // mainArr[2].burstLeft = mainArr[2].burstTime;
    // mainArr[2].newArrivvalTime = mainArr[2].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[3].arrivalTime = 3;
    // mainArr[3].burstTime = 2;
    // mainArr[3].burstLeft = mainArr[3].burstTime;
    // mainArr[3].newArrivvalTime = mainArr[3].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[4].arrivalTime = 4;
    // mainArr[4].burstTime = 3;
    // mainArr[4].burstLeft = mainArr[4].burstTime;
    // mainArr[4].newArrivvalTime = mainArr[4].arrivalTime;




    // mainArr[0].arrivalTime = 5;
    // mainArr[0].burstTime = 100;
    // mainArr[0].burstLeft = mainArr[0].burstTime;
    // mainArr[0].newArrivvalTime = mainArr[0].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[1].arrivalTime = 10;
    // mainArr[1].burstTime = 10;
    // mainArr[1].burstLeft = mainArr[1].burstTime;
    // mainArr[1].newArrivvalTime = mainArr[1].arrivalTime;

    // // mainArr[0].name = "A";
    // mainArr[2].arrivalTime = 30;
    // mainArr[2].burstTime = 10;
    // mainArr[2].burstLeft = mainArr[2].burstTime;
    // mainArr[2].newArrivvalTime 