#include <math.h>
void setup() { 
  Serial.begin(9600); 
}
  float i=0.0;
  float left;
  float right;
  float diff;
  float avg;
  void loop() { 
    left = sin(i);
    right = sin(i+1.5);
    avg = (left+right)/2.0;
    diff = left-right;
    Serial.print(avg);
    Serial.print(" ");
    Serial.print(diff);
    Serial.print(" ");
    Serial.print(left);
    Serial.print(" ");
    Serial.println(right);
    i += 0.1;
    delay(1000);
} 
