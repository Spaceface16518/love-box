//
// Created by amrit on 5/6/21.
//

#include "quote_sampler.hpp"

extern char _binary_quotes_txt_start;

extern char _binary_quotes_txt_end;

/**
 * This function is extremely low level and dangerous as it involves questionable manipulation of manually linked binary
 * data, many assumptions about types, and dubious raw pointers.
 */
QuoteSampler::QuoteSampler() {
    for (char *i = &_binary_quotes_txt_start, *start = i; i < &_binary_quotes_txt_end; ++i) {
        char b = *i;
        if (b == '\n') {
            // terminate c-string
            // NOTE: every day we stray further from god
            *i = '\0';
            // add string to list of quotes
            quotes.push_back(start);
            // update the start
            // NOTE: this won't go out of bounds because we'll reach the stop condition first
            start = i + 1;
        }
    }
}

char *QuoteSampler::next() {
    size_t choice;
    // clear if we've gone through all of them
    if (history.size() >= quotes.size()) {
        history.clear();
    }
    // choose randomly but guard against double-dipping
    do {
        choice = distribution(rng);
    } while (history.count(choice) == 1);
    history.insert(choice);

    return quotes[choice];
}
