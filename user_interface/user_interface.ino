#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16 ,2);
const int ROW_NUM = 4;
const int COLUMN_NUM = 3;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'},
};
byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3};

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
void setup() {
  // put your setup code here, to run once:
   lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Please select");
  
  lcd.setCursor(0, 1);
  lcd.print("Your Water Level");
  
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Press Keys 1-4");
  
  lcd.setCursor(0, 1);
  lcd.print("For Level");
  
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Four being");
  lcd.setCursor(0, 1);
  lcd.print("wettest");
  lcd.clear();
  

  
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if (key) {
    lcd.setCursor(0,0);
    lcd.print(key);
    delay(2000);
    lcd.clear();
  }
}
