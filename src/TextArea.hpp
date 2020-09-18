#pragma once

#include <gtkmm/drawingarea.h>
using Glib::ustring;

/// A widget that can be used to display text.
///
/// This works by being a custom drawing area, and doing the job of laying out
/// and drawing text more or less manually.
class TextArea : public Gtk::DrawingArea {
    ustring _text;
    /// Clear graphical context of this drawing area
    ///
    /// @param ctx a reference to the drawing context
    /// @param width the width of the rectangle to draw
    /// @param height the height of the rectangle to draw
    void clear(const Cairo::RefPtr<Cairo::Context> &ctx, int width, int height);
    /// Draw the main text of this component over the graphical context
    ///
    /// @param ctx a reference to the drawing context
    void draw_text(const Cairo::RefPtr<Cairo::Context> &ctx);

  protected:
    /// A custom implementation of the drawing callback for the area.
    ///
    /// We override this to be able to render the stuff we want to render when
    /// it's time to draw things.
    ///
    /// @param ctx a reference to the drawing context
    bool on_draw(const Cairo::RefPtr<Cairo::Context> &ctx) override;

    /// A callback for when this widget receives focus
    ///
    /// Useful for displaying the input cursor again, and things like that.
    bool on_focus_in_event(GdkEventFocus *) override;

    /// A callback for when this widget loses focus
    ///
    /// Useful for no longer displaying the text cursor, and things like that
    bool on_focus_out_event(GdkEventFocus *) override;

  public:
    /// Construct a new TextArea.
    TextArea(const char *text);
    /// We want to be able to call the superclass's destructor
    virtual ~TextArea();
};
