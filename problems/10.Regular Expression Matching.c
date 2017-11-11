#define N 10001
struct AutoMachine {
    int next[512];
    int tag; //tag = 1 ==> other character except '.','*'
    //tag = 256 ==> '*'
    //tag = 0 ==> start
    int next_inx; // '*' 0 match flag
};

struct AutoMachine a[N];

void init(int indx) {
    memset(a[indx].next, 0, sizeof(a[indx].next));
    a[indx].tag = 0;
    a[indx].next_inx = 0;
}

void build(char *p) {
    int size = 1, state = 1, i = 0, tail = 0;
    int len = strlen(p);
    int j;
    int tag = 0;
    init(1);
    while(i < len) {
        char c = p[i];
       // init(size); !!
        int val = a[state].tag;
        if (c == '.') {
            tail = size ++;
            for (j = 0; j < 256; ++ j) {
                a[state].next[j + val] = size;
            }
            init(size);
            state = size;
        } else if (c == '*') {
            state = tail;
            a[state].next_inx = 1;
            if (p[i-1] == '.') {
                for (j = 0; j < 256; ++ j) {
                    a[state].next[j] = state;
                }
            } else {
                a[state].next[p[i-1]] = state;
            }
            a[state].tag = 256;
            a[state].next_inx =  ++ size; // skip pre
            init(size);
            state = size;
        } else {
            a[state].next[val+p[i]] = ++size;
            tail = state;
            init(size);
            state = size;
        }
        ++ i;
    }
  //  init(size);
    a[state].tag = 1;
}

bool dfs(char *s, int cont, int st) {
    bool res3 = 0;
    if(a[st].next_inx != 0) {
      //  printf("next_inx %d cnt %d\n", a[st].next_inx, cont);
        res3 = dfs(s, cont, a[st].next_inx);
    }

    int len = strlen(s);
    if(cont == len) {
        if (a[st].tag == 1) return 1;
        else return res3;
    }
 
    int tmp1 = a[st].next[s[cont]];
    bool res1 = 0, res2 = 0;
    if(tmp1)
      res1 = dfs(s, cont+1, tmp1);
    int tmp2 = a[st].next[s[cont] + 256];
    if(tmp2)
        res2 = dfs(s, cont+1, tmp2);
    return res1 || res2 || res3;
}

bool isMatch(char* s, char* p) {
    //if(strlen(s) == 0) return 1;
    build(p);
    return dfs(s, 0, 1);
}


