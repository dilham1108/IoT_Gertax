#ifndef COMMUNICATION_LIBRARY_H
#define COMMUNICATION_LIBRARY_H

#include <WiFi.h>
#include <HTTPClient.h>

// Function prototypes
void initCommunication();
void sendData(float voltage, float current, float rpm);

// WiFi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Server settings
const char* serverName = "http://yourserver.com/update";
const char* apiKey = "your_API_KEY";

void initCommunication() {
  // Initialize WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void sendData(float voltage, float current, float rpm) {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    // Prepare URL with data
    String url = String(serverName) + "?api_key=" + apiKey + "&voltage=" + String(voltage) + "&current=" + String(current) + "&rpm=" + String(rpm);
    
    http.begin(client, url);
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending GET: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}

#endif // COMMUNICATION_LIBRARY_H
