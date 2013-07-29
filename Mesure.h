/*
 * Mesure.h
 *
 *  Created on: 29 juil. 2013
 *      Author: Alexandre
 */

#ifndef MESURE_H_
#define MESURE_H_

#include "Note.h"

#define RONDE 4
#define BLANCHE 2
#define NOIR 1
#define CROCHE 0.5
#define DB_CROCHE 0.25

class Mesure
{
	public:
		Mesure(int pin, int tempo, int nbTemps, int nbTempsTot);
		virtual ~Mesure();

		void addNote(int note, int octave, float duree);
		void play();
		void loop(int loop = 2);

	private:
		/**
		 * Pin of the speaker
		 */
		int m_pin;

		/**
		 * mesure's tempo
		 */
		int m_tempo;

		/**
		 * Amount of beat play
		 */
		int m_nbTempsJoue;

		/**
		 * Amount of beat total
		 */
		int m_nbTempsTot;

		/**
		 * tableau de note
		 */
		Note *m_tabNote[];

		void mesureError();
};

#endif /* MESURE_H_ */
