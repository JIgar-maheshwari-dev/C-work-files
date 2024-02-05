#include<gtk/gtk.h>

void send_button_func(GtkWidget* widget, gpointer data) {
    GtkFileChooserAction action = GPOINTER_TO_INT(data);
    GtkWidget* entry = NULL;
    const gchar* dialog_title = NULL;
    
    if (action == GTK_FILE_CHOOSER_ACTION_OPEN) {
        entry = g_object_get_data(G_OBJECT(widget), "entry");
        dialog_title = "Select a file";
    } else if (action == GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER) {
        entry = g_object_get_data(G_OBJECT(widget), "folder_entry");
        dialog_title = "Select a folder";
    }   
        
    // Create a new file chooser dialog
    GtkWidget* dialog = gtk_file_chooser_dialog_new(dialog_title, 
                                                     GTK_WINDOW(gtk_widget_get_toplevel(widget)), 
                                                     action, 
                                                     "Cancel", GTK_RESPONSE_CANCEL, 
                                                     "Select", GTK_RESPONSE_ACCEPT, 
                                                     NULL);
        
    // Run the file chooser dialog
    gint result = gtk_dialog_run(GTK_DIALOG(dialog));
        
    // If the user selects a file or folder
    if (result == GTK_RESPONSE_ACCEPT) {
        // Get the selected file or folder path
        gchar* filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
            
        // Set the text of the entry widget to the selected file or folder path
        gtk_entry_set_text(GTK_ENTRY(entry), filename);
            
        // Free the filename string
        g_free(filename);
    }   
        
    // Destroy the file chooser dialog
    gtk_widget_destroy(dialog);
}



