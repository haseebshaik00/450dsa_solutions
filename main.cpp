#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str){
    int l = str.length();
    for(int i=0;i<l/2;i++)
        swap(str[i],str[l-i-1]);
    return str;
}

int main()
{
    cout<<"**********Menu**********"<<endl<<endl;
    cout<<"Arrays"<<endl;
    cout<<"1. Reverse the array or string"<<endl;
    cout<<"2. Find the maximum and minimum element in an array"<<endl;
    int n;
    cout<<endl<<"Enter your choice : ";
    cin>>n;
    switch(n)
    {
        case 1  :   {
                        string s;
                        cin>>s;
                        cout<<reverseWord(s)<<endl;
                        break;
                    }
        case 2  :   {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int min_ans=INT_MAX,max_ans=INT_MIN;
                        for(int i=0;i<n;i++)
                        {
                            if(a[i]<min_ans)
                                min_ans = a[i];
                            if(a[i]>max_ans)
                                max_ans = a[i];
                        }
                        cout<<min_ans<<" "<<max_ans<<endl;
                        break;
                    }
        default  :      cout<<"Try Again!"<<endl;
                        break;
    }
    return 0;
}
