int num_groups, p[N];
int par(int x) { return (p[x]==x)? x:p[x]=par(p[x]); }
bool isSameGroup(int a, int b) { return par(a) == par(b); }
void merge(int a, int b) {
    num_groups -= (!isSameGroup(a, b);
    p[par(a)] = par(b);
}

/* Initialize */
for (int i = 0; i < N; ++i) p[i] = i;
num_groups = N;
