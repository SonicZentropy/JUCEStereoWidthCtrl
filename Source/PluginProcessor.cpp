/* ==============================================================================
//  PluginProcessor.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/17
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Handles main VST processing via reactions to automation
//    	     (which calls the .setParameter() method) as well as GUI handling from PluginEditor.cpp
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
================================================================================*/

#pragma warning (disable : 4100 )  // get rid of unused param warnings

#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;
//==============================================================================
StereoWidthCtrlAudioProcessor::StereoWidthCtrlAudioProcessor()
{
	DBG("Entered method: StereoWidthCtrlAudioProcessor:StereoWidthCtrlAudioProcessor()");
 	addParameter(masterBypassParam = new BoolParameter(0.0f, "MasterBypass"));
 	addParameter(stereoWidthParam = new FloatParameter(0.5f, "StereoWidth"));
 	addParameter(muteAudioParam = new BoolParameter(0.0f, "MuteAudio"));
 	addParameter(audioGainParam = new FloatParameter(0.251189f, "AudioGain")); //0.251189f is 0 gain with this range
 	addParameter(lockGainParam = new BoolParameter(0.0f, "LockGain"));
 	addParameter(invertLeftParam = new BoolParameter(0.0f, "InvertLeft"));
 	addParameter(invertRightParam = new BoolParameter(0.0f, "InvertRight"));
	debugPrintTimer = 0;

	//widthControl = new StereoWidthCtrlSlider("StereoWidthCtrlSlider", stereoWidthParam);
	
	//widthControl->setValue(stereoWidthParam->getValue()); //Push user width to the controller, should happen in constructor now
	//gainControl.setGain(audioGainParam->getValue());
	
	UIUpdateFlag = true; //flag UI for update

}

StereoWidthCtrlAudioProcessor::~StereoWidthCtrlAudioProcessor()
{
	//delete widthControl;
}

//==============================================================================

/**
* Method:    processBlock
* FullName:  StereoWidthCtrlAudioProcessor::processBlock
* Access:    public 
* Qualifier:
* @param     AudioSampleBuffer & buffer
* @param     MidiBuffer & midiMessages
* @return    void
*/
void StereoWidthCtrlAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	/*
	// Assumes Stereo channels only
	// Assumes Equal number of inputs and outputs
	*/
	if (getNumInputChannels() < 2 || masterBypassParam->getValue())
	{
		//Do nothing, just pass through
	}
	else  //Process channel data here **MAIN LOOP**
	{
		float* leftData = buffer.getWritePointer(0);  //leftData references left channel now
		float* rightData = buffer.getWritePointer(1); //right data references right channel now
		//Handle Muting
		if (!muteAudioParam->getValue())
		{
			//Stereo Width Process
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
/*				if (++debugPrintTimer >= 1000)
				{
						DBG("Incoming Width is: " + String(stereoWidthParam->getValue()));
						debugPrintTimer = 0;
				}*/

				BufferSampleProcesses::processStereoWidth(&leftData[i], &rightData[i], stereoWidthParam->getValue());
			}
		}
		else if (muteAudioParam->getValue())  // MUTE ALL Audio
		{

			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				leftData[i] = 0.0f;
				rightData[i] = 0.0f;
			}
		}
		else
		{
			//	throw 
		}
	
		// Handle Gain
		if (audioGainParam->getValue() != 0.251189f && !muteAudioParam->getValue()) // 0.251189f is value for gain = 0.0db in set range -96->12
		{
			//gainControl.setGain(audioGainParam->getValue());
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				//gainControl.processBufferSample(&leftData[i], &rightData[i]);
				if (++debugPrintTimer >= 1000)
				{
					//DBG("Incoming Gain is: " + String(audioGainParam->getValue()));
					debugPrintTimer = 0;
				}
				
				BufferSampleProcesses::processGain(&leftData[i], &rightData[i], audioGainParam->getValue(), 12.0);

			}
		}
		if (invertLeftParam->getValue() && !muteAudioParam->getValue())
		{
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				leftData[i] *= -1;
			}
		}
		if (invertRightParam->getValue() && !muteAudioParam->getValue())
		{
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				rightData[i] *= -1;
			}
		}


	}
	
}

//==============================================================================

//==============================================================================
void StereoWidthCtrlAudioProcessor::getStateInformation(MemoryBlock& destData)
{
	// #TODO: Implement State Information
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.
	// 	XmlElement root("Root");
	// 	XmlElement* el;
	// 	el = root.createNewChildElement("Bypass");
	// 	el->addTextElement(String(UserParams[MasterBypass]));
	// 	el = root.createNewChildElement("StereoWidth");
	// 	el->addTextElement(String(UserParams[StereoWidth]));
	// 	el = root.createNewChildElement("MuteAudio");      // This shouldn't work? Was "Mute"
	// 	el->addTextElement(String(UserParams[MuteAudio]));
	// 	el = root.createNewChildElement("Gain");
	// 	el->addTextElement(String(UserParams[AudioGain]));
	// 	copyXmlToBinary(root, destData);
}

void StereoWidthCtrlAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.
	// 	XmlElement* pRoot = getXmlFromBinary(data, sizeInBytes);
	// 	if (pRoot != nullptr)
	// 	{
	// 		forEachXmlChildElement((*pRoot), pChild)
	// 		{
	// 			if (pChild->hasTagName("Bypass"))
	// 			{
	// 				String text = pChild->getAllSubText();
	// 				setParameter(MasterBypass, text.getFloatValue());
	// 			}
	// 			else if (pChild->hasTagName("StereoWidth"))
	// 			{
	// 				String text = pChild->getAllSubText();
	// 				setParameter(StereoWidth, text.getFloatValue() / 2.0f);
	// 			}
	// 			else if (pChild->hasTagName("MuteAudio"))  //This shouldn't work?  Switch MuteAudio to Mute
	// 			{
	// 				String text = pChild->getAllSubText();
	// 				setParameter(StereoWidth, text.getFloatValue());
	// 			}
	// 			else if (pChild->hasTagName("Gain"))
	// 			{
	// 				String text = pChild->getAllSubText();
	// 				setParameter(StereoWidth, text.getFloatValue());
	// 			}
	// 		}
	// 		delete pRoot;
	// 		UIUpdateFlag = true;
	//	}
}

//==============================================================================

const String StereoWidthCtrlAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

const String StereoWidthCtrlAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String StereoWidthCtrlAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool StereoWidthCtrlAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool StereoWidthCtrlAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool StereoWidthCtrlAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool StereoWidthCtrlAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool StereoWidthCtrlAudioProcessor::silenceInProducesSilenceOut() const
{
    return true;
}

double StereoWidthCtrlAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int StereoWidthCtrlAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int StereoWidthCtrlAudioProcessor::getCurrentProgram()
{
    return 0;
}

void StereoWidthCtrlAudioProcessor::setCurrentProgram (int index)
{

}

const String StereoWidthCtrlAudioProcessor::getProgramName (int index)
{
	return String();
}

void StereoWidthCtrlAudioProcessor::changeProgramName (int index, const String& newName)
{
	
}

//==============================================================================

void StereoWidthCtrlAudioProcessor::prepareToPlay (double inSampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	//sampleRate = inSampleRate;
	samplesPerBlock = samplesPerBlock;
}


void StereoWidthCtrlAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

//==============================================================================
bool StereoWidthCtrlAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StereoWidthCtrlAudioProcessor::createEditor()
{
	return new StereoWidthCtrlAudioProcessorEditor(*this);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StereoWidthCtrlAudioProcessor();
}
