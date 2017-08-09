#include<iostream>
#include<queue>

using namespace std;

struct data_t{
    int num;
    string str;
};

int main(){

    queue<int> q1;
    queue<data_t> q2;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    q2.push({1,"hoge"});

    cout << q1.front() << endl;
    q1.pop();
    cout << q1.front() << endl;
    q1.pop();
    cout << q1.front() << endl;
    q1.pop();

    return 0;
}