
#include<Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
const int buzzer = 6; //buzzer to arduino pin 6
DHT dht(DHTPIN, DHTTYPE);

int trigPin = 12;
const int echoPin = 11;
int chk;
float hum; //Stores humidity value
float temp;
// defines variables
long duration;
int distance;
void setup() {
pinMode(buzzer, OUTPUT);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
dht.begin();
delay(100);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);\
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
if (distance<=5)
{
tone(buzzer, 1000); // Send 1KHz sound signal...
delay(1000);
// ...for 1 sec
noTone(buzzer);
// Stop sound...
delay(1000);
Serial.print("Distance: ");
Serial.print(distance);
Serial.println("cm");
hum = dht.readHumidity();
temp= dht.readTemperature();
//Print temp and humidity values to serial monitor
Serial.print("Humidity: ");
Serial.print(hum);
Serial.println(" %");
Serial.print("Temp: ");
Serial.print(temp);
Serial.println(" Celsius");
Serial.print("Garbage Box Full!!!!");
Serial.println(" ");
} 
}
