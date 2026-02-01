// a*
// a*b+
// abb

#include <stdio.h>
#include <string.h>

#define NUM_STATES 7
#define NUM_INPUTS 3
#define MAX_LEN 100

// DFA states
enum { D0, D1, D2, D3, D4, D5, DEAD };

// Input mapping: a -> 0, b -> 1, other -> 2
int get_input(char c) {
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    return 2; // invalid input
}

// Accepting states with token labels
const char* accepting_tokens[NUM_STATES] = {
    "a*",        // D0
    "a*",        // D1
    "a*b+",      // D2
    "a*",        // D3
    "a*b+",      // D4
    "a*b+, abb", // D5
    NULL         // DEAD
};

int main() {
    // DFA transition table
    int next_state[NUM_STATES][NUM_INPUTS] = {
        /* D0 */ { D1, D2, DEAD },
        /* D1 */ { D3, D4, DEAD },
        /* D2 */ { DEAD, D2, DEAD },
        /* D3 */ { D3, D2, DEAD },
        /* D4 */ { DEAD, D5, DEAD },
        /* D5 */ { DEAD, D2, DEAD },
        /* DEAD */{ DEAD, DEAD, DEAD }
    };

    char str[MAX_LEN];

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) {
        printf("Input error\n");
        return 1;
    }

    // Remove trailing newline if present
    str[strcspn(str, "\n")] = '\0';

    int state = D0;

    for (int i = 0; str[i] != '\0'; i++) {
        int input = get_input(str[i]);
        state = next_state[state][input];

        if (state == DEAD)
            break;
    }

    // Final acceptance check
    if (state != DEAD && accepting_tokens[state] != NULL) {
        printf("\"%s\" Accepted by DFA → Token: %s\n", str, accepting_tokens[state]);
    } else {
        printf("\"%s\" Rejected by all patterns\n", str);
    }

    return 0;

}


// a*
// a*b+
// abb

#include <stdio.h>
#include <string.h>

#define NUM_STATES 7
#define NUM_INPUTS 3
#define MAX_LEN 100

// DFA states
enum { D0, D1, D2, D3, D4, D5, DEAD };

// Input mapping: a -> 0, b -> 1, other -> 2
int get_input(char c) {
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    return 2; // invalid input
}

// Accepting states with token labels
const char* accepting_tokens[NUM_STATES] = {
    "a*",        // D0
    "a*",        // D1
    "a*b+",      // D2
    "a*",        // D3
    "a*b+",      // D4
    "a*b+, abb", // D5
    NULL         // DEAD
};

int main() {
    // DFA transition table
    int next_state[NUM_STATES][NUM_INPUTS] = {
        /* D0 */ { D1, D2, DEAD },
        /* D1 */ { D3, D4, DEAD },
        /* D2 */ { DEAD, D2, DEAD },
        /* D3 */ { D3, D2, DEAD },
        /* D4 */ { DEAD, D5, DEAD },
        /* D5 */ { DEAD, D2, DEAD },
        /* DEAD */{ DEAD, DEAD, DEAD }
    };

    char str[MAX_LEN];

    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                          DFA LEXER                           ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n\n");
    printf("╔════════════════════╦════════════════════╦════════════════════╗\n");
    printf("║ Token Pattern      ║ Token Status       ║ Input String       ║\n");
    printf("╠════════════════════╬════════════════════╬════════════════════╣");

    while (1){
        printf("\tEnter a string: ");

        if (!fgets(str, sizeof(str), stdin)) {
            printf("\tInput error\n");
            return 1;
        }

        // Remove trailing newline if present
        str[strcspn(str, "\n")] = '\0';

        if(strcmp(str, "exit") == 0){
            printf("║ %-18s ║ %-18s ║ %-18s ║\n", "-", "Exit", str);
            printf("╚════════════════════╩════════════════════╩════════════════════╝\n");
            break;
        }

        int state = D0;

        for (int i = 0; str[i] != '\0'; i++) {
            int input = get_input(str[i]);
            state = next_state[state][input];

            if (state == DEAD)
                break;
        }

        // Final acceptance check
        if (state != DEAD && accepting_tokens[state] != NULL) {
            printf("║ %-18s ║ %-18s ║ %-18s ║\n", accepting_tokens[state], "ACCEPTED", str);
        } else {
            printf("║ %-18s ║ %-18s ║ %-18s ║\n", "-", "REJECTED", str);
        }
        printf("╠════════════════════╬════════════════════╬════════════════════╣");

    }

    return 0;
}
