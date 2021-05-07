#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <GUI_Paint.h>
#include <EPD_2in9d.h>
#include "display_manager.hpp"

void DisplayManager::show(std::string *quote) {
    // update the foreground image
    paintString(quote);

    // clear the physical canvas
    clear();

    // display the layers on the physical screen
    EPD_2IN9D_Display((uint8_t *) backgroundImageName.c_str());
    EPD_2IN9D_Display((uint8_t *) foregroundImageName.c_str());
}


inline void DisplayManager::clear() {
    EPD_2IN9D_Clear();
}

DisplayManager::DisplayManager() {
    // initialize physical display
    EPD_2IN9D_Init();

    // initialize paint buffers
    #define INIT_BUF(name) Paint_NewImage((uint8_t *) name.c_str(), EPD_2IN9D_WIDTH, EPD_2IN9D_HEIGHT, 0, WHITE)
    INIT_BUF(backgroundImageName);
    INIT_BUF(foregroundImageName);

    // initialize background image buffer
    selectImage(backgroundImageName);
    paintBackground();
}

DisplayManager::~DisplayManager() {
    EPD_2IN9D_Sleep();
}

inline void DisplayManager::selectImage(const std::string &name) {
    Paint_SelectImage((uint8_t *) name.c_str());
}

void DisplayManager::paintString(const std::string *quote) {
    selectImage(foregroundImageName);
    Paint_Clear(WHITE);
    Paint_DrawString_EN(0, 0, quote->c_str(), font, BLACK, WHITE);
}

void DisplayManager::paintBackground() {
    selectImage(backgroundImageName);
    Paint_Clear(WHITE);
    // load an image in the background?
}

#pragma clang diagnostic pop