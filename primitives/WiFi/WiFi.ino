#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "wifi-ssid";
const char* password = "wifi-password";

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }
  // N.B: blocks execution until Serial is ready

  // Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" CONNECTED!");

}

void loop() {}
