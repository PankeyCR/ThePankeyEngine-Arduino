
#ifndef arduinoStringHelper_hpp
	#define arduinoStringHelper_hpp

	#include "ArrayPointer.hpp"

		namespace pankey{

			template<class T>
			String toString(const T& a_add){
				return String(a_add);
			}
			
			template<class T>
			String concat(const T& a_add){
				return String(a_add);
			}
			
			template<class T, class... Args>
			String concat(const T& a_string, const Args&... a_add){
				String i_string = String(a_string) + concat(a_add...);
				return i_string;
			}

			IPAddress toIPAddress(const String& a_ip){
				IPAddress i_ip;
				i_ip.fromString(a_ip);
				return i_ip;
			}

			Base::ArrayPointer<uint8_t> toMAC(const String& a_mac){
				Base::ArrayPointer<uint8_t> i_mac;
				i_mac.createArray(6);
				String i_note;
				for(int x = 0; x < a_mac.length(); x++){
					char f_char = a_mac.charAt(x);
					if(f_char == '.'){
						uint8_t i_value = i_note.toInt();
						i_mac.add(i_value);
						i_note = "";
						continue;
					}
					i_note += f_char;
				}
				if(!i_note.isEmpty()){
					uint8_t i_value = i_note.toInt();
					i_mac.add(i_value);
				}
				return i_mac;
			}

			using MACAddress = Base::ArrayPointer<uint8_t>;
			
		}
 
#endif