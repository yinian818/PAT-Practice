#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string strSum(string str){
    int ret = 0;
    for (int i=0;i<str.size();i++){
        ret += (str[i]-'0');
    }
    return to_string(ret);
}

int main(){
    string s;
    cin>>s;
    string s_sum = strSum(s);
    string numbers[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int i;
    for (i=0; i < s_sum.size()-1; i++){
        cout << numbers[s_sum[i]-'0'] << ' ';
    }
    cout << numbers[s_sum[i]-'0'];
    return 0;
}
