#include <stdio.h>

#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
void push(Stack* stack, int v, FILE* pushfile);

int pop(Stack* stack, FILE* popfile);

int main() {
    Stack stack;
    stack.top = -1;

    FILE* inputfile = fopen("input.txt", "r");
    if (inputfile == NULL) {
        printf("Error: could not open input file\n");
        exit(1);
    }
if (stack->top == -1) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    int popped = stack->items[stack->top];
    stack->top--;
    fprintf(popfile, "Popped %d from the stack\n", popped);
    return popped;
}

void print_stack(FILE* fp) {
    fprintf(fp, "Stack contents:");
    for (int i = top; i >= 0; i--) {
        fprintf(fp, " %d", stack[i]);
    }
    fprintf(fp, "\n");
}

int main() {
    FILE* stack_fp = fopen("stack.txt", "r");
    if (stack_fp == NULL) {
        printf("Error opening stack file.\n");
        return 1;
    }

    int data;
    printf("Enter elements to push (or -1 to stop):\n");
    while (fscanf(stack_fp, "%d", &data) != EOF) {
        printf("%d ", data);
        if (data != -1) {
            push(data);
        }
    }
    printf("\n");

    fclose(stack_fp);

    FILE* output_fp = fopen("output.txt", "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int option;
    do {
        printf("Select operation:\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Print stack\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element to push:\n");
                scanf("%d", &data);
                push(data);
                fprintf(output_fp, "Pushed element: %d\n", data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    fprintf(output_fp, "Popped element: %d\n", data);
                }
                break;
            case 3:
                print_stack(output_fp);
                break;
            case 4:
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 4);
    FILE* pushfile = fopen("pushlog.txt", "w");
    if (pushfile == NULL) {
        printf("Error: could not create push log file\n");
        exit(1);
    }

    FILE* popfile = fopen("poplog.txt", "w");
    if (popfile == NULL) {
        printf("Error: could not create pop log file\n");
        exit(1);
    }

    int n;
    while (fscanf(inputfile, "%d", &n) == 1) {
        push(&stack, n, pushfile);
    }

    fclose(inputfile);
    fclose(pushfile);

    while (stack.top != -1) {
        pop(&stack, popfile);
    }

    fclose(popfile);

    return 0;
}

void push(Stack* stack, int v, FILE* pushfile) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack->top++;
    stack->items[stack->top] = v;
    fprintf(pushfile, "Pushed %d onto the stack\n", v);
}

int pop(Stack* stack, FILE* popfile) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    int popped = stack->items[stack->top];
    stack->top--;
    fprintf(popfile, "Popped %d from the stack\n", popped);
    return popped;
}
void print_stack(FILE* fp) {
    fprintf(fp, "Stack contents:");
    for (int i = top; i >= 0; i--) {
        fprintf(fp, " %d", stack[i]);
    }
    fprintf(fp, "\n");
}
