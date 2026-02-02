/*
 * stats.c
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stats.h"

/**
 * Update the stats
 * @param stats	the histogram
 * @param str	the string used to update the histogram
 */
void updateStats(wordstats_t *stats, char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char c = tolower(str[i]);
            stats->letterCounts[c - 'a']++;

            if (c == 'a' || c == 'e' || c == 'i' ||
                c == 'o' || c == 'u') {
                stats->vowelCounts++;
            } else {
                stats->consonantCounts++;
            }
        }
    }

	char *token = strtok(str, " \t\n");
    while (token != NULL) {
        stats->wordCount++;
        token = strtok(NULL, " \t\n");
	}
}

void printStats(wordstats_t *stats){
    int totalLetters = stats->vowelCounts + stats->consonantCounts;

    double avg = 0.0;
    if (stats->wordCount > 0) {
        avg = (double) totalLetters / stats->wordCount;
    }

    double vowelPct = 0.0;
    double consonantPct = 0.0;
    if (totalLetters > 0) {
        vowelPct = (double) stats->vowelCounts / totalLetters * 100.0;
        consonantPct = (double) stats->consonantCounts / totalLetters * 100.0;
    }

    printf("\n");
    printf("Words = %d , Average Word Length = %.2f\n",
           stats->wordCount, avg);
    printf("Vowels = %d (%.2f%%), Consonants = %d (%.2f%%), Total= %d\n\n",
           stats->vowelCounts, vowelPct,
           stats->consonantCounts, consonantPct,
           totalLetters);
	
};
void printHistogram(wordstats_t *stats){
	int max = 0;

    for (int i = 0; i < 26; i++) {
        if (stats->letterCounts[i] > max) {
            max = stats->letterCounts[i];
        }
    }

    for (int row = max; row > 0; row--) {
        for (int col = 0; col < 26; col++) {
            if (stats->letterCounts[col] >= row) {
                printf("*  ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 26; i++) {
        printf("%c  ", 'a' + i);
    }
    printf("\n");

    for (int i = 0; i < 26; i++) {
        printf("%d  ", stats->letterCounts[i]);
    }
    printf("\n\n"); 
};
