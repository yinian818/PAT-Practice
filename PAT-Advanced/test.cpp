#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string str = "hello world";
    string str_rev = str;
    reverse(str.begin(), str.end());

    cout << str << " " << str_rev << endl;
}
