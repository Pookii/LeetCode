//#include <stdio.h>
//#define MAXSIZE 100
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int r[100001], k = 0, i = 0, j = 0;
    for ( ; (i < nums1Size)&&(j < nums2Size); ) {
        if (nums1[i] < nums2[j]) {
            r[k ++] = nums1[i];
            ++ i;
        } else {
            r[k ++] = nums2[j];
            ++ j;
        }
    }
    if (i == nums1Size) {
        for ( ; j < nums2Size; ++ j) 
            r[k ++] = nums2[j];
    } else if (j == nums2Size) {
        for ( ; i < nums1Size; ++ i)
            r[k ++] = nums1[i];
    }
    double res = 0;
    if(k % 2 == 0) res = (r[k/2] + r[k/2-1])/2.0;
    else res = r[k/2];
    return res;
}
/*
int main() {
    int n, m, arr1[MAXSIZE], arr2[MAXSIZE];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++ i) 
        scanf("%d", &arr1[i]);
    for(int j = 0; j < m; ++ j)
        scanf("%d", &arr2[j]);
    printf("%f\n", findMedianSortedArrays(arr1, n, arr2, m));
    return 0;
}
*/