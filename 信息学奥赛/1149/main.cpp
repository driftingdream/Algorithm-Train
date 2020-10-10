#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    // freopen("input.txt", "r", stdin);
    using namespace std;
    string s;
    getline(cin ,s);
    s = s.substr(0, s.find('.'));
    // cout << s;
    int i, j, z=0;
    j=0;
    int max = 0;
    for(i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
        {
            j++;
            if (i == s.size() - 1)
            {
                if (j > max)
                {
                    max = j;
                    z = i - j + 1;
                }
            }
        }
        else
        {
            if(j>max)
            {
                max = j;
                z = i - j;
                // cout << z << '\n';
                // cout << "i " << i << '\n';
            }
            j = 0;
        }
        
    }
    s = s.substr(z, max);
    // cout << z << '\n';
    // cout << z+max;
    cout << s;
    return 0;
}