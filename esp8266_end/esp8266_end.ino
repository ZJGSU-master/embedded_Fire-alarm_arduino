#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "mi9";   // wifi name
const char* password = "asdfghjkl";   //wifi passwd

const char* host = "192.168.43.61"; //需要访问的域名
const int httpsPort = 9999;  // 需要访问的端口
//String url = "/Embedded_background/nmsl?msg=";   

char* sbuf;
void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); // 连接WIFI
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); // 显示WIFI地址
}

void loop() {
  Serial.print("connecting to ");
  Serial.println(host);

  WiFiClient client;

  /**
     测试是否正常连接
  */
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  delay(10);
  if (Serial.available())       //判断串口缓存区是否有数据
  {
    Serial.println("work");
    // 需要访问的地址
    char* str = "/Embedded_background/nmsl?msg="; 
    // 为请求添加数据
    while (Serial.available() > 0) {  
      char a = Serial.read();
      str = appendCharToCharArray(str, a);
    }
    delay(100);
//    Serial.flush();
//    Serial.println(str);
    String postRequest = (String)("GET ") + str + "/ HTTP/1.1\r\n" +
                         "Content-Type: text/html;charset=utf-8\r\n" +
                         "Host: " + host + "\r\n" +
                         "User-Agent: BuildFailureDetectorESP8266\r\n" +
                         "Connection: Keep Alive\r\n\r\n";
    Serial.println(postRequest);  //测试
    client.print(postRequest);  // 发送HTTP请求到服务器
  }

  client.stop();
  delay(500);
}

char* appendCharToCharArray(char* array, char a)
{
  size_t len = strlen(array);
  char* ret = new char[len + 2];
  strcpy(ret, array);
  ret[len] = a;
  ret[len + 1] = '\0';
  return ret;
}
