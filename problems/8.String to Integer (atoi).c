#include <stdio.h>
#include <string.h>
#include <math.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int myAtoi(char* str) {
     char tmp[1001];
    char *mx = "2147483647";
    char *mi = "2147483648";
    memset(tmp, 0, sizeof(tmp));
    int k = 0, i = 0, flag = 1;
    int len = strlen(str);
    if (len == 0) return 0;

    for (i = 0; i < len; ++ i) {
        if (str[i] == ' ') continue;
        if (str[i] == '-') {
            flag = 0;
            break;
        } else if (str[i] == '+') {
            flag = 1;
            break;
        } else if (str[i] >= '0' && str[i] <= '9') {
            -- i;
            break;
        } else return 0;
    }

    for (int j = i+1; j < len; ++ j) {
        if (str[j] >= '0' && str[j] <= '9')
            tmp[k ++] = str[j];
        else break;
    }

    int lenTmp = strlen(tmp);
    if (flag == 1) {
        if (lenTmp > 10) return INT_MAX;
        else if(lenTmp == 10 && strcmp(mx, tmp) < 0) return INT_MAX;
        else {
            int integer = 0;
            for (int h = 0; h < lenTmp; ++ h) {
                int a = tmp[h] - '0';
                integer += a * pow(10, lenTmp-1-h);
            }
            return integer;
        }
    } else if (flag == 0) {
        if (lenTmp > 10) return INT_MIN;
        else if(lenTmp == 10 && strcmp(mi, tmp) < 0) return INT_MIN;
        else {
            int integer = 0;
            for (int h = 0; h < lenTmp; ++ h) {
                int a = tmp[h] - '0';
                integer += a * pow(10, lenTmp-1-h);
            }
            return integer*(-1);
        }
    }
    return 0;
}

int main() {
    char str[1001];
    while(~scanf("%s", str)) {
        int a = myAtoi(str);
        printf("%d\n", a);
    }
    return 0;
}