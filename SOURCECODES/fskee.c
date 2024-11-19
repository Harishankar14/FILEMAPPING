#include <stdio.h>

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Reposition to 10th byte from the beginning
    fseek(file, 10, SEEK_SET);

    // Read a character from the new position
    char c = fgetc(file);
    printf("Character at 10th byte: %c\n", c);

    fclose(file);
    return 0;
}
