#include <bits/stdc++.h>

using namespace std;

// Direct XOR of all numbers from 1 to n
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int main()
{
    int num;
    cout << "Please Enter the Number : ";
    cin >> num;
    int result = computeXOR(num);
    cout << "Result is : " << result << endl;

    return 0;
}