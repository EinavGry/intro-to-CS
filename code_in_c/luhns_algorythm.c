#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Luhn’s Algorithm
void invalid(void);

int main(void)
{
    // input a number
    long int credit_num = get_long("Number: ");
    long int num = 0;
    long int sum_even = 0;
    long int sum_odd = 0;
    long int checker = 0; 
    long int check_luhn = 0;
    
    if (credit_num > 0)
    {
        num = credit_num;
        while (num > 0)
        {
            sum_odd = sum_odd + (num % 10);
            // printf("%li ,",sum_odd);
            num = num / 10;
            // printf("%li ,",num);
            checker = 2 * (num % 10);
            while (checker > 0)
            {
                sum_even = sum_even + checker % 10;    
                checker = checker / 10;
            }
            num = num / 10;
            // printf("%li \n",sum_even);
        }
    }
    
    check_luhn = sum_odd + sum_even;

    if (check_luhn % 10 == 0)
    {
        //378282246310005
        long int x_15 = credit_num / pow(10, 13);
        long int x_16 = credit_num / pow(10, 14); 
        long int x_13 = credit_num / pow(10, 11);
        
        if (x_15 == 34 || x_15 == 37)
        { 
            //at this point we checked if the number is valid 
            //and if its 15 digets long starting with 37 or 34
            // so it's an American Express number.
            printf("AMEX\n");
        }
        else if ((x_16 < 56 && x_16 > 50) || (x_16 < 50 && x_16 > 39))
        {
            //4003600000000014
            if (x_16 / 10 == 4)
            {
                printf("VISA\n");
            }
            else 
            {
                printf("MASTERCARD\n");
            }
        }
        else if (x_13 / 10 == 4)
        {
            printf("VISA\n");
        }
        // if it still went through all thet and doesn't fit then - invalid.
        else
        {
            invalid();
        }
        // printf("%li \n",x_16);

    }
    else
    {
        invalid();
    }
    
    /*
    
    if (credit_num %  pow(10,15) == 3)
    //does it have 15 digets, does it start with 3
    {
        if(credit_num %  pow(10,14) == 34 || credit_num % pow(10,14) == 37)
        // is the next number 4 or 5
        {
            printf("AMEX\n");
        }
    }
    else if (1==2)
    {
        invalid();
    }
    else if (3>4)
    {
        invalid();
    }
    else
    {
        invalid();
    }



   
        // no -> invalid
    // 

    
    //does it start with 4
    //does it have 13 or 16 digets?
    //VISA\n
    
    //does it start with 5
    // are the next numbers 1,2,3,4,5
    // does it have 16 digets
    //MASTERCARD\n

    */
}


void invalid(void)
{
    printf("INVALID\n");
}


// cd ~/pset1/ctredit
// make credit
// ./credit
