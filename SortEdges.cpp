#include<bits\stdc++.h>
using namespace std;
int main()
{
     int N;
     cin>>N;
       priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>>pq;
     for(int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
       pq.push({a, b});
     }
     while(!pq.empty()){
         pair<int, int> value= pq.top();
         pq.pop();
         cout<<value.first<<" "<<value.second<<endl;
     }
    return 0;
}
