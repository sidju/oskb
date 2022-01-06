#include <gtk-layer-shell.h>

#include "keeb.h"
#include "keymap.h"
#include "ui.h"

static keeb_handle kb_handle;
static int layer = 0;

void key_callback(GtkWidget*, gpointer);

void perform_redraw(GtkGrid* grid) {
  // Get each tile in the keyboard in turn and replace it
  for(int i = 0; i < KEYMAP_NR_ROWS; i++) {
    for(int j = 0; j < (sizeof(base_keymap) / (sizeof(key_data) * KEYMAP_NR_ROWS)); j++ ) {
      GtkWidget* child = gtk_grid_get_child_at(grid, j, i);
      if(child != NULL) {
        gtk_container_remove( GTK_CONTAINER(grid), child);
      }

      const key_data* tmp = &base_keymap[j][i];
      if(layer == -1) {
        tmp = &num_keymap[j][i];
      }
      else if(layer == -2) {
        tmp = &sym_keymap[j][i];
      }
      GtkWidget* key;
      if(tmp->type == 1) {
        key = gtk_toggle_button_new_with_label(tmp->label);
      }
      else {
        key = gtk_button_new_with_label(tmp->label);
      }
      g_signal_connect(key, "clicked", G_CALLBACK(key_callback), (gpointer) tmp);
      gtk_grid_attach( GTK_GRID(grid), key, j, i, tmp->width, 1);
    }
  }
  // Make it visible
  gtk_widget_show_all( GTK_WIDGET(grid) );
}
void key_callback(GtkWidget* widget, gpointer data) {
  // Cast the data into its real type
  key_data* tmp = (key_data*) data;
  // Get parent, since many branches use it
  GtkGrid* grid = GTK_GRID(gtk_widget_get_parent(widget));
  // Match the type
  switch(tmp->type) {
    case 1:
      // Modifier
      // Instead of tapping, read the toggle button and propagate its state
      gboolean state = gtk_toggle_button_get_active( GTK_TOGGLE_BUTTON(widget) );
      keeb_set_key(&kb_handle, tmp->keycode, state);
      break;
    case -1:
      // Toggle numbers layer
      if(layer == -1){ layer = 0; }
      else{ layer = -1; }
      perform_redraw(grid);
      break;
    case -2:
      // Toggle symbols layer
      if(layer == -2){ layer = 0; }
      else{ layer = -2; }
      perform_redraw(grid);
      break;
    default:
      // Normal keycode
      // Then use the virtual keyboard device to create the given event
      keeb_send_key(&kb_handle, tmp->keycode);
      break;
  }
}
static void activate(GtkApplication* app, gpointer user_data) {
  GtkWidget* window = gtk_application_window_new(app);

  // Create a special wayland layer to render to
  // This enables us to dock to bottom of screen
  gtk_layer_init_for_window( GTK_WINDOW(window) );
  // Prevent other windows covering the window
  gtk_layer_set_layer( GTK_WINDOW(window), GTK_LAYER_SHELL_LAYER_BOTTOM);
  gtk_layer_auto_exclusive_zone_enable( GTK_WINDOW(window) );
  // Bind to bottom of screen
  gtk_layer_set_anchor( GTK_WINDOW(window), GTK_LAYER_SHELL_EDGE_BOTTOM, TRUE );

  // Draw the basics of the ui
  // To hold more than one key we need a grid
  GtkWidget* grid = gtk_grid_new();
  gtk_container_add( GTK_CONTAINER(window), grid);
  // The redraw is adjusted for a potentially empty grid, so we use that
  perform_redraw( GTK_GRID(grid) );

  // And make the window visible
  gtk_widget_set_visible(window, TRUE);
}

int start_ui(int argc, char** argv) {
  // Create application object
  GtkApplication *app;
  app = gtk_application_new("se.sidju.oskb", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  // Instantiate the static keeb object stored in this file as well
  kb_handle = keeb_init();
  // Hand over execution into the UI object
  int status = g_application_run( G_APPLICATION(app), argc, argv);
  // When returning, cleanup and return status
  keeb_destroy(kb_handle);
  g_object_unref(app);
  return status;
}
