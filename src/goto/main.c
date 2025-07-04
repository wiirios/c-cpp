#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[20];
    char password[20];

    printf("your username");
    scanf("%19s", username);

    printf("your password");
    scanf("%19s", password);

    if (strcmp(username, "william") != 0) {
        goto err_username;
    }

    if (strcmp(password, "teste") != 0) {
        goto err_password;
    }

    printf("teste");
    return 0;

    err_username:
        printf("invalid username");
        return 1;

    err_password:
        printf("invalid password");
        return 1;
}
