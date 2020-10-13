#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    string s = to_string(n);
    return (s.find("2") != string::npos) || (s.find("0") != string::npos) || (s.find("1") != string::npos) || (s.find("9") != string::npos);
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    // cout << check(n);
    for(int i = 1; i <= n; i++)
    {
        if(check(i))
        {
            sum += i;
        }
    }
    cout << sum;
    return 0;
}