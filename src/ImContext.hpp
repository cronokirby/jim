#pragma once

#include <gtkmm/window.h>
using Glib::ustring;

/// A wrapper around Gtk's ImContext.
///
/// The point of this class is to be able to consume keyboard inputs, and
/// produce complete characters. For ASCII text, this might seem a bit pointless
/// at first, since every character can be typed in a single key stroke,
/// although potentially with a modifier. 'a' is just the key `a`, and 'A' is
/// just the key combination `SHIFT + a`.
///
/// On the other hand, some input methods require chords to produce a single
/// character. For example, if you use the alt-international keyboard for typing
/// English, then you're able to produce accented characters using a sequence of
/// keys. For example, 'ä' comes from `" a`. Languages like Japanese have even
/// more complicated input methods, where you first need to type in multiple
/// characters to get a phonetic syllable, but then multiple syllables can be
/// combined into a potential ideogram.
///
/// For example, to type '橋', meaning bridge, pronounced "ha shi", you'd need
/// to type in the characters `h a s h i` and then select 橋 out of the
/// possibilities, which would include homonyms like 箸 (chopsticks), 端 (edge)
/// and はし (the syllables themselves).
///
/// You wouldn't produce any input until the full sequence is typed out, and an
/// option is selected. On the other hand, you'd get intermediate feedback, such
/// as seeing the syllable 'は' as soon as you type it. This is why this class
/// likes to be informed about where the window and cursor is, so that it can
/// display this intermediate information at the right spot.
///
/// For some reason, GtkIMContext does not have a corresponding C++ wrapper in
/// gtkmm, so it's necessary to create this class.
class ImContext {
    /// The underlying object we're wrapping.
    ///
    /// This is the object whose functionality we're emulating, more or less,
    /// trying our best to make something more friendly to C++ usage.
    GtkIMContext *_ctx;

    /// A signal for when we emit the committed strings from the context
    sigc::signal<void, ustring> _signal_commit;

    /// A sort of hack to allow providing some kind of callback to
    /// GtkIMContext's commit signal.
    friend void commit_cb(GtkIMContext *, const gchar *str, gpointer data);

  public:
    ImContext();

    ~ImContext();

    /// This should be called when a new key press happens.
    ///
    /// The idea is that this im context will try to handle this key, and if it
    /// can't it's up to us to do something else with it. After handling enough
    /// keys, it will produce some input through signalling.
    ///
    /// @return true when this key has been handled
    bool on_key_press(GdkEventKey *key_event);

    /// A signal for when a string is committed.
    ///
    /// A string is committed when we've managed to combine multiple keys into
    /// an input string.
    sigc::signal<void, ustring> signal_commit();
};
