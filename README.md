# embedded_Fire-alarm_arduino

## 这里是嵌入式大作业 - 火灾报警的 arduino 代码

## 主要包含两个部分
#### arduino UNO 端
 代码在arduino_end下面
	 
#### esp8266 端
代码在esp8266_end下面


## 主要思路

1. arduino端连接火焰传感器，MQ4传感器，蜂鸣器。
2. ardunio端读取到火焰传感器、MQ4传感器的值，通过串口的方式传送给esp8266。此外，如果发现火焰或者MQ4值过高，蜂鸣器将会报警。
3. esp8266 接收到arduino传来的值，并且连接上wifi，把这些传感器获得的值传送到tomcat 服务器( [服务器代码请参考](https://github.com/ZJGSU-master/embedded_Fire-alarm_backend)）

