struct segment {
	int n, mn, mx, s, e, m;
	segment *l, *r;
	segment(int start, int end, int a[] = NULL): s(start), e(end) {
		m = (s + e) / 2;
		mx = mn = n = 0;
		if (s == e && (a != NULL)) n = mx = mn = a[s];
		else {
			l = new segment(s, m, a);
			r = new segment(m + 1, e, a);
			n = l->n + r->n;
			mx = max(l->mx, r->mx);
			mn = min(l->mn, r->mn);
		}
	}
	int add(int start, int end, int delta) {
		if (start > e || end < s) return n;
		else if (s == e) return (mx = mn = (n += delta));
		else return (n = l->add(start, min(m, end), delta) + r->add(max(m + 1, start), end, delta)),
					(mx = max(l->mx, r->mx)), (mn = min(l->mn, r->mn)), n;
	}
	int set(int start, int end, int target) {
		if (start > e || end < s) return n;
		else if (s == e) return (mx = mn = n = target);
		else return (n = l->set(start, end, target) + r->set(start, end, target)),
					(mx = max(l->mx, r->mx)), (mn = min(l->mn, r->mn)), n;
	}
	int querysum(int start, int end) {
		if (start > e || end < s) return 0;
		else if (s == start && e == end) return n;
		else return l->querysum(start, min(end, m)) + r->querysum(max(m + 1, start), end);
	}
	int querymax(int start, int end) {
		if (start > e || end < s) return INT_MIN;
		else if (s == start && e == end) return mx;
		else return max(l->querymax(start, min(end, m)), r->querymax(max(m + 1, start), end));
	}
	int querymin(int start, int end) {
		if (start > e || end < s) return INT_MAX;
		else if (s == start && e == end) return mn;
		else return min(l->querymin(start, min(end, m)), r->querymin(max(m + 1, start), end));
	}
} *root;


root = new segment(0, n - 1, array); // creates a segment tree with elements 0 to n - 1. The array parameter is optional.
root->add(start, end, delta); // adds a delta to elements start to end, inclusive.
root->set(start, end, target); // sets elements start to end to target, inclusive.
root->querymin(start, end); // queries the minimum of elements start to end. querymax and querysum are similar.