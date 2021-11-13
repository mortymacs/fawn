/**
 *                    GTK+ Widget Library
 * Copyright (C) 2016  Morteza NourelahiAlamdari (mortymacs <m@0t1.me>)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * ERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * NU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * long with this program.  If not, see <http://www.gnu.org/licenses/>.**/
#ifndef FAWN_H_
#define FAWN_H_

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define AUTO 0

enum PaneStyle {
    VERTICAL, HORIZONTAL
};

/**
 * Text utilities
 */
char *NewTitleText(char *title) {
    char *tmp_title = malloc(sizeof(char *) * strlen(title) + 18);
    sprintf(tmp_title, "<big><b>%s</b></big>", title);
    return tmp_title;
}

/**
 * Window widget
 */
GtkWidget *NewWindow(char *title,
                     uint size[2],
                     GtkWidget *header,
                     bool enable_scrolling,
                     char *icon_path,
                     bool is_parent) {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    void *tmp = NULL;

    gtk_window_set_title(GTK_WINDOW(window), title);
    gtk_window_set_default_size(GTK_WINDOW(window), size[0], size[1]);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    if (is_parent == FALSE)
        gtk_window_set_keep_above(GTK_WINDOW(window), TRUE);

    if (is_parent == TRUE) {
        if (!icon_path)
            gtk_window_set_default_icon_from_file(icon_path, NULL);
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    } else {
        g_signal_connect(window, "destroy", G_CALLBACK(gtk_widget_destroy), NULL);
    }

    if (header != NULL) {
        gtk_window_set_titlebar(GTK_WINDOW(window), header);
    }

    if (enable_scrolling == TRUE) {
        GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
        GtkWidget *scroll_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
        GtkWidget *window_scroll = gtk_scrolled_window_new(NULL, NULL);
        gtk_container_add(GTK_CONTAINER(window), box);
        gtk_box_pack_start(GTK_BOX(box), window_scroll, TRUE, TRUE, 1);
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(window_scroll), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
        gtk_container_set_border_width(GTK_CONTAINER(window_scroll), 10);
        gtk_container_add(GTK_CONTAINER(window_scroll), scroll_box);
        tmp = (void *) scroll_box;
    } else {
        gtk_container_set_border_width(GTK_CONTAINER(window), 10);
        tmp = (void *) window;
    }
    gtk_widget_show_all(window);
    return (GtkWidget *) tmp;
}

/**
 * Header widget
 */
GtkWidget *NewHeaderBar(char *title, int items_count, ...) {
    GtkWidget *headerbar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(headerbar), title);
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(headerbar), TRUE);

    va_list btns;
    va_start(btns, items_count);
    for (int i = 0; i < items_count; i++) {
        gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), va_arg(btns, GtkWidget * ));
    }
    va_end(btns);

    return headerbar;
}


/**
 * Box container
 */
GtkWidget *NewBox(bool is_vertical, int rows) {
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, rows);
    gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
    return box;
}

/**
 * Button widget
 */
GtkWidget *NewButton(char *title, char *name) {
    GtkWidget *btn = gtk_button_new_with_label(title);
    gtk_widget_set_name(btn, name);
    return btn;
}

/**
 * Big Button widget
 */
GtkWidget *NewBigButton(char *title, char *description, char *name) {
    GtkWidget *btn = gtk_button_new();
    GtkWidget *title_lbl = gtk_label_new(NULL);
    GtkWidget *description_lbl = gtk_label_new(description);
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
    char *markup_title = NewTitleText(title);

    gtk_widget_set_name(btn, name);

    gtk_label_set_markup(GTK_LABEL(title_lbl), markup_title);
    gtk_widget_set_halign(title_lbl, GTK_ALIGN_START);
    gtk_widget_set_halign(description_lbl, GTK_ALIGN_START);

    gtk_box_pack_start(GTK_BOX(box), title_lbl, TRUE, TRUE, 1);
    gtk_box_pack_start(GTK_BOX(box), description_lbl, TRUE, TRUE, 1);
    gtk_container_add(GTK_CONTAINER(btn), box);

    free(markup_title);
    return btn;
}

/**
 * Switch widget
 */
GtkWidget *NewSwitchBox(bool is_active) {
    GtkWidget *switchbox = gtk_switch_new();
    if (is_active == TRUE)
        gtk_switch_set_active(GTK_SWITCH(switchbox), TRUE);
    return switchbox;
}

