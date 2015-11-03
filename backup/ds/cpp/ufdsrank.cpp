int num_groups, p[N], grpsize[N];
int par(int x) { return (p[x]==x)? x:par(p[x]); } //No compression
bool isSameGroup(int a, int b) { return par(a) == par(b); }
void merge(int a, int b) {
    a = par(a), b = par(b);
    num_groups -= (!isSameGroup(a, b));
    if (grpsize[a] < grpsize[b]) {
        p[a] = b;
        grpsize[b] += grpsize[a];
    }
    else {
        p[b] = a;
        grpsize[a] += grpsize[b];
    }
}

/* Initialize */
for (int i = 0; i < N; ++i) p[i] = i, grpsize[i] = 1;
num_groups = N;
