#include <gtk/gtk.h>

void notebook(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *notebook;
    GtkWidget *page1, *page2;
    GtkWidget *label1, *label2;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    notebook = gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(window), notebook);

    page1 = gtk_label_new("Page 1");
    page2 = gtk_label_new("Page 2");

    label1 = gtk_label_new("This is page 1");
    label2 = gtk_label_new("This is page 2");

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), label1, page1);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), label2, page2);

    gtk_widget_show_all(window);

    gtk_main();

}

