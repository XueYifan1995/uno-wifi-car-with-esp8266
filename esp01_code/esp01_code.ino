#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "setting.h"
#include "home.h"

const char* PARAM_dir = "dir"; 

AsyncWebServer server(80);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  connect_to_wifi();
  //主网页
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  // Send a GET request to <IP>/move?dir=<dir> 前进dir=F;后退 dir=B ;左转 dir=L; 右转dir=R;停止 dir =S
  server.on("/move", HTTP_GET, [] (AsyncWebServerRequest *request) {
      String dir;
      if (request->hasParam(PARAM_dir)) {
          dir = request->getParam(PARAM_dir)->value();
      } else {
          dir = "No message sent";
      }
      
      Serial.print(dir);//串口输出：F  B  L  R  S
      request->send(200, "text/plain", "接收到的指令为: " + dir);
  });

   server.onNotFound(notFound);

  //启动 web 服务器
  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
}
