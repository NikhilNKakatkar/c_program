#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

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

    fclose(output_fp);

    return 0;
}

