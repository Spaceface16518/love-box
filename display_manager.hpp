//
// Created by amrit on 5/6/21.
//

#ifndef LOVE_BOX_DISPLAY_MANAGER_HPP
#define LOVE_BOX_DISPLAY_MANAGER_HPP


#include <string>
#include <fonts.h>

class DisplayManager {
private:
    void clear();

    static constexpr auto font = &Font8;

    void paintString(const std::string *quote);

    void paintBackground();

    const std::string backgroundImageName = "background";

    const std::string foregroundImageName = "foreground";

    void selectImage(const std::string &name);


public:
    DisplayManager();

    void show(std::string *quote);

    virtual ~DisplayManager();

};


#endif //LOVE_BOX_DISPLAY_MANAGER_HPP
