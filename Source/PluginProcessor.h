

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "zen_utils/juce_zen_utils.h"
#include "components/StereoWidthCtrlSlider/StereoWidthCtrlSlider.h"
#include "components/GainCtrlSlider/GainCtrlSlider.h"
#include "BufferSampleProcesses.h"

/// <summary> Handles main VST processing via reactions to automation
/// 		  (which calls the .setParameter() method) as well as GUI handling from PluginEditor.cpp</summary>
/// <seealso cref="T:AudioProcessor"/>
class StereoWidthCtrlAudioProcessor  :  public AudioProcessor
{
public:

    //==============================================================================
    StereoWidthCtrlAudioProcessor();
    ~StereoWidthCtrlAudioProcessor();

	//==============================================================================
	void processBlock(AudioSampleBuffer& audioSampleBuffer, MidiBuffer& midiBuffer) override;

	//==============================================================================
	void getStateInformation(MemoryBlock& destData) override;
	void setStateInformation(const void* data, int sizeInBytes) override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    //int getNumParameters() override;
    //float getParameter (int index) override;
    //void setParameter (int index, float newValue) override;

    //const String getParameterName (int index) override;
    //const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

	//==============================================================================

	
	//add boolean param derived class
	AudioProcessorParameter* masterBypassParam;
 	AudioProcessorParameter* stereoWidthParam;
 	AudioProcessorParameter* muteAudioParam;
 	AudioProcessorParameter* audioGainParam;
 	AudioProcessorParameter* lockGainParam;
 	AudioProcessorParameter* invertLeftParam;
 	AudioProcessorParameter* invertRightParam;

	bool needsUIUpdate() { return UIUpdateFlag; };
	void RequestUIUpdate(){ UIUpdateFlag = true; };
	void ClearUIUpdateFlag() { UIUpdateFlag = false; };

private:
    //==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoWidthCtrlAudioProcessor)
	
	//ScopedPointer<StereoWidthCtrlSlider> widthControl;
//	VolumeInDBCtrl gainControl;
	bool UIUpdateFlag;
	int debugPrintTimer;
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
