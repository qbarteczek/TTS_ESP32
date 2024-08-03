# TTS_ESP32
Text to Speach
Instrukcje
Podłącz ESP32 do wyświetlacza OLED SSD1306 zgodnie ze schematem połączeń:

VCC (OLED) -> 3.3V (ESP32)
GND (OLED) -> GND (ESP32)
SDA (OLED) -> GPIO21 (ESP32)
SCL (OLED) -> GPIO22 (ESP32)
Podłącz USB Host Shield do ESP32:

MOSI (USB Host Shield) -> GPIO23 (ESP32)
MISO (USB Host Shield) -> GPIO19 (ESP32)
SCK (USB Host Shield) -> GPIO18 (ESP32)
SS (USB Host Shield) -> GPIO5 (ESP32)
VCC (USB Host Shield) -> 5V (ESP32)
GND (USB Host Shield) -> GND (ESP32)
Podłącz głośnik do ESP32:

Jeden biegun głośnika do DAC1 (GPIO25) na ESP32
Drugi biegun głośnika do GND na ESP32
Podłącz klawiaturę USB do USB Host Shield.

Zainstaluj wymagane biblioteki:

ESP8266SAM: Pobierz z GitHub: ESP8266SAM i dodaj bibliotekę do Arduino IDE (Sketch -> Include Library -> Add .ZIP Library...).
Adafruit SSD1306 i Adafruit GFX: Zainstaluj z menedżera bibliotek w Arduino IDE (Sketch -> Include Library -> Manage Libraries... -> Search for "Adafruit SSD1306" i "Adafruit GFX").
USB Host Shield Library 2.0: Zainstaluj z menedżera bibliotek w Arduino IDE (Sketch -> Include Library -> Manage Libraries... -> Search for "USB Host Shield Library 2.0").
Wgraj kod na ESP32:

Podłącz ESP32 do komputera za pomocą kabla USB.
Otwórz Arduino IDE, skopiuj powyższy kod i wgraj go na ESP32 (Tools -> Board -> ESP32 Dev Module, Tools -> Port -> wybierz odpowiedni port, Sketch -> Upload).
Obsługa urządzenia
Uruchomienie: Po podłączeniu zasilania, ESP32 zainicjuje wyświetlacz OLED oraz USB Host Shield.
Wprowadzanie tekstu: Użyj klawiatury USB do wprowadzania tekstu. Tekst będzie wyświetlany na OLED SSD1306.
Synteza mowy: Naciśnij klawisz Enter na klawiaturze USB. Tekst zostanie usunięty z wyświetlacza OLED i przetworzony na mowę, którą odtworzy głośnik.
Uwagi
Upewnij się, że wszystkie połączenia są stabilne i poprawnie wykonane.
Jeśli masz problemy z jakością dźwięku, sprawdź połączenie głośnika i ustawienia w kodzie.
Sprawdź, czy klawiatura USB jest poprawnie podłączona i czy działa z USB Host Shield.
