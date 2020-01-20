#include <iostream>
using namespace std;
#define MAX 10
typedef struct Job{
    char id[7];
    int deadline;
    int profit;
}Job;
int mini(int x, int y){
    if(x < y){
    return x;
    }else{
    return y;
    }
}

void deadline_j(Job jobs[], int n){
    int i, j, k, maxprt;

    int tslot[MAX];
    int ftimeslot = 0;
    int dead_max = 0;
    for(i=0;i<n;i++){
        if (jobs[i].deadline > dead_max){
            dead_max = jobs[i].deadline;
        }
        
    }
    for(i = 1;i <= dead_max; i++){
        tslot[i] = -1;
    }
    cout << "Max :" << dead_max  ;
    for(i = 1; i <= n; i++){
        k = mini(dead_max,jobs[i-1].deadline);
        while(k >= 1){
            if(tslot[k]==-1){
                tslot[k] = i-1;
                ftimeslot++;
                break;
            }
            k--;
        }
        if(ftimeslot == dead_max){
            break;
        }
    }
   cout << "\nRequered JoBS are :";
    for(i=1;i<=dead_max;i++){
        printf("%s", jobs[tslot[i]].id);

        if(i< dead_max){
            printf("-->");
        }
    }
    maxprt = 0;
    for(i = 1; i<= dead_max; i++){
        maxprt += jobs[tslot[i]].profit;
    }
   cout << "\nMax Profit Are : " << maxprt << "\n";
}

int main(void){
    int i,j;

    Job jobs[7] = {
        {"j1", 2, 90},
        {"j2", 2, 20},
        {"j3", 1, 40},
        {"j4", 1, 30},
        {"j5", 4, 65},
        {"j6", 1, 35},
        {"j7", 3, 50},
    };
    Job tmp;
    int n = 7;

    for(i = 7; i < n;i++){
        for(j = 0 ;j < n-i; j++){
            if(jobs[j+1].profit > jobs[j].profit){
                tmp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j]=tmp;
            }
        }
    }
    cout << "JOB " << " DEADLINES " << " PROFIT " << "\n";
    for(i = 0 ; i < n ; i++){
        cout << jobs[i].id << "      " << jobs[i].deadline << "         " << jobs[i].profit << "\n";
    }
    deadline_j(jobs,n);
    return 0;
}