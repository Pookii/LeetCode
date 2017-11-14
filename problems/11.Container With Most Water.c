int maxArea(int* height, int heightSize) {
    int mx = -1;
    int p = 0, q = heightSize-1;
    while(p < q) {
        int tmp;
        if(height[p] < height[q]) {
            tmp = (q-p) * height[p];
            p ++;
        } else {
            tmp = (q-p) * height[q];
            q --;
        }
        if(mx < tmp) mx = tmp;
    }
    return mx;
}