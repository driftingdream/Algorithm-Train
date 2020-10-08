#include <iostream>
#include <string>


using namespace std;
int main()
{
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != 'z' && s[i] != 'Z' && isalpha(s[i]))
        {
            s[i]++;
        }
        else if(isalpha(s[i]))
        {
            s[i] -= 25;
        }
    }
    cout << s;
}