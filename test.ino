#include <SoftwareSerial.h>

const int RX = 2, TX = 3;
SoftwareSerial hm10(RX, TX);

const int led_pin = 13;

void setup()
{
	hm10.begin(9600);
	Serial.begin(9600);

	pinMode(led_pin, OUTPUT);
}

void loop()
{
	if (hm10.available())
	{
		String data = hm10.readStringUntil('\n');
		Serial.println(data);

		if (data == "ON")
			digitalWrite(led_pin, HIGH);
		else if (data == "OFF")
			digitalWrite(led_pin, LOW);
	}
}