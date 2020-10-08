#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string user_ans = get_string("what's your name?\n");
    printf("hello %s \n", user_ans);
   /*clang -o string string.c -lcs50*/
}

/* $make string */
/* $./string  */