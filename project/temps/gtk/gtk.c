#include <gtk/gtk.h>

// Function to handle button click event
void on_button_clicked(GtkWidget *button, gpointer data) {
    // Get pointers to the entry widgets
    GtkWidget *entry1 = (GtkWidget *)data;
    GtkWidget *entry2 = (GtkWidget *)g_object_get_data(G_OBJECT(button), "entry2");
    
    // Get the text from the entry widgets
    const gchar *text1 = gtk_entry_get_text(GTK_ENTRY(entry1));
    const gchar *text2 = gtk_entry_get_text(GTK_ENTRY(entry2));
    
    // Convert text to integers
    int num1 = atoi(text1);
    int num2 = atoi(text2);
    
    // Perform addition
    int sum = num1 + num2;
    
    // Display the result
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "The sum is %d", sum);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 150);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    // Create two entry widgets for input
    GtkWidget *entry1 = gtk_entry_new();
    GtkWidget *entry2 = gtk_entry_new();
    GtkWidget *entry3 = gtk_entry_new();
    
    // Create a button for addition
    GtkWidget *button = gtk_button_new_with_label("Add");
    
    // Set up the layout
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_attach(GTK_GRID(grid), entry1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry2, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry3, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);
    gtk_container_add(GTK_CONTAINER(window), grid);
    
    // Connect the button click event
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), entry1);
    g_object_set_data(G_OBJECT(button), "entry2", entry2);
    
    // Show all widgets
    gtk_widget_show_all(window);
    
    // Run the main loop
    gtk_main();
    
    return 0;
}

