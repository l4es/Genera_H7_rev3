/*==============================================================================

    leaf-midi.h
    Created: 30 Nov 2018 11:29:26am
    Author:  airship

==============================================================================*/

#ifndef LEAF_MIDI_H_INCLUDED
#define LEAF_MIDI_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif
    
//==============================================================================
    
#include "leaf-globals.h"
#include "leaf-math.h"

#include "leaf-utilities.h"

//==============================================================================
    
#define POLY_NUM_MAX_VOICES 4
/* tPoly */
typedef struct _tPoly
{
    tStack* stack;
    tStack* orderStack;
    
    tRamp* ramp[POLY_NUM_MAX_VOICES];
    float rampVals[POLY_NUM_MAX_VOICES];
    oBool firstReceived[POLY_NUM_MAX_VOICES];
    float glideTime;
    oBool pitchGlideIsActive;
    
    int numVoices;
    
    int voices[POLY_NUM_MAX_VOICES][2];
    
    int notes[128][2];
    
    int CCs[128];
    
    uint8_t CCsRaw[128];
    
    int lastVoiceToChange;
    
    float pitchBend;
    tRamp* pitchBendRamp;
    
    int currentNote;
    int currentVoice;
    int currentVelocity;
    int maxLength;
    
} tPoly;

/* MPoly*/
void    tPoly_init(tPoly* const, int numVoices);
void    tPoly_free(tPoly* const);

//ADDING A NOTE
int     tPoly_noteOn(tPoly* const, int note, uint8_t vel);
int     tPoly_noteOff(tPoly* const, uint8_t note);
void    tPoly_orderedAddToStack(tPoly* const, uint8_t noteVal);
void    tPoly_setNumVoices(tPoly* const, uint8_t numVoices);

void    tPoly_setPitchBend(tPoly* const, float pitchBend);
void    tPoly_setPitchGlideActive(tPoly* const, oBool isActive);
void    tPoly_setPitchGlideTime(tPoly* const, float t);
void    tPoly_tickPitch(tPoly* const);
void    tPoly_tickPitchGlide(tPoly* const);
void    tPoly_tickPitchBend(tPoly* const);
    
int     tPoly_getNumVoices(tPoly* const);
float   tPoly_getPitch(tPoly* const, uint8_t voice);
int     tPoly_getKey(tPoly* const, uint8_t voice);
int     tPoly_getVelocity(tPoly* const, uint8_t voice);
int     tPoly_isOn(tPoly* const, uint8_t voice);

//==============================================================================
    
#ifdef __cplusplus
}
#endif

#endif // LEAF_MIDI_H_INCLUDED

//==============================================================================

