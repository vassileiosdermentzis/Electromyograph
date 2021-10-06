/*Dequantization du signal, pour être net et sans bruit
*/

#pragma once

#include "amplifier.h"

class Mega644ADC:public amplifier{
	protected:
		float V_ref; //V referential
	
	public:
		amplifier SignalAmp;
		Mega644ADC();
		Mega644ADC(float vr);
		void setMega644ADC(float vr);
		float getMega644ADC();
		Mega644ADC(amplifier snAmp);
		float transmit(amplifier amp);

};

		
		Mega644ADC::Mega644ADC(){
			V_ref = 0;
		}
		
		Mega644ADC::Mega644ADC(float vr){
			V_ref = vr;
		}

		void Mega644ADC::setMega644ADC(float vr){
			V_ref = vr;
		}
		
		float Mega644ADC::getMega644ADC(){
			return V_ref;
		}

		Mega644ADC::Mega644ADC(amplifier snAmp){
			snAmp = SignalAmp;
		}

		float Mega644ADC::transmit(amplifier amp){
			/*			
			   V_ref = amplify(generateSignal() - (0.013 * amplify(generateSignal());
			   
			   assumer que amplify(generateSignal() = a.
			   
			   a - 0.013*a =>
			   a * (1 - 0.013) =>
			   a * 0.987.
			*/
			V_ref = 0.987 * amp.amplify(SignalAmp);
			return V_ref;	   
		}

