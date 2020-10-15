#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    cout << endl;

    int arr[n]{};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;

    int csum[n]{};
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        csum[i] = sum;
    }

    int maximum = INT_MIN;

    int sumsubarray{};

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sumsubarray = csum[j] - csum[i - 1];
            if (sumsubarray > maximum)
            {
                maximum = sumsubarray;
            }
        }
    }

    cout << maximum << endl;
}