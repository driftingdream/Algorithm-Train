#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <iomanip>


using namespace std;
int main()
{
    int a, b,x, y;
    cin >> x >> a >> y >> b;
    cout << fixed << setprecision(2) << (double)(b*y - a*x)/(b-a);
    return 0;
}