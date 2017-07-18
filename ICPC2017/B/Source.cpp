#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int N,M;

    vector<string> answers;
    while(1){

        string s1;
        string s2;

        cin >> s1;
        cin.ignore();
        if(s1=="."){
            break;
        }
        cin >> s2;
        cin.ignore();

        if(s1=="." || s2 == "."){
            break;
        }

        int cflag =0,dflag =0;
        int state = 0;
        int j=0;

        for(int i=0;i<s1.size();i++){
            if(state==0){
                //定数外で不一致
                if(s1[i] != s2[j]){
                    dflag = 1;
                    break;
                }
                //セミコロンの読みはじめ
                if((int)s1[i]==34){
                     state = 1;
                 }
                j++;
            }else{
                //定数内で不一致ならば
                if(s1[i]!=s2[j]){
                    if(cflag==0){
                        cflag = 1;
                    } else{
                        dflag = 1;
                        break;
                    }
                    for(;(int)s1[i]!=34;i++)//二重引用符がくるまで
                        ;
                    for(;(int)s2[j] != 34;j++)//二重引用符がくるまで
                        ;
                    state = 0;
                }else {//一致していたら
                    if ((int)s1[i] == 34) {//二重引用符なら
                        state=0;
                    }
                } 
                j++;
            }
        }

        if(s2[j]!='\0'){
            //cout << j << endl;
            answers.push_back("DIFFERENT");
        }else if(dflag==0){
            if(cflag==1){
                answers.push_back("CLOSE");
            }else{
                answers.push_back("IDENTICAL");
            }

        }else{
            answers.push_back("DIFFERENT");
        }

    }

    for(int i=0;i<answers.size();i++){
            cout << answers[i] << endl;
    }
    return 0;
}
