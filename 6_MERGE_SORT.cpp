#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int merge(vector<int>&input, int s, int e)
{
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int>first(len1);
    vector<int>second(len2);

    int k = s;
    for(int i = 0 ;i<len1; i++)
    {
        first[i] = input[k++];
    }
    k = mid + 1;
    for(int i = 0; i<len2; i++)
    {
        second[i] = input[k++];
    }

    int i1 = 0;
    int i2 = 0;
    int mainIndex = s;

    while(i1<len1 && i2<len2)
    {
        if(first[i1]<second[i2])
        {
            input[mainIndex++] = first[i1++];
        }
        else{
            input[mainIndex++] = second[i2++];
        }
    }
    while(i1<len1)
    {
        input[mainIndex++] = first[i1++];
    }
    while(i2<len2)
    {
        input[mainIndex++] = second[i2++];
    }
}

void merge_sort(vector<int>&input, int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid = (s+e)/2;

    merge_sort(input, s, mid);
    merge_sort(input, mid + 1, e);

    merge(input, s, e);
}
 
int main()
{
    vector<int>input = {6, 4, 8, 1, 3, 9, 10};
    int s = 0;
    int e = input.size() - 1;
    merge_sort(input, s, e);
    for(int i = 0; i<input.size(); i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}