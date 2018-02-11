#include<ESP8266WiFi.h>

String apiKey ="paste_your_api_key_here";

char thingSpeakAddress[] = "api.thingspeak.com";
String thingtweetAPIKey = "paste_your_thingtweetapi_key_here"; 
const char* ssid = "Your_ssid_here";
const char* password = "Your_ssid_password";
String twitmsg = "This is twitthings msg";
const char* server ="api.thingspeak.com";

// Variable Setup
long lastConnectionTime = 0; 
boolean lastConnected = false;
int failedCounter = 0;
float temp = 0;
int smoke;
int flame;
int analog = 0;
int digital = 1;
WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
    Serial.println("");
    Serial.println("WiFi connected");

}

void loop() {
 analog = analogRead(A0);
 float temp =analog * 0.322265625;
 digital = (digitalRead(D0)==LOW);
 int smoke =digital;
 digital = (digitalRead(D1)==LOW);
 int flame =digital;

 if (client.connect(server,80)){//"184.106.153.149"
  String postStr = apiKey;
         postStr +="&field1=";
         postStr += String(temp);
         postStr +="&field2=";
         postStr += String(smoke);
         postStr +="&field3=";
         postStr += String(flame);
         postStr +="\r\n\r\n";


  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(postStr.length());
  client.print("\n\n");
  client.print(postStr);
  
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("\nSmoke status: ");
  Serial.print(smoke);
  Serial.print("\nFlame status: ");
  Serial.print(flame);
  Serial.print("\nsending data to thingspeak");
  
 }
 client.stop();
 Serial.println("\nWaiting...");
 if(smoke == 1){
  updateTwitterStatus("Smoke Detected"); 
 }
 if(temp>50){ 
  updateTwitterStatus("Temperature rising"); 
 }
 if(flame == 1){
  
  updateTwitterStatus("Fire Detected"); 
 }
 //thinspeak needs minimum 15 sec delay between updates
 delay(500);
}
void updateTwitterStatus(String tsData)
{
  if (client.connect(thingSpeakAddress, 80))
  { 
    // Create HTTP POST Data
    tsData = "api_key="+thingtweetAPIKey+"&status="+tsData;
            
    client.print("POST /apps/thingtweet/1/statuses/update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(tsData.length());
    client.print("\n\n");

    client.print(tsData);
    
    lastConnectionTime = millis();
    
    if (client.connected())
    {
      Serial.println("Connecting to ThingSpeak...");
      Serial.println();
      
      failedCounter = 0;
    }
    else
    {
      failedCounter++;
  
      Serial.println("Connection to ThingSpeak failed ("+String(failedCounter, DEC)+")");   
      Serial.println();
    }
    
  }
  else
  {
    failedCounter++;
    
    Serial.println("Connection to ThingSpeak Failed ("+String(failedCounter, DEC)+")");   
    Serial.println();
    
    lastConnectionTime = millis(); 
  }
}

