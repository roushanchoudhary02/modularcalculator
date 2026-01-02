#include <stdio.h>
#include <stdlib.h>

// Structure to hold operation information
typedef struct {
    const char* name;
    void (*handler)();
} Operation;

// Function prototypes
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);
int modulo(int a, int b);
float power(float base, int exponent);
int factorial(int n);

void handleAddition();
void handleSubtraction();
void handleMultiplication();
void handleDivision();
void handleModulo();
void handlePower();
void handleFactorial();
void displayMenu();
void clearScreen();
void executeOperation(int choice);
void showExitMessage();

// Array of operations
Operation operations[] = {
    {"Addition", handleAddition},
    {"Subtraction", handleSubtraction},
    {"Multiplication", handleMultiplication},
    {"Division", handleDivision},
    {"Modulo", handleModulo},
    {"Power", handlePower},
    {"Factorial", handleFactorial}
};

const int NUM_OPERATIONS = sizeof(operations) / sizeof(operations[0]);

int main() {
    int choice;
    
    clearScreen();
    printf("==================================\n");
    printf("      MODULAR CALCULATOR\n");
    printf("==================================\n");
    
    while (1) {
        displayMenu();
        printf("Enter your choice (1-%d, or %d to exit): ", 
               NUM_OPERATIONS + 1, NUM_OPERATIONS + 1);
        scanf("%d", &choice);
        
        while(getchar() != '\n'); // Clear input buffer
        
        if (choice == NUM_OPERATIONS + 1) {
            showExitMessage();
            break;
        }
        
        if (choice < 1 || choice > NUM_OPERATIONS) {
            printf("Invalid choice! Please try again.\n");
        } else {
            executeOperation(choice - 1);
        }
        
        printf("\nPress Enter to continue...");
        while(getchar() != '\n');
        clearScreen();
    }
    
    return 0;
}

void executeOperation(int choice) {
    // Call the appropriate handler function
    operations[choice].handler();
}

void displayMenu() {
    int i;
    
    printf("\n==================================\n");
    printf("           MENU\n");
    printf("==================================\n");
    
    for (i = 0; i < NUM_OPERATIONS; i++) {
        printf("%d. %s\n", i + 1, operations[i].name);
    }
    printf("%d. Exit\n", NUM_OPERATIONS + 1);
    printf("==================================\n");
}

// Handler functions (same as before)
void handleAddition() {
    float num1, num2;
    
    printf("\n--- %s ---\n", operations[0].name);
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("%.2f + %.2f = %.2f\n", num1, num2, add(num1, num2));
}

void handleSubtraction() {
    float num1, num2;
    
    printf("\n--- %s ---\n", operations[1].name);
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("%.2f - %.2f = %.2f\n", num1, num2, subtract(num1, num2));
}

void handleMultiplication() {
    float num1, num2;
    
    printf("\n--- %s ---\n", operations[2].name);
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("%.2f * %.2f = %.2f\n", num1, num2, multiply(num1, num2));
}

void handleDivision() {
    float num1, num2;
    
    printf("\n--- %s ---\n", operations[3].name);
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    
    if (num2 != 0) {
        printf("%.2f / %.2f = %.2f\n", num1, num2, divide(num1, num2));
    } else {
        printf("Error: Division by zero is not allowed!\n");
    }
}

void handleModulo() {
    int num1, num2;
    
    printf("\n--- %s ---\n", operations[4].name);
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    if (num2 != 0) {
        printf("%d %% %d = %d\n", num1, num2, modulo(num1, num2));
    } else {
        printf("Error: Division by zero is not allowed!\n");
    }
}

void handlePower() {
    float base;
    int exponent;
    
    printf("\n--- %s ---\n", operations[5].name);
    printf("Enter base and exponent: ");
    scanf("%f %d", &base, &exponent);
    printf("%.2f ^ %d = %.2f\n", base, exponent, power(base, exponent));
}

void handleFactorial() {
    int num;
    
    printf("\n--- %s ---\n", operations[6].name);
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    if (num >= 0) {
        printf("%d! = %d\n", num, factorial(num));
    } else {
        printf("Error: Factorial is not defined for negative numbers!\n");
    }
}

// Mathematical functions (same as before)
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }
int modulo(int a, int b) { return a % b; }

float power(float base, int exponent) {
    float result = 1.0;
    int i, isNegative = 0;
    
    if (exponent < 0) {
        isNegative = 1;
        exponent = -exponent;
    }
    
    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    
    return isNegative ? 1.0 / result : result;
}

int factorial(int n) {
    int result = 1;
    int i;
    
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    
    return result;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showExitMessage() {
    printf("\nThank you for using the calculator. Goodbye!\n");
}