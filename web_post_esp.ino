/*
  
Title: HTTP POSt example to read data from Website
*/
#include <WiFi.h>
#include <HTTPClient.h>
 

#define WiFi_timeout 10000  // 10sec Wifi connection timeout


const char* ssid  = "xxxxxxxx";  //Introduce your network SSID
const char* password  = "xxxxxxxx"; //Introduce your network password
 
//-------------------------------------------------------
  const char* serverName = "http://xxx.xxx.xxx.xxx/index.php"; //your local host
//const char* serverName = "http://yourWebSite.com/index.php "; // your web site
bool toggle_pressed = false;           
String data_to_send = "";    
WiFiClient client;
HTTPClient http;
 
//-------------------------------------------------------------------

//Variables used in the code
             
unsigned int Actual_Millis, Previous_Millis;
int refresh_time = 200;               //Refresh rate of connection to website (recommended more than 1s)

//Inputs/outputs
 const int LED_BUILTIN = 4;                        //Connect LED on this pin (add 150ohm resistor)                                                   // use as visual indicator
//Button press interruption
 
void setup(){
 Serial.begin(115200);
// Connect to Wi-Fi
pinMode( LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, HIGH);
delay(100);

  WiFi.begin(ssid, password);
  Serial.print("Title: WEB > POST >ESP ");
  Serial.print("Connecting to ");
  while (WiFi.status() != WL_CONNECTED) {
    
    Serial.print('.');
    delay(1000);
  }
Serial.print(" Local IP:      ");
Serial.println(WiFi.localIP());
Serial.println("Title: WEB > POST > ESP ");
 
                //Check WiFi connection status  
      HTTPClient http;                                  //Create new client      
        data_to_send = "getData"  ;    //send for data post
             
      //Begin new connection to website       
      http.begin(client,serverName);   //Indicate the destination webpage 
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //  header
      
      int response_code = http.POST(data_to_send);                        //  POST. 
      
      //If the code is higher than 0, it means we received a response
      if(response_code > 0){
        Serial.println("------------Start of Post------------------------"); 
        Serial.println("HTTP code " + String(response_code));            //  return code
  
        if(response_code == 200){                                         //  read the echo data
          String response_body = http.getString();                                // 
          Serial.print("Server reply: ");                                  //Print data  
          Serial.println(response_body);

          Serial.println("------------------End of Post-------------------"); 
          
        }//  if(response_code == 200){       
      }//  if(response_code > 0){
      
      else{
       Serial.print("Error sending POST, code: ");
       Serial.println(response_code);
      }
      http.end();                                                                 //End the connection
      digitalWrite(LED_BUILTIN, LOW);      
}
void loop(){
    

}
