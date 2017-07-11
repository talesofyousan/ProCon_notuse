#include <iostream>
#include<vector>
#include<string>

#define MAX_N 50
#define T 1
#define F 0

using namespace std;

int N;
vector< string > port(MAX_N);
vector <int> ans;

int isBoin(char a){
    if(a=='a'||a=='i'||a=='u'||a=='e'||a=='o'){
        return 1;
    }else{
        return 0;
    }
}

int hikaku(string s1,string s2,int n){

    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            return F;
        }
    }

    return T;
}

int main(){

    while(1){
        cin >> N;
        cin.ignore();

        if(N == 0){
            break;
        }

        for(int i=0;i<N;i++){
            cin >> port[i];
            cin.ignore();
        }
        
        int maxlen = 0;
        vector<string> cord(N);
        for(int i=0;i<N;i++){
            string cordsingle;
            for(int j =0;j<port[i].size();j++){
                if(j==0){
                    cordsingle+=port[i][j];
                }else{
                    if(isBoin(port[i][j-1])==T){
                        cordsingle+=port[i][j];
                    }
                }
            }
            if(maxlen < cordsingle.size()){
                maxlen = cordsingle.size();
            }
            cord[i] = cordsingle;
        }

        for(int i=0;i<N;i++){
            int len = cord[i].size();
            for(int j=0;j<maxlen-len;j++){
                cord[i] += '*';
            }
        }

        int mini = 0;
        int count = 0;
        for(int i=1;i<=maxlen;i++){
            count = 0;
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(j!=k){
                        count += hikaku(cord[j],cord[k],i);
                    }
                }
            }
            if(count == 0){
                mini = i;
                break;
            }
        }

        if(mini == 0){
            mini = -1;
        }

        ans.push_back(mini);

    }

    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}