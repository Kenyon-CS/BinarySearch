#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int binarySearch(vector<int> v, int find) {
  int lo = 0, hi = v.size() - 1;
  int mid;
  // This below check covers all cases , so need to check
  // for mid=lo-(hi-lo)/2
  while (hi - lo > 1) {
    int mid = (hi + lo) / 2;
    if (v[mid] < find) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  if (v[lo] == find) {
    return lo;
  } else if (v[hi] == find) {
    return hi;
  } 
  // Not found
  return -1;
}

int main() {
  vector<int> v = {1, 3, 4, 5, 6};

  cout << binarySearch(v, 1) << endl;
  cout << binarySearch(v, 6) << endl;
  cout << binarySearch(v, 10) << endl;

  return 0;
}

Recursive C++ code (repl):

// C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
  cout << binarySearch(arr, 0, n - 1, 2) << endl;
  cout << binarySearch(arr, 0, n - 1, 10) << endl;
  cout << binarySearch(arr, 0, n - 1, 22) << endl;
	return 0;
}
