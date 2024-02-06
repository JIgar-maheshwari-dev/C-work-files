#include"head.h"
#include<string.h>

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

	    if(!(strcmp(selected_protocol,"NFS")))
		NFS_func();
        }
    }

    g_free(selected_protocol);
}

