#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strReverse(string n);
string deleteStr0(string r);
string strSum(string n);

string strSum(string n)
{
    string r = strReverse(n);
    int s, m;
    m = 0;
    string ret;
    for (int i = n.size() - 1; i >= 0; i--)
    {
        s = n[i] - '0' + r[i] - '0' + m;
        ret.insert(0, 1, (s%10)+'0');
        m = s / 10;
    }
    if (m != 0)
        ret.insert(0, 1, m + '0');
    return ret;
}

string deleteStr0(string r)
{
    int i;
    for (i = 0; i < r.size(); i++)
    {
        if (r[i] != '0')
            break;
    }
    return r.substr(i, r.size());
}

string strReverse(string n)
{
    string ret(n.size(), 'a');
    for (int i = 0; i < n.size(); i++)
    {
        ret[n.size() - i - 1] = n[i];
    }
    return ret;
}

int main()
{
    string num;
    cin >> num;
    if (num.size() == 1)
    {
        cout << num << " is a palindromic number.";
        return 0;
    }
    string rev = strReverse(num);
    string n_sum = strSum(num);
    int i = 0;
    while (num != rev && i < 10)
    {
        cout << num << " + " << deleteStr0(rev) << " = " << n_sum << endl;
        num = n_sum;
        rev = strReverse(num);
        n_sum = strSum(num);
        i++;
        // cout << i << '\n';
    }
    if (num == rev)
        cout << num << " is a palindromic number.";
    else
        cout << "Not found in 10 iterations.";

    return 0;
}