int contador = 0;
float valor = 0;
float valores[] = {1.0,0.50,0.25,0.10,0.05};

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 250; 

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Smart wallet");
  lcd.setCursor(2,1);
  lcd.print("R$ 0.00");
  Serial.begin(115200);
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(3);
  
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    if ((millis() - lastDebounceTime) > debounceDelay) {
      contador++;
      valor += valores[2];
      Serial.print("cont: ");
      Serial.println(contador);
      Serial.print("valor: ");
      Serial.println(valor);
      lcd.setCursor(2,1);
      lcd.print("R$");
      lcd.setCursor(5,1);
      lcd.print(valor);
      lastDebounceTime = millis();
    }
  }
}
