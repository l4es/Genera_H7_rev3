/*
  ==============================================================================

    leaf.h
    Created: 20 Jan 2017 12:07:26pm
    Author:  Michael R Mulshine

  ==============================================================================
*/

#ifndef LEAF_H_INCLUDED
#define LEAF_H_INCLUDED

#define LEAF_DEBUG 0

#if LEAF_DEBUG
#include "../LEAF_JUCEPlugin/JuceLibraryCode/JuceHeader.h"
#endif

#if _WIN32 || _WIN64

#include ".\Inc\leaf-globals.h"
#include ".\Inc\leaf-math.h"
#include ".\Inc\leaf-utilities.h"
#include ".\Inc\leaf-delay.h"
#include ".\Inc\leaf-filter.h"
#include ".\Inc\leaf-oscillator.h"
#include ".\Inc\leaf-oversampler.h"
#include ".\Inc\leaf-reverb.h"
#include ".\Inc\leaf-vocoder.h"
#include ".\Inc\leaf-808.h"
#include ".\Inc\leaf-string.h"
#include ".\Inc\leaf-pitch.h"
#include ".\Inc\leaf-formant.h"
#include ".\Inc\leaf-midi.h"
#include ".\Inc\leaf-sample.h"
#include ".\Inc\leaf-crusher.h"
#include ".\Inc\leaf-wavefolder.h"
#include ".\Inc\leaf-wavetables.h"

#else

#include "./Inc/leaf-globals.h"
#include "./Inc/leaf-math.h"
#include "./Inc/leaf-utilities.h"
#include "./Inc/leaf-delay.h"
#include "./Inc/leaf-filter.h"
#include "./Inc/leaf-oscillator.h"
#include "./Inc/leaf-oversampler.h"
#include "./Inc/leaf-reverb.h"
#include "./Inc/leaf-vocoder.h"
#include "./Inc/leaf-808.h"
#include "./Inc/leaf-string.h"
#include "./Inc/leaf-pitch.h"
#include "./Inc/leaf-formant.h"
#include "./Inc/leaf-midi.h"
#include "./Inc/leaf-sample.h"
#include "./Inc/leaf-crusher.h"
#include "./Inc/leaf-wavefolder.h"
#include "./Inc/leaf-wavetables.h"

#endif

#ifdef __cplusplus
extern "C" {
#endif
    
void        LEAF_init            (float sampleRate, int blocksize, float(*randomNumberFunction)(void));
void        LEAF_setSampleRate   (float sampleRate);
float       LEAF_getSampleRate   (void);

#ifdef __cplusplus
}
#endif

#endif  // LEAF_H_INCLUDED
