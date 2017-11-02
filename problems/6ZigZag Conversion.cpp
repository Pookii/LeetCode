#include <stdio.h>
#include <string.h>

char* convert(char* s, int numRows) {
	//puts(s);
	if(numRows == 1) return s;
	int len = strlen(s);
	
	int c = (len/(2*numRows - 2) + 1) * (numRows - 1);
	//printf("c %d\n", c);
	
	char mp[numRows][c];
	int g, h;
	for (g = 0; g < numRows; ++ g) {
		for (h = 0; h < c; ++ h)
			mp[g][h] = '#';
	}
	
	int k = 0;
	int i = 0, j = 0;;
	while (k < len) {
		for (; i < numRows; ++ i) {
			if (k >= len) break;
			mp[i][j] = s[k ++];
			//printf("1 %d %d %c\n", i, j, mp[i][j]);
		}
		i -= 2;
		++ j;
		for ( ;(i >= 0 && j < c); -- i, ++ j) {
			if (k >= len) break;
			mp[i][j] = s[k ++];
		//	printf("2 %d %d %c\n", i, j, mp[i][j]);
		}
		i += 2;
		-- j;
	}

	static char res[10001];
	memset(res, 0, sizeof(res));
	k = 0;
	for (g = 0; g < numRows; ++ g) {
		for (h = 0; h < c; ++ h) 
			if(mp[g][h] != '#') {
				//printf("%c",mp[g][h]);
				res[k ++] = mp[g][h];
			}
	}
	res[k] = '\0';
	return res;
}

int main() {
	char *str;
	int numRows;
	while(~scanf("%s %d", str, &numRows)) {
		//printf("%s %d %d\n", str, numRows, strlen(str));
		puts(convert(str, numRows));
		//convert(str, numRows);
	}
}