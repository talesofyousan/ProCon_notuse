#include<iostream>
#include<map>

using namespace std;

int main(){

    map<string, int> mp;
    map<string, int>::iterator itr;

    mp["abc"] = 100;

    itr = mp.find("abc");
    if(itr != mp.end()){
        cout << "arimasu" << endl;
    }else{
        cout << "naidesu" << endl;
    }

    for(itr=mp.begin();itr!=mp.end();itr++){
        cout << itr->first <<","<<itr->second << endl;
    }

    int size = mp.size();
    cout << size << endl;

}