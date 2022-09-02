# 1 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\main.ino"
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
# 1 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\test.ino"
# 2 "c:\\Users\\joshu\\Documents\\GitHub\\smartwatch\\test.ino" 2

const int RX = 2, TX = 3;
SoftwareSerial hm10(RX, TX);

const int led_pin = 13;

void setup()
{
 hm10.begin(9600);
 Serial.begin(9600);

 pinMode(led_pin, 0x1);
}

void loop()
{
 if (hm10.available())
 {
  String data = hm10.readStringUntil('\n');
  Serial.println(data);

  if (data == "ON")
   digitalWrite(led_pin, 0x1);
  else if (data == "OFF")
   digitalWrite(led_pin, 0x0);
 }
}
