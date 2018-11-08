#include "helloworld.hpp"
#include <iostream>

void Minerer::disconnected(){ }
void Minerer::buttonChanged(sl::cabl::Device::Button button_, bool buttonState_, bool shiftPressed_){
	std::cout << "Goodebye Moon!" << std::endl;
}
void Minerer::encoderChanged(unsigned encoder_, bool valueIncreased_, bool shiftPressed_){ }
void Minerer::keyChanged(unsigned index_, double value_, bool shiftPressed){ }
void Minerer::controlChanged(unsigned pot_, double value_, bool shiftPressed){ }
void Minerer::initDevice(){ }
void Minerer::render(){ }

HelloWorld::HelloWorld()
: m_button("Hello World")   // creates a new button with label "Hello World".
{
	// Sets the border width of the window.
	set_border_width(10);

	// When the button receives the "clicked" signal, it will call the
	// on_button_clicked() method defined below.
	m_button.signal_clicked().connect(sigc::mem_fun(*this,
		 &HelloWorld::on_button_clicked));

	// This packs the button into the Window (a container).
	add(m_button);

	// The final step is to display this newly created widget...
	m_button.show();
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
	std::cout << "Hello World" << std::endl;
}
