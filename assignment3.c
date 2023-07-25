#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10

struct Book {
    int isbn;
    char title[100];
};

struct Book hashTable[TABLE_SIZE];

// Hash function 1: Returns the primary hash index
int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

// Hash function 2: Returns the secondary hash index
int hashFunction2(int key) {
    return 7 - (key % 7);
}

// Double hashing function: Returns the next probing position
int doubleHashing(int key, int i) {
    return (hashFunction1(key) + i * hashFunction2(key)) % TABLE_SIZE;
}

// Insert a new book into the hash table
void insertBook(int isbn, char title[]) {
    struct Book newBook;
    newBook.isbn = isbn;
    strcpy(newBook.title, title);

    int i = 0;
    int index;
    do {
        index = doubleHashing(isbn, i);
        if (hashTable[index].isbn == -1) {
            hashTable[index] = newBook;
            printf("Book with ISBN %d inserted successfully.\n", isbn);
            return;
        }
        i++;
    } while (i < TABLE_SIZE);

    printf("Hash table is full. Cannot insert book with ISBN %d.\n", isbn);
}

// Search for a book by its ISBN
void searchBook(int isbn) {
    int i = 0;
    int index;
    do {
        index = doubleHashing(isbn, i);
        if (hashTable[index].isbn == isbn) {
            printf("Book with ISBN %d found. Title: %s\n", isbn, hashTable[index].title);
            return;
        }
        i++;
    } while (hashTable[index].isbn != -1 && i < TABLE_SIZE);

    printf("Book with ISBN %d not found.\n", isbn);
}

// Delete a book from the hash table
void deleteBook(int isbn) {
    int i = 0;
    int index;
    do {
        index = doubleHashing(isbn, i);
        if (hashTable[index].isbn == isbn) {
            hashTable[index].isbn = -1;
            strcpy(hashTable[index].title, "");
            printf("Book with ISBN %d deleted successfully.\n", isbn);
            return;
        }
        i++;
    } while (hashTable[index].isbn != -1 && i < TABLE_SIZE);

    printf("Book with ISBN %d not found. Cannot delete.\n", isbn);
}

// Display all the books in the hash table
void displayBooks() {
    printf("\nLibrary Book Collection:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isbn != -1) {
            printf("ISBN: %d, Title: %s\n", hashTable[i].isbn, hashTable[i].title);
        }
    }
    printf("\n");
}

int main() {
    // Initialize the hash table with empty values
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isbn = -1;
        strcpy(hashTable[i].title, "");
    }

    int choice, isbn;
    char title[100];

    do {
        printf("Menu:\n");
        printf("1. Insert a new book\n");
        printf("2. Search for a book by ISBN\n");
        printf("3. Delete a book by ISBN\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ISBN: ");
                scanf("%d", &isbn);
                printf("Enter title: ");
                getchar(); // Consume the newline character from the previous input
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = '\0'; // Remove the trailing newline
                insertBook(isbn, title);
                break;
            case 2:
                printf("Enter ISBN to search: ");
                scanf("%d", &isbn);
                searchBook(isbn);
                break;
            case 3:
                printf("Enter ISBN to delete: ");
                scanf("%d", &isbn);
                deleteBook(isbn);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
