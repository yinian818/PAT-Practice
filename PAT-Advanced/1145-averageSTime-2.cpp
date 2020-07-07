#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(int n);
int minBiggerPrime(int n);
void genePrimes(int n);
int hashVal(int maxSize, int key, int array[]);

int main(){
    int MSize, N, M;
    int sum=0;
    cin >> MSize >> N >> M;
    MSize = minBiggerPrime(MSize);
    int table[MSize];
    for(int i = 0; i<MSize; i++) table[i]=-1;
    int n, index;
    for(int i=0; i < N; i++){
        cin >> n;
        index = hashVal(MSize, n, table);
        // cout << index << "------------" << endl;
        if(index != -1){
            table[index] = n;
           }
        else cout << n << " cannot be inserted." << endl;
    }
    int *cprcount=0;
    for(int i=0; i < M; i++){
        cin >> n;
        index = hashVal(MSize, n, table);
        sum += *cprCount;
    }
    cout.precision(2);
    // cout << p_idx << endl;
    cout << (float)sum/M;
    return 0;
}

bool isPrime(int n){
    bool ret = true;
    if(n % 2 == 0) ret = false;
    else {
        for(int i = 3; i < pow(n, 0.5); i+=2){
            if(n % i == 0) ret= false;
            break;
        }
    }
    return ret;
}

int minBiggerPrime(int n){
    // genePrimes(n);
    // for(int i=0; ; i++){
    //     if(primes[i] >= n) return primes[i];
    // }
    if(n % 2 == 0) n += 1;
    for(; ; n+=2){
        if(isPrime(n)) return n;
    }
}

// void genePrimes(int n){
//     int max_p = primes[p_idx];
//     while(primes[p_idx] < n){
//         max_p += 2;
//         bool break_m = false;
//         for(int i = 0; i <= p_idx; i++){
//             if(max_p % primes[i] == 0){
//                 break_m = true;
//                 break;
//             }
//         }
//         if(break_m) continue;
//         // cout << "--------" << max_p << endl;
//         p_idx += 1;
//         primes[p_idx] = max_p;
//     }
//     return ;
// }

int hashVal(int maxSize, int key, int array[]){
    cprCount = 1;
    int ind = key % maxSize;
    // int ret = 1;
    int i = 1;
    // int l_ind;
    int r_ind = ind;
    while(array[r_ind]!=-1 && i < maxSize+1 && array[r_ind] != key){
        // ret = -1;
        r_ind = (ind+i*i)%maxSize;
        cprCount += 1;
        // l_ind = (ind-i*i)%maxSize + maxSize;
        // if(array[r_ind]==0 || array[r_ind] == key){
        //     ind = r_ind;
        //     ret = 1;
        //     break;}

        i += 1;
    }
    if(i < maxSize+1) return r_ind;
    else return -1;

}

/*
4 5 4
10 6 4 15 11
11 4 15 2
*/