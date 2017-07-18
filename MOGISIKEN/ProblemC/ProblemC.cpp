#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_N

struct data_t{
    int max;
    int min;
};

struct data_a{
    int max;
    int min;
};

bool asc( const data_t& left, const data_t& right ) {
    return left.max == right.max ? left.min < right.min : left.max < right.max;
};

bool asc_a( const data_t& left, const data_t& right ) {
    return left.min == right.min ? left.max > right.max : left.min > right.min;
};

int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector<data_t> data_array(n);

    for(int i=0;i<n;i++){
        cin >> data_array[i].min >> data_array[i].max;
        cin.ignore();
    }

    sort(data_array.begin(),data_array.end(),asc);

/*
    cout << "-----------------" << endl;
    for(int i=0;i<n;i++){
        cout << data_array[i].min << "," << data_array[i].max << endl;
   }
*/
    int ans = n+1;
    for(int i=0;i<ans-1;i++){
        if(data_array[i].max < ans){
            ans--;
            for(int j=i;j<ans-1;j++){
                data_array[j]=data_array[j+1];
            }
            i--;
        }else{
            break;
        }
    }

    cout << ans-1 << endl;
    /*
    cout << "-----------------" << endl;
    for(int i=0;i<ans-1;i++){
        cout << data_array[i].min << "," << data_array[i].max << endl;
    }*/

    sort(data_array.begin(),data_array.begin()+ans-1,asc_a);

    cout << "KOJUN-----------------" << endl;
    for(int i=ans-1-245;i<ans-1-235;i++){
        cout << data_array[i].min << "," << data_array[i].max << endl;
    }

    for(int i=0;i<ans-1;i++){
        if(data_array[i].min > ans){
             ans--;
            for(int j=i;j<ans-1;j++){
                data_array[j]=data_array[j+1];
            }
           
            i--;
        }else{
            break;

        }
    }
/*
    cout << "-----------------" << endl;
    for(int i=0;i<ans-1;i++){
        cout << data_array[i].min << "," << data_array[i].max << endl;
    }
*/
    cout << ans-1 << endl;

    return 0;

}