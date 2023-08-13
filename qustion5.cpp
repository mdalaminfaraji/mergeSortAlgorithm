//Question: Write a C++ program that takes N integer numbers and sorts them in non-increasing order using Merge Sort. 

#include<bits\stdc++.h>
using namespace std;
const int N=1e5 +7;
int nums[N];

void merge(int l, int r , int mid) {
    int l_size = mid - l + 1;
    int r_size = r - mid;
    
    int l_half[l_size];
    int r_half[r_size];
    
    for (int i = 0; i < l_size; i++)
        l_half[i] = nums[l + i];
    
    for (int i = 0; i < r_size; i++)
        r_half[i] = nums[mid + 1 + i];
    
    int i = 0, j = 0, k = l;
    
    while (i < l_size && j < r_size) {
        if (l_half[i] >= r_half[j]) { 
            nums[k] = l_half[i];
            i++;
        } else { 
            nums[k] = r_half[j];
            j++;
        }
        k++;
    }
    
    while (i < l_size) {
        nums[k] = l_half[i];
        i++;
        k++;
    }
    
    while (j < r_size) {
        nums[k] = r_half[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r){
    if(l==r) return;
    int mid=(l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
   merge(l, r, mid);
};


int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0; i<n; i++){
       cin>>nums[i];
   }
   int m;
   cin>>m;
   int arr1[m];
   for(int i=0; i<m; i++){
    cin>>nums[n+i];
   }

   mergeSort(0, (n+m)-1);
    for(int i=0; i<(n+m); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
