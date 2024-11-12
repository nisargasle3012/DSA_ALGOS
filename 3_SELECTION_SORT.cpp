#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>&input)
{
    int n = input.size();

    for(int i = 0 ; i<n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j<n; j++)
        {
            if(input[minIndex] > input[j])
            {
                minIndex = j;
            }
        }
        swap(input[i], input[minIndex]);
    }
}
 
int main()
{
    vector<int>input = {6, 4, 8, 1, 3, 9, 10};
    selection_sort(input);
    for(int i = 0; i<input.size(); i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}