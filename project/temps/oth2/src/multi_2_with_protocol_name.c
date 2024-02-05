#include <gtk/gtk.h>
#include"head.h"


void protocol_selected(GtkComboBox *widget, gpointer data) {
    gchar *selected_protocol = NULL;
    
    // Get the active item index
    int active_index = gtk_combo_box_get_active(widget);
    
    if (active_index >= 0) {
        // Get the model associated with the combo box
        GtkTreeModel *model = gtk_combo_box_get_model(widget);
        
        // Get the active item from the model
        GtkTreeIter iter;
        if (gtk_combo_box_get_active_iter(widget, &iter)) {
            // Get the value of the first column (in this case, the protocol name)
            gtk_tree_model_get(model, &iter, 0, &selected_protocol, -1);
            g_print("Selected Protocol: %s\n", selected_protocol);
        }
    }
    
    g_free(selected_protocol);
}



void file_selected(GtkWidget* widget, gpointer data) {
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

void destroy(GtkWidget* widget, gpointer data) {
    gtk_main_quit();
}

void manpage(int argc, char* argv[]) {
    GtkWidget* window;
    GtkWidget* notebook;
    GtkWidget* protocol_page;
    GtkWidget* send_page;
    GtkWidget* receive_page;
    GtkWidget* send_button;
    GtkWidget* receive_button;
    GtkWidget* send_entry;
    GtkWidget* receive_folder_entry;
    GtkWidget* protocol_combo_box;
    GtkListStore *protocol_store;
    GtkTreeIter iter;
    
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400); // Set window size
    
    notebook = gtk_notebook_new();
    
    // Create the "Protocol" page
    protocol_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), protocol_page, gtk_label_new("Select Protocol"));
    
    protocol_store = gtk_list_store_new(1, G_TYPE_STRING);
    gtk_list_store_append(protocol_store, &iter);
    gtk_list_store_set(protocol_store, &iter, 0, "HTTP", -1);
    gtk_list_store_append(protocol_store, &iter);
    gtk_list_store_set(protocol_store, &iter, 0, "SFTP", -1);
    gtk_list_store_append(protocol_store, &iter);
    gtk_list_store_set(protocol_store, &iter, 0, "NFS", -1);
    gtk_list_store_append(protocol_store, &iter);
    gtk_list_store_set(protocol_store, &iter, 0, "Samba", -1);
    
    protocol_combo_box = gtk_combo_box_new_with_model(GTK_TREE_MODEL(protocol_store));
    g_object_unref(protocol_store);
    
    GtkWidget *renderer;
    renderer = gtk_cell_renderer_text_new();
    gtk_cell_layout_pack_start(GTK_CELL_LAYOUT(protocol_combo_box), renderer, TRUE);
    gtk_cell_layout_set_attributes(GTK_CELL_LAYOUT(protocol_combo_box), renderer, "text", 0, NULL);
    
    gtk_box_pack_start(GTK_BOX(protocol_page), protocol_combo_box, FALSE, FALSE, 0);
    g_signal_connect(protocol_combo_box, "changed", G_CALLBACK(protocol_selected), NULL);

    // Create the "Send" page
    send_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    send_button = gtk_button_new_with_label("Select File");
    send_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(send_page), send_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(send_page), send_button, FALSE, FALSE, 0);
    g_object_set_data(G_OBJECT(send_button), "entry", send_entry);
    g_signal_connect(send_button, "clicked", G_CALLBACK(file_selected), GINT_TO_POINTER(GTK_FILE_CHOOSER_ACTION_OPEN));
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), send_page, gtk_label_new("Send"));

    // Create the "Receive" page
    receive_page = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    receive_button = gtk_button_new_with_label("Select Folder");
    receive_folder_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(receive_page), receive_folder_entry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(receive_page), receive_button, FALSE, FALSE, 0);
    g_object_set_data(G_OBJECT(receive_button), "folder_entry", receive_folder_entry);
    g_signal_connect(receive_button, "clicked", G_CALLBACK(file_selected), GINT_TO_POINTER(GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER));
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), receive_page, gtk_label_new("Receive"));

    gtk_container_add(GTK_CONTAINER(window), notebook);

    gtk_widget_show_all(window);

    gtk_main();
    
}

