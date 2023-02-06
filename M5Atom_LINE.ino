//参考：
//こちらの記を元にしたものとなっております。感謝致します！
//
//マイコン技術Navi
//【ESP32】ボタンを押したらLINE通知
//https://www.ekit-tech.com/?p=3434


#include <M5Atom.h>

#include <WiFi.h>
#include <WiFiClientSecure.h>

// WiFi設定
const char* ssid     = "ssid";              //SSIDを入れます。
const char* password = "wifipassword";      //パスワードを入れます。

// LINE Notify設定
const char* host = "notify-api.line.me";
const char* token = "linetokenstrings";     //LINE Notify API で得たトークン文字列を入れます。（発行した時に必ずメモしておく）
const char* message = "ピンポーン";          //好きな文字列

void setup()
{
    //Serial.begin(115200);
  
    M5.begin(true, false, true);   //Clear the serial port buffer, set the serial port baud rate to 115200; initialize the LED matrix.  清空串口缓冲区,设置串口波特率为 115200；初始化LED矩阵

    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);                // WiFi接続

    while (WiFi.status() != WL_CONNECTED) {    // WiFiの接続状態を確認
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    
    M5.dis.fillpix(0xffffff);
}

// line通知
void send_line() {
  WiFiClientSecure client;
  client.setInsecure();      // サーバー証明書の検証を行わずに接続する
  
  Serial.println("Try");
  
  if (!client.connect(host, 443)) {                       //LineのAPIサーバにSSL接続（ポート443:https）
    Serial.println("Connection failed");
    return;
  }
  Serial.println("Connected");

  String query = String("message=") + String(message);   // リクエスト
  String request = String("") +
               "POST /api/notify HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Authorization: Bearer " + token + "\r\n" +
               "Content-Length: " + String(query.length()) +  "\r\n" + 
               "Content-Type: application/x-www-form-urlencoded\r\n\r\n" +
                query + "\r\n";
  client.print(request);
 
  while (client.connected()) {                            // 受信完了まで待機 
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
  
  String line = client.readStringUntil('\n');
  Serial.println(line);
}

int sw_val = 0;                                     // スイッチの変数宣言

void loop(){
  M5.update();

  if ( M5.Btn.wasPressed() ) {
    Serial.println("BtnA.wasPressed() == TRUE");

    sw_val++;
    if (sw_val >= 3) {
      sw_val = 0;
    }

    if (sw_val == 0) {
      M5.dis.fillpix(0xff0000);
    }
    else if (sw_val == 1) {
      M5.dis.fillpix(0x00ff00);
    }
    else if (sw_val == 2) {
      M5.dis.fillpix(0x0000ff);
    }

    send_line();                    // Lineにリクエストを送信する
  }
  
  
}
