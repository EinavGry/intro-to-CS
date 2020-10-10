// substitution
#include <stdio.h>
#include <cs50.h>
#include<string.h>
#include <math.h>

void run_substitution(string key);
int legit_key(string key);

int main(int argc, char *argv[]) 
{

    if (argc == 2)
    {
        // printf("The argument supplied is %s\n", argv[1]);
        string le_key = argv[1];
        //   printf("%i",legit_key(le_key));
        if (legit_key(le_key) == 1)
        {
            printf("Key must only contian alphabetic characters.\n");
            return 1;
        }
        else if (legit_key(le_key) == 2)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (legit_key(le_key) == 3)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        else
        {
            run_substitution(le_key);
        }
    }
    else
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}


int legit_key(string key)
{
    int pass = 100;
    int length = strlen(key);
    int num = 26;
    int diff = 'A' - 'a';
    
    if (strlen(key) < num || strlen(key) > num)
    {
        pass = 2;
        // Key must contain 26 characters
    }
    
    // so we have 26 chars. now let's see if they are all letters:
    if (pass == 100)
    {
        pass = 0;
        for (int i = 0; i < length; i++)
        {
            // if it's a letter then go on
            if ((pass == 0) && ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z')))
            {
                pass = 0; // awesome
            }
            // Key must only contian alphabetic characters. , pass = 1
            else
            {
                pass = 1; //out and on with it.
            }
        }
    }
    
    // now let's see if there are doubles.
    if (pass == 0)
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1 ; j < length + 1 ; j++)
            {
                if ((pass == 0) && (key[i] == key[j]))
                {
                    // Key must not contain repeated characters, pass =3
                    pass = 3;
                }
            }
        }
    }
    
    
    
    
    
    
    // // printf("len of thing : %lu ",strlen(key));
    // if (pass == 1)
    // {
        
        
    //     int j = 0;
    //     for (int i = 0; i < length; i++)
    //     {
    //         // printf("%i : %c \n",i , key[i]);
    //         if ((pass == 1) && ( (key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z')))
    //         {
    //             for (j = i + 1 ; j < length+1 ; j++)
    //                 printf("%i : %c = %c ,pass = %i \n",j , key[i],key[j], pass);
    //                 if ((pass == 1) && (key[i] == key[j])) // || (key[i]+diff == key[j] || key[i] == key[j]+diff))
    //                 {

    //                     pass = 3;
    //                     printf("AAAAAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH %i : %c = %c ,pass = %i \n",j , key[i],key[j], pass);
    //                 }
    //                 else
    //                 {
    //                     pass = 1;
    //                 }
    //         }
    //         else if (pass == 1)
    //         {
    //             pass = 2;
    //         }
    //     }
    // }




    if (pass == 2)
    {
        return 2;
        // Key must contain 26 characters
    }
    else if (pass == 1)
    {
        return 1;
    }
    else if (pass == 3)
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void run_substitution(string key)
{
    // well, assuming the key is 26 different characters
    // and returning a letter in the state that it was
    // capital stayes capital...
    int new_char;
    // string s = "A string";
    int diff = 'A' - 'a';
    // printf("%c\n", (s[0]-diff));

    // for everyletter in the given string... oh - 1) get a sting:
    string user_str = get_string("plaintext: ");  // \n
    // for every letter in the string check if it's upper or lower.... mmm....
    printf("ciphertext: ");
    int length = strlen(user_str);
    for (int i = 0; i < length; i++)
    {
        //  is it a lowercase letter?
        if (user_str[i] >= 'a' && user_str[i] <= 'z')
        {
            new_char = user_str[i] - 'a';
            new_char = key[new_char];
            // check if the new letter is lower case
            if (new_char >= 'a' && new_char <= 'z')
            {
                printf("%c", new_char);
            }
            else
            {
                new_char = new_char - diff;
                printf("%c", new_char);
            }
        }
        // is it Upper case?
        else if (user_str[i] >= 'A' && user_str[i] <= 'Z')
        {
            new_char = user_str[i] - 'A';
            new_char = key[new_char];
            // check if the new letter is upper case
            if (new_char >= 'A' && new_char <= 'Z')
            {
                printf("%c", new_char);
            }
            else
            {
                new_char = new_char + diff;
                printf("%c", new_char);
            }
        }
        // else keep the char.
        else
        {
            printf("%c", user_str[i]);
        }
    }

    printf("\n");


}
// int main(string arg)
// {
//     string key = get_string("");
//     printf("the str: %s\n",key);
// }

// make substitution
// ./substitution
