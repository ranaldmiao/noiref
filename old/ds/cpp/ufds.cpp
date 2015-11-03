int N = 7;
int num_groups = N, p[N];

int par(int x) {
    if (p[x] == x) return x; //If you are the parent of yourself, you are the leader
    return p[x] = par(p[x]); //Save the result of par(parent) to be your parent, so you do not have to compute again later
}
bool isSameGroup(int a, int b) {
    return par(a) == par(b);
}
void merge(int a, int b) {
    if (par(a) == par(b)) return; //Don't need to merge if already same group
    --num_groups; //Each merge decreases the number of groups by 1
    p[par(a)] = par(b);
}

/* Initialize */
for (int i = 0; i < N; ++i) p[i] = i;
num_groups = 0;


/* Merge */
merge(0, 2); //[0,2][1][3][4][5][6][7]
merge(0, 1); //[0,1,2][3][4][5][6][7]
merge(1, 2); //[0,1,2][3][4][5][6][7]
merge(4, 5); //[0,1,2][3][4,5][6][7]
merge(1, 5); //[0,1,2,4,5][3][6][7]

/* Checking */
isSameGroup(2, 4); //true
isSameGroup(2, 3); //false

/* Number of groups */
printf("There are %d\n groups of elements.\n", num_groups); //4 groups