#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int num;
    cin >> num;
    // cout << num;
    int *indexToLine = new int[num*(num+1)/2+1];
    int *arr= new int [num*(num+1)/2+1];
    int *value = new int[num * (num + 1) / 2 + 1];

    for (int i = 1; i <= num * (num + 1) / 2; i++)
    {
        value[i]=0;
        // cout << i << '\n';
        cin >> arr[i];
    }
    int line = 1, add = 0;
    for (int i = 1; i <= num * (num + 1) / 2; i++)
    {
        indexToLine[i] = line;
        add++;
        if(add == line)
        {
            add = 0;
            line++;
        }
        // cout << indexToLine[i];
    }
    // for (int i = 1; i <= num * (num + 1) / 2; i++)
    // {
    //     cout << arr[i] << '\n';
    // }
    
    int sum = num * (num + 1) / 2;
    for (int i = num; i >= 1; i--)
    {
        for(int j = (1+i-1)*(i-1)/2+1; j<= (1+i)*i/2; j++)
        {
            if(i!=num)
            {
                value[j] = value[j+i] >= value[j+i+1]?value[j+i]+arr[j]:value[j+i+1]+arr[j];
            }
            else
            {
                value[j] = arr[j];
            }
            
        }
    }
    cout << value[1];
    return 0;
}