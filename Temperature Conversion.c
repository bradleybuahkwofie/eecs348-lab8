/*
 * EECS 348 - Lab 8
 * Task 2: Temperature Conversion Program
 *
 * Description:
 *   This program converts temperatures among Celsius, Fahrenheit, and Kelvin.
 *   The user enters a numeric temperature followed by a unit character (C, F, or K).
 *   It prints the equivalent temperatures in all three scales, a category, and an advisory.
 *   The program stops when the user enters 999 as the numeric value.
 *
 *   Example input:
 *     Enter temperature (or 999 to stop): 32 F
 *     Output:
 *       0.00 C = 32.00 F = 273.15 K
 *       Category: Cold
 *       Advisory: Dress warmly!
 */

#include <stdio.h>
#include <ctype.h>

void categorize(double celsius);

int main(void) {
    double temp;
    char unit;

    printf("Temperature Conversion Program\n");
    printf("--------------------------------\n");

    while (1) {
        printf("Enter temperature followed by unit (C/F/K), or 999 to stop: ");

        // Try to read numeric and char input
        if (scanf("%lf %c", &temp, &unit) != 2) {
            // Input format wrong
            printf("Invalid input. Please enter like '100 C', '212 F', or '300 K'.\n");
            while (getchar() != '\n'); // flush invalid input
            continue;
        }

        // Sentinel check (matches the original behavior)
        if ((int)temp == 999) {
            printf("Exiting program.\n");
            break;
        }

        // Normalize unit
        unit = toupper((unsigned char)unit);

        // Prepare variables for all scales
        double c, f, k;

        if (unit == 'C') {
            // Absolute zero check in Celsius
            if (temp < -273.15) {
                printf("Invalid temperature: below absolute zero (-273.15 C).\n");
                continue;
            }
            c = temp;
            f = c * 9.0 / 5.0 + 32.0;
            k = c + 273.15;
        }
        else if (unit == 'F') {
            // Absolute zero check in Fahrenheit
            if (temp < -459.67) {
                printf("Invalid temperature: below absolute zero (-459.67 F).\n");
                continue;
            }
            f = temp;
            c = (f - 32.0) * 5.0 / 9.0;
            k = c + 273.15;
        }
        else if (unit == 'K') {
            // Absolute zero check in Kelvin
            if (temp < 0.0) {
                printf("Invalid temperature: Kelvin cannot be negative (>= 0 K).\n");
                continue;
            }
            k = temp;
            c = k - 273.15;
            f = c * 9.0 / 5.0 + 32.0;
        }
        else {
            printf("Invalid unit '%c'. Use C, F, or K only.\n", unit);
            // flush any extra input on the line just in case
            while (getchar() != '\n');
            continue;
        }

        // Display results (single line as per lab style), then category/advisory
        printf("\nConverted Temperatures:\n");
        printf("  %.2f C = %.2f F = %.2f K\n", c, f, k);
        categorize(c);
        printf("--------------------------------\n");
    }

    return 0;
}

/*
 * categorize - prints weather category and advisory based on Celsius temperature.
 */
void categorize(double celsius) {
    if (celsius < 0.0) {
        printf("  Category: Freezing Cold\n");
        printf("  Advisory: Stay indoors and bundle up!\n");
    }
    else if (celsius < 15.0) {
        printf("  Category: Cold\n");
        printf("  Advisory: Dress warmly!\n");
    }
    else if (celsius < 30.0) {
        printf("  Category: Moderate\n");
        printf("  Advisory: Comfortable weather. Enjoy your day!\n");
    }
    else if (celsius < 40.0) {
        printf("  Category: Hot\n");
        printf("  Advisory: Stay hydrated and wear light clothing.\n");
    }
    else {
        printf("  Category: Extreme Heat\n");
        printf("  Advisory: Avoid outdoor activity and drink plenty of water!\n");
    }
}
