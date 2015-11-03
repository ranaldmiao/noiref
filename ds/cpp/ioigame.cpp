#include "game.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define mp make_pair
int R, C;
pi lca(int s, int e, int x, int y, int p) {
	int m = (s+e)/2;
	if (s <= x && y <= m && p > m) return mp(s, e);
	if (p <= m && m < x && y <= e) return mp(s, e);
	if (p > m) return lca(m+1, e, x, y, p);
	else return lca(s, m, x, y, p);
}
struct node {
	node *l, *r;
	ll val;
	int s, e;
	node(ll _s, ll _e): s(_s), e(_e), val(0), l(NULL), r(NULL) {}
	inline bool inrange(int x) {
		if (x < s || x > e) return false;
		return true;
	}
	void update(int x, ll v) {
		int m = (s+e)/2;
		if (s == e) val = v;
		else {
			if (x > m) {
				if (r == NULL) r = new node(x, x);
				else if (!r->inrange(x)) {
					node* tmp = r;
					pi nxt = lca(s, e, r->s, r->e, x);
					r = new node(nxt.first, nxt.second);
					if (tmp->e <= (r->s + r->e)/2 ) r->l = tmp;
					else r->r = tmp;
				}
				r->update(x, v);
			}
			else {
				if (l == NULL) l = new node(x, x);
				else if (!l->inrange(x)) {
					node* tmp = l;
					pi nxt = lca(s, e, l->s, l->e, x);
					l = new node(nxt.first, nxt.second);
					if (tmp->e <= (l->s + l->e)/2 ) l->l = tmp;
					else l->r = tmp;
				}
				l->update(x, v);
			}
			val = 0;
			if (l != NULL) val = __gcd(l->val, val);
			if (r != NULL) val = __gcd(r->val, val);
		}
	}
	ll query(int x, int y) {
		int m = (s+e)/2;
		if (x <= s && e <= y) return val;
		ll ret = 0;
		if (l != NULL && x <= m) ret = __gcd(ret, l->query(x, min(y, m)));
		if (r != NULL && y > m) ret = __gcd(ret, r->query(max(m+1, x), y));
		return ret;
	}
	node* clone() {
		node* t = new node(s, e);
		t->val = val;
		if (l != NULL) t->l = l->clone();
		if (r != NULL) t->r = r->clone();
		return t;
	}
};
struct row {
	row *l, *r;
	int s, e;
	node* val;
	row(ll _s, ll _e): s(_s), e(_e), val(0), l(NULL), r(NULL) {
	    val = new node(0, C);
	}
	inline bool inrange(int x) {
		if (x < s || x > e) return false;
		return true;
	}
	void update(int x, int y, ll v) {
		int m = (s+e)/2;
		if (s == e) val->update(y, v);
		else {
			if (x > m) {
				if (r == NULL) r = new row(x, x);
				else if (!r->inrange(x)) {
					row* tmp = r;
					pi nxt = lca(s, e, r->s, r->e, x);
					r = new row(nxt.first, nxt.second);
					if (tmp->e <= (r->s + r->e)/2 ) r->l = tmp;
					else r->r = tmp;
					r->val = tmp->val->clone();
				}
				r->update(x, y, v);
			}
			else {
				if (l == NULL) l = new row(x, x);
				else if (!l->inrange(x)) {
					row* tmp = l;
					pi nxt = lca(s, e, l->s, l->e, x);
					l = new row(nxt.first, nxt.second);
					if (tmp->e <= (l->s + l->e)/2 ) l->l = tmp;
					else l->r = tmp;
					l->val = tmp->val->clone();
				}
				l->update(x, y, v);
			}
			ll rv = 0;
			if (l != NULL) rv = __gcd(l->val->query(y, y), rv);
			if (r != NULL) rv = __gcd(r->val->query(y, y), rv);
			val->update(y, rv);
		}
	}
	ll query(int x, int y, int p1, int p2) {
		int m = (s+e)/2;
		if (x <= s && e <= y) return val->query(p1, p2);
		ll ret = 0;
		if (l != NULL && x <= m) ret = __gcd(ret, l->query(x, min(y, m), p1, p2));
		if (r != NULL && y > m) ret = __gcd(ret, r->query(max(m+1, x), y, p1, p2));
		return ret;
	}
};
row* root;
void init(int _R, int _C) {
    R = _R, C = _C;
    root  = new row(0, R);
}
 
void update(int P, int Q, long long K) {
    root->update(P, Q, K);
}
 
long long calculate(int P, int Q, int U, int V) {
    return root->query(P, U, Q, V);
}
