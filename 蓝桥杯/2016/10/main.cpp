#include <bits/stdc++.h>

using namespace std;
class Div
{
    public:
    int x; // 分子
    int y; // 分母
    void square()
    {
        this->x = this->x * this->x;
        this->y = this->y * this->y;
    }

};
bool isPrime(long n)
{
    if(n == 2)
        return true;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
        
    }
    return true;
}

vector <long> findPrimeDiv(int n)
{
    vector <long> arr;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if (isPrime(i) && n % i == 0)
        {
            // cout << i << ' ';
            arr.push_back(i);
        }
    }
    
    return arr;
}
bool check(vector <long> v, float div)
{
    if(v.size()==0 || v.size() == 1)
    {
        cout << "size is 0 || 1\n";
        return false;
    }
    for(int i = 0; i < v.size(); i++)
    {
        int j = 0;
        while(1)
        {
            if(v[i] == pow(div, j) * v[0])
            {
                break;
            }
            else if(v[i] > pow(div, j) * v[0])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // cout << isPrime(5);
    // vector<int> arr = findPrimeDiv(2147483647);
    // for(int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << '\n';
    // }
    // cout << sizeof(long);
    int n;
    cin >> n;
    vector <long> primeDiv;
    vector <long> data;
    Div divClass;
    divClass.x = 1;
    divClass.y = 1;
    for(int i = 0; i < n; i++)
    {
        long temp;
        cin >> temp;
        data.push_back(temp);
        vector <long> tempArr = findPrimeDiv(temp);
        for(int j = 0; j < tempArr.size(); j++)
        {
            primeDiv.push_back(tempArr[j]);
        }
    }
    // 去重
    sort(primeDiv.begin(), primeDiv.end());
    sort(data.begin(), data.end());
    primeDiv.erase(unique(primeDiv.begin(), primeDiv.end()), primeDiv.end());
    data.erase(unique(data.begin(), data.end()), data.end());
    sort(data.begin(), data.end());

    if(primeDiv.size() == 1)
    {
        divClass.x = primeDiv[0];
        divClass.y = 1;
    }
    else
    {
        divClass.x = primeDiv[1];
        divClass.y = primeDiv[0];
    }
    

    #ifdef LOCAL
    cout << "Prime div: \n";
    for (auto &i : primeDiv)
    {
        cout << i << ' ';
    }
    cout << '\n';
    cout << "Data: \n";
    for (auto &i : data)
    {
        cout << i << ' ';
    }
    cout << '\n';

    if (primeDiv.size() != 2 && primeDiv.size() != 1)
    {
        cout << "Error\n";
    }
    #endif

    // cout << primeDiv.size();
    float minDiv = data[1]/data[0];
    float divFactor;
    if(primeDiv.size() == 2)
    {
        divFactor = (float)primeDiv[1] / primeDiv[0];

    }
    else if(primeDiv.size() == 1)
    {
        divFactor = primeDiv[0];
    }
    else
    {
        cout << "error\n";
    }
    
    float div = divFactor;
    while(1)
    {
        if(check(data, div*div))
        {
            div = div*div;
            divClass.square();
        }
        else
        {
            break;
        }
        
        // else if(check(data, sqrt(div))
        // {
        //     div = sqrt(div);
        // }
    }
    cout << divClass.x << '/' << divClass.y;

    return 0;
}