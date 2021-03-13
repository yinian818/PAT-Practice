# include <string>
# include <algorithm>
# include <vector>
# include <iostream>
# include <cstdio>

using namespace std;

void buildHeap(vector<int> &heap, int n){
    if((n-1)/2 >= 0 && heap[n] > heap[(n-1)/2]){
        swap(heap[n], heap[(n-1)/2]);
        buildHeap(heap, (n-1)/2);
    }
}

bool isSib(vector<int> &heap, int p, int q, int pos){
    if(pos<0) return false;
    if(pos>=heap.size()) return false;
    if(heap[pos]==p){
        if(pos%2==0 && heap[pos-1]==q) return true;
        else if(pos%2==1 && heap[pos+1]==q) return true;
    }
    return isSib(heap, p, q, pos*2+1) || isSib(heap, p, q, 2*pos+2);
}

bool isLeft(vector<int> &heap, int p, int q, int pos){
    if(pos<0) return false;
    if(pos>=heap.size()) return false;
    if(heap[pos]==p){
        if(heap[pos*2+1]==q) return true;
    }
    return isSib(heap, p, q, pos*2+1) || isSib(heap, p, q, 2*pos+2);
}

bool isRight(vector<int> &heap, int p, int q, int pos){
    if(pos<0) return false;
    if(pos>=heap.size()) return false;
    if(heap[pos]==p){
        if(heap[pos*2+2]==q) return true;
    }
    return isSib(heap, p, q, pos*2+1) || isSib(heap, p, q, 2*pos+2);
}

bool isParent(vector<int> &heap, int p, int q, int pos){
    if(pos<0) return false;
    if(pos>=heap.size()) return false;
    if(heap[pos]==p){
        if(heap[pos*2+1]==q || heap[pos*2+2]==q) return true;
    }
    return isSib(heap, p, q, pos*2+1) || isSib(heap, p, q, 2*pos+2);
}


int main(){
    int n, m, inp;
    cin >> n >> m;
    vector<int> maxHeap;
    for(int i=0; i<n; i++){
        cin >> inp;
        maxHeap.push_back(inp);
        buildHeap(maxHeap, i);
    }
    // m = 1;
    // cout << m;
    string sense;
    for(int j=0; j<m; j++){
        getline(cin, sense);
        cout << sense <<endl;
        int len=sense.size();
        // cout << len;
        if(sense.substr(len-4)=="root"){
            int n=sense.find(' ', 0);
            if(maxHeap[0]==stoi(sense.substr(0, n))) cout << 1;
            else cout << 0;
        }
        else if(sense.find("and", 0)<100){
            int x=sense.find("and", 0);
            int y=sense.find("are", x+4);
            int p=stoi(sense.substr(0, x-1));
            int q=stoi(sense.substr(x+4, y-1));
            if(isSib(maxHeap, p, q, 1)) cout << 1;
            else cout << 0;
        }
        else if(sense.find("parent", 0)<100){
            int x=sense.find("is", 0);
            int y=sense.find("of", x+1);
            int p=stoi(sense.substr(0, x-2));
            int q=stoi(sense.substr(y+2));
            if(isParent(maxHeap, p, q, 1)) cout << 1;
            else cout << 0;
        }
        else if(sense.find("left", 0)<100){
            int x=sense.find("is", 0);
            int y=sense.find("of", x+1);
            int q=stoi(sense.substr(0, x-2));
            int p=stoi(sense.substr(y+2));
            if(isLeft(maxHeap, p, q, 1)) cout << 1;
            else cout << 0;
        }
        else{
            int x=sense.find("is", 0);
            int y=sense.find("of", x+1);
            int q=stoi(sense.substr(0, x-2));
            int p=stoi(sense.substr(y+2));
            if(isRight(maxHeap, p, q, 1)) cout << 1;
            else cout << 0;
        }
    }
    return 0;
}