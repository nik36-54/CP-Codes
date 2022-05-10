//  SEGMENT TREE 

 #include<bits/stdc++.h>
 using namespace std;

class SGTree{
    vector<int> seg;
    public: 
    SGTree(int n)
    {
        seg.resize(4*n+1);
    }

    void update(int ind,int low,int high,int i,int val)
    {
        if(low==high)
        {
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid)
        update(2*ind+1,low,mid,i,val);
        else
        update(2*ind+2,mid+1,high,i,val);
        
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }

    int query(int ind,int low,int high,int l,int r)
    {
        // no overlap
        if(r<low || high<l)
        return INT_MAX;

        // complete overlap
        if(low>=l && high<=r)
        return seg[ind];

        // Partial Overlap
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }

    void build(int ind,int low,int high,int arr[])
    {
        if(low==high)
        {
            seg[ind]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    }

};

void solve()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++)
    cin>>arr1[i];
    SGTree sg1(n1);
    sg1.build(0,0,n1-1,arr1); 

    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++)
    cin>>arr2[i];
    SGTree sg2(n2);
    sg2.build(0,0,n2-1,arr2); 

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int min1=sg1.query(0,0,n1-1,l1,r1);
        int min2=sg2.query(0,0,n2-1,l2,r2);
        cout<<min(min1,min2);
        }
        else if(type==2)
        {
            // int i,val;
            // cin>>i>>val;
            // update(0,0,n-1,i,val,seg);
            // arr[i]=val;
            int arrNo,i,val;
            cin>>arrNo>>i>>val;
            if(arrNo==1)
            {
                sg1.update(0,0,n1-1,i,val);
                arr1[i]=val;
            }
            else if(arrNo==2)
            {
                sg2.update(0,0,n2-1,i,val);
                arr2[i]=val;
            }
        }
    }
}


int main()
{
    solve();
    return 0;
}

