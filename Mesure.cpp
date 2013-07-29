/*
 * Mesure.cpp
 *
 *  Created on: 29 juil. 2013
 *      Author: Alexandre
 */

#include "Mesure.h"

Mesure::Mesure(int pin, int tempo, int nbTemps, int nbTempsTot)
{
	m_pin = pin;
	m_tempo = tempo*10;
	m_nbTempsJoue = nbTemps;
	m_nbTempsTot = nbTempsTot;

	m_tabNote[0] = NULL;
}

Mesure::~Mesure()
{
	int i = 0;
	while(m_tabNote[i] != '\0')
	{
		m_tabNote[i]->~Note();
		i++;
	}
}

void Mesure::addNote(int note, int octave, float duree)
{
	int i = 0;
	while(m_tabNote[i] != NULL)
		i++;

	m_tabNote[i] = new Note(m_pin,note,octave,duree*m_tempo);
	m_tabNote[i+1] = '\0';
}

void Mesure::play()
{
	int i = 0;
	while(m_tabNote[i] != '\0')
	{
		m_tabNote[i]->play();
		i++;
	}
}

void Mesure::loop(int loop)
{
	while(loop > 0)
	{
		play();
		loop--;
	}
}

/*********************** Error ******************/

/**
 * Incomplete mesure.
 * 1 bip each second
 */
void Mesure::mesureError()
{
	Note *n;
	n = new Note(m_pin,440,100);
	while(1)
		n->play();
}
//TODO impleter method
