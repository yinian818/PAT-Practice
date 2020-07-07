#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


typedef struct
{
    string user;
    string pw;
} Account;

string pdModify(string psd){
    replace(psd.begin(), psd.end(), '1', '@');
    replace(psd.begin(), psd.end(), '0', '%');
    replace(psd.begin(), psd.end(), 'l', 'L');
    replace(psd.begin(), psd.end(), 'O', 'o');
    return psd;
}

void outPrint(int M, int N, Account accounts[]){
    if (M == 0 && N == 1){
        cout<<"There is "<< N <<" account and no account is modified";
    }
    else if (M == 0 && N != 1){
        cout<<"There are "<< N <<" accounts and no account is modified";
    }
    else{
        cout << M << endl;
        for(int i = 0; i < M-1; i++){
            cout << accounts[i].user << ' ' << accounts[i].pw << endl;
        }
        cout << accounts[M-1].user << ' ' << accounts[M-1].pw;

    }
    return ;
}

int main(){
    int N;
    int M = 0;
    cin>>N;
    Account acts[N];
    string _u;
    string _p;
    for(int i = 0; i < N; i++){
        cin >> _u >> _p;
        string pModified = pdModify(_p);
        if (pModified != _p){
            acts[M].user = _u;
            acts[M].pw = pModified;
            M += 1;
        }
    }
    outPrint(M, N, acts);
    return 0;
}