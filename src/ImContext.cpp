#include "./ImContext.hpp"
#include <iostream>

static void cb(GtkIMContext *, const gchar *str) {
    std::cout << str << '\n';
}

ImContext::ImContext() {
    _ctx = gtk_im_context_simple_new();
    g_signal_connect(_ctx, "commit", G_CALLBACK(cb), NULL);
}

ImContext::~ImContext() {
    g_object_unref(_ctx);
}

bool ImContext::on_key_press(GdkEventKey *key_event) {
    return gtk_im_context_filter_keypress(_ctx, key_event);
}
