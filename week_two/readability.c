#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int key_test(char* key);
string encrypt_message(string message, char** key);


int main(int argc, char** argv)
{
    // if less or more than 1 argument passed, print error and return 1
    if(argc > 2 || argc == 1)
    {
        printf("You need to pass in exactly 1 encryption key\n");
        return 1;
    }
    //If key is invalid print error and return 1.
    if(key_test(argv[1]) == 1)
    {
        printf("Key must meet the following requirements: (1) contain 26 chars, (2) contain alphabetice characters only, contain each letter at least once\n");
        return 1;
    }
    //prompt user for string
    string message = get_string("plaintext: ");

    //encrypt the text, preserving case
    string encrypted_message = encrypt_message(message, argv);

    //output ciphertext and print newline
    printf("%s\n", encrypted_message);
    return 0;

}

int key_test(char* key)
{
    printf("%s\n", key);

    //does key contain 26 chars
    int length = strlen(key);
    if(length != 26)
    {
        printf("length failed");
        return 1;
    }
    printf("Passed length test");
    //does key contain only alphabetic chars
    int isalpha = isalpha(key);
    printf("%i", isalpha);
    if(isalpha == 0)
    {
        printf("alpha test failed");
        return 1;
    }
    printf("Passed alpha test");
    //does key contain every letter in alphabet at least once
    int alpha[26] = {0};
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        char letter = key[i];
        printf("%c", letter);
        int value = (int)toupper(letter) - 65;
        if (alpha[value] == 0)
        {
            alpha[value]++;
        }
    }

    for(int i = 0; i < 26; i++) {
        sum += alpha[i];
    }

    if (sum == 26)
    {

        return 0;
    }
    printf("does not contain every letter of alphabet");
    return 1;
}

string encrypt_message(string message, char** key)
{
    return "Hello";
}