#include <ESP32Firebase.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define _SSID "Caiowifi"
#define _PASSWORD "senhasegura"
#define REFERENCE_URL "https://postalert-4439c-default-rtdb.firebaseio.com/"

#define SENSOR_PIN 26  // Pino conectado ao sensor de proximidade

Firebase firebase(REFERENCE_URL);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_PIN, INPUT);  // Configura o pino do sensor como entrada

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  timeClient.begin();
  timeClient.setTimeOffset(-10800);  // Configure para o fuso horário desejado em segundos (-10800 para BRT)

  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  timeClient.update();
  int sensorValue = digitalRead(SENSOR_PIN);  // Lê o valor do sensor
  if (sensorValue == LOW) {  // Se o sensor detectar um objeto
    String currentTime = timeClient.getFormattedTime();
    firebase.pushString("sensor/detection", "Detected at: " + currentTime);  // Envie para o Firebase
    Serial.println("Object detected at " + currentTime);
    delay(1000);  // Delay para evitar múltiplos registros no mesmo evento
  }
}
