#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int n , m ;
    cin >> n >> m ;

    int arr[n][m] ;

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cin >> arr[i][j] ;
        }
    }

    int suffix[n][m] ;

    for(int i=n-1 ; i>=0 ; i--)
    {
        int sum = 0 ;
        for(int j=m-1 ; j>=0 ; j--)
        {
            sum += arr[i][j];
            suffix[i][j] = sum ;
        }
    }

    for(int j=m-1 ; j>=0 ; j--)
    {
        int sum = 0;
        for(int i=n-1 ; i>=0 ; i--)
        {
            sum += suffix[i][j];
            suffix[i][j] = sum ;
        }
    }

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            cout << suffix[i][j] << " " ;
        }

        cout << endl ;
    }

    int max = INT_MIN ; 

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if (suffix[i][j] > max)
            {
                max = suffix[i][j] ;
            }
        }
    }

    cout << "The sum of maximum submatrix is : " << max << endl ;

    
    return 0;
}