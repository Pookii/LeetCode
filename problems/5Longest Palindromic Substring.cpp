#include <stdio.h>
#include <string.h>

int isPalindrome(char *s) {
		int length = strlen(s);
		for (int i = 0, j = length-1; i <= j; ++i, --j) {
			if (s[i] != s[j]) return 0;
		}
		return 1;
}

char* longestPalindrome(char* s) {
	int len = strlen(s);
	char str[2001];
	int c = 0;
	if (len == 1) return s;
	if(len == 2 && s[0] == s[1]) return s;
	//if(len == 2 && s[0] != s[1]) 
	memset(str, 0, sizeof(str));
	for (int i = 0; i < len;) {
		if (c % 2 == 0) {
			str[c ++] = s[i ++];
		}
		else
			str[c++] = '#';
	}
	len = strlen(str);
	//puts(str);
	int start = 0, end = 0, cnt = 0;
	int mx = -1, flag = 0;
	for (int i = 1; i < len; ++ i) {
		flag = 0;
		int j;
		cnt = 0;
		for (j = 1; (i-j>=0) && (i+j<len); j ++) {
		//	printf("i %d, %d %d %c %c\n", i, i-j, i+j, str[i-j], str[i+j]);
			if (str[i - j] == str[i + j]) {
				if(str[i-j] != '#')
					cnt = 2*j;
				flag = 1;
			} else {
				if(mx < cnt) {
					
			 	//	printf("%c %c\n", str[start], str[end]);
				//	if (!(mx == 0 && str[start] == '#')) {
						start = i - j + 1;
						end = i + j - 1;
						mx = cnt;
				//	} 
				}
				flag = 0;
				break;
			}
		}
		if(flag && (mx < cnt)) {
			mx = cnt;
			start = i - j + 1;
			end = i + j - 1;
		}
	//	printf("mx: %d, start: %d, end: %d\n", mx, start, end);
	}
	
	static char res[1001];
	memset(res, 0, sizeof(res));
	int k = 0;
	//printf("%d %d %s\n", start, end, res);
	
	//memset(s, 0, sizeof(s));
	//printf("len %d\n", strlen(s));
	for (int i = start; i <= end; ++ i) {
		if (str[i] != '#'){
		//	s[k ++] = str[i];
			res[k ++] = str[i];
		}
	}
	//printf("len %d\n", strlen(res));
//	puts(s);
	if (strlen(res) == 0) res[0] = str[0];
	//if (strlen(s) == 0) s[0] = str[0];
	//return s;
	return res;
}

int main() {
	char str[1001];
	while(~scanf("%s", str)) {
		puts(longestPalindrome(str));
	}

	return 0;
}