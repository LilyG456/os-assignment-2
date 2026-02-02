/*
 * stats.h
 */

#ifndef STATS_H_
#define STATS_H_

// TODO word stats constants
#define MAX_WORD_LENGTH 20


// TODO word stats struct
typedef struct {
    int wordCount;
    int vowelCounts;
    int consonantCounts;
    int letterCounts[26];
} wordstats_t;

// TODO functions declarations
void updateStats(wordstats_t *stats, char *str);
void printStats(wordstats_t *stats);
void printHistogram(wordstats_t *stats);

#endif /* STATS_H_ */
