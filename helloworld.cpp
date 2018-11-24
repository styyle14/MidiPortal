#include "helloworld.hpp"
#include <iostream>
#include <RtMidi.h>

Minerer::Minerer() : sl::cabl::Client({"Maschine Mikro MK3"})
{
}
void Minerer::init(){
	//RtMidiIn  *midiin = 0;
	//RtMidiOut *midiout = 0;
	std::cout << "\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX.\n";
	//try {
		//midiin = new RtMidiIn();
	//} catch (RtMidiError &error) {
	//// Handle the exception here
		//error.printMessage();
	//}
	//// Check inputs.
	//unsigned int nPorts = midiin->getPortCount();
	//std::cout << "\nThere are " << nPorts << " MIDI input sources available.\n";
	//std::string portName;
	//for ( unsigned int i=0; i<nPorts; i++ ) {
		//try {
			//portName = midiin->getPortName(i);
		//}
		//catch ( RtMidiError &error ) {
			//error.printMessage();
			//goto cleanup;
		//}
		//std::cout << "  Input Port #" << i+1 << ": " << portName << '\n';
	//}
	//// Clean up
	//cleanup:
		//delete midiin;
}
void Minerer::initDevice(){ 
	std::cout << "\nYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY.\n";
	device()->setButtonLed(sl::cabl::Device::Button::NativeInstruments, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Play, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Rec, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Shift, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Pad13, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Pad10, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Pad7, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::Pad4, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::SmartstripLed01, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::SmartstripLed13, sl::cabl::Color(15));
	device()->setButtonLed(sl::cabl::Device::Button::SmartstripLed25, sl::cabl::Color(15));
}
void Minerer::disconnected(){ }
void Minerer::buttonChanged(sl::cabl::Device::Button button_, bool buttonState_, bool shiftPressed_){
	sl::cabl::Client::buttonChanged(button_, buttonState_, shiftPressed_);
}
void Minerer::encoderChanged(unsigned encoder_, bool valueIncreased_, bool shiftPressed_){
	sl::cabl::Client::encoderChanged(encoder_, valueIncreased_, shiftPressed_);
}
void Minerer::keyChanged(unsigned index_, double value_, bool shiftPressed){
	sl::cabl::Client::keyChanged(index_, value_, shiftPressed);
}
void Minerer::controlChanged(unsigned pot_, double value_, bool shiftPressed){
	sl::cabl::Client::controlChanged(pot_, value_, shiftPressed);
}
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
