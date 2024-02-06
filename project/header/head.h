#include<gtk/gtk.h>

void destroy(GtkWidget* widget, gpointer data);
void start_page();

void send_button_func(GtkWidget* widget, gpointer data);
void rec_button_func(GtkWidget* widget, gpointer data);
void protocol_selected(GtkComboBox *widget, gpointer data);

void NFS_func();

extern GtkWidget* window;
extern GtkWidget* notebook;
extern GtkWidget* send_page;
extern GtkWidget* receive_page;
extern GtkWidget* send_button;
extern GtkWidget* receive_button;
extern GtkWidget* send_entry;
extern GtkWidget* receive_folder_entry;

