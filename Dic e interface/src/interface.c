#include <gtk/gtk.h>
#include "interface.h"
#include "arquivo.h"

static void input(GtkWidget *widget, gpointer data) {
    (void)widget;

    GtkEntry *entry = GTK_ENTRY(((GtkWidget **)data)[0]);
    GtkLabel *label = GTK_LABEL(((GtkWidget **)data)[1]);
	int	fd;
	char	*str;
	char	*meaning;

  	const char *word_source;
	word_source = gtk_entry_get_text(entry);

	if ((((char)word_source[0]) >= 'A' && ((char)word_source[0] <= 'Z'))
		|| (((char)word_source[0]) >= 'a' && ((char)word_source[0] <= 'z')))
	{
		fd = open_archive((char)word_source[0]);
		str = get_word(fd, word_source);
		if (!str)
			gtk_label_set_text(label, "palavra não encontrada!");
		else
		{
			meaning = print_meaning(fd);
	    	gtk_label_set_text(label, meaning);
			free(meaning);
		}
		free(str);
	}
	else
		gtk_label_set_text(label, "Entrada inválida!");
}

static	void	on_clear(GtkWidget *widget, gpointer data)
{
	(void)widget;

	GtkWidget	*entry = (((GtkWidget **)data)[0]);
	GtkWidget	*label = (((GtkWidget **)data)[1]);

	gtk_entry_set_text(GTK_ENTRY(entry), "");
	gtk_label_set_text(GTK_LABEL(label), "...");
}

void iniciar_interface(void) {
	
	gtk_init(NULL, NULL);
	GtkWidget *window, *box, *label, *botao, *entry, *clear;
	GtkWidget *widgets[2];

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Dicionário");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 150);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
	gtk_container_add(GTK_CONTAINER(window), box);
	
	entry = gtk_entry_new();
	clear = gtk_button_new_with_label("Apagar");
	botao = gtk_button_new_with_label("Buscar");
	label = gtk_label_new("...");

	gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), botao, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), clear, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(box), label, FALSE, FALSE, 0);

	widgets[0] = entry;
	widgets[1] = label;

	g_signal_connect(clear, "clicked", G_CALLBACK(on_clear), widgets);
	g_signal_connect(botao, "clicked", G_CALLBACK(input), widgets);

	gtk_widget_show_all(window);
	gtk_main();
}
