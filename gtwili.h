/* ============================================================
                   GTK+ Widget Library
Copyright (C) 2016  Morteza Nourelahi Alamdari (Mortezaipo)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
============================================================ */
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef GtkWidget *gtwili;

GtkWidget* create_window(char *title, int width, int height, GtkWidget *header, bool enable_scrolling, char *icon_path, bool is_parent);
GtkWidget* create_headerbar(char *title, int items_count, ...);
GtkWidget* create_button(char *title, char *name);
GtkWidget* create_bigbutton(char *title, char *description, char *name);
GtkWidget* create_input(char *placeholder, char *value, bool is_multiline, int max_length, char *name, int width, int height);
GtkWidget* create_switchbox(bool is_active);
GtkWidget* create_label(char *text, bool is_title);
GtkWidget* create_alert(char *title, char *description, char *name);

char* get_entry_text(GtkWidget *textbox, bool is_multiline);
int get_switch_value(GtkWidget *switchbox);

void gtwili_init(int argc, char *argv[]);
void gtwili_render();

char* create_title_text(char *title);
