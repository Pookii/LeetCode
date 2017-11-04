
int lengthOfLongestSubstring(char* s) {
    int alph[256];
    memset(alph, 0, sizeof(alph));
    int len = strlen(s);
    int res = 0, cnt = 0, end;
    for (int i = 0; i < len; ++ i) {
        for (int j = i; j < len; ++ j) {
            alph[s[j]] ++;
            if (alph[s[j]] > 1) {
                if (res < cnt) res = cnt;
              //  printf("j: %d %d %d %c\n", j, res, cnt, s[j]);
                cnt = 0;
                memset(alph, 0, sizeof(alph));
                break;
            } else {
              //  printf("%d %d\n", i, j);
                cnt ++;
            }
        }
        if (res >= len - i) break;
    }
  //  printf("res %d\n", res);
    if (res < cnt) res = cnt; 
    return res;
}

int main() {
    char s[20];
    scanf("%s", s);
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}