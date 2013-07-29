/*
 * Note.cpp
 *
 *  Created on: 29 juil. 2013
 *      Author: Alexandre
 */

#include "Note.h"

/**
 * @param time (milliseconde)
 */
Note::Note(int pin, int freq, double time)
{
	Note::pin = pin;
	Note::tPeriod = ((1/(float)freq)*1000000) / 2;
	Note::fTime = time;
	Note::cTime = millis();
	pinMode(pin,OUTPUT);
}

/**
 * @param time (milliseconde)
 */
Note::Note(int pin, float note, int octave, double time)
{
	Note::pin = pin;
	Note::tPeriod = ((1/(note*pow(2,octave+1)))*1000000) / 2;
	Note::fTime = time;
	Note::cTime = millis();
	pinMode(pin,OUTPUT);
	Note::play();
}

Note::~Note()
{

}

void Note::play()
{
	while(millis() < (Note::cTime + Note::fTime))
	{
		digitalWrite(Note::pin, HIGH);
		delayMicroseconds(Note::tPeriod);
		digitalWrite(Note::pin, LOW);
		delayMicroseconds(Note::tPeriod);
	}
}

