#include <SD.h>
#include <Update.h>

const int SD_CS = 42;

#define FIRMWARE_VERSION 0.0

void monitorProgress(size_t wrote, size_t total) {
  Serial.printf("Updated %d of %d bytes...\n", wrote, total);
}

void setup() {
  Serial.begin(115200);
  while (!Serial) { delay(10); }

  Serial.print("Current firmware version: ");
  Serial.println(FIRMWARE_VERSION);

  SPI.begin(2, 3, 1); // NOTE: board Specific; skip for defaults

  Serial.print("Mounting SD card ");
  if(!SD.begin(SD_CS)){
    Serial.println("failed!");
    return;
  }
  Serial.println("succeeded.");

  File firmware = SD.open("/firmware.bin");
  if (firmware) {
    Serial.println("Updating firmware...");
    Update.onProgress(monitorProgress);

    Update.begin(firmware.size(), U_FLASH);
    Update.writeStream(firmware);

    if (Update.end()) {
      Serial.println("SUCCESS!");
    } else {
      Serial.print("ERROR: ");
      Serial.println(Update.getError());
    }

    firmware.close();

    if (SD.rename("/firmware.bin", "/firmware.bak")){
      Serial.println("Firmware backed up!");
    }else{
      Serial.println("Firmware backup error!");
    }
    delay(1000);

    ESP.restart();
  }

  Serial.print("Current firmware version: ");
  Serial.println(FIRMWARE_VERSION);
}

void loop(void) {}