#include<bits/stdc++.h>
using namespace std;
string reverseString(string str)
{
    vector<string> arr;
    int start = 0,count = 0;
    for( int i=0; i<str.length(); i++ )
    {
        start = i;
        if( str[i] != ' ')
        {
            count = 0;
            while( str[i] != ' ')
            {
                count++;
                i++;
            }
            arr.push_back(str.substr(start,count));
        }
    }
    
    string s;
    
    for( int i=arr.size()-1; i>=0; i-- )
    {
        s.append(arr[i]);
        s.append(" ");   
    }
    return s;
}