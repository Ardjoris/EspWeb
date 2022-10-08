#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <C:\Librarys\wifiConnect.h>
#include "LittleFS.h"

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;



void setup()
{
  Serial.begin(115200);

  // start here my own wifi connect function from #wifi conncect library
  WIFIConnect();
  server.begin();
  WiFiClient client = server.available(); // Listen for incoming clients'

 
  if (client)
  {
    Serial.println("client connected");
  }
  LittleFS.begin();
  if (!LittleFS.begin())
  {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }




  
  // Serial.println("File Content:");
  // while (file.available())
  // {
  //   Serial.write(file.read());
  // //  client.write(file.read());
  // }
  // file.close();
}

void loop()
{
   WiFiClient client = server.available(); // Listen for incoming clients'
               // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
  // LittleFS.format();
  File file = LittleFS.open("/index.html", "r");
  if (!file)
  {
    Serial.println("Failed to open file for reading");
    return;
  }
            client.write(file);
  // client.println("<script>console.log(`hello world joris`)</script>");
  
}
