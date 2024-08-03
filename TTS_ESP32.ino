#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266SAM.h>
#include <hidboot.h>
#include <usbhub.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SAM sam;

USB     Usb;
USBHub  Hub(&Usb);
HIDBoot<HID_PROTOCOL_KEYBOARD> Keyboard(&Usb);

String inputText = "";

class KeyboardReportParser : public KeyboardReportParser {
protected:
    void OnKeyDown(uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};

void KeyboardReportParser::OnKeyDown(uint8_t mod, uint8_t key) {
    uint8_t c = OemToAscii(mod, key);
    if (c) OnKeyPressed(c);
}

void KeyboardReportParser::OnKeyPressed(uint8_t key) {
    if (key == 13) { // Enter key
        display.clearDisplay(); // Clear the display when Enter is pressed
        display.display();

        // Speak the text and show progress
        sam.Say(inputText.c_str());
        inputText = "";
    } else {
        inputText += (char)key;
        display.clearDisplay();
        display.setCursor(0, 0);
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE);
        display.println(inputText);
        display.display();
    }
}

KeyboardReportParser KbdPrs;

void setup() {
    Serial.begin(115200);

    // Initialize OLED display
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.display();

    // Initialize SAM TTS
    sam.Init();

    // Initialize USB Host
    if (Usb.Init() == -1) {
        Serial.println("OSC did not start.");
        while (1); // halt
    }
    delay(200);

    Keyboard.SetReportParser(0, &KbdPrs);
}

void loop() {
    Usb.Task();
}
