/*
 * MIDI_application.c
 *
 *  Created on: 6 d�c. 2014
 *      Author: Xavier Halgand
 *
 *	Modified on: 9/12/16 by C.P. to handle the MIDI_IDLE state properly, and
 *	added required code to be compatible with "NucleoSynth"
 *
 *	11/8/17 by C.P.: Version 0.7.7 - Use for Casio CTK-6200 Keyboard
 */

/* Includes ------------------------------------------------------------------*/
#include "audiostream.h"
#include "MIDI_application.h"
#include "usbh_core.h"
#include "usbh_MIDI.h"
#include "usb_host.h"
MIDI_ApplicationTypeDef MIDI_Appli_state = MIDI_APPLICATION_READY;
extern ApplicationTypeDef Appli_state;
extern USBH_HandleTypeDef hUsbHostFS;
uint8_t MIDI_RX_Buffer[RX_BUFF_SIZE] __ATTR_RAM_D2; // MIDI reception buffer

uint8_t key, velocity, ctrl, data, sustainInverted;

uint8_t paramvalue[256], firstkey, h;
/* Private define ------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/




/*-----------------------------------------------------------------------------*/
/**
 * @brief  Main routine for MIDI application, looped in main.c
 * @param  None
 * @retval none
 */
void MIDI_Application(void)
{
	if(Appli_state == APPLICATION_READY)
	{
		if(MIDI_Appli_state == MIDI_APPLICATION_READY)
		{

			USBH_MIDI_Receive(&hUsbHostFS, MIDI_RX_Buffer, RX_BUFF_SIZE); // just once at the beginning, start the first reception
			MIDI_Appli_state = MIDI_APPLICATION_RUNNING;
		}
	}
	if(Appli_state == APPLICATION_DISCONNECT)
	{
		MIDI_Appli_state = MIDI_APPLICATION_READY;
		USBH_MIDI_Stop(&hUsbHostFS);
	}
}

/*-----------------------------------------------------------------------------*/
void ProcessReceivedMidiDatas(uint32_t myLength)
{
	uint16_t numberOfPackets;
	uint8_t *ptr = MIDI_RX_Buffer;
	midi_package_t pack;

	numberOfPackets = myLength >> 2; //each USB midi package is 4 bytes long

	if (numberOfPackets != 0)
	{
		while(numberOfPackets--)
		{
			pack.cin_cable = *ptr ; ptr++ ;
			pack.evnt0 = *ptr ; ptr++ ;
			pack.evnt1 = *ptr ; ptr++ ;
			pack.evnt2 = *ptr ; ptr++ ;

			// Handle MIDI messages
			switch(pack.evnt0)
			{
				case (0x80): // Note Off
					key = pack.evnt1;
					velocity = pack.evnt2;

					noteOff(key, velocity);

					break;
				case (0x90): // Note On
					key = pack.evnt1;
					velocity = pack.evnt2;

					noteOn(key, velocity);

					break;
				case (0xA0):
					break;
				case (0xB0):
					ctrl = pack.evnt1;
					data = pack.evnt2;
					switch(ctrl)
					{


						case (0x01):
								//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, data);
								break;
											/*
							for (int i = 0; i < 8; i++)
							{
								tCycleSetFreq(osc[i], ((((float)data) * INV_TWO_TO_7) * 1000.0f) + 100.0f + detuneAmounts[i]);
							}
							break;
						case (0x02):
									for (int i = 8; i < 16; i++)
									{
										tCycleSetFreq(osc[i], ((((float)data) * INV_TWO_TO_7) * 1000.0f) + 100.0f + detuneAmounts[i]);
									}
							break;
						case (0x03):
									for (int i = 16; i < 24; i++)
									{
										tCycleSetFreq(osc[i], ((((float)data) * INV_TWO_TO_7) * 1000.0f) + 100.0f + detuneAmounts[i]);
									}
							break;
						case (0x04):
									for (int i = 24; i < 32; i++)
									{
										tCycleSetFreq(osc[i], ((((float)data) * INV_TWO_TO_7) * 1000.0f) + 100.0f + detuneAmounts[i]);
									}
							break;
*/
						case (0x0D):
							break;
						case (0x4B):
							break;
						case (0x4C):
							break;
						case (0x5C):
							break;
						case (0x5F):
							break;
						case (0x49):
							break;
						case (0x48):
							break;
						case (0x5B):
							break;
						case (0x5D):
							break;
						case (0x4A):
							break;
						case (0x47):
							break;
						case (0x05):
							break;
						case (0x54):
							break;
						case (0x10):
							break;
						case (0x11):
							break;
						case (0x12):
							break;
						case (0x07):
							break;
						case (0x13):
							break;
						case (0x14):
							break;
						case (64): // sustain
							if (data)
							{
								if (sustainInverted) 	sustainOff();
								else					sustainOn();
							}
							else
							{
								if (sustainInverted) 	sustainOn();
								else					sustainOff();
							}
							break;
					}


          break;
				case (0xC0): // Program Change
					break;
				case (0xD0): // Mono Aftertouch
					break;
				case (0xE0): // Pitch Bend
					data = pack.evnt2;
					break;
				case (0xF0):
					break;
			}
		}
	}
}

void LocalMidiHandler(uint8_t param, uint8_t data)
{
	switch(param)
	{
		case (0): // pitch wheel
			break;
		case (1): // modulation wheel
			break;
		case (2): // Tuning

			break;
		case (3): // Wave Select

			break;
		case (4): // OSC Mix

			break;
		case (5): // De-Tune

			break;
		case (6): // Scale

			break;
		case (7): // Resonance

			break;
		case (8): // Pulse Width Value

			break;
		case (9): // PWM Level

			break;
		case (10): // VCF Attack

			break;
		case (11): // VCF Decay

			break;
		case (12): // VCF Sustain

			break;
		case (13): // VCF Release

			break;
		case (14): // VCA Attack

			break;
		case (15): // VCA Decay

			break;
		case (16): // VCA Sustain

			break;
		case (17): // VCA Release

			break;
		case (18): // VCF Follow Level

			break;
		case (19): // ENV Follow Level

			break;
		case (20): // Velocity Select

			break;
		case (21): // VCF Envelope Level

			break;
		case (22): // Mod LFO rate

			break;
		case (23): // Pwm LFO rate

			break;
	}
	paramvalue[param] = data;
}

/*-----------------------------------------------------------------------------*/
/**
 * @brief  MIDI data receive callback.
 * @param  phost: Host handle
 * @retval None
 */
void USBH_MIDI_ReceiveCallback(USBH_HandleTypeDef *phost, uint32_t myLength)
{
	ProcessReceivedMidiDatas(myLength);
	USBH_MIDI_Receive(&hUsbHostFS, MIDI_RX_Buffer, RX_BUFF_SIZE); // start a new reception
}

