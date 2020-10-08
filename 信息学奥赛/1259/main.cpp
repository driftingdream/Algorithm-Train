#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// 其实可以用 string 头文件下的 to_string 函数将 int 数据转为 string 类型的数据，
// 但是 OJ 平台不支持该函数，提示编译报错
string toString(int n)
{
    ostringstream stream;
    stream << n;
    return stream.str();
}
int main()
{
    freopen("input.txt", "r", stdin);
    int num;
    cin >> num;
    int * wpl = new int [num+1];
    int * arr = new int[num+1];
    string * route = new string[num+1];
    for (int i = 1; i < num+1; i++)
    {
        wpl[i] = 1;
        cin >> arr[i];
        route[i] = toString(arr[i]);
        // cout << route[i] << '\n';
    }
    
    for(int i = num; i >= 1; i--)
    {
        int max = -1;
        int z = -1;
        if(i!=num)
        {
            for (int j = i+1; j <= num; j++)
            {
                if(arr[i] <= arr[j] && wpl[j] >= max)
                {
                    max = wpl[j];
                    z = j;
                }
            }
        }
        if(max!=-1)
        {
            route[i] = "";
            route[i] = toString(arr[i]) + ' ' + route[z];
            wpl[i] += max;
        }
    }
    int max = -1;
    int j = -1;
    for(int i = 1; i <= num; i++)
    {
        // cout << toString(wpl[i]) << '\n';
        // cout << route[i] << '\n';
        wpl[i]>max? max = wpl[i], j = i: max; 
    }
    cout << "max="+ toString(max) << '\n';
    cout << route[j];
    return 0;
}