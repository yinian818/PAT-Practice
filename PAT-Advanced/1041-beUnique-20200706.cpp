#include <unordered_map>  // this is hash, or use <map>
#include <string>
#include <iostream>

using namespace std;

int main(){
    unordered_map<int, int> bet_map;
    int N;
    cin >> N;
    int bets[N];
    int input;
    for (int i = 0; i < N; i++){
        cin >> input;
        bet_map[input] += 1;
        bets[i] = input;
    }
    int j;
    for (j = 0; j < N; j++){
        if (bet_map[bets[j]] == 1){
            cout << bets[j];
            break;
        }
    }
    if (j == N){
        cout << "None";
    }
    return 0;
}