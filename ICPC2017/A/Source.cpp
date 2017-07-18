#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N,M;

    vector<int> answers;
    while(1){

        cin >> N >> M;
        cin.ignore();

        if(N+M == 0){
            break;
        }

        vector<int> a(N);
        for(int i=0;i<N;i++){
            cin >> a[i];
        }
        cin.ignore();

        

        //sort(a.begin(),a.end());

        int ans = -1;
        bool flag = false;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i!=j){
                    if(ans < a[i]+a[j] && a[i]+a[j] <= M){
                        ans = a[i]+a[j];
                    }
                }
            }
        }

        answers.push_back(ans);

    }

    for(int i=0;i<answers.size();i++){
        if(answers[i]!=-1){
            cout << answers[i] << endl;
        }else{
            cout << "NONE" << endl;
        }
    }
    return 0;
}
