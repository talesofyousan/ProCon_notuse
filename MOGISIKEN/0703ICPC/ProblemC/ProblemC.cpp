#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define MAX 100

int exor(int a,int b){

    if( a == b){
        return 0;
    }else{
        return 1;
    }
}

vector<int> exor(vector<int> a, vector<int> b,int bit){

    vector<int> ret(bit);
    for(int i=0;i<bit;i++){
        ret[bit] = exor(a[i],b[i]);
    }

    return ret;
}

int main(){

    while(1){
        int n,b,t;
        cin >> n >> b >> t;
        cin.ignore();

        cout << n << b << t;

        if(n==0 && b == 0&& t==0){
            break;
        }

        vector< vector<int> > switches(t);
        vector< vector<int> > denkyu(t);
        for(int i=0;i<t;i++){
            string buff;
            getline(cin,buff);

            for(int j=0;j<n;j++){
                if(buff[j]=='0'){
                    switches[i].push_back(0);
                }else{
                    switches[i].push_back(1);
                }
            }

            for(int j=n+1;j<=b+n;j++){
                if(buff[j]=='0'){
                    denkyu[i].push_back(0);
                }else{
                    denkyu[i].push_back(1);
                }
            }
        }
/*
        for(int i=0;i<t;i++){
            for(int j=0;j<n;j++){
                cout << switches[i][j];
            }
            cout << ",";
            for(int j=0;j<b;j++){
                cout << denkyu[i][j];
            }
            cout << endl;
        }
*/
        vector< vector<int> > answers(b);
        for(int i=0;i<b;i++){
            vector<int> buff(n);
            for(int j=0;j<n;j++){
                buff[j] = 1;
            }
            answers[i] = buff;
        }

/*
        for(int i=0;i<b;i++){
            for(int j=0;j<n;j++){
                cout << answers[i][j] << "," ;
            }
            cout << endl;
        }
*/

        vector<int> state(b);
        for(int i=0;i<b;i++){
            state[i] = 0;
        }
        for(int i=0;i<t;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<b;k++){
                    
                }

            }
        }

        cout << "--------------------" << endl;
    }
    return 0;
}