char* longestCommonPrefix(char** strs, int strsSize) {
    if (strlen(strs) == 0) return "";
    int miLen = INT_MAX;
    for(int i = 0; i < strsSize; ++ i) {
        int len = strlen(strs[i]);
        if (miLen > len) 
            miLen = len;
    }
    
    int end = 0;
    
    for(int i = 0; i < miLen; ++ i) {
        int ct = 0, flag = 0;
        char ch = strs[0][i];
        for(int j = 0; j < strsSize; ++ j) {
            if(strs[j][i] != ch) {
               flag = 1;
               break;
            } else ++ ct;
        }
        if(flag) break;
        if (ct == strsSize) {
          ++ end;
        }
    }

    if (end == 0) return "";
    static char res[10001];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < end; ++ i)
        res[i] = strs[0][i];
    return res;
}