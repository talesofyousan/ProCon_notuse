#include<iostream>
#include<vector>

using namespace std;

int main(){

    int N,W;
    cin >> N >> W;
    cin.ignore();

    vector< vector<int> > values(N);

    for(int i=0;i<N;i++){
        vector<int> row(2);
        cin >> row[0] >> row[1];
        cin.ignore();

        values[i] = row;
    }

    for(int i=0;i<N;i++){
        //cout << values[i][0] << values[i][1] << endl;
    }



    int dp[N+1][W+1];
    for(int i=0;i<=W;i++){
        dp[N][i] = 0;
    }
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<=W;j++){
            //cout << "j=" << j << ",weight=" << values[i][0] << endl;
            if(j<values[i][0]){
                dp[i][j]=dp[i+1][j];
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i+1][j-values[i][0]]+values[i][1]);
            }
            //cout << "dp["<<i << "][" << j << "]=" << dp[i][j] << endl;
        }
    }

/*
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            cout << dp[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
*/
    cout << dp[0][W] << endl;
}