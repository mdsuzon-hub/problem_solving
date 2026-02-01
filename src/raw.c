// This program implements a DFA (Deterministic Finite Automaton) to recognize
// the patterns: "a*", "a*b+", and "abb" in input strings.

#include <stdio.h>
#include <string.h>

// Maximum length of input string
#define MAX_LEN 100

// DFA states
enum { 
    D0,   // Start state, also accepts "a*" (empty string allowed)
    D1,   // After reading 1 'a', still accepts "a*"
    D2,   // State for "a*b+" pattern (strings ending with at least one 'b')
    D3,   // After reading multiple 'a's ("aa", "aaa", ...), still accepts "a*"
    D4,   // After reading "ab" or "aab", matches "a*b+" pattern
    D5,   // After reading "abb" or "aabb", matches "a*b+" and specifically "abb"
    DEAD  // Trap state for invalid inputs or dead ends; non-accepting
};

// Function to map input characters to DFA input indices
// 'a' -> 0, 'b' -> 1, others -> 2 (invalid input)
int get_input(char c) {
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    return 2; // invalid input triggers DEAD state
}

// Array of accepting states with token labels
// Each index corresponds to a DFA state
const char* accepting_tokens[] = {
    "a*",        // D0: Accepts empty string or only 'a's
    "a*",        // D1: Accepts strings like "a", "aa", ...
    "a*b+",      // D2: Accepts strings like "b", "bb", "ab", "aab", ...
    "a*",        // D3: Accepts strings like "aa", "aaa", ...
    "a*b+",      // D4: Accepts strings like "ab", "aab", ...
    "a*b+, abb", // D5: Accepts strings like "abb", "aabb", ...
    NULL         // DEAD state: not accepting
};

int main() {
    // DFA transition table
    // Rows = current states (D0-D5, DEAD)
    // Columns = input symbols ('a' = 0, 'b' = 1, other = 2)
    int next_state[][3] = {
        /* D0 */ { D1, D2, DEAD }, // From D0: 'a'->D1, 'b'->D2, other->DEAD
        /* D1 */ { D3, D4, DEAD }, // From D1: 'a'->D3, 'b'->D4, other->DEAD
        /* D2 */ { DEAD, D2, DEAD }, // From D2: 'a'->DEAD, 'b'->D2, other->DEAD
        /* D3 */ { D3, D2, DEAD }, // From D3: 'a'->D3, 'b'->D2, other->DEAD
        /* D4 */ { DEAD, D5, DEAD }, // From D4: 'a'->DEAD, 'b'->D5, other->DEAD
        /* D5 */ { DEAD, D2, DEAD }, // From D5: 'a'->DEAD, 'b'->D2, other->DEAD
        /* DEAD */{ DEAD, DEAD, DEAD } // DEAD state loops to itself
    };

    char str[MAX_LEN]; // Buffer for input string

    printf("Enter a string: ");
    if (!fgets(str, sizeof(str), stdin)) { // Read input safely
        printf("Input error\n");
        return 1;
    }

    // Remove trailing newline character if present
    str[strcspn(str, "\n")] = '\0';

    int state = D0; // Start state

    // Process each character of the input string
    for (int i = 0; str[i] != '\0'; i++) {
        int input = get_input(str[i]); // Map character to DFA input
        state = next_state[state][input]; // Move to next state

        if (state == DEAD) // If DEAD state is reached, stop
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
// abbc

#include <stdio.h>
#include <string.h>

#define NUM_STATES 8
#define NUM_INPUTS 4
#define MAX_LEN 100

// DFA States
enum { 
    D0,   // Start state (a*)
    D1,   // After reading 'a' (a*)
    D2,   // In b+ loop (a*b+)
    D3,   // After reading "ab"
    D4,   // After reading "abb"
    D5,   // After reading "abbc" (final accepting state)
    DEAD  // Trap state
};

// Input mapping
// a -> 0, b -> 1, c -> 2, other -> 3
int get_input(char c) {
    if (c == 'a') return 0;
    if (c == 'b') return 1;
    if (c == 'c') return 2;
    return 3;
}

// Accepting states with tokens
const char* accepting_tokens[NUM_STATES] = {
    "a*",        // D0
    "a*",        // D1
    "a*b+",      // D2
    NULL,        // D3
    NULL,        // D4
    "abbc",      // D5
    NULL         // DEAD
};

int main() {

    // DFA transition table
    int next_state[NUM_STATES][NUM_INPUTS] = {
        /* D0 */ { D1, D2, DEAD, DEAD },
        /* D1 */ { D1, D3, DEAD, DEAD },
        /* D2 */ { DEAD, D2, DEAD, DEAD },
        /* D3 */ { DEAD, D4, DEAD, DEAD },
        /* D4 */ { DEAD, DEAD, D5, DEAD },
        /* D5 */ { DEAD, DEAD, DEAD, DEAD },
        /* DEAD */{ DEAD, DEAD, DEAD, DEAD }
    };

    char str[MAX_LEN];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int state = D0;

    for (int i = 0; str[i] != '\0'; i++) {
        int input = get_input(str[i]);
        state = next_state[state][input];
        if (state == DEAD)
            break;
    }

    if (state != DEAD && accepting_tokens[state]) {
        printf("\"%s\" Accepted → Token: %s\n", str, accepting_tokens[state]);
    } else {
        printf("\"%s\" Rejected\n", str);
    }

    return 0;
}


