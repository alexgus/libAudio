/*
 * Note.h
 *
 *  Created on: 29 juil. 2013
 *      Author: Alexandre
 */

#ifndef NOTE_H_
#define NOTE_H_

#include "Arduino.h"

// Define note at -1 octave
#define Note_C 16.3
#define Note_Cd 17.3
#define Note_D 18.3
#define Note_Dd 19.4
#define Note_E 20.5
#define Note_F 21.8
#define Note_Fd 23.1
#define Note_G 24.5
#define Note_Gd 26
#define Note_A 27.5
#define Note_Ad 29.1
#define Note_B 30.8

// TODO Inclure silence

class Note
{
	public:
		Note(int pin, int freq, double time);
		Note(int pin, float note, int octave, double time);
		virtual ~Note();

		void play();

	private:
		/**
		 * The pin where is connected the speakers
		 */
		int pin;

		/**
		 * The time of the period of the signal / 2
		 */
		int tPeriod;

		/**
		 * Final time. The note have to play this time
		 */
		double fTime;

		/**
		 * Current time of the note is playing
		 */
		unsigned int cTime;
};

#endif /* NOTE_H_ */
