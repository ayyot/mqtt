# Ayyot Sample Demo files for MQTT on IOT Platforms

YunMQTT folder
--------------
Platform - Arduino YUN
Arduino - 1.6.4

Schematics
- Arduino simple relay switch control 

Details
- When it trun on, enable relay/LED 13 and publish Light ON to Mosquitto server
- When it trun on, enable relay/LED 13 and publish Light OFF to Mosquitto server

MQSpark folder
--------------
Spark Scala program to setup MQTT subscriber program

Setup the same Subscriber topic which was set by Yun 
Keep wait for new message arrival from Mosquitto server as soon as Yub publish
