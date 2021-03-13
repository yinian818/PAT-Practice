# include <string>
# include <iostream>

using namespace std;

int main(){
    string m;
    for(int i=0;i<3;i++){
        getline(cin, m);
        cout << m << endl;
        cout << m.size() << endl;
        }
    cout << m.find("a", 1);
    return 0;
}