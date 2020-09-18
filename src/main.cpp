#include "./Window.hpp"
#include <gtkmm.h>
#include <gtkmm/window.h>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "Example");

    Window window{};

    return app->run(window);
}
