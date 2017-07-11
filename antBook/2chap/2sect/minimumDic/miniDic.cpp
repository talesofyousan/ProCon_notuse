#include<iostream>
#include<string>
#include<vector>

#define MAX_N 2000

using namespace std;
int N;
vector<char> S(MAX_N);

int main(){
  cin >> N;
  cin.ignore();

  for(int i=0;i<N;i++){
    cin >> S[i];
    cin.ignore();
  }
/*
  for(int i=0;i<N;i++){
    cout << S[i];
  }
  cout << endl;
*/
  int a = 0,b = N-1;

  while(a <= b){

    for(int i=0;a+i <= b;i++){
      if(S[a+i] < S[b-i]){
        cout << S[a];
        a++;
        break;
      }else{
        cout << S[b];
        b--;
        break;
      }
    }
  }
  cout << endl;

  return 0;
}
