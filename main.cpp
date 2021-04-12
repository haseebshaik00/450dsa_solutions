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
        return kthSmallest(arr, pos+1, r, k-pos+l-1);//(k-(pos-l+1))
    }
    return INT_MAX;
}

int partition2(int a[], int s, int e)
{
    int p = a[e];
    int i=s-1;
    for(int j=s;j<=e-1;j++)
    {
        if(a[j]<=p)
            swap(a[++i],a[j]);
    }
    swap(a[i+1],a[e]);
    return i+1;
}

int quickSelect(int a[], int s, int e, int k)
{
    int p = partition2(a,s,e);
    if(p-s == k-1)
        return a[p];
    else if(p-s > k-1)
        return quickSelect(a,s,p-1,k);
    return quickSelect(a,p+1,e,k-(p-s+1));
}

void sort012(int a[], int n)
{
         int l=0,m=0,h=n-1;
         while(m<=h)
         {
            if(a[m]==0)
                swap(a[l++],a[m++]);
            else if(a[m]==1)
                m++;
            else
                swap(a[h--],a[m]);
         }
}

void rearrange(int a[], int n)
{
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]<0)
        {
            if(i!=j)
                swap(a[j],a[i]);
            i++;
        }
    }
    /* same as
    int i=-1;
    for(int j=0;j<n;j++)
    {
        if(a[j]<0)
            swap(a[++i],a[j]);
    }
    */
}

int doUnion1(int a[], int n, int b[], int m)
{
    set<int> s;
    for(int i=0;i<n;i++)
        s.insert(a[i]);
    for(int i=0;i<m;i++)
        s.insert(b[i]);
    for(auto it=s.begin(); it!=s.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    return s.size();
}

int doIntersection1(int a[], int n, int b[], int m)
{
    int c=0;
    map<int,int> m1;
    for(int i=0;i<n;i++)
        m1.insert({a[i],1});
    for(int i=0;i<m;i++)
    {
        if(m1.find(b[i])!= m1.end())
        {
            cout<<b[i]<<" ";
            c++;
        }
    }
    return c;

}

int doUnion2(int a[], int n, int b[], int m)
{
    int c=0,i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            i++;j++;
        }
        else if(a[i]<b[j])
            cout<<a[i++]<<" ";
        else
            cout<<b[j++]<<" ";
        c++;
    }
    while(i<n)
    {
        cout<<a[i++]<<" ";
        c++;
    }
    while(j<m)
    {
        cout<<b[j++]<<" ";
        c++;
    }
    cout<<endl;
    return c;
}


int doIntersection2(int a[], int n, int b[], int m)
{
    int c=0,i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
            cout<<a[i]<<" ";
            c++;
            i++;
            j++;
        }
        else if(a[i]<b[j])
            i++;
        else
            j++;
    }
    return c;
}

int main()
{
    cout<<"**********Menu**********"<<endl<<endl;
    cout<<"Arrays"<<endl;
    cout<<"1. Reverse the array or string"<<endl;
    cout<<"2. Find the maximum and minimum element in an array"<<endl;
    cout<<"3. Find the kth max and min element in an array - Quick Select Algorithm"<<endl;
    cout<<"4. Quick Select Easy-O(n) & worst-O(n^2)"<<endl;
    cout<<"5. DNF Sort"<<endl;
    cout<<"6. Move all negative numbers to left"<<endl;
    cout<<"7. Union of 2 unsorted arrays - O(m+n)"<<endl;
    cout<<"8. Intersection of 2 unsorted arrays - O(m+n)"<<endl;
    cout<<"9. Union of 2 sorted arrays - O(m+n)"<<endl;
    cout<<"10. Intersection of 2 sorted arrays - O(m+n)"<<endl;
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
                        cout<<kthSmallest(a,0,n-1,k)<<endl;
                        break;
                    }
        case 4 :    {
                        int n,k;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        cin>>k;
                        cout<<quickSelect(a,0,n-1,k);
                        break;
                    }
        case 5 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        sort012(a,n);
                        break;
                    }
        case 6 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        rearrange(a,n);
                        for(int i=0;i<n;i++)
                            cout<<a[i];
                        break;
                    }
        case 7 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int m;
                        cin>>m;
                        int b[m];
                        for(int i=0;i<m;i++)
                            cin>>b[i];
                        cout<<doUnion1(a,n,b,m)<<endl;
                        break;
                    }
        case 8 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int m;
                        cin>>m;
                        int b[m];
                        for(int i=0;i<m;i++)
                            cin>>b[i];
                        cout<<doIntersection1(a,n,b,m)<<endl;
                        break;
                    }
        case 9 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int m;
                        cin>>m;
                        int b[m];
                        for(int i=0;i<m;i++)
                            cin>>b[i];
                        cout<<doUnion2(a,n,b,m)<<endl;
                        break;
                    }
        case 10 :    {
                        int n;
                        cin>>n;
                        int a[n];
                        for(int i=0;i<n;i++)
                            cin>>a[i];
                        int m;
                        cin>>m;
                        int b[m];
                        for(int i=0;i<m;i++)
                            cin>>b[i];
                        cout<<doIntersection2(a,n,b,m)<<endl;
                        break;
                    }
        default  :      cout<<"Try Again!"<<endl;
                        break;
    }
    return 0;
}
