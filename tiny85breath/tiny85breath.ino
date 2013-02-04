/*
ATtiny85 pranayama blinker
 */

#define right_led  0
#define left_led  1
#define left_thermistor 3
#define right_thermistor 2 //pin mapping diagram?
int left,right;
void setup() {                
  pinMode(left_led, OUTPUT);     
  pinMode(right_led, OUTPUT); 
  pinMode(left_thermistor, INPUT); 
  pinMode(right_thermistor, INPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  right = analogRead(right_thermistor);
  left  = analogRead(left_thermistor);
  if(abs(right-left) < 10) {
    delay(100);
    return;
  }
  if(right > left){
    digitalWrite(left_led, HIGH);   
    delay(100);               
    digitalWrite(left_led, LOW); 
  }else{  
    digitalWrite(right_led, HIGH); 
    delay(100);               
    digitalWrite(right_led, LOW);    
  }
  delay(100);
}