/**
 * Get switch widget value
 */
int GetSwitchValue(GtkWidget *switchbox) {
    if (gtk_switch_get_active(GTK_SWITCH(switchbox)) == TRUE)
        return 1;
    return 0;
}

/**
 * Input widget
 */
GtkWidget *
NewInput(char *placeholder, char *value, bool is_multiline, int max_length, char *name, int width, int height) {
    GtkWidget *entry;
    if (is_multiline == FALSE) {
        //Single line input
        entry = gtk_entry_new();
        gtk_entry_set_max_length(GTK_ENTRY(entry), max_length);
        if (placeholder != NULL)
            gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholder);
        if (value != NULL)
            gtk_entry_set_text(GTK_ENTRY(entry), value);
    } else {
        //Multi line input
        entry = gtk_text_view_new();

        gtk_widget_set_size_request(entry, width, height);
        gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(entry), GTK_TEXT_WINDOW_LEFT, 1);
        gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(entry), GTK_TEXT_WINDOW_RIGHT, 1);
        gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(entry), GTK_TEXT_WINDOW_TOP, 1);
        gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(entry), GTK_TEXT_WINDOW_BOTTOM, 1);

        gtk_text_view_set_accepts_tab(GTK_TEXT_VIEW(entry), TRUE);

        char *default_value = (value != NULL) ? value : placeholder;
        if (default_value != NULL) {
            GtkTextBuffer *bd = gtk_text_buffer_new(NULL);
            gtk_text_buffer_set_text(bd, default_value, strlen(default_value));
            gtk_text_view_set_buffer(GTK_TEXT_VIEW(entry), bd);
        }
    }
    gtk_widget_set_name(entry, name);
    return entry;
}

/**
 * Get input (entry widget) value.
 */
char *GetEntryText(GtkWidget *textbox, bool is_multiline) {
    char *text;
    if (is_multiline == TRUE) {
        GtkTextIter s, n;
        GtkTextBuffer *tb = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textbox));
        gtk_text_buffer_get_bounds(tb, &s, &n);
        text = gtk_text_buffer_get_text(tb, &s, &n, FALSE);
    } else {
        text = (char *) gtk_entry_get_text(GTK_ENTRY(textbox));
    }
    return text;
}

/**
 * Label widget.
 */
GtkWidget *NewLabel(char *text, bool is_title) {
    GtkWidget *label;
    label = gtk_label_new(NULL);
    if (is_title == TRUE) {
        char *tmp_title = NewTitleText(text);
        gtk_label_set_markup(GTK_LABEL(label), tmp_title);
        free(tmp_title);
    } else {
        gtk_label_set_text(GTK_LABEL(label), text);
    }
    return label;
}

/**
 * Alert widget.
 */
GtkWidget *NewAlert(char *title, char *description, char *name, bool is_title) {
    GtkWidget *t_label = gtk_label_new(NULL);

    if (is_title) {
        char *tmp_title = NewTitleText(title);
        gtk_label_set_markup(GTK_LABEL(t_label), tmp_title);
        free(tmp_title);
    } else {
        gtk_label_set_markup(GTK_LABEL(t_label), title);
    }
    GtkWidget *d_label = gtk_label_new(description);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_box_pack_start(GTK_BOX(box), t_label, TRUE, TRUE, 1);
    gtk_box_pack_start(GTK_BOX(box), d_label, TRUE, TRUE, 1);
    gtk_widget_set_name(box, name);

    gtk_widget_show_all(box);

    return box;
}

/**
 * Attach widgets.
 */
void Attach(GtkWidget *widget, GtkWidget *container) {
    gtk_container_add(GTK_CONTAINER(container), widget);
    gtk_widget_show_all(container);
}

/**
 * Connect widgets.
 */
void Action(GtkWidget *widget, char *event, void (*fn)(GtkWidget *, gpointer)) {
    g_signal_connect(G_OBJECT(widget), event, G_CALLBACK((*fn)), NULL);
}

/**
 * CSS & theme
 */
void LoadCss(char *path) {
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(css_provider, (const gchar *) path, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), \
                                            GTK_STYLE_PROVIDER(css_provider),
                                              GTK_STYLE_PROVIDER_PRIORITY_USER);
}

/**
 * Fawn
 */
void FawnInit(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
}

void FawnRender() {
    gtk_main();
}

#endif //FAWN_H_
