#include<iostream>
#include<vector>
#include<string>

using namespace std;

#define MAX 100
#define LU "lu"
#define RU "ru"
#define LD "ld"
#define RD "rd"

int main(){

    vector<int> answers;
    while(1){
        int n;
        string str;

        cin >> n;
        cin.ignore();

        if(n==0){
            break;
        }

        vector<string> command(n);
        
        getline(cin,str);
        //cout << str << endl;

        for(int i=0;i<n;i++){
            //cout << str[3*i] << "," << str[3*i+1] << endl;
            string buff = str.substr(3*i,2);
            //cout << str[3*i]+str[3*i+1] << endl;
            command[i] = buff;
        }

        for(int i=0;i<n;i++){
            //cout << command[i] << endl;
        }

        int ans = 0;

        for(int i=1;i<n;i+=2){
            if(command[i] == "ru" && command[i-1] == "lu"){
                ans ++;
            }else if(command[i] == "lu" && command[i-1] == "ru"){
                ans++;
            }else if(command[i] == "ld" && command[i-1] == "rd"){
                ans++;
            }else if(command[i] == "rd" && command[i-1] == "ld"){
                ans++;
            }else{

            }
        }

        answers.push_back(ans);
    }

    for(int i=0;i<answers.size();i++){
        cout << answers[i] << endl;
    }
    return 0;
}