#include<bits/stdc++.h>
using namespace std;


// struct comparator {
//     bool operator()  (int i,int j)
//     {
//         return i > j;
//     }
// };
// void showq(priority_queue <int,vector<int>,greater<int>> pq)
// {
//     priority_queue<int, vector<int>,greater<int>> g = pq;
//     while(!g.empty())
//     {cout << " "<<g.top();
//     g.pop();}
// }
// int main()
// {
//     int k;cin >> k;
//    priority_queue <int,vector<int>, greater<int>> pq;
//    vector<vector<int>> arrays(8);
//    for(int i=1;i<=10;i++)
//    {
//        pq.push(i*4 -234%1);
//    }

//    cout << "the priority que is : ";
//    showq(pq);
// }
vector<int> merge_arrays(vector<int> a,vector<int> b)
{

    // a merging function  just like the one used in merge sort;

    int l1 = a.size();
    int l2 = b.size();
    int i =0,j=0;
    vector <int> temp;
    while(i<l1 && j<l2)
    {
        if(a[i] < b[j])
        {
            temp.push_back(a[i]);i++;
        }

        else
        {
            temp.push_back(b[j]);j++;
        }
    }

    if(i <= l1-1)
    {
        while(i < l1-1)
        {
            temp.push_back(a[i]);i++;
        }
    }

    else
    {
        while(j <= l2-1)
        {
            temp.push_back(b[j]);j++;
        }
    }


    return temp;
}
vector<int> merge_k(vector<vector<int>> a)
{
    vector<vector<int>> temp;

    // pairwise we will keep merging the arrays until unless
    //  we are left with only one array
    while(a.size() > 1)
    {
        // clears the temp for another round of merging;
        temp.clear();

        // this loop does the pair-wise merge
        for(int i=0;i<a.size();i+=2)
        {
            // if only one array remains append as it is;
            if(i == a.size()-1)
            temp.push_back(a[i]);
             
            //  else merge the current array with the next array
            else{
            temp.push_back(merge_arrays(a[i],a[i+1]));
            }
        }

        a = temp;
    }

    return a[0];
}
int main()
{
    vector<vector<int>> a{{1,2,3},
                          {2,3,4},
                          {4,5,6,8,9}};

    // initiating merge;
    vector<int>  sorted = merge_k(a);

    for(int i=0;i<sorted.size();i++)
    {
        cout << sorted[i] << " ";
    }

    // cout <<endl<< a.size()<<endl;
}