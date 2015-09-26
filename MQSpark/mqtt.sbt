name := "MQTT Project"

version := "1.0"

scalaVersion := "2.10.5"

libraryDependencies += "org.apache.spark" %% "spark-core" % "1.5.0"
libraryDependencies += "org.mongodb" % "mongo-java-driver" % "3.0.4"
libraryDependencies += "org.mongodb" % "bson" % "3.0.4"
libraryDependencies += "org.mongodb.mongo-hadoop" % "mongo-hadoop-core" % "1.4.0"
libraryDependencies += "org.apache.spark" % "spark-streaming_2.10" % "1.5.0"
libraryDependencies += "org.apache.spark" % "spark-streaming-mqtt_2.11" % "1.5.0"
libraryDependencies += "org.eclipse.paho" % "mqtt-client" % "0.4.0"
libraryDependencies += "org.eclipse.paho" % "org.eclipse.paho.client.mqttv3" % "1.0.2"

resolvers += "MQTT Repository" at "https://repo.eclipse.org/content/repositories/paho-releases/"