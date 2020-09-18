#include "./Window.hpp"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "Example");

    Window window{};

    return app->run(window);
}
