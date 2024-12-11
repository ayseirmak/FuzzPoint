#include <stdio.h>
#include <math.h>

int main() {
    // Initialize variables
    float num1 = 5.0f; // Example fixed value
    float num2 = 3.0f; // Example fixed value
    float a;

    // Perform calculations and print results
    a = num1 + num2;
    printf("Sum: %f\n", a);

    // Infix operators
    printf("Addition: %f\n", num1 + num2);
    printf("Subtraction: %f\n", num1 - num2);
    printf("Multiplication: %f\n", num1 * num2);
    printf("Division: %f\n", num1 / num2);

    // Comparison operators
    printf("Comparisons:\n");
    printf("num1 < num2: %d\n", num1 < num2);
    printf("num1 <= num2: %d\n", num1 <= num2);
    printf("num1 == num2: %d\n", num1 == num2);
    printf("num1 >= num2: %d\n", num1 >= num2);
    printf("num1 > num2: %d\n", num1 > num2);
    printf("num1 != num2: %d\n", num1 != num2);

    printf("num1 < num1: %d\n", num1 < num1);
    printf("num1 <= num1: %d\n", num1 <= num1);
    printf("num1 == num1: %d\n", num1 == num1);
    printf("num1 >= num1: %d\n", num1 >= num1);
    printf("num1 > num1: %d\n", num1 > num1);
    printf("num1 != num1: %d\n", num1 != num1);

    printf("num2 < num1: %d\n", num2 < num1);
    printf("num2 <= num1: %d\n", num2 <= num1);
    printf("num2 == num1: %d\n", num2 == num1);
    printf("num2 >= num1: %d\n", num2 >= num1);
    printf("num2 > num1: %d\n", num2 > num1);
    printf("num2 != num1: %d\n", num2 != num1);

    // Assignment operators
    a = num1;
    a += num2;
    printf("After addition assignment: %f\n", a);

    a = num1;
    a -= num2;
    printf("After subtraction assignment: %f\n", a);

    a = num1;
    a *= num2;
    printf("After multiplication assignment: %f\n", a);

    a = num1;
    a /= num2;
    printf("After division assignment: %f\n", a);

    // Prefix operators
    printf("Prefix + operator: %f\n", +num1);
    printf("Prefix - operator: %f\n", -num1);

    // Type coercion and function usage
    float coercedValue = num1;
    printf("Coerced value: %f\n", coercedValue);
    printf("Sine of num1: %f\n", sin(num1));

    return 0;
}