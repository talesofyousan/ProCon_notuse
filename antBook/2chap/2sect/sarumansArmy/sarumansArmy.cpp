#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_N 1000
#define MAX_R 1000
#define MAX_X 1000
using namespace std;
int N,R;
vector<int> X(MAX_N+1);

int main(){

    cin >> N >> R;
    cin.ignore();

    for(int i=0;i<N;i++){
        cin >> X[i];
    }
    cin.ignore();

    sort(X.begin(),X.begin()+N);
/*
    cout << endl;
    for(int i=0;i<N;i++){
        cout << X[i] << ",";
    }
    cout << endl;
*/
    int count = 0,i=0;
    while(i <= N-1){

        int left = X[i];
        i++;
        while(i < N && X[i] <= left+R){
            i++;
            //cout << i << endl;
        }

        int center = X[i-1];

        while(i<N && X[i] <= center+R){
            i++;
            //cout << i << endl;
        }

        count++;
    }

    cout << count << endl;

    return 0;
}