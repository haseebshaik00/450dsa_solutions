#include<bits/stdc++.h>
using namespace std;

string reverseWord(string str){
    int l = str.length();
    for(int i=0;i<l/2;i++)
        swap(str[i],str[l-i-1]);
    return str;
}

void swapit(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int randomPartition(int arr[], int l, int r)
{
        int n = r-l+1;
        int pivot = rand() % n;
        swapit(&arr[l + pivot], &arr[r]);
        return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l, r);
        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    return INT_MAX;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swapit(&arr[i], &arr[j]);
            i++;
        }
    }
    swapit(&arr[i], &arr[r]);
    return i;
}

int main()
{
    cout<<"**********Menu**********"<<endl<<endl;
    cout<<"Arrays"<<endl;
    cout<<"1. Reverse the array or string"<<endl;
    cout<<"2. Find the maximum and minimum element in an array"<<endl;
    cout<<"3. Find the kth max and min element in an array - Quick Start Algorithm"<<endl;
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
        case 3 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int k;
                        cin>>k;
                        cout<<(a,0,n-1,k)<<endl;
                        break;
                    }
        default  :      cout<<"Try Again!"<<endl;
                        break;
    }
    return 0;
}
