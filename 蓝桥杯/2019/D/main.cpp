#include <bits/stdc++.h>
using namespace std;
vector<int> v;
// bool judge(int n)
// {
//     int t;
//     while (n)
//     {
//         if (((t = n % 10) == 2) || t == 4)
//         {
//             return true;
//         }
//         n /= 10;
//     }
//     return false;
// }

// bool check(int a, int b, int c)
// {
//     // 有数字出现 2 和 4，或者出现重复数字，返回 0
//     if (judge(a) || judge(b) || judge(c) ||
//         a == b || a == c || b == c)
//     {
//         return false;
//     }
//     return true;
// }

// bool check(int n )
// {
//     while(n)
//     {
//         if(n%10 == 2 || n%10==4)
//         {
//             return true;
//         }
//         n /= 10;
//     }
//     return false;
// }
bool check(int n)
{
    return (to_string(n).find("2") != string::npos) || (to_string(n).find("4") != string::npos);
}
int main()
{
    const int N = 2018;
    int sum = 0;
    // int s = 0;

    // 这里 a=1，排错了半天，题目要求为各项数字为正整数，一开始填入a=0导致了错误
    for (int a = 1; a < N; a++)
    {
        for (int b = a + 1; b < N; b++)
        {
            for (int c = b + 1; c < N; c++)
            {
                if (a + b + c == 2019)
                {
                    // if(sum++ == 40)
                    // {
                    //     return 0;
                    // }
                    // cout << string::npos << '\n';
                    // cout << to_string(a).find("2")<< '\n';
                    // bool a2, a4, b2, b4, c2, c4;
                    // a2 = to_string(a).find("2") != string::npos;
                    // a4 = to_string(a).find("4") != string::npos;
                    // b2 = to_string(b).find("2") != string::npos;
                    // b4 = to_string(b).find("4") != string::npos;
                    // c2 = to_string(c).find("2") != string::npos;
                    // c4 = to_string(c).find("4") != string::npos;
                    // if(a2||a4||b2||b4||c2||c4||a==b||a==c||b==c)
                    // {
                    //     continue;
                    // }

                    bool ab, bb, cb;
                    ab = check(a);
                    bb = check(b);
                    cb = check(c);
                    if (ab || bb || cb || a == b || a == c || b == c)
                    {
                        continue;
                    }
                    // if(a==0)
                    // {
                    //     cout << a << ' ' << b << ' ' << c << ' ' << '\n';
                    //     s++;
                    // }

                    // if(!check(a,b,c))
                    // {
                    //     continue;
                    // }
                    // cout << a << ' ' << b << ' ' << c << ' ' << '\n';
                    // sum += check(a,b,c);
                    sum++;
                }
            }
        }
    }
    cout << sum << endl;
    // cout << s;
    return 0;
}