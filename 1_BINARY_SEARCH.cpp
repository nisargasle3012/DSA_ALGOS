#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int binarySearch(vector<int>&input, int target)
{
    int s = 0;
    int e = input.size();

    int m = (s + e)/2;

    while(s<=e)
    {
        if(input[m]==target)
        {
            return 1;
        }
        if(target > input[m])
        {
            s = m + 1;
        }
        else{
            e = m - 1;
        }
        m = (s + e)/2;
    }
    return 0;
}

int main()
{
    vector<int>input = {0, 2, 3, 6, 7};
    int target = 5;
    int ans1 = binary_search(input.begin(), input.end(), target);
    cout<<ans1<<endl;

    int ans2 = binarySearch(input, target);
    cout<<ans2<<endl;
    return 0;
}