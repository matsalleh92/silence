#include <gtk/gtk.h>
 
GtkWidget *bmc_image;
GtkWidget *layout;
 
int main(int argc, char *argv[])
{
    GtkBuilder		*builder; 
	GtkWidget 		*window;
 
    gtk_init(&argc, &argv);
 
    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "BasicWindow.glade", NULL);
 
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);
    
    //get the layout container..
    layout = GTK_WIDGET(gtk_builder_get_object(builder, "layout_container"));
 
    g_object_unref(builder);
 
    gtk_widget_show(window);                
    gtk_main();
 
    return 0;
}
 
//called when window is made..
void on_btn_clicked()
{ 
    //load the image..
    bmc_image = gtk_image_new_from_file("cat.jpg");
    gtk_container_add (GTK_CONTAINER(layout), bmc_image);
    gtk_widget_show(bmc_image);                
}
 
// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
