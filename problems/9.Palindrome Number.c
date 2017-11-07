bool isPalindrome(int x) {
    if(x < 0) return false;
    int tmp[100001];
   // memset(tmp, 0, sizeof(tmp));
    int k = 0;
    
    while(x) {
        tmp[k ++] = x%10;
        x /= 10;
    }
    if (k == 0) return true;
    for(int i = 0; i <= (k-1)/2; ++ i) {
        if(tmp[i] != tmp[k-1-i]) return false;
    }
    return true;
}