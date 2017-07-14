/*
数字numが小さい順にソート
もし数字numが同じなら、文字列strが若い順にソート
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct data_t{
    int num;
    string str;
};

// numを昇順にソート→strを昇順にソート
bool asc1( const data_t& left, const data_t& right ) {
    return left.num == right.num ? left.str < right.str : left.num < right.num;
}
// numを昇順にソート→strを降順ににソート
bool asc2( const data_t& left, const data_t& right ) {
    return left.num == right.num ? left.str > right.str : left.num < right.num;
}
// numを降順ににソート→strを昇順にソート
bool asc3( const data_t& left, const data_t& right ) {
    return left.num == right.num ? left.str < right.str : left.num > right.num;
}
// numを降順にソート→strを降順にソート
bool asc4( const data_t& left, const data_t& right ) {
    return left.num == right.num ? left.str > right.str : left.num > right.num;
}

int main(){

    vector<data_t> data_array(3);

    data_array[0].num = 15;
    data_array[0].str = "zzz";
    data_array[1].num = 30;
    data_array[1].str = "aaa";
    data_array[2].num = 15;
    data_array[2].str = "ccc";

    sort(data_array.begin(), data_array.end(),asc1);

    for(int i=0;i<data_array.size();i++){
        cout << data_array[i].num << "," << data_array[i].str << endl;
    }

    cout << "------------------" << endl;

    data_array[0].num = 15;
    data_array[0].str = "zzz";
    data_array[1].num = 30;
    data_array[1].str = "aaa";
    data_array[2].num = 15;
    data_array[2].str = "ccc";

    sort(data_array.begin(), data_array.end(),asc2);

    for(int i=0;i<data_array.size();i++){
        cout << data_array[i].num << "," << data_array[i].str << endl;
    }

    cout << "------------------" << endl;

    data_array[0].num = 15;
    data_array[0].str = "zzz";
    data_array[1].num = 30;
    data_array[1].str = "aaa";
    data_array[2].num = 15;
    data_array[2].str = "ccc";

    sort(data_array.begin(), data_array.end(),asc3);

    for(int i=0;i<data_array.size();i++){
        cout << data_array[i].num << "," << data_array[i].str << endl;
    }

    cout << "------------------" << endl;

    data_array[0].num = 15;
    data_array[0].str = "zzz";
    data_array[1].num = 30;
    data_array[1].str = "aaa";
    data_array[2].num = 15;
    data_array[2].str = "ccc";

    sort(data_array.begin(), data_array.end(),asc4);

    for(int i=0;i<data_array.size();i++){
        cout << data_array[i].num << "," << data_array[i].str << endl;
    }
    return 0;
}