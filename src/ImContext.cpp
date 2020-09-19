#include "./ImContext.hpp"
#include <iostream>

void commit_cb(GtkIMContext *, const gchar *str, gpointer data) {
    auto ctx = reinterpret_cast<ImContext *>(data);
    ctx->_signal_commit.emit(str);
}

ImContext::ImContext() {
    _ctx = gtk_im_context_simple_new();
    g_signal_connect(_ctx, "commit", G_CALLBACK(commit_cb), this);
}

ImContext::~ImContext() {
    g_object_unref(_ctx);
}

sigc::signal<void, ustring> ImContext::signal_commit() {
    return _signal_commit;
}

bool ImContext::on_key_press(GdkEventKey *key_event) {
    return gtk_im_context_filter_keypress(_ctx, key_event);
}
