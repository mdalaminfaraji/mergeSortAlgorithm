#include<bits\stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++){
    cin>>arr[i];
   }
   
   
   int m;
   cin>>m;
   int val=0;
   int left=0;
   int right=(n-1);
   while (left<=right) 
   {
      int mid=(left+(right-left)/2);
      if(arr[mid]==m){
        val++;
        
      }
      if(arr[mid]<m){
        left=mid+1;
      }else{
        right=mid-1;
      }
   }
    cout<<val<<endl;
    if(val==2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
   
    return 0;
}
