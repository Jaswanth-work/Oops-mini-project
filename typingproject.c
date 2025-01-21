#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to calculate accuracy
float calculateAccuracy(const char* target, const char* typed) {
    int targetLen = strlen(target);
    int typedLen = strlen(typed);
    int correctChars = 0;

    for (int i = 0; i < targetLen && i < typedLen; i++) {
        if (target[i] == typed[i]) {
            correctChars++;
        }
    }

    return ((float)correctChars / targetLen) * 100;
}

// Main function
int main() {
    const char sentence[] = "The quick brown fox jumps over the lazy dog.";
    char input[256];
    clock_t startTime, endTime;
    double typingTime;

    printf("Typing Speed Test\n");
    printf("-----------------\n");
    printf("Type the following sentence as quickly and accurately as possible:\n");
    printf("\"%s\"\n", sentence);

    printf("\nPress Enter to start...");
    getchar();  // Wait for Enter key

    printf("\nStart typing:\n");
    startTime = clock();  // Start time
    fgets(input, sizeof(input), stdin);  // Take user input
    endTime = clock();  // End time

    // Calculate typing time
    typingTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    // Calculate words per minute (WPM)
    int wordCount = 9;  // Predefined for the sentence
    double wordsPerMinute = (wordCount / typingTime) * 60;

    // Calculate accuracy
    float accuracy = calculateAccuracy(sentence, input);

    // Display results
    printf("\nResults:\n");
    printf("Time Taken: %.2f seconds\n", typingTime);
    printf("Typing Speed: %.2f words per minute (WPM)\n", wordsPerMinute);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}
