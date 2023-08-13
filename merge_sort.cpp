#include <iostream>

void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1;
    int right_size = right - mid;
    
    int left_half[left_size];
    int right_half[right_size];
    
    for (int i = 0; i < left_size; i++)
        left_half[i] = arr[left + i];
    
    for (int i = 0; i < right_size; i++)
        right_half[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    
    while (i < left_size && j < right_size) {
        if (left_half[i] >= right_half[j]) { // Non-increasing order
            arr[k] = left_half[i];
            i++;
        } else { 
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }
    
    while (i < left_size) {
        arr[k] = left_half[i];
        i++;
        k++;
    }
    
    while (j < right_size) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n;
  
   std::cin >> n;
    
    int arr[n];
 
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    mergeSort(arr, 0, n - 1);
    

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
// void merge(int l, int r, int mid){
//     int left_size=mid-l+1;
//     int L[left_size+1];
//     int right_size=r-mid;
//     int R[right_size+1];
//     for(int i=l, j=0; i<=mid; i++, j++){
//         L[j]=nums[i];
//     }

//     for(int i=mid+1, j=0; i<=r; i++, j++){
//         R[j]=nums[i];
//     }

//     L[left_size]=INT_MAX;
//     R[right_size]=INT_MAX;
//     int lp=0, rp=0;
//    for(int i=l; i<=r; i++){
//     if(L[lp]<=R[rp]){
//         nums[i]=L[lp];
//         lp++;
//     }else{
//         nums[i]=R[rp];
//         rp++;
//     }
//    }
// }
