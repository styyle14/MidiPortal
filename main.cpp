#include "helloworld.hpp"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
	
	//Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("basic.glade");
	
	auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

	HelloWorld helloworld;
	Minerer minerer;

	//Shows the window and returns when it is closed.
	return app->run(helloworld);
}
