using namespace std;
#include<bits/stdc++.h>



int construct_seg(int* st, int* a,int l,int r,int curr)
{
    if(l>=r)
    return a[l];

    else
    {
        int mid =  l + (r-l)/2;

        st[2*curr+1] = construct_seg(st,a,l,mid,2*curr + 1);
        st[2*curr+2] = construct_seg(st,a,mid+1,r,2*curr + 2);

        return st[2*curr+1] + st[2*curr+2];
    }

}
void update(int l,int r,int* st,int i,int diff,int curr)
{
    if(i < l || i > r)
    return;

    st[curr] = st[curr] + diff;
    if(l != r)
    {
        int  mid = l + (r-l)/2;
        update(l,mid,st,i,diff,2*curr+1);
        update(mid +1,r,st,i,diff,2*curr+2);
    }
}
int Get_sum(int* st,int n, int l,int r,int curr, int rl,int rr)
{

    if(rr<l || rl > r)
    {return 0;}


    if(rl <= l && rr >= r)
    {return st[curr];}
    int mid = l + (r-l)/2;
    return Get_sum(st,n,l,mid,2*curr+1,rl,rr) + Get_sum(st,n,mid+1,r,2*curr+2,rl,rr);
}
int main()
{
    int n;cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int st[2*n +2] = {0};
    st[0] = construct_seg(st,a,0,n-1,0);
    
    cout << "enter the index to be updated and the difference\n";
    int i,diff;
    cin >> i >> diff;
    update(0,n-1,st,i,diff,0);

    cout << " Give a range for query."<<endl;
    int l , r;
    cin >> l >> r;
    cout << "Sum of values in given range." << Get_sum(st,n,0,n-1,0,l,r)<<endl;

    

}