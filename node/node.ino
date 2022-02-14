#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
// including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11 // DHT 11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);
#define TRIGGERPIN D1
#define ECHOPIN    D2


char auth[] = "5e916dee4a4540038eb6572408048253";
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char ssid[] = "ONEPLUS_6T"; // Your WiFi credentials.
char pass[] = "9868585253"; // Set password to "" for open networks.
float t;
// Declare the variables
float h;
WidgetLCD lcd(V2);
void setup()
{
Serial.begin(9600);// Debug console
Blynk.begin(auth, ssid, pass);
dht.begin();
lcd.clear(); //Use it to clear the LCD Widget
lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
pinMode(TRIGGERPIN, OUTPUT);
pinMode(ECHOPIN, INPUT);
}

void loop()
{
Blynk.run();
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.println("Humidity and temperature\n\n");
Serial.print("Current humidity = ");
Serial.print(h);
Serial.print("% ");
Serial.print("temperature = ");
Serial.print(t);
Blynk.virtualWrite(V0, h);
Blynk.virtualWrite(V1, t);
lcd.clear();
lcd.print(0, 0, "Distance in cm"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
long duration, distance;
digitalWrite(TRIGGERPIN, LOW);  
delayMicroseconds(2); 
digitalWrite(TRIGGERPIN, HIGH);
delayMicroseconds(10); 
digitalWrite(TRIGGERPIN, LOW);
duration = pulseIn(ECHOPIN, HIGH);
distance = duration*0.034/2;
Serial.print(distance);
Serial.println("Cm");
lcd.print(7, 1, distance);
Serial.print("Distance=");
Serial.print(distance);
}
