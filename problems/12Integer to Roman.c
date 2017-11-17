char* intToRoman(int num) {
    static char res[100];
    //I（1）、V（5）、X（10）、L（50）、C（100）、D（500）、M（1000）
    char ch[10][5] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    char st[10][5] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char hu[10][5] = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char th[10][5] = {"", "M", "MM", "MMM"};
    memset(res, 0, sizeof(res));
    strcat(res, th[num/1000]);
    num %= 1000;
    strcat(res, hu[num/100]);
    num %= 100;
    strcat(res, st[num/10]);
    num %= 10;
    strcat(res, ch[num]);
    return res;
}