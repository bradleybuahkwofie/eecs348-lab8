#include <stdio.h>
#include <ctype.h>

int main(void) {
    double temp;
    char unit;

    printf("Temperature Conversion Program\n");
    printf("--------------------------------\n");

    while (1) {
        printf("Enter temperature followed by unit (C/F), or 999 to stop: ");

        // Try to read numeric and char input
        if (scanf("%lf %c", &temp, &unit) != 2) {
            // Input format wrong
            printf("Invalid input. Please enter like '100 C' or '212 F'.\n");
            while (getchar() != '\n'); // flush invalid input
            continue;
        }

        // Sentinel check
        if ((int)temp == 999) {
            printf("Exiting program.\n");
            break;
        }

        // Normalize unit
        unit = toupper(unit);

        // Compute conversion
        if (unit == 'C') {
            double f = temp * 9.0 / 5.0 + 32.0;
            printf("%.2f C = %.2f F\n", temp, f);
        }
        else if (unit == 'F') {
            double c = (temp - 32.0) * 5.0 / 9.0;
            printf("%.2f F = %.2f C\n", temp, c);
        }
        else {
            printf("Invalid unit '%c'. Use C or F only.\n", unit);
        }
    }

    return 0;
}