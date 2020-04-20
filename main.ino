/*
 * ESP32 AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 */
#include <WebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "BluetoothSerial.h"
#include "index.h"  //Web page header file

//=======================================================

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
std::string bt_data;
String wifi_data = "test";

//==============================================

WebServer server(80);

//Enter your SSID and PASSWORD
const char* ssid = "MK";
const char* password = "123456789";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
    String s = MAIN_page;              //Read HTML contents
    server.send(200, "text/html", s);  //Send web page
}

void handleTime() {
    //int a = analogRead(A0);
    int a = millis();
    String adcValue = String(a);

    server.send(200, "text/plane", adcValue);  //Send ADC value only to client ajax request
}

void handleBT() {
    //int a = analogRead(A0);

    server.send(200, "text/plane", bt_data.c_str());  //Send ADC value only to client ajax request
}

void handleWifi() {
    //int a = analogRead(A0);

    server.send(200, "text/plane", wifi_data);  //Send ADC value only to client ajax request
}
//===============================================================
// Setup
//==============================================================

IPAddress local_IP(192, 168, 2, 105);
IPAddress gateway(192, 168, 2, 9);
IPAddress subnet(255, 255, 255, 0);

void setup(void) {
    Serial.begin(115200);
    Serial.println();
    Serial.println("Booting Sketch...");

    SerialBT.begin("ESP32test");  //Bluetooth device name

    /*
//ESP32 As access point
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);
*/
    //ESP32 connects to your wifi -----------------------------------
    // WiFi.mode(WIFI_STA);  //Connectto your wifi
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAP("TEST-DSP", "12345678");
    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.begin(ssid, password);

    Serial.println("Connecting to ");
    Serial.print(ssid);

    //Wait for WiFi to connect
    uint8_t reconnect_counter = 0;
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.print(".");
        reconnect_counter++;
        if (reconnect_counter > 3) ESP.restart();
    }

    //If connection successful show IP address in serial monitor
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  //IP address assigned to your ESP
                                     //----------------------------------------------------------------

    server.on("/", handleRoot);        //This is display page
    server.on("/readTime", handleTime);  //To get update of ADC Value only
    server.on("/readBT", handleBT);
    server.on("/readWifi", handleWifi);

    server.begin();  //Start server
    Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================

int k = 0;
void loop(void) {
    server.handleClient();
    if (SerialBT.available()) {
        bt_data = "";
        while (SerialBT.available()) {
            bt_data += SerialBT.read();
            //Serial.write(SerialBT.read());
        }
        Serial.print(bt_data.c_str());
    }
    if (k > 10000) {
        wifi_data = "";
        int n = WiFi.scanNetworks();
        Serial.println("scan done");
        if (n == 0) {
             wifi_data = "no networks found";
        } else {
            wifi_data += n;
            wifi_data += " networks found";
            wifi_data += "<br>";
            for (int i = 0; i < n; ++i) {
                // Print SSID and RSSI for each network found
                wifi_data += (i + 1);
                wifi_data += ": ";
                wifi_data += WiFi.SSID(i);
                wifi_data += " (";
                wifi_data += WiFi.RSSI(i);
                wifi_data += ")";
                wifi_data += ((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
                wifi_data += "<br>";
                //delay(10);
            }
        }
        //Serial.println("");
        k = 0;
    }
    delay(1);
    k++;
}