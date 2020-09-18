#include "./TextArea.hpp"

// The constructor doesn't need to do anything
TextArea::TextArea(const char *text) : _text(text) {
}

// We still need to keep this around, so that the super class destructs
TextArea::~TextArea() {
}

void TextArea::clear(const Cairo::RefPtr<Cairo::Context> &ctx, int width,
                     int height) {
    // We just draw a black rectangle
    ctx->set_source_rgb(0.0, 0.0, 0.0);
    ctx->rectangle(0.0, 0.0, width, height);
    ctx->fill();
}

void TextArea::draw_text(const Cairo::RefPtr<Cairo::Context> &ctx) {
    ctx->set_source_rgb(1.0, 1.0, 1.0);
    Pango::FontDescription font{};
    font.set_family("JetBrains Mono");
    font.set_size(14000);
    auto layout = create_pango_layout(_text);
    layout->set_font_description(font);
    int text_width;
    int text_height;
    layout->get_pixel_size(text_width, text_height);
    layout->show_in_cairo_context(ctx);
}

bool TextArea::on_draw(const Cairo::RefPtr<Cairo::Context> &ctx) {
    auto allocation = get_allocation();
    auto width = allocation.get_width();
    auto height = allocation.get_height();

    clear(ctx, width, height);

    draw_text(ctx);
    return true;
}
