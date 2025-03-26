
#ifndef ArduinoClassMethodNamesEnable_hpp
	#define ArduinoClassMethodNamesEnable_hpp

	#include "Logger_status.hpp"
	#include "InvokeMethod.hpp"
	#include "InvokeRawList.hpp"
	#include "ArrayRawMap.hpp"

	namespace pankey{

		namespace Base{

			ArrayRawMap<String,ArrayRawList<String>> g_ArduinoClassMethodNamesEnable_map;
		
			template<class L>
			bool ArduinoClassMethodNamesEnable(int a_status, const String& a_name, const String& a_method, L a_log){
				for(auto entry :  g_ArduinoClassMethodNamesEnable_map){
				  String f_key = entry.getKey();
				  if(f_key != a_name){
					continue;
				  }
				  ArrayRawList<String> f_value = entry.getValue();
				  if(f_value.contain(a_method)){
					return true;
				  }
				}
				return false;
			}

			template<class... Args>
			void pankey_Log_Class_Method(String a_class, Args... a_methods){
				ArrayRawList<String> i_methods;
				i_methods.addPack(a_methods...);
				g_ArduinoClassMethodNamesEnable_map.put(a_class,i_methods);
			}

		}

	}

	#ifndef pankey_Log_enable
		#define pankey_Log_enable(status,name,method,mns) pankey::Base::ArduinoClassMethodNamesEnable(status,name,method,mns)
	#endif

#endif 

