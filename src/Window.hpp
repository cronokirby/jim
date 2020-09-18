#pragma once

#include <gtkmm/button.h>
#include <gtkmm/window.h>

/// A Class for the main window in our application.
///
/// This inherits from Gtk::Window, because it's essentially a customized
/// version of that, providing the extra behavior and content we want for our
/// application.
class Window : public Gtk::Window {
    /// The single button the user can press in our application
    Gtk::Button _button;

    /// A callback for when _button gets clicked
    void on_button_clicked();

  public:
    /// Create a new Window, without the need for any parameters
    Window();

    // We have a virtual destructor here to make sure that the parent stuff gets
    // cleaned up
    virtual ~Window();
};
