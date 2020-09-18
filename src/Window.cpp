#include "./Window.hpp"
#include <iostream>

Window::Window() : _text_area("Hello -> World!") {
    // Sets the border width of the window.
    set_border_width(10);

    add(_text_area);
    _text_area.show();
}

Window::~Window() {
}
