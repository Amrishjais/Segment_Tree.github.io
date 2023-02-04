#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],seg[4*N];


void build(int ind, int low, int high){
    if(low==high){
        seg[ind]=a[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);

    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int ind,int low, int high,int l, int r,int val){
    if(low>=l && high<=r){
        return seg[ind]+val;
    }

    if(low>r||high<l){
        return 0;
    }

    int mid=(low+high)/2;
    int left=query(2*ind+1,low,mid,l,r,val);
    int right=query(2*ind+2,mid+1,high,l,r,val);
    return left+right+2*val;

}
int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   build(0,0,n-1);
   
   int q;
   cin>>q;
   while(q--){
        int l,r,val;
    cin>>l>>r>>val;
    cout<<query(0,0,n-1,l,r,val)<<endl;
   }
   return 0;
}