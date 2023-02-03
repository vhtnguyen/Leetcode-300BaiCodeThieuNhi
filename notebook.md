# My notebook for some common algorithms

## Binary search

```cpp
#include<algorithm>

vector<int>v = { 1,1, 2,2,2, 3,4,5 ,7 };
int x = 3;
bool result = binary_search(v.begin(), v.end(), x);
// true
```

### lower_bound

```cpp
#include<algorithm>

//return iterator of the first element greater or equal to the target in range [first,last)
vector<int>v = { 1, 1, 2, 2, 2, 3, 4, 5, 7};
int x = 3;
vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);
int index = it - v.begin();
// 5
```

### upper_bound

```cpp
#include<algorithm>

//return iterator of the first element greater than the target in range [first,last)
vector<int>v = { 1, 1, 2, 2, 2, 3, 4, 5, 7};
int x = 3;
vector<int>::iterator it = upper_bound(v.begin(), v.end(), x);
int index = it - v.begin();
// 6
```

### Implement

```cpp
int binarySearch(const vector<int>& nums, int left, int right, int target) {

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    //not found
    return -1;

}
```

```cpp
int binarySearch(const vector<int>& nums, int left, int right, int target) {

    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, right, target);
        }
        return binarySearch(nums, left, mid - 1, target);
    }
    //not found
    return -1;

}
```

```cpp
int binarySearchFirst(const vector<int>& nums, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == left || nums[mid - 1] < target )&& nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearchFirst(nums, mid + 1, right, target);
        }
        return binarySearchFirst(nums, left, mid - 1, target);
    }
    return -1;
}
```

```cpp
int binarySearchLast(const vector<int>& nums, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if ((mid == right || nums[mid + 1] > target) && nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binarySearchLast(nums, mid + 1, right, target);
        }
        return binarySearchLast(nums, left, mid - 1, target);
    }
    return -1;
}
```
