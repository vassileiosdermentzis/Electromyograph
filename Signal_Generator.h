#pragma once

//pour l' utilisation de rand()
#include <cstdlib>
#include <ctime>

#include <math.h>

class Signal_Generator {
		protected:
		
			float V_neg, V_pos; //Tension V+ et V-
			
		public:
		Signal_Generator();
		Signal_Generator(float vn);
		Signal_Generator(float vn, float vp);
		float getPositive();
		float getNegative();
		float generateSignal();
};
			Signal_Generator::Signal_Generator(){
				V_neg = 0;
				V_pos = 0;
			}

			Signal_Generator::Signal_Generator(float vn) {
				V_neg = vn;
			}

			Signal_Generator::Signal_Generator(float vn, float vp){
				V_neg = vn;
				V_pos = vp;
			}
		
		//création du signal positif (return V_pos)
		float Signal_Generator::getPositive(){
		
		//generator de signal positif
    
          	V_pos = (float)rand()/(float)RAND_MAX;
          	V_pos *= pow(10.0,-2.0); 
			
			return V_pos;
		}
		
		//création du signal negatif 
		float Signal_Generator::getNegative(){
		
		//generator de signal negatif
          
          	V_neg = (float)rand()/(float)RAND_MAX;
         	V_neg *= getPositive();
			
			return V_neg;
		}
		
		float Signal_Generator::generateSignal(){
			float V_out;
			V_out = getPositive() - getNegative();
			
			return V_out;

		}

