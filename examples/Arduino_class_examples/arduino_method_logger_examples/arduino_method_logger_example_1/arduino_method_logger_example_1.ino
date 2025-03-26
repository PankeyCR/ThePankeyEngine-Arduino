
#include "ArduinoClassMethodNamesEnable.hpp"
#include "arduino_method_logger.hpp"

#define Array_Log
//#define pankey_Global_Log
//#define pankey_Base_Log

#include "Array.hpp"

using namespace pankey::Base;

void setup() {
  Serial.begin(9600);
  pankey_Log_Class_Method("Array", "addLocalValue");
  pankey_Log_Start();
}

void loop() {
  Array<int> array;
  array.addLocalValue(5);
  array.addLocalValue(6);
  array.addLocalValue(7);
  for(int x : array){
    Serial.println(x);
  }
  delay(3000);
}