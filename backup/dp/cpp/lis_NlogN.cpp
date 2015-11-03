int a[N];
int h[N], l;

for (int i = l = 0; i < N; ++i) {
    int p = lower_bound(h, h+l, a[i])-h;
    h[p] = a[i];
    l = max(p+1, l);
}