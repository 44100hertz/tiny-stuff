#include <stdio.h>

/* reasoning about current position:
    - adjacent positions should be adjacent in data
    - data should be column-oriented (tiled sucks for this lol)
    - data should be easiest to read in order of depth draws
*/

// runtime format
struct node {
    struct node* u, d, l, r;
    int x, y;
    int col[4];
};
/* method:
    - if y is even, d and u point right, else left
    - locate the leftmost visible column and store it
    - traverse right and draw each column
    - go back to the stored column and move down til bottom of screen
*/

// still to resolve:
// storage format
// resolving sprites
