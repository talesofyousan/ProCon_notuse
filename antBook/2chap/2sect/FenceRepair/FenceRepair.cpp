#include<iostream>
#include<vector>

#define MAX_N 20000

using namespace std;

int N;
vector<int> L(MAX_N);

int swap(int *m1,int *m2){
    int temp = *m1;
    *m1 = *m2;
    *m2 = temp;

    return 0;
}

int main(){

    cin >> N;
    cin.ignore();

    for(int i=0;i<N;i++){
        cin >> L[i];
    }
    cin.ignore();

    /*
    for(int i=0;i<N;i++){
        cout << L[i] << ",";
    }
    cout << endl;
    */
    int ans = 0;
    while(N>1){

        int m1 = 0, m2=1;

        if(L[m1]>L[m2]){
            swap(&m1,&m2);
        }

        for(int i=2;i<N;i++){
            if(L[i]<L[m1]){
                m2 = m1;
                m1 = i;
            }else if(L[i]<L[m2]){
                m2 = i;
            }
        }

        int cost = L[m1]+L[m2];
        ans += cost;

        //cout << m1 << "," << m2 << endl;
        if(m1 == N-1){
            swap(&m1,&m2);
        }
        L[m1] = cost;
        L[m2] = L[N-1];
        N--;

    }

    cout << ans << endl;
}