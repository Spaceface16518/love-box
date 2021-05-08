//
// Created by amrit on 5/6/21.
//

#ifndef LOVE_BOX_QUOTE_SAMPLER_HPP
#define LOVE_BOX_QUOTE_SAMPLER_HPP


#include <random>
#include <unordered_set>

class QuoteSampler {
private:
    std::default_random_engine rng;

    std::uniform_int_distribution<size_t> distribution;

    std::unordered_set<size_t> history;

    std::vector<char *> quotes;

public:
    QuoteSampler();

    char *next();
};


#endif //LOVE_BOX_QUOTE_SAMPLER_HPP
