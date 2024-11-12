#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int>&input)
{
    int n = input.size();
    for(int i = 0 ; i<n - 1; i++)
    {
        for(int j = 0; j<n - i - 1; j++)
        {
            if(input[j] > input[j+1])
            {
                swap(input[j], input[j+1]);
            }
        }
    }
}

int main()
{
    vector<int>input = {6, 4, 8, 1, 3, 9, 10};
    bubble_sort(input);
    for(int i = 0; i<input.size(); i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}