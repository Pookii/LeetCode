int reverse(int x) {
    int sign = 0, k = 0;
    if (x < 0) sign = 1;
    x = abs(x);
    long long tmp[1001];
    while(x) {
        tmp[k ++] = x%10;
        x /= 10;
    }
    
    long long res = 0;
    
    for (int i = 0; i < k; ++ i) {
        res += tmp[i]*pow(10, k-i-1);
        if ((res > INT_MAX) || (res < INT_MIN)) return 0;
    }
  
    if((res > INT_MAX) || (res < INT_MIN)) return 0;
    if (sign) res *= -1;
    return res;
}