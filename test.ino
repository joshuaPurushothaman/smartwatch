#include <SoftwareSerial.h>

const int RX = 2, TX = 3;
SoftwareSerial hm10(RX, TX);

void setup()
{
	hm10.begin(9600);
	Serial.begin(9600);

	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	if (hm10.available())
	{
		String data = hm10.readStringUntil('\n');
		Serial.println(data);

		if (data == "ON")
			digitalWrite(LED_BUILTIN, HIGH);
		else if (data == "OFF")
			digitalWrite(LED_BUILTIN, LOW);
	}
}