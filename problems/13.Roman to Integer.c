int romanToInt(char* s) {
    //I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、M（1000）
    int len = strlen(s);
    int fth = 0, fhu = 0, ft = 0, fd = 0;
    bool bhu = false, bt = false, bd = false;
    for (int i = 0; i < len-1; ++ i) {
        if(s[i] == 'M' && (!bhu)) {
            ++ fth;
        } else if(s[i] == 'C' && s[i+1] == 'D') {
            fhu = 4;
            bhu = true;
        } else if(s[i] == 'C' && s[i+1] == 'M') {
            fhu = 9;
            bhu = true;
        } else if(s[i] == 'C' && (!bhu) && (!bt)) {
            ++ fhu;
        } else if(s[i] == 'D' && (!bhu)){
            fhu += 5;
        } else if(s[i] == 'X' && s[i+1] == 'L') {
            ft = 4;
            bt = true;
        } else if(s[i] == 'X' && s[i+1] == 'C') {
            ft = 9;
            bt = true;
        } else if(s[i] == 'X' && (!bt) && (!bd)) {
            ++ ft;
        } else if(s[i] == 'L' && (!bt)) {
            ft += 5;
        } else if(s[i] == 'I' && s[i+1] == 'V') {
            fd = 4;
            bd = true;
        } else if(s[i] == 'I' && s[i+1] == 'X') {
            fd = 9;
            bd = true;
        } else if(s[i] == 'V' && (!bd)) {
            fd += 5;
        } else if (s[i] == 'I' && (!bd)) {
            ++ fd;
        }
    }
    if(s[len-1] == 'X' && (!bd)) ++ ft;     
    if(s[len-1] == 'C' && (!bt)) ++ fhu;    
    if(s[len-1] == 'V' && (!bd)) fd += 5;      
    if(s[len-1] == 'I' && (!bd)) ++ fd;    
    if(s[len-1] == 'D' && (!bhu)) fhu += 5;
    if(s[len-1] == 'L' && (!bt)) ft += 5;
    if(s[len-1] == 'M' && (!bhu)) ++ fth;
    int res = fth * 1000 + fhu * 100 + ft * 10 + fd;
    return res;
}