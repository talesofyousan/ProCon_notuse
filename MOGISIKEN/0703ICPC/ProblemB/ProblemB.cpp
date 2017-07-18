#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define MAX 100
#define LU "lu"
#define RU "ru"
#define LD "ld"
#define RD "rd"

int main(){

    vector<int> answers;

    while(1){
    vector< vector<int> > P(100);
    int n;
    cin >> n;
    cin.ignore();

    if(n==0){
        break;
    }
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int m;
            cin >> m;
            P[i].push_back(m);
        }
        cin.ignore();
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<P[i].size();j++){
           // cout << P[i][j] <<" ,";
        }
        //cout << endl;
    }

    int moreta;
    vector<int> moretalist(100);
    cin >> moreta;
    for(int i=0;i<moreta;i++){
        cin >> moretalist[i];
    }
    cin.ignore();

    for(int i=0;i<moreta;i++){
        //cout << moretalist[i];
        //cout << endl;
    }

    int index = -1;

    for(int i=0;i<n;i++){
        int flag1 = 0;
        int flag = 0;
        for(int j=0;j<P[i].size();j++){

            for(int k=0;k<moreta;k++){
                if(P[i][j]==moretalist[k]){
                    cout << "P[" << i << "]" <<"[" << j << "]=" << P[i][j] << ",";
                    cout << "moretalist[" << k << "]"  << moretalist[k] << endl;

                    flag++;
                }
            }
            if(flag != moreta){
                flag1 = 1;
                break;
            }
        }
        if(flag1 != 1){
        if(index != -1){
            index = -1;
            break;
        }else{
            index = i+1;
        }
        }
    }
    answers.push_back(index);
    }

    for(int i=0;i<answers.size();i++){
        cout << answers[i] << endl;
    }
    return 0;
}