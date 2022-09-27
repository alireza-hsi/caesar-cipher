#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




string encipher(string text, int k);



char c_t[1000];
string cth;
string key_s;

int main(int argc, string argv[])
{
    
    if (argc == 2)
    {
        key_s = argv[1];
        for (int i = 0; i < strlen(key_s); i++)
        {
            if (isalpha(key_s[i]))
            {
                printf("Usage : ./caesar key\n");
                return 1;
            }
            //printf("%s\n%s\n%s\n", argv[0], argv[1],argv[2]);
            if (argv[2] != (NULL))
            {
                printf("Usage : ./caesar key\n");
                return 1;
            }
            
        }
        
        int key = atoi(key_s);

        string ptext = get_string("Plaintext: ");
        //char c_t[strlen(ptext)];

        string ctext = encipher(ptext, key);

        printf("ciphertext: %s\n", ctext);
    }
    
    else
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    
}
   




string encipher(string text, int k)
{
    //string c_t;
    int ascii;
    for (int i = 0; i < strlen(text); i++)
    {
        char t = text[i];
        ascii = t;
        if (islower(t))
        {
            
            c_t[i] = (((ascii - 97) + k) % 26) + 97;
        }
        else if (isupper(t))
        {
            c_t[i] = (((ascii - 65) + k) % 26) + 65;
        }
        else
        {
            c_t[i] = t;
        }
    }
    cth = c_t;
    return cth;
}