#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>


#define SSID "Deco_3C88"
#define PASSWORD "j3HCZJVDwKvL"

#define MDNS_NAME "harrywebserver"


const char* ssid = SSID;
const char* password = PASSWORD;

ESP8266WebServer server(80);

int led = LED_BUILTIN;
bool ledstatus = true;


void rootweb() {
  Serial.println("Root Webpage");
  String websitehtml = "";
  websitehtml += "<h1>"; 
  websitehtml += "<p>ESP8266 Use of remote controlling the WeMos d1 Built-in LED<p>";
  websitehtml += "<a href=\"/activate\">Activate Led</a> \t\t ";
  websitehtml += "<br><br>";
  websitehtml += "<a href=\"/deactivate\">Deactivate Led</a>";
  websitehtml += "</h1>";
  server.send(200, "text/html", websitehtml);
  
}

void activatebtn() {
  Serial.println("Activated Light");
  ledstatus = true;
  rootweb();
  //then to go to root website eg. handleroot()
}

void deactivatebtn() {
  Serial.println("Deactivated Light");
  ledstatus = false;
  rootweb();
  //then to go to root website eg. handleroot()
}

void websiteled(int time) {
  digitalWrite(led, LOW);
  delay(time);
}

void webapp() {
  if (ledstatus) {
    websiteled(300);
  }
  digitalWrite(led, HIGH);

}

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  Serial.begin(115200);

  //connecting to wifi network with ssid and pswd
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  delay(5);  
  Serial.println("Starting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.print("WiFi connected to ");
  Serial.println(ssid);
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(MDNS_NAME)) {
    
    Serial.println("MDNS started");
    
  }
  
  server.on("/", rootweb);
  server.on("/activate", activatebtn);
  server.on("/deactivate", deactivatebtn);

  server.begin();
  Serial.println("HTTP server started");

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //WiFiClient client = server.available();   // Listen for incoming clients
  server.handleClient();
  MDNS.update();

  webapp();
}
