#include <stdio.h>
#include <stdlib.h>

// https://blog.heycoach.in/handling-serialization-and-deserialization-in-c/

typedef struct {
    int id;
    char name[50];
} Person;

void serialize(Person *p, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fwrite(p, sizeof(Person), 1, file);
    fclose(file);
}

void deserialize(Person *p, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fread(p, sizeof(Person), 1, file);
    fclose(file);
}

int main() {
    Person A = {1, "John Doe"};
    serialize(&A, "person.dat");

    Person B = {};
    deserialize(&B, "person.dat");
    printf("ID: %d, Name: %s\n", B.id, B.name);

    return 0;
}
