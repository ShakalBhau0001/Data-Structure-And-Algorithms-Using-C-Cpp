#include <stdio.h>

float addition(float, float);
float subtraction(float, float);
float multiplication(float, float);
float division(float, float);
int modulus(int, int);

int main()
{
    int choice;
    float num1, num2;

    do
    {
        printf("\n===== ARITHMETIC OPERATIONS =====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        }

        switch (choice)
        {
            case 1:
                printf("Addition = %.2f\n",
                addition(num1, num2));
                break;

            case 2:
                printf("Subtraction = %.2f\n",
                subtraction(num1, num2));
                break;

            case 3:
                printf("Multiplication = %.2f\n",
                multiplication(num1, num2));
                break;

            case 4:
                if (num2 == 0)
                    printf("Error: Division by zero is not allowed.\n");
                else
                    printf("Division = %.2f\n",
                    division(num1, num2));
                break;

            case 5:
                if ((int)num2 == 0)
                    printf("Error: Modulus by zero is not allowed.\n");
                else
                    printf("Modulus = %d\n",modulus((int)num1, (int)num2));
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

float addition(float a, float b) {return a + b;}
float subtraction(float a, float b) {return a - b;}
float multiplication(float a, float b) {return a * b;}
float division(float a, float b) {return a / b;}
int modulus(int a, int b) {return a % b;}
