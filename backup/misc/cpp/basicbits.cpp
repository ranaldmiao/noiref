int a = 5; // base 2: 0101
int b = 9; // base 2: 1001
int c = 1; // base 2: 0001
int result;


/* AND */
result = a&b; // 0101 AND 1001
//result will be 1 (0001)

/* OR */
result = a|b; // 0101 OR 1001
//result will be 13 (1101)

/* XOR */
result = a^b; // 0101 XOR 1001
//result will be 12 (1100)

/* LEFT PUSH */
result = a<<1; // 0101 << 1
//result will be 10 (1010)
result = c<<2; // 0001 << 1
//result will be 4 (0100)

/* RIGHT PUSH */
result = a>>1; // 0101 >> 1
//result will be 2 (0010)
result = b>>2; // 1001 >> 2
//result will be 2 (0010)