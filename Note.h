/**
 * Note.h
 *
 *  Created on: 29 juil. 2013
 *      Author: Alexandre Guyon
 *
 *  Used to generate a pulse on arduino's pin. If you 're connecting
 *  a speaker to it, you will hear the song of the freq.
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

// TODO Add timbre

class Note
{
	public:
		/**
		 * Contructor of the class.
		 * Used for frequence
		 * @param pin The out pin
		 * @param freq The frequance of the signam
		 * @param time The  duration of the signal before stop (millis)
		 */
		Note(int pin, int freq, double time);

		/**
		 * Constructor of the class.
		 * Used for Note
		 * @param pin The out pin
		 * @param note The defined note
		 * @param octave The octave of the note
		 * @param time The  duration of the signal before stop (millis)
		 */
		Note(int pin, float note, int octave, double time);

		/**
		 * Destructor
		 */
		virtual ~Note();

		/**
		 * Play the note
		 */
		void play();

	private:
		/**
		 * The pin where is connected the speakers
		 */
		int m_pin;

		/**
		 * The time of the half period of the signal
		 */
		int m_tPeriod;

		/**
		 * The final time, note have to be hear
		 */
		double m_fTime;

		/**
		 * Current time at the begening of the note
		 */
		unsigned int m_cTime;

		/**
		 * Time of silent before and/or after the note
		 * (microsecond)
		 */
		static const unsigned int SILENT_TIME = 100;
};

#endif /* NOTE_H_ */
