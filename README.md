# Random Password Generator

## Description
This C program generates random passwords of a user-specified length. It effectively utilizes basic concepts such as arrays, dynamic memory allocation, and random number generation.

## Author
[\[Chieng Sisovin\]](https://github.com/sisovin)


## Observations
### Dynamic Memory Allocation
- Dynamically allocated memory for the password, providing flexibility.
- Correctly frees the memory after use to prevent memory leaks.

### Random Seed
- Uses `srand(time(NULL) * getpid())` to ensure a unique seed every time the program runs.

### Character Types
- Divides the character pool into digits, lowercase, uppercase, and symbols to ensure a diverse password.

## Potential Improvements
### Password Diversity
- Ensures at least one character from each type (digits, lowercase, uppercase, symbols) appears in the password.

### Input Validation
- Adds checks to handle non-numeric or out-of-range inputs for robustness.

### Use of `getchar`
- Clears the input buffer using `getchar()` to avoid issues with extra newline characters after `scanf`.

### Security
- Considers using a cryptographically secure random number generator (e.g., `/dev/urandom` on Unix-based systems) for applications requiring strong security.

## Improved Version
```c
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
```

### Key Changes
- Added enforcement of diversity by pre-filling one character from each type.
- Introduced shuffling for better randomness.
- Included a minimum length check to ensure the password can accommodate all character types.

## Make the debug directory
Before running the compilation, make a debug directory and run the following command:
```sh
mkdir debug
```

## Compilation
To compile the project, run the following command:
```sh
gcc src/password_generator.c -o debug/password_generator
```

## Execution
To execute the compiled program, run:
```sh
.\debug\password_generator.exe
```

### Example
```sh
PS D:\CGroupProjects\password_generator> .\debug\password_generator.exe
Length: 32
Password: 9(S3(k737(Hm42*%1Qrel$^6i3(8IVp*
```

## Steps to Push to GitHub
1. Initialize a new repository or navigate to an existing one.
2. Add the files to the repository:
    ```sh
    git add .
    ```
3. Commit the changes:
    ```sh
    git commit -m "Add random password generator program"
    ```
4. Push the changes to GitHub:
    ```sh
    git push origin main
    ```
