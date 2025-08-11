#include <bits/stdc++.h>

using namespace std;

int XorOperationInArray(int n, int start)
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = x ^ start + (2 * i);
    }
    return x;
}

int main()
{
    int num, start;
    cout << "Please Enter Number : " << endl;
    cin >> num;
    cout << "Please Enter Starting Number : " << endl;
    cin >> start;

    int result = XorOperationInArray(num, start);

    cout << "Result is : " << result << endl;
}