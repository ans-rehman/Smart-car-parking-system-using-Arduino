
#include <LiquidCrystal.h>
#include<Wire.h>
#include <Servo.h>   

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  int IR1 = 7; // IR Sensor 1
  int IR2 = 8; // IR Sensor 2
  Servo myservo; 
  int Slot = 5;      //Enter Total number of parking Slots  
  int flag1 = 0;  
  int flag2 = 0;          
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);  
  myservo.attach(9);  
  myservo.write(100);  
   lcd.setCursor(0,0); 
  String msg_1 = ("WELCOME TO OUR");
  lcd.print(msg_1);
  delay(2000);
  for (int pos=0 ; pos<msg_1.length() ; pos++){
    lcd.scrollDisplayLeft();
    delay(100);    
  }
  lcd.clear();
  lcd.setCursor(0,0);
  String msg_2 = ("MICROPROCESSOR SYSTEM PROJECT.....");
  lcd.print(msg_2);
  delay(2000);
  for (int pos=0 ; pos<msg_2.length() ; pos++){
    lcd.scrollDisplayLeft();
    delay(100);    
  }
  lcd.clear();
 lcd.setCursor(0,0);
  String msg_3 = ("2020-EE-351, 353, 361");
  lcd.print(msg_3);
  delay(2000);
  for (int pos=0 ; pos<msg_3.length() ; pos++){
    lcd.scrollDisplayLeft();
    delay(100);    
  }
  lcd.clear();  
  
}
void loop() {
if(digitalRead (IR1) == LOW && flag1==0){  
if(Slot>0){flag1=1;  
if(flag2==0){myservo.write(180); Slot = Slot-1;}  
}else{  
lcd.setCursor (0,0);  
lcd.print("  SORRY   ");   
lcd.setCursor (0,1);  
lcd.print(" Parking Full ");   
delay (3000);  
lcd.clear();   
}  
}  
if(digitalRead (IR2) == LOW && flag2==0){flag2=1;  
if(flag1==0){myservo.write(180); Slot = Slot+1;}  
}  
if(flag1==1 && flag2==1){  
delay (1000);  
myservo.write(100);  
flag1=0, flag2=0;  
}  
lcd.setCursor (0,0);  
lcd.setCursor (0,1);  
lcd.print("Slot Left: ");  
lcd.print(Slot);  
}

