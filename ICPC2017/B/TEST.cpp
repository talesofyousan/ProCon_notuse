#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main(){

    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        cout << s[i] << "," << (int)s[i] << endl ;
    }
    return 0;
}
