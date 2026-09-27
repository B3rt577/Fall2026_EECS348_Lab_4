#include <stdio.h>

int main() {
    int score;
    
    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }
        
        if (score == 1) {
            break;
        }
        
        if (score < 2) {
            printf("Invalid score. Valid NFL scores are 2 or higher.\n");
            continue;
        }
        
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        
        for (int td8 = 0; td8 * 8 <= score; td8++) {
            for (int td7 = 0; td8 * 8 + td7 * 7 <= score; td7++) {
                for (int td6 = 0; td8 * 8 + td7 * 7 + td6 * 6 <= score; td6++) {
                    for (int fg3 = 0; td8 * 8 + td7 * 7 + td6 * 6 + fg3 * 3 <= score; fg3++) {
                        int remaining = score - (td8 * 8 + td7 * 7 + td6 * 6 + fg3 * 3);
                        if (remaining % 2 == 0) {
                            int safety2 = remaining / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                   td8, td7, td6, fg3, safety2);
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}