#include <Arduino.h>
#line 8 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\test.ino"
void setup();
#line 16 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\test.ino"
void loop();
#line 0 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\test.ino"
#line 1 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\main.ino"
// #include <SoftwareSerial.h>

// const int RX = 2, TX = 3;
// SoftwareSerial hm10(RX, TX);

// void setup()
// {
// 	hm10.begin(9600);
// }

// void loop()
// {

// }
#line 1 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\test.ino"
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
