#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define A '.'
#define S 'S'
#define G 'G'
#define D '#'

int H,W,N,M;
vector<int> data;

//"N M"と入力→"0 0"が入力されたら終了
/*
1 2
10 100
0 0

*/
int getInputZero(){
    while(1){
        cin >> N >> M;
        cin.ignore();

        data.push_back(N);
        data.push_back(M);

        if(N==0 && M == 0){
            break;
        }
    }

    cout << "---------------" << endl;
    for(int i=0;i<data.size();i+=2){
        cout << data[i] << "," << data[i+1] << endl;
    }
}

// 2行目以降が文字列になっているやつ
/*
3 3
..S
##.
G..
*/
void getInputString(){

    cin >> H >> W;
    cin.ignore();
    
    vector< vector<char> > maze;
    vector<char> row(W);
    
    for(int i=0;i<H;i++){
        string s;
        getline(cin,s);
        for(int j=0;j<W;j++){
            if(s[j] == S){
                row[j] = S;
            }else if(s[j] == G){
                row[j] = G;
            }else if(s[j] == A){
                row[j] = A;
            }else{
                row[j] = D;
            }
        }
        maze.push_back(row);
    }

    cout << "---------------" << endl;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;

}

int main(){

    cout << "getInputZero()" << endl;
    getInputZero();

    cout << "getInputString" << endl;
    getInputString();

    return 0;
}