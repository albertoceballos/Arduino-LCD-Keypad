/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','/'},
  {'.','0','=','*'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A4, A5, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  //lcd.print("Test");
}
char op[4]={"+","-","/","*"};
char eq = "=";
void loop(){
  char key = keypad.getKey();
  lcd.setCursor(0,0);
  
  if (key){
    if(key=="="){
      lcd.setCursor(0,0);
    }
    //Serial.println(key);
    lcd.print(key);
  }
}
