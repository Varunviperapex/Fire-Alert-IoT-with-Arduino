 

int buzzerPin = 10;                                                          
int smokeinPin = A1;
int burninPin = 7;
float tempinPin = A0;
void setup() {                                                               
  Serial.begin(9600); 
  pinMode(buzzerPin, OUTPUT);                               
  pinMode(tempinPin, INPUT);
  pinMode(smokeinPin, INPUT);
  pinMode(burninPin, INPUT);

  beep(50);                                                 

  beep(50);                                                                         

  delay(1000);                                              

}

void loop() {                                               

  float temp;
  int smoke;
  int flame;

  temp = analogRead(tempinPin);
  Serial.print("\nTemperature reading :");
  Serial.print(temp);
  smoke = analogRead(smokeinPin);
  Serial.print("\nSmoke state :");
  Serial.print(smoke);
  flame = digitalRead(burninPin);
  Serial.print("\nFlame state :");
  Serial.print(flame);
  if(temp>50)
  {
  beep(50);                                                                         
  
  delay(1000);  
  }
  if(smoke>500)
  {
  beep(50);                                                                          
  
  delay(50);
  analogWrite(tempinPin, LOW);                                                                     
  }
  if(flame == 0)
  {
  analogWrite(tempinPin, LOW);
  analogWrite(smokeinPin, LOW);  
  beep(50);                                                                       
  
  delay(20);                                                                     
  }
}

void beep(unsigned char delayms) {                       // Created a function for beep

  analogWrite(buzzerPin, 20);                                      // This will set pin 11 to high

  delay(delayms);                                                             // Giving a delay

  analogWrite(buzzerPin ,0);                                        // This will set pin 11 to LOW

  delay(delayms);                                                             // Giving a delay
}
