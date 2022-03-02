//these are the libraries you need for this program
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


//this is the port were you plug in the data wire
#define ONE_WIRE_BUS 2


//thhese are the necessary Setups that the libaries need
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);

//these are the addresses of my sensory you need to change them fitting to yours
uint8_t sensor1[8] = { 0x28, 0x96, 0x1C, 0x29, 0x00, 0x00, 0x80, 0x2F };
uint8_t sensor2[8] = { 0x28, 0x1D, 0x50, 0x40, 0x0D, 0x00, 0x00, 0x6A };


void setup(void)
{
  sensors.begin();
  lcd.begin();
  lcd.backlight();
}

void loop(void)
{
  sensors.requestTemperatures();


  //the printing of the 2 sensor names
  lcd.setCursor(0, 0);
  lcd.print("INSIDE:  ");
  printTemperature(sensor1);

  lcd.setCursor(0, 1);
  lcd.print("OUTSIDE: ");
  printTemperature(sensor2);

  delay(1000);
}

void printTemperature(DeviceAddress deviceAddress)
{
  //the printing of the 2 sensor temperatures
  float tempC = sensors.getTempC(deviceAddress);
  lcd.print(tempC);
  lcd.println("C  ");
}
