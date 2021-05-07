#include <algorithm>
#include <pico/time.h> // NOLINT(modernize-deprecated-headers)
#include <chrono>
#include "quote_sampler.hpp"
#include "display_manager.hpp"

typedef std::chrono::duration<uint32_t, std::ratio<3600, 1>> hours;
typedef std::chrono::duration<uint32_t, std::ratio<1, 1000>> millis;
constexpr millis delay = hours(3);

int main() {
    QuoteSampler sampler;
    DisplayManager displayManager;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
    while (true) {
        displayManager.show(sampler.next());

        sleep_ms(delay.count());
    }
}
#pragma clang diagnostic pop
