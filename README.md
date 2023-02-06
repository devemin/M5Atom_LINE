# M5Atom_LINE

M5 ATOM Matrix (ESP32 PICO) のボタンを押すと、LINE に通知を送ります。

LINE Notify API を利用
（個人ユーザーは1時間に1000回まで）


# 動作のようす

![image](https://user-images.githubusercontent.com/52738228/216858395-27668fe2-c0f0-40fe-834d-80f141b80e9b.png)

動画

https://twitter.com/devemin/status/1622398806901006336

# HOW TO USE

1. こちらの元の記事を参考に、LINE Notify API のトークン文字列を発行し、メモります。

   https://www.ekit-tech.com/?p=3434

2. Arduino IDE を使い、M5Atom_LINE.ino ファイルに、"WiFi SSID" / "パスワード" / "LINE トークン文字列" / "好きなメッセージ文字列" を入力します。そして M5 ATOM Matrix に書き込んでください。

3. ボタンを押せば通知が届くはずです。便利♪

4.（電源をつけるとLED が白くなり、ボタンを押すたびに色が変わります。電波が悪いと正しく動作せず色が変わりませんので注意）

# 参考元：

ほぼこちらの記事を元にしたものとなっております。感謝致します！

マイコン技術Navi
【ESP32】ボタンを押したらLINE通知

https://www.ekit-tech.com/?p=3434


# 確認環境

M5Stack 社 M5 ATOM Matrix

Arduino IDE (ver 1.8.9)

M5Stack ボードマネージャ ライブラリ (ver 2.0.3)

（ソースの LED 部を削って、ノーマル M5 ATOM 等でももちろん使えると思います。）


# ライセンス

MIT LICENSE
