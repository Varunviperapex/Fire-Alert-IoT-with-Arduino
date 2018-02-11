# Fire-Alert-IoT-with-Arduino
This is FireAlert App Created by me and Prahlad (@Varunviperapex) This app checks for Current temperature, smoke and flame in any particular location. If it detects any increment in flame, smoke or temperature it alerts home owners or Administrations. You can customize this App yourself.
 
![Snapshot 1](https://raw.githubusercontent.com/rohitcoder/Fire-Alert-IoT-with-Arduino/master/Snap1.jpg)
![Snapshot 2](https://raw.githubusercontent.com/rohitcoder/Fire-Alert-IoT-with-Arduino/master/Snap2.jpg)

This is an IOT (Internet of things) based project.This project aims to give people a low cost and effecient way to fireproof their homes,offices,storage units; practically any infrastructure in question.The temperature module in the project also allows users to monitor the temperature and humidity thus never allowing users to compromise their cold storages,green house etc and all such infrasturctures which require a certaing range of temperature to be maintained.The components required are very much affordable and readily available both onlline and offline moreover the installation procedure is quite easy which requires biginner level coding experience in NodeMCU and Arduino (if  in case the user requires customisation).This Documentation is designed to help prototype the basic model of this project.

hardware requirements :
NodeMCU,
Lm 35 temperature sensor/DHT-11(for temp+humidity),
MQ-2 smoke sensor,
IR Flame Sensor,
Arduino Buzzer YL-44,
Arduino UNO,
Bread board/Prototyping board,
Jumperwires [M2M-40 including spares ,M2F-3]

software requirements:
Arduino IDE,
MATLAB Thingspeak Channel 

The System is divided into three different  modules 

1> Temperature Module
The First module is  based on LM35 temperature sensor which has a  detection range range of -55 deg C to +150 deg C the sensor will detect rapid rise in temperature in case of fire i.e. when the temperature exceeds the fixed threshold value NodeMCU sends a message "Temperature rising"and trigger a primary alarm that will notify any person present near the target area by  beeping simultaneously  with a long  delay of 3-4 seconds.

2> Smoke Module
The second module is based on the MQ-2 Smoke sensor which detects the smoke preceding the fire; this triggers a higher magnitude of alarm with a lesser delay also relaying another message ("Smoke Detected") via Node MCU

3.> Flame Module
The third and final module is based on the IR Flame sensor,it detects  IR (Infra Red) light wavelengths between 760 nm – 1100 nm (nano meter) that is emitted from fire/flames from an approximate distance of 2 mtrs. If flames are detected by the module then an even higher pitched alarm is activated with an even lesser delay of 20 ms along with the undesirable ("Fire Detected") message. 
More detailed understading is only possible through code analysis the comments in the codes will help u understand it.
All the three modules work in conjunction with each other to achieve sentiens in order to process all the data from the target area and relay it to the thingspeakserver via NodeMCU Wifi module
below is a screenshot of Thingspeak channel alongwith the real time data readings  recieved from the three individual modules.Thingspeak allows us to display data using dynamic charts for research and analytical purposes.


This IOT project has immense possibilities and numerous applications for example the smoke sensors can be used to analyse and decode the nature of the air molecules to make deductions about  air quality,pollution and other molecules  present in the air like methane butane LPG etc.




