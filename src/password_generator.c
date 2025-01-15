
/*******************************************************************************
*
* Program: Random Password Generator
* 
* Description: Generates random passwords of a user-specified length using C.
*
* Author: [\Chieng Sisovin\][https://github.com/sisovin]
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    printf("Length: ");
    int length;
    scanf("%d", &length);
    if (length < 4) {
        printf("Password length must be >= 4 to ensure diversity!\n");
        return 1;
    }

    char *password = malloc(length + 1);
    if (!password) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    char *digits = "0123456789";
    char *lowers = "abcdefghijklmnopqrstuvwxyz";
    char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *symbols = "!@#$%^&*()";

    int digits_length = strlen(digits);
    int lowers_length = strlen(lowers);
    int uppers_length = strlen(uppers);
    int symbols_length = strlen(symbols);

    srand(time(NULL) * getpid());

    // Ensure at least one character from each category
    password[0] = digits[rand() % digits_length];
    password[1] = lowers[rand() % lowers_length];
    password[2] = uppers[rand() % uppers_length];
    password[3] = symbols[rand() % symbols_length];

    // Fill the rest of the password randomly
    for (int i = 4; i < length; i++) {
        int char_type = rand() % 4;
        if (char_type == 0)
            password[i] = digits[rand() % digits_length];
        else if (char_type == 1)
            password[i] = lowers[rand() % lowers_length];
        else if (char_type == 2)
            password[i] = uppers[rand() % uppers_length];
        else
            password[i] = symbols[rand() % symbols_length];
    }

    // Shuffle the password for randomness
    for (int i = 0; i < length; i++) {
        int swap_idx = rand() % length;
        char temp = password[i];
        password[i] = password[swap_idx];
        password[swap_idx] = temp;
    }

    password[length] = '\0';
    printf("Password: %s\n", password);

    free(password);
    return 0;
}
