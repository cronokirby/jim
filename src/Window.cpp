#include "./Window.hpp"
#include <iostream>

Window::Window() : _button("Hello World") {
    // Sets the border width of the window.
    set_border_width(10);

    // When the button receives the "clicked" signal, it will call the
    // on_button_clicked() method defined below.
    _button.signal_clicked().connect(
        sigc::mem_fun(*this, &Window::on_button_clicked));

    // This packs the button into the Window (a container).
    add(_button);

    // The final step is to display this newly created widget...
    _button.show();
}

Window::~Window() {
}

void Window::on_button_clicked() {
    std::cout << "Hello World" << std::endl;
}
