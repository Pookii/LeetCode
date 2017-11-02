#include <stdio.h>
int* twoSum(int* nums, int numsSize, int target) {
    static int res[2];
    for(int i = 0; i < numsSize; ++ i) {
        for (int j = i+1; j < numsSize; ++ j) {
            if (nums[i] + nums[j] == target) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }
    return res;
}

int main() {
    int n, target;
    int arr[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i)
        scanf("%d", &arr[i]);
    scanf("%d", &target);
    int *r = twoSum(arr, n, target);
    printf("%d %d\n", r[0], r[1]);
}