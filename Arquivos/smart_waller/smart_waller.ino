#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int receptorA = A0;
const int receptorB = A1;
const int receptorC = A2;
const int receptorD = A3;
const int receptorE = A6;
float dimdim = 0;
float lastdimdim = 0;

unsigned long lastDebounceTime = 0;
const int debounceDelay = 250;

void setup() {
  Serial.begin(9600);
  pinMode(receptorA, INPUT);
  pinMode(receptorB, INPUT);
  pinMode(receptorC, INPUT);
  pinMode(receptorD, INPUT);
  pinMode(receptorE, INPUT);
  dimdim = EEPROM.read(0);
  lastdimdim = EEPROM.read(0);
  Serial.print("valor: ");
  Serial.println(dimdim);
  lcd_init();
}

void loop() {

  if (dimdim != lastdimdim ) {
    Serial.print("valor: ");
    Serial.println(dimdim);
    lastdimdim = dimdim;
  }

  somar(receptorA, 0.10);
  //somar(receptorB,0.5);
  //somar(receptorC,0.50);
  somar(receptorD, 0.25);
  somar(receptorE, 1.0);

}
