/* $mkdir ~/pset1/   */
/* $ cd ~pset1/   */

#include <stdio.h>
#include <cs50.h>


void print_row(int);
void build_blocks(int);

int main(void)
//program to build mario blocks with width given by user
{
    int n;
    do
    {
        n = get_int("Width: ");
    }
    while (n < 1 || n > 8);
    
    build_blocks(n);
}


void build_blocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1 ; j > i ; j--)
        {
            printf(" ");
        }
        print_row(i + 1);
        printf("  ");
        print_row(i + 1);
        printf("\n");
    }
    
}


void print_row(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

// cd ~/pset1/mario
// make mario
// ./mario
