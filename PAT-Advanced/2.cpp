# include <iostream>
# include <string>
# include <vector>

using namespace std;

long Tonum(string time){
    long ret;
    ret += stoi(time.substr(0, 2))*3600;
    ret += stoi(time.substr(3, 2))*60;
    ret += stoi(time.substr(6, 2));
    return ret;
}

int main(){
    int n;
    cin >> n;
    string inTime, outTime;
    vector<vector<long>> table;
    vector<long> req(2, 0);
    int total=0;
    for(int i=0; i<n; i++){
        cin >> inTime >> outTime; 
        req[0]=Tonum(inTime); req[1]=Tonum(outTime);
        if(table.size()==0){
            table.push_back(req);
            total += 1;
        }
        else{
            int tag=1;
            for(auto it : table){
                if(req[0]>it[1] || req[1]<it[0]) continue;
                else{
                    tag=0;
                    break;
                }
            }
            total += tag;
        }
    }
    // cout << "===";
    cout << total;
    return 0;
}