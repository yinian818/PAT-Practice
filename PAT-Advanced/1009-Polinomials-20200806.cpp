#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

float poly[1005];
float ret[2005];
int num;
int c_count=0;

int main(){
    int exp;
    float coef;
    cin >> num;
    memset(poly, 0, sizeof(poly));
    memset(ret, 0, sizeof(ret));
    for(int i=0; i<num; i++){
        cin >> exp >> coef;
        poly[exp] = coef;
    }
    cin >> num;
    for(int i=0; i<num; i++){
        cin >> exp >> coef;
        for(int j=0; j<1005; j++){
            if(poly[j] != 0){
                ret[exp+j] += poly[j]*coef;
            }
        }
    }
    for(int i=0; i<2005; i++){
        if(ret[i] != 0){
            c_count+=1;
            }
    }
    cout << c_count;
    for(int i=2005; i>=0; i--){
        if(ret[i] != 0){
            printf(" %d %.1f", i, ret[i]);
        }
    }
    return 0;
}
