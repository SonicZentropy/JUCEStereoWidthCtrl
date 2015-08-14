/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
StereoWidthCtrlAudioProcessor::StereoWidthCtrlAudioProcessor()
{
	UserParams[MasterBypass] = 0.0f; //default to non-bypassed
	UserParams[StereoWidth] = 1.0f; //Normal stereo width by default
	UserParams[MuteAudio] = 0.0f; //Not muted by default
	UserParams[AudioGain] = 0.0f; //set at 0Decibels by default
	widthControl.setWidth(UserParams[StereoWidth]); //Push user width to the controller
	gainControl.setGainFromDB(UserParams[AudioGain]);
	UIUpdateFlag = true; //flag UI for update
}

StereoWidthCtrlAudioProcessor::~StereoWidthCtrlAudioProcessor()
{
}

//==============================================================================
const String StereoWidthCtrlAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int StereoWidthCtrlAudioProcessor::getNumParameters()
{
	return totalNumParam;
}

float StereoWidthCtrlAudioProcessor::getParameter (int index)
{
	switch (index)
	{
	case MasterBypass:
		return UserParams[MasterBypass];
	case StereoWidth:
		UserParams[StereoWidth] = widthControl.getWidth();
		return UserParams[StereoWidth];
	case MuteAudio:
		return UserParams[MuteAudio];
	case AudioGain:
		return UserParams[AudioGain];
	default:
		return 0.0f; //Invalid Index
	}
}

/// This method takes the GUI value and deposits it into the Corresponding Processor Parameter field
void StereoWidthCtrlAudioProcessor::setParameter (int index, float newValue)
{
	switch (index)
	{
		case MasterBypass:
			UserParams[MasterBypass] = newValue;
			break;
		case StereoWidth:
			UserParams[StereoWidth] = newValue; //Set Width Parameter
			widthControl.setWidth(UserParams[StereoWidth]); //Update control value
			break;
		case MuteAudio:
			UserParams[MuteAudio] = newValue;
			break;
		case AudioGain:
			UserParams[AudioGain] = newValue;
			gainControl.setGainFromDB(UserParams[AudioGain]);
			break;
		default: return;
	}
	UIUpdateFlag = true;
}

const String StereoWidthCtrlAudioProcessor::getParameterName (int index)
{
	switch (index)
	{
		case MasterBypass: return "Master Bypass";
		case StereoWidth: return "StereoWidth Factor";
		case MuteAudio: return "Mute Audio";
		case AudioGain: return "Audio Gain";
		default: return String::empty;
	}
}

const String StereoWidthCtrlAudioProcessor::getParameterText (int index)
{
    return String();
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
    return false;
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
void StereoWidthCtrlAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void StereoWidthCtrlAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void StereoWidthCtrlAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    //for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    //    buffer.clear (i, 0, buffer.getNumSamples());

    //// This is the place where you'd normally do the guts of your plugin's
    //// audio processing...
    //for (int channel = 0; channel < getNumInputChannels(); ++channel)
    //{
    //    float* channelData = buffer.getWritePointer (channel);

    //    // ..do something to the data...
    //}
	if (getNumInputChannels() < 2 || UserParams[MasterBypass])
	{
		//Do nothing, just pass through
	}
	else  //Process channel data here **MAIN LOOP**
	{
		// Handle Muting
		if (!UserParams[MuteAudio])
		{
			
			float* leftData = buffer.getWritePointer(0);  //leftData references left channel now
			float* rightData = buffer.getWritePointer(1); //right data references right channel now
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				widthControl.ClockProcess(&leftData[i], &rightData[i]);;
			}
		}
		else if (UserParams[MuteAudio])
		{
			
			float* leftData = buffer.getWritePointer(0);  //leftData references left channel now
			float* rightData = buffer.getWritePointer(1); //right data references right channel now
			
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				leftData[i] = 0.0f;
				rightData[i] = 0.0f;
			}
		}
		else
		{
			DBG("SHOULD NOT EVER ARRIVE HERE");
		}

		// Handle Gain
		if (UserParams[AudioGain] != 1.0f && !UserParams[MuteAudio])
		{ 
			
			float* leftData = buffer.getWritePointer(0);  //leftData references left channel now
			float* rightData = buffer.getWritePointer(1); //right data references right channel now
			for (long i = 0; i < buffer.getNumSamples(); i++)
			{
				gainControl.ClockProcess(&leftData[i], &rightData[i]);;
			}
		}
		
	}

}

//==============================================================================
bool StereoWidthCtrlAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StereoWidthCtrlAudioProcessor::createEditor()
{
    return new StereoWidthCtrlAudioProcessorEditor (*this);
}

//==============================================================================
void StereoWidthCtrlAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
	XmlElement root("Root");
	XmlElement* el;
	el = root.createNewChildElement("Bypass");
	el->addTextElement(String(UserParams[MasterBypass]));
	el = root.createNewChildElement("StereoWidth");
	el->addTextElement(String(UserParams[StereoWidth]));
	el = root.createNewChildElement("Mute");
	el->addTextElement(String(UserParams[MuteAudio]));
	el = root.createNewChildElement("Gain");
	el->addTextElement(String(UserParams[AudioGain]));
	copyXmlToBinary(root, destData);
}

void StereoWidthCtrlAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
	XmlElement* pRoot = getXmlFromBinary(data, sizeInBytes);
	if (pRoot != nullptr)
	{
		forEachXmlChildElement((*pRoot), pChild)
		{
			if (pChild->hasTagName("Bypass"))
			{
				String text = pChild->getAllSubText();
				setParameter(MasterBypass, text.getFloatValue());
			}
			else if (pChild->hasTagName("StereoWidth"))
			{
				String text = pChild->getAllSubText();
				setParameter(StereoWidth, text.getFloatValue());
			}
			else if (pChild->hasTagName("MuteAudio"))  //This shouldn't work?  Switch MuteAudio to Mute
			{
				String text = pChild->getAllSubText();
				setParameter(StereoWidth, text.getFloatValue());
			}
			else if (pChild->hasTagName("Gain"))
			{
				String text = pChild->getAllSubText();
				setParameter(StereoWidth, text.getFloatValue());
			}
		}
		delete pRoot;
		UIUpdateFlag = true;
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StereoWidthCtrlAudioProcessor();
}
