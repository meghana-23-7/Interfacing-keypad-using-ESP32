#include <Keypad.h>

#define ROW_NUM     4 
#define COLUMN_NUM  4

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', ‘A’},
  {'4', '5', '6', ‘B’},
  {'7', '8', '9', ‘C’},
  {'*', '0', '#', ‘D’}
};

byte pin_rows[ROW_NUM] = {19, 18, 5, 17}; // connect to the row pins
byte pin_column[COLUMN_NUM] = {16,  4, 0, 2};  // connect to the column pins

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

const String password = "7890"; // change your password here
String input_password;

void setup() {
  Serial.begin(9600);
  input_password.reserve(32); // maximum input characters is 33, change if needed
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '*') {
      input_password = ""; // clear input password
    } else if (key == '#') {
      if (password == input_password) {
        Serial.println("The password is correct, ACCESS GRANTED!");
       

      } else {
        Serial.println("The password is incorrect, ACCESS DENIED!");
      }

      input_password = ""; // clear input password
    } else {
      input_password += key; // append new character to input password string
    }
  }
}
