// DS2401 Changes by: Seyed roohollah Marashi   Iran -Tehran 2020
// DS2401 is unique Transistor, IC or Chip or memory
// Coming with Constant Serial Number That we Can Depend
// Running program to This Uniq Serial Availability or other Usages
// in case of any changes for this serial we are able to clean all
// EPROMS OR EXTERNAL MEMORIES to keep safe Programmed device


#include <OneWire.h>
OneWire net(10);  // on pin 10


void PrintBytes(const uint8_t* addr, uint8_t count, bool newline=false) {
  for (uint8_t i = 0; i < count; i++) {
    Serial.print(addr[i]>>4, HEX);
    Serial.print(addr[i]&0x0f, HEX);
  }
  if (newline)
    Serial.println();
}


void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte addr[8] = {0};

  if (!net.search(addr)) {
    Serial.print("------------------------\n");
    net.reset_search();
    delay(1000);
    return;
  }

  if (addr[0] != 0x29) {
    PrintBytes(addr, 8);
    Serial.print(" is Uniqu code of your DS2401.\n");
    return;
  }

}

