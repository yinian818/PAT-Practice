#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPrime(int n){
    bool ret = true;
    if(n % 2 == 0) ret = false;
    else {
        for(int i = 3; i < pow(n, 0.5)+1; i+=2){
            if(n % i == 0) ret= false;
            break;
        }
    }
    return ret;
}

int main(){
    int MSize, N, M;
    int sum=0;
    cin >> MSize >> N >> M;
    while ( !isPrime(MSize) ) MSize++;
    int table[MSize];
    for(int i = 0; i<MSize; i++) table[i]=-1;
    int n, m;
    for(int i=0; i < N; i++){
        cin >> n;
        for(int j=0;j<MSize+1; j++){
            if(table[(n+j*j)%MSize]==-1){
                table[(n+j*j)%MSize]=n;
                break;
            }
            if ( j == MSize ) cout << n << " cannot be inserted." << endl;
        }
        // int j = 0;
        // while(table[(n+j*j)%MSize]!=-1 && table[(n+j*j)%MSize]!=n){
        //     j += 1;
        //     if(j==MSize){
        //         cout << n << " cannot be inserted." << endl;
        //         break;
        //     }
        // }
        // if(j<MSize) table[(n+j*j)%MSize]=n;
    }
    for(int i=0; i < M; i++){
        cin >> m;
        for(int j=0; j<MSize+1; j++){
            sum++;
            if(table[(m+j*j)%MSize]==-1 || table[(m+j*j)%MSize]==m) break;
        }
        // int j = 0;
        // while(table[(m+j*j)%MSize]!=-1 && table[(m+j*j)%MSize]!=m){
        //     j += 1;
        //     if(j==MSize+1){
        //         // cout << n << " cannot be inserted." << endl;
        //         j--;
        //         break;
        //     }
        // }
        // sum += (j+1);
    }
    printf("%.1f\n", (float)sum/M);
    return 0;
}

/*
4 5 4
10 6 4 15 11
11 4 15 2
*/