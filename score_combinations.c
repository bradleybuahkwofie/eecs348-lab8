

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

        if (score < 0) {
            printf("Invalid score: negatives are not allowed.\n");
            continue;
        }


        int found = 0;
        for (int a = 0; a <= score / TD2; ++a) {
            for (int b = 0; b <= score / TDFG; ++b) {
                for (int c = 0; c <= score / TD; ++c) {     
                    for (int d = 0; d <= score / FG; ++d) { 
                        int used = a*TD2 + b*TDFG + c*TD + d*FG;
                        if (used > score) break;            
                        int remaining = score - used;
                        if (remaining % SF == 0) {          
                            int e = remaining / SF;

                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   a, b, c, d, e);
                            found = 1;
                        }
                    }
                }
            }
        }

        if (!found) {
    
            printf("No combinations produce %d.\n", score);
        }
    }

    return 0;
}
