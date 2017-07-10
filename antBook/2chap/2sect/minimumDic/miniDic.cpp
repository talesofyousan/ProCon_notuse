#include<iostream>
#include<string>
#include<vector>

#define REP(i,n) for(i=0;i<n;i++)
#define MAX_N 2000

using namespace std;

int N;
vector<char> S(MAX_N);

int main(){
  cin >> N;
  cin.ignore();

  int i,j,k;
  REP(i,N){
    cin >> S[i];
    cin.ignore();
  }

  REP(i,N){
    cout << S[i];
  }
  cout << endl;

  return 0;
}
