/*
 * Note.cpp
 *
 *  Created on: 29 juil. 2013
 *      Author: Alexandre
 */

#include "Note.h"

Note::Note(int pin, int freq, double time)
{
	m_pin = pin;
	m_tPeriod = ((1/(float)freq)*1000000) / 2;
	m_fTime = time;
	m_cTime = millis();
	pinMode(pin,OUTPUT);
}

Note::Note(int pin, float note, int octave, double time)
{
	m_pin = pin;
	m_tPeriod = ((1/(note*pow(2,octave+1)))*1000000) / 2;
	m_fTime = time;
	m_cTime = millis();
	pinMode(pin,OUTPUT);
}

Note::~Note()
{

}

void Note::play()
{
	delayMicroseconds(SILENT_TIME);
	while(millis() < (m_cTime + m_fTime))
	{
		digitalWrite(m_pin, HIGH);
		delayMicroseconds(m_tPeriod);
		digitalWrite(m_pin, LOW);
		delayMicroseconds(m_tPeriod);
	}
	delayMicroseconds(SILENT_TIME);
}

