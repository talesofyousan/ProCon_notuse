#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector< vector<int> > Y(10);

int dfs(int x,y){

    int ret = 0;
    int flag = 1;

    for(int i=-1;i<=1;i++){
        for(int i=-1;i<=1;i++){
            
        }   
    }

    if(flag == 0){
        return 0;
    }else{
        ret = 1;
    }

    Y[y][x] = 9;
    for(int dx=-1;dx<=1;dx++){
        for(int dy=-1;dy<=1;dy++){
            ret += dfs(nx+dx,nx+dy);
        }
    }

    return ret;
}

int main(){

    vector<int> answers;
    while(1){
        int x,y;

        cin >> y >> x;
        cin.ignore();

        if(x+y == 0){
            break;
        }

        for(int i=0;i<y;i++){
            vector<int> a(x);
            for(int j=0;j<x;j++){
                cin >> a[j];
            }
            cin.ignore();
            Y[i] = a;
        }

        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                cout << Y[i][j];
            }
            cout << endl;
        }
        cout << "-----------" << endl;

        int max = 0;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                int hoge = dfs(i,j);
                if(max < hoge){
                    max = hoge;                    
                }
            }
        }

        answers.push_back(max);
    }

    for(int i=0;i<answers.size();i++){
        cout << answers[i] << endl;
    }

    return 0;
}
