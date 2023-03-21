#include <iostream>
using namespace std;
int mid;
int BinarySearch(int arr[], int x, int left, int right){
    while (left <= right){
         mid = left +  (right - left) / 2;

        if (arr[mid] == x){
            return mid;
        }
        else if (arr[mid] > x ){
            return BinarySearch(arr, x, left, mid-1);
        }
        else if (arr[mid] < x){
            return BinarySearch(arr, x, mid+1, right);
        }
    }

}


int main() {
    int i, num, find, n, result;

    cout << "Enter the size of the array = ";
    cin >> num;
    
    int arr[num];
    cout << "Enter " << num << " numbers." << endl;

    for (i = 0; i < num; i++)
    {
        cout << "Arr[" << i << "] = ";
        cin >> arr[i];
    }

    for (i = 0; i < num ; i++)
    {
        cout << arr[i] << " " << endl;
    }


    for (int x=0; x<num; x++){
        for (int y = x+1; y < num; y++){
            if (arr[x] > arr[y]){
                swap(arr[x], arr[y]);
            }
        }
    }

    cout << "Sorted array are : " << endl;

    for (i = 0; i < num; i++)
    {
        cout << arr[i] << endl;
    }



    n = sizeof(arr) / sizeof(arr[0]);
    cout << "Size of array : " << n << endl;
    cout << "Enter the number you want to search : ";
    cin >> find;

    
    result = BinarySearch(arr, find, 0, n-1);
    if (result == -1){
        cout << "Number is not in array";
    }
    else{
        cout << "Number is found in index " << result;
    }
        
    return 0;
}
