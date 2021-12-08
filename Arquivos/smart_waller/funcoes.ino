void somar(int porta, float valor) {
  if (analogRead(porta) > 800) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      Serial.print("+ ");
      Serial.print(valor);
      if (valor < 1.0) {
        Serial.println(" centavos");
      } else {
        Serial.println(" real");
      }
      dimdim += valor;
      EEPROM.write(0, dimdim);
      lcd_print(0,0,"Valor: R$" + String(dimdim));
      lastDebounceTime = millis();
    }
  }
}

void lcd_init(){
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void lcd_print(int col, int line, String msg){
  lcd.setCursor(col,line);
  lcd.print(msg);  
}
