/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>
#include <WSClient.h>

const char* ssid     = "SSID GOES HERE";
const char* password = "PASSPHRASE";

WSClient websocket;

WiFiClient client;



void setup() {
  Serial.begin(115200);
  delay(1);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  Serial.println("Connected to wifi");
  Serial.println("\nStarting connection...");
 
 delay(300);
 
 
  // Connect and test websocket server connectivity
  if (client.connect("echo.websocket.org", 80)) {
    Serial.println("Connected");
  } 
  else {
    Serial.println("Connection failed.");
    while(1) {
      // Hang on failure
    }
  }

  // Define path and host for Handshaking with the server
  websocket.path = "/";
  websocket.host = "echo.websocket.org";

  if (websocket.handshake(client)) {
    Serial.println("Handshake successful");
  } 
  else {
    Serial.println("Handshake failed.");
    while(1) {
      // Hang on failure
    }
  }

}


void loop() {
  String data;

  if (client.connected()) {
    data = websocket.getData();
    if (data.length() > 0) {
      Serial.print("Received data: ");
      Serial.println(data);
    }

    Serial.println(""); Serial.println("Sending Data");
    websocket.sendData("echo test");
  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }

  delay(3000);  // wait to fully let the client disconnect

}

