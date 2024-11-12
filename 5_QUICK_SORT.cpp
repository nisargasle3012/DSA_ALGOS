#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>&input, int s, int e)
{
    int p = input[s];
    int count = 0;

    for(int i = s+1; i<=e; i++)
    {
        if(input[i]<=p)
        {
            count++;
        }
    }
    int pi = s + count;
    swap(input[pi], input[s]);

    int i = s;
    int j = e;

    while(i<pi && j>pi)
    {
        while(input[i]<p)
        {
            i++;
        }
        while(input[j]>p)
        {
            j--;
        }
        if(i<pi && j>pi)
        {
            swap(input[i++], input[j--]);
        }
    }
    return pi;
}

void quick_sort(vector<int>&input, int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int p = partition(input, s, e);

    quick_sort(input, s, p - 1);
    quick_sort(input, p + 1, e);
}
 
int main()
{
    vector<int>input = {6, 4, 8, 1, 3, 9, 10};
    int s = 0;
    int e = input.size() - 1;
    quick_sort(input, s, e);
    for(int i = 0; i<input.size(); i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}