#include <WiFiManager.h>
#include <ESP32Firebase.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define SENSOR_PIN 15  // Pino conectado ao sensor de proximidade

// Definições do Firebase
#define REFERENCE_URL "https://post-alert-79f8d-default-rtdb.firebaseio.com/"
Firebase firebase(REFERENCE_URL);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

char phone[20];
char password[40];

void saveConfigCallback() {
  Serial.println("Salvando dados...");
}

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_PIN, INPUT);  // Configura o pino do sensor como entrada

  WiFiManager wm;

  // Adicionando campos personalizados para telefone e senha
  WiFiManagerParameter custom_phone("phone", "Telefone", phone, 20);
  WiFiManagerParameter custom_password("password", "Senha", password, 40);

  wm.addParameter(&custom_phone);
  wm.addParameter(&custom_password);

  wm.setSaveConfigCallback(saveConfigCallback);

  // Configurar o hostname
  wm.setHostname("postalert");

  // Iniciar configuração do WiFiManager
  if (!wm.autoConnect("Post Alert")) {
    Serial.println("Falha na conexão");
    ESP.restart();
  }

  // Recuperar dados fornecidos pelo usuário
  strcpy(phone, custom_phone.getValue());
  strcpy(password, custom_password.getValue());

  Serial.println("Telefone: " + String(phone));
  Serial.println("Senha: " + String(password));

  // Conectar ao NTP para obter a hora
  timeClient.begin();
  timeClient.setTimeOffset(-10800);

  Serial.println("WiFi Connected");
  Serial.print("IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  // Enviar dados do usuário para o Firebase
  String deviceId = String((uint32_t)ESP.getEfuseMac(), HEX);
  firebase.setString("devices/" + deviceId + "/phone", phone);
  firebase.setString("devices/" + deviceId + "/password", password);

  Serial.println("Dados do usuário enviados para o Firebase.");
}

void loop() {
  timeClient.update();
  int sensorValue = digitalRead(SENSOR_PIN);  // Lê o valor do sensor
  if (sensorValue == LOW) {  // Se o sensor detectar um objeto
    String currentTime = timeClient.getFormattedTime();
    String deviceId = String((uint32_t)ESP.getEfuseMac(), HEX);
    firebase.pushString("devices/" + deviceId + "/sensor/detection", "Detected at: " + currentTime);  // Envie para o Firebase
    Serial.println("Object detected at " + currentTime);
    delay(1000);  // Delay para evitar múltiplos registros no mesmo evento
  }
}
