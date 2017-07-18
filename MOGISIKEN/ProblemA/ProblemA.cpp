#include<iostream>
#include<vector>

using namespace std;

#define MAX_N


int main(){
    int x,y,s;

    vector<double> answer;
    while(1){
        cin >> x >> y >> s;
        cin.ignore();

        volatile double rate1 = (100.0+(double)x)/(100.0);
        volatile double rate2 = (100.0+(double)y)/(100.0);

/*
        int hoge = 1;
        double a = 3.00;
        cout << ((double)hoge * 3.16) << endl;
*/
        //cout << rate1 << rate2 << endl;

        if( x == 0 && y == 0&& s == 0){
            break;
        }

        volatile double max = 0;
        for(int i=1;i<=s-1;i++){
            for(int j=1;j<=s-1;j++){
                
                
                if(i==25 && j==75){
                    //cout << (int)((float)i*rate1)+(int)((float)j*rate1)  << endl;
                    //cout << (float)((float)i*rate2)+((float)j*rate2) << endl;
                    //cout << ((float)i*rate2) << "," << ((float)j*rate2) << endl;
                }
                if(((int)((double)i*rate1)+(int)((double)j*rate1))==s){
                    //cout << i << "," << j << endl;
                    //cout << (int)((float)i*rate1)+(int)((float)j*rate1)  << endl;
                    //cout << (int)((float)i*rate2)+(int)((float)j*rate2) << endl;
                    //if(i==25 && j==75)cout << (double)((double)i*rate2) << "," << (int)((double)i*rate2) <<endl;
                    if(max < (((double)i*rate2)+((double)j*rate2))){
                        //cout << ((float)i*rate2) << "," << ((float)j*rate2) << endl;
                        max = ((double)i*rate2)+((double)j*rate2);
                    }
                }
            }
        }

        //cout << (int)max << endl;
        answer.push_back((double)max);

    }

    for(int i=0;i<answer.size();i++){
       cout << answer[i] << endl;
    }
    return 0;

}