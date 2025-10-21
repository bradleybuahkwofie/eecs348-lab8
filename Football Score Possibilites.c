/* 
 * EECS 348 - Lab 8: Football Score Possibilities
 * Lists all combinations of NFL scoring plays that sum to a given score.
 * Sentinel: enter 1 to stop.
 * Valid scoring plays: 8 (TD + 2pt), 7 (TD + FG), 6 (TD), 3 (FG), 2 (Safety).
 * Robustness: handles non-integer input and negative scores (invalid).
 *
 * Spec references:
 *  - Program repeats until user enters 1. (Description-2.pdf)
 *  - Print all combinations for each provided score. (Description-2.pdf)
 */

#include <stdio.h>

static void flush_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* discard */ }
}

int main(void) {
    const int TD2 = 8; 
    const int TDFG = 7;  
    const int TD = 6;    
    const int FG = 3;    
    const int SF = 2;    

    while (1) {
        int score;
        printf("Enter the NFL score (Enter 1 to stop): ");

    
        if (scanf("%d", &score) != 1) {
            printf("Invalid input: please enter an integer.\n");
            flush_stdin();
            continue;
        }
        
        if (score == 1) {
            break;
        }
        
        // Negative is invalid (explicitly required). Zero is allowed (only 0 of each play).
        if (score < 0) {
            printf("Invalid score: negatives are not allowed.\n");
            continue;
        }

        // Compute and print combinations
        int found = 0;
        for (int a = 0; a <= score / TD2; ++a) {            // a = count of TD+2 (8)
            for (int b = 0; b <= score / TDFG; ++b) {       // b = count of TD+FG (7)
                for (int c = 0; c <= score / TD; ++c) {     // c = count of TD (6)
                    for (int d = 0; d <= score / FG; ++d) { // d = count of 3pt FG
                        int used = a*TD2 + b*TDFG + c*TD + d*FG;
                        if (used > score) break;            // small pruning
                        int remaining = score - used;
                        if (remaining % SF == 0) {          // e = count of safeties (2)
                            int e = remaining / SF; {          
                            int e = remaining / SF;
                            // Print in the style shown by the sample (labels preserved)
                            // Example line format mirrors sample output ordering:
                            // "X TD + 2pt, Y TD + FG, Z TD, W 3pt FG, V Safety"
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   a, b, c, d, e);
                            found = 1;
                        }
                    }
                }
            }
        }
        if (!found) {
            // If no combinations sum to score, say so (not strictly required but helpful)
            printf("No combinations produce %d.\n", score);
        }
    }

    return 0;
}

