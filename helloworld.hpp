#ifndef HELLOWORLD_HPP
#define HELLOWORLD_HPP

#include <cabl/cabl.h>

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Minerer : public sl::cabl::Client
{
public:  
  void init();

  void disconnected();
  void buttonChanged(sl::cabl::Device::Button button_, bool buttonState_, bool shiftPressed_);
  void encoderChanged(unsigned encoder_, bool valueIncreased_, bool shiftPressed_);
  void keyChanged(unsigned index_, double value_, bool shiftPressed);
  void controlChanged(unsigned pot_, double value_, bool shiftPressed);

  void initDevice();
  void render();
};

class HelloWorld : public Gtk::Window
{
	public:
		HelloWorld();
		virtual ~HelloWorld();

	protected:
		//Signal handlers:
		void on_button_clicked();

		//Member widgets:
		Gtk::Button m_button;
};

#endif // HELLOWORLD_HPP
