# include <iostream>
# include <vector>
# include <cmath>
# include <iostream>

using namespace std;

int main(){
    int n, maxmum;
    cin >> n >> maxmum;
    bool isPrime[maxmum+1]={false};
    vector<int> primes;
    // vector<vector<int>> dif(maxmum+1, vector<int>(maxmum+1, 0))
    int m_diff=0, m_end=0;
    primes.push_back(2);
    isPrime[2]=true;
    for(int i=3; i<=maxmum; i+=2){
        int t=1;
        for(int j=2; j<=sqrt(i); j++){
            if(i%j==0){
                t=0;
                break;
            }
        }
        if(t==1){
            isPrime[i]=true;
            primes.push_back(i);
            for(int it=primes.size()-2; it>0; it--){
                // dif[i][it] = i-it;
                int d=i-primes[it-1], tap=1;
                if(d<m_diff || i-(n-1)*d<2) continue;
                for(int p=2; p<n; p++){
                    if(!isPrime[i-p*d]){
                        tap=0; break;
                    }
                }
                if(tap==1){
                    m_diff = d;
                    m_end = i;
                }
            }
        }
    }
    if(m_diff==0) cout << primes.back();
    else {
        for(int i=0; i<n-1; i++) cout << m_end-i*m_diff << ' ';
        cout << m_end-(n-1)*m_diff;}
    return 0;
}