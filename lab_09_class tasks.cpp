// Question 1

#include <stdio.h>
#include <string.h>

int main() {
    char feedback[256];
    char updated[512] = "";
    
    // Get feedback input from the user
    printf("Enter customer feedback message: ");
    if (fgets(feedback, sizeof(feedback), stdin) != NULL) {
        // Remove the trailing newline character added by fgets, if present
        feedback[strcspn(feedback, "\n")] = '\0';
    }

    // 1. Count the total number of characters using strlen
    size_t total_chars = strlen(feedback);
    printf("\n--- Analysis Report ---\n");
    printf("Total characters in message: %zu\n", total_chars);

    // 2. Find if the word "bad" or "good" exists using strstr
    char *bad_found = strstr(feedback, "bad");
    char *good_found = strstr(feedback, "good");

    if (bad_found != NULL) {
        printf("Keyword Check: The word \"bad\" was found.\n");
    } else {
        printf("Keyword Check: The word \"bad\" was NOT found.\n");
    }

    if (good_found != NULL) {
        printf("Keyword Check: The word \"good\" was found.\n");
    } else {
        printf("Keyword Check: The word \"good\" was NOT found.\n");
    }

    // 3. Replace the word "bad" with "not good" using strcpy and strcat logic
    char *p = feedback;
    char *match;

    while ((match = strstr(p, "bad")) != NULL) {
        // Temporarily null-terminate at the match position to copy the prefix
        *match = '\0';
        strcat(updated, p);
        strcat(updated, "not good");
        
        // Advance past the word "bad" (length 3)
        p = match + 3;
        
        // Restore the original character to preserve the source string integrity
        *match = 'b';
    }
    
    // Append any remaining text after the last occurrence of "bad"
    strcat(updated, p);

    // Print the final updated review
    printf("Updated Review: %s\n", updated);

    return 0;
}


// Question 2


#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 10
#define MAX_NAME_LENGTH 50

int main() {
    char names[NUM_STUDENTS][MAX_NAME_LENGTH];
    char temp[MAX_NAME_LENGTH];

    // Input 10 student names
    printf("Enter the names of %d students:\n", NUM_STUDENTS);
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("Student %d: ", i + 1);
        if (fgets(names[i], sizeof(names[i]), stdin) != NULL) {
            // Remove the trailing newline character added by fgets
            names[i][strcspn(names[i], "\n")] = '\0';
        }
    }

    // Sort names alphabetically using Bubble Sort, strcmp, and strcpy
    for (int i = 0; i < NUM_STUDENTS - 1; i++) {
        for (int j = 0; j < NUM_STUDENTS - i - 1; j++) {
            // Compare adjacent names
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap names[j] and names[j + 1] using strcpy and a temporary buffer
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    // Display the sorted list of student names
    printf("\n--- Sorted Student Names (Alphabetical Order) ---\n");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}


// Question 3


#include <stdio.h>
#include <string.h>

int main() {
    char email[100];
    char domain[50];

    // Get employee email input from the user
    printf("Enter employee email address (e.g., user@rehbartech.com): ");
    if (fgets(email, sizeof(email), stdin) != NULL) {
        // Remove the trailing newline character added by fgets
        email[strcspn(email, "\n")] = '\0';
    }

    // 1. Locate the '@' character using strchr
    char *at_symbol = strchr(email, '@');

    if (at_symbol != NULL) {
        // 2. Extract the domain using strcpy 
        // at_symbol points to '@', so at_symbol + 1 points to the start of the domain
        strcpy(domain, at_symbol + 1);

        // Display the results
        printf("\n--- Extraction Result ---\n");
        printf("Email: %s\n", email);
        printf("Extracted Domain: %s\n", domain);
    } else {
        printf("\nError: Invalid email address. The '@' symbol was not found.\n");
    }

    return 0;
}
