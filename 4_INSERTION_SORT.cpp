#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>&input)
{
    int n = input.size();

    for(int i = 1; i<n; i++)
    {
        int temp = input[i];
        int j =  i - 1;

        while(j>=0)
        {
            if(input[j]>temp)
            {
                input[j+1] = input[j];
            }
            else{
                break;
            }
            j--;
        }
        input[j+1] = temp;
    }
}
 
int main()
{
    vector<int>input = {6, 4, 8, 1, 3, 9, 10};
    insertion_sort(input);
    for(int i = 0; i<input.size(); i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
    return 0;
}