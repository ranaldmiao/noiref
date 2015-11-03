int bitmask = 0; //initially 000000

/* Set the 2nd item to be taken */
bitmask = bitmask ^ (1<<2); //bitmask = 000100

/* Set the 0th item to be taken */
bitmask = bitmask ^ (1<<0); //bitmask = 000101

/* Check if the 3rd item is not taken */
if ( (bitmask & (1<<3)) == 0) { //if the 3rd item is not taken
    bitmask = bitmask ^ (1<<3); //set the 3rd item to be taken
} //bitmask = 001101

/* Check if the 3nd item is taken */
if ( (bitmask & (1<<3)) > 0) { //if the 3rd item is taken
    bitmask = bitmask ^ (1<<3); //set the 3rd item to be not taken 
} //bitmask = 000101

for (int k = 0; k < 6; ++k) {
    if (bitmask&(1<<k)) { //check if the K-th item is taken, shortcut for (bitmask&(1<<k)) > 0
        /* do some processing */
        printf("Item %d is taken.\n", k);
    }
}