#include <gtk/gtk.h>

void on_button_clicked(GtkWidget *widget, gpointer label)
{
    /*这是gtk的一个函数，用来给Label设定文字*/
    gtk_label_set_text(GTK_LABEL(label), "你看，标签变了！");
}

int main(int argc, char *argv[])
{
    /*这些語句声明了一些组件变量，由于GTK是面向对象的，
所以都可以声明为GtkWidget，这也是习惯作法 */
    GtkBuilder *builder;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *label;

    /*每一个gtk程序都会用到这一句，用来初始化*/
    gtk_init(&argc, &argv);

    /*这个builder就是用来读取我们用Glade设计的界面的一个东西*/
    builder = gtk_builder_new();

    /*用下面这个gtk函数把abitno.glade的内容给builder*/
    gtk_builder_add_from_file(builder, "ui.glade", NULL);

    /*通过名字从abitno.glade中读取我们需要使用的组件*/
    window = GTK_WIDGET(gtk_builder_get_object(builder, "MainWindow"));
    button = GTK_WIDGET(gtk_builder_get_object(builder, "button"));
    label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));

    /*这是glib里的一个函数，用来把一个组件与一个函数关联起来，下面
这句就是把button和我们上面的那个on_button_clicked给关联了*/
    g_signal_connect(G_OBJECT(button), "clicked",
                     G_CALLBACK(on_button_clicked), (gpointer)label);

    /*这条語句就是自动把所有人信号处理函数都关联好*/
    gtk_builder_connect_signals(builder, NULL);

    /*因为我们已经不需要builder了，就释放builder的空间*/
    g_object_unref(G_OBJECT(builder));

    /*将window内所有的组件都显示出来，这们我们才能看见*/
    gtk_widget_show_all(window);

    /*这也是每一个gtk程序都要有的*/
    gtk_main();

    return 0;
}
