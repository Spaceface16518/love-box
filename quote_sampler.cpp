//
// Created by amrit on 5/6/21.
//

#include "quote_sampler.hpp"
#include "quotes.hpp"

std::string *QuoteSampler::next() {
    size_t choice;
    // clear if we've gone through all of them
    if (history.size() >= NUM_QUOTES) {
        history.clear();
    }
    // choose randomly but guard against double-dipping
    do {
        choice = distribution(rng);
    } while (history.count(choice) == 1);
    history.insert(choice);

    return &quotes[choice];
}
