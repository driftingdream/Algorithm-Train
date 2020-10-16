/*
各种示例数据都试了，都是与相应的答案相符的，但是提交的时候显示答案错误…放弃了
*/
#include <bits/stdc++.h>

using namespace std;
/*
class Rectangle
{
    public:
    int x,y;
    Rectangle()
    {
        this->x=0;
        this->y=0;
    }
    Rectangle(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
};
class Cuboid
{
    public:
    Rectangle a, b, c;
    Cuboid()
    {

    }
};
*/
int store[3][2];
int tempStore[6][2];
bool visited[6];
void displayTemp()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << tempStore[i][j] << ' ';
        }
        cout << '\n';
    }
}


bool storeNCheck()
{
    int storeIndex = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < 5; i++)
    {
        for(int j = i+1; j < 6; j++)
        {
            bool used = visited[i] == false && visited[j] == false;
            if(tempStore[i][0] == tempStore[j][0]
                && tempStore[i][1] == tempStore[j][1]
                && used)
            {
                store[storeIndex][0] = tempStore[i][0];
                store[storeIndex][1] = tempStore[i][1];
                visited[i] = true; visited[j] = true;
                storeIndex++;
                break;
            }
            else if(tempStore[i][1] == tempStore[j][0]
            && tempStore[i][0] == tempStore[j][1]
            && used)
            {
                store[storeIndex][0] = tempStore[i][0];
                store[storeIndex][1] = tempStore[i][1];
                visited[i] = true; visited[j] = true;
                storeIndex++;
                break;
            }
        }
    }
    if(storeIndex != 3)
    {
        return false;
    }
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //     {
    //         cout << store[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int a, b;
    if(store[0][0] == store[1][0])
    {
        a = store[0][1];
        b = store[1][1];
    }
    else if(store[0][0] == store[1][1])
    {
        a = store[0][1];
        b = store[1][0];
    }
    else if(store[0][1] == store[1][0])
    {
        a = store[0][0];
        b = store[1][1];
    }
    else if(store[0][1] == store[1][1])
    {
        a = store[0][0];
        b = store[1][0];
    }
    else
    {
        // cout << "error!\n";
        return false;
    }
    if(a == store[2][0] && b == store[2][1])
    {
        return true;    
    }
    else if(a == store[2][1] && b == store[2][0])
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
    
    
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(store, -1, sizeof(int) * 6);
    int n;
    bool second = false;
    int indexRow = 0;
    while(cin >> n)
    {
        
        if(!second)
        {
            tempStore[indexRow][0] = n;
            second = !second;
        }
        else
        {
            tempStore[indexRow++][1]=n;
            second = !second;
        }
        if (indexRow == 6)
        {
            if (storeNCheck())
            {
                cout << "POSSIBLE\n";
            }
            else
            {
                cout << "IMPOSSIBLE\n";
            }
            indexRow = 0;
        }
    }
    // if (indexRow == 6)
    // {
    //     if (storeNCheck())
    //     {
    //         cout << "POSSIBLE\n";
    //     }
    //     else
    //     {
    //         cout << "IMPOSSIBLE\n";
    //     }
    // }
    // else if(indexRow != 0)
    // {
    //     cout << "IMPOSSIBLE\n";
    // }
    
    // displayTemp();
    return 0;
    }