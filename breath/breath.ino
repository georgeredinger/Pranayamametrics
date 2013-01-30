#include <math.h>


void setup() { 
  Serial.begin(9600); 
  analogReadResolution(12);

}
  float rleft;
  float rright;
  float diff;
  float avg;
  float vl,vr;
  float tr,tl;
  float rawl,rawr;
  
  #define A 8.271111e-4
  #define B 2.088020e-4
  #define C 8.059200e-8
  
 
  
  void loop() { 
    rawl = analogRead(0);
    vl =  (rawl/4096)*3.3;
    rleft = ((vl/3.3)/(1-vl/3.3))*249e3;
    tl = (1/(A+B*(log(rleft)+C*pow(log(rleft),3)))-273.15)*1.8+32.0;
    rawr = analogRead(1);
    vr = (rawr/4096)*3.3;
    rright = ((vr/3.3)/(1-vr/3.3))*249e3;
    tr = (1/(A+B*(log(rright)+C*pow(log(rright),3)))-273.15)*1.8+32.0;
    avg = (tl+tr)/2.0;
    diff = tr-tl;
    Serial.print(avg);
    Serial.print(" ");
    Serial.print(diff);
    Serial.print(" ");
    Serial.print(tl);
    Serial.print(" ");
    Serial.println(tr);
    delay(1000);
} 
