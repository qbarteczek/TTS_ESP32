# TTS_ESP32 🚀

Bilingual documentation for the **TTS_ESP32** project.  
*Dwujęzyczna dokumentacja dla projektu TTS_ESP32.*

---

## 📁 Project Overview (O Projekcie)
- **Microcontroller:** ESP8266
- **IDE Support:** Arduino IDE & VS Code PlatformIO

---

## 🔌 Hardware Wiring (Połączenia Sprzętowe)
For connection mappings, refer to:  
*Rozkład pinów znajdziesz w:*  
👉 **[WIRING.md](file://WIRING.md)**

---

## 🚀 How to Compile & Flash (Instrukcja Uruchomienia)

### Method 1: VS Code PlatformIO (Recommended)
1. Open this directory in VS Code with PlatformIO extension installed.
2. Select your environment configuration.
3. Click **Build & Upload**.

### Method 2: Arduino IDE
1. Open the `.ino` file in the sketch folder.
2. Add support for ESP8266 in Arduino Boards Manager.
3. Install the libraries listed below.
4. Upload to your board!

### Required Libraries (Biblioteki):
- `adafruit/Adafruit GFX Library`
- `adafruit/Adafruit SSD1306`
- `earlephilhower/ESP8266SAM`

---
## 🛑 Safety Rules (Zasady Bezpieczeństwa)
Before connecting power, read:  
*Przed podłączeniem zasilania przeczytaj:*  
👉 **[DOS_AND_DONTS.md](file://DOS_AND_DONTS.md)**
