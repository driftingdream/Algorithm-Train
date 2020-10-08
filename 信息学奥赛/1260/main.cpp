#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int n[1000];
    int index = 0;
    while(cin >> n[index++])
    {
        cout << n[index - 1] << '\n';
    }
    index--;
    int sum = index;
    // cout << index;
    
    return 0;
}