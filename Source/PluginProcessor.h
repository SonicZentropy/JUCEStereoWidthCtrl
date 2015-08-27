

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "JuceHeader.h"
#include "zen_utils/juce_zen_utils.h"
#include "components/StereoWidthCtrlSlider/StereoWidthCtrlSlider.h"
#include "components/GainCtrlSlider/GainCtrlSlider.h"
#include "BufferSampleProcesses.h"
//#include "PluginParameters.h"
//#include "PluginEditor.h"

/// <summary> Handles main VST processing via reactions to automation
/// 		  (which calls the .setParameter() method) as well as GUI handling from PluginEditor.cpp</summary>
/// <seealso cref="T:AudioProcessor"/>
class StereoWidthCtrlAudioProcessor  :  public AudioProcessor, public ParamGroup
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
	//StereoWidthCtrlAudioProcessorEditor* guiEditor;
	
	

	bool needsUIUpdate() { return UIUpdateFlag; };
	void RequestUIUpdate(){ UIUpdateFlag = true; };
	void ClearUIUpdateFlag() { UIUpdateFlag = false; };

	//TEST STUFF
	ScopedPointer<Slider> testSlider;
	float floatVar;
	float logVar;
	enum Params
	{
		floatIndex = 0,
		logIndex,
		logWith0Index,
		symSignedLogIndex,
		asymSignedLogIndex,
		intIndex,
		boolIndex,
		boolButtonIndex
	};
	void initParameters()
	{
		//Parameters   
		addFloatParam(floatIndex, "float", true, SAVE, &floatVar, -6.f, 6.f);
		addLogParam(logIndex, "log", true, SAVE, &logVar, 0.001f, 6.f);
		addLogWith0Param(logWith0Index, "logWith0", true, SAVE, &logWith0Var, 0.001f, 6.f);
		addLogWithSignParam(symSignedLogIndex, "symSignedLog", true, SAVE, &symSignedLogVar, -6.f, 6.f);
		addLogWithSignParam(asymSignedLogIndex, "asymSignedLog", true, SAVE, &asymSignedLogVar, -4.f, 3.f);
		addIntParam(intIndex, "int", true, SAVE, &intVar, 0, 3);
		addBoolParam(boolIndex, "bool", true, SAVE, &boolVar);
		addBoolParam(boolButtonIndex, "boolButton", true, SAVE, &boolButtonVar);
	}

	void runAfterParamChange(int paramIndex, UpdateFromFlags /*updateFromFlag*/)
	{
		switch (paramIndex) {
			case floatIndex:
			{
				logVar = floatVar;
				runAfterParamGroupUpdate();
				intVar = 0; //Custom setting
				getParam(intIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				break;
			}
			case logIndex:
			{
				floatVar = logVar;
				getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				intVar = 0; //Custom setting
				getParam(intIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				break;
			}
			case logWith0Index:
			{
				floatVar = logWith0Var;
				getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				intVar = 0; //Custom Setting
				getParam(intIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				break;
			}
			case symSignedLogIndex:
			{
				floatVar = symSignedLogVar;
				getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				intVar = 0; //Custom Setting
				getParam(intIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				break;
			}
			case asymSignedLogIndex:
			{
				floatVar = asymSignedLogVar;
				getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				intVar = 0; //Custom Setting
				getParam(intIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				break;
			}
			case boolButtonIndex:
			{
				//reset
				floatVar = 1.f;
				getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				runAfterParamGroupUpdate();
				intVar = 2; //Linear 1.0 Setting
				getParam(intIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
				break;
			}
			case intIndex:
			{
				//settings
				if (intVar == 1) {
					floatVar = 0.0f; //Linear 0.0 (Mute) Setting
					getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
					runAfterParamGroupUpdate();
				} else if (intVar == 2) {
					floatVar = 1.f; //Linear 1.0 (Bypass) Setting
					getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
					runAfterParamGroupUpdate();
				} else if (intVar == 3) {
					floatVar = 2.f; //Linear 2.0 Setting
					getParam(floatIndex)->updateHostAndUi(false, UPDATE_FROM_PROCESSOR);
					runAfterParamGroupUpdate();
				}
			}
			default: break;
		}

	}

	void runAfterParamGroupUpdate(){
      //updates all the other parameters with the value of logVar so that they
      //all represent the same value in different logarithmic ranges.

      //this called after a new set of values is loaded to make sure
      //that all variables represent the same value (floatVar).
      logVar=floatVar;
      getParam(logIndex)->updateHostAndUi(false,UPDATE_FROM_PROCESSOR);
      
    }



private:
    //==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(StereoWidthCtrlAudioProcessor)
	
	//ScopedPointer<StereoWidthCtrlSlider> widthControl;
//	VolumeInDBCtrl gainControl;
	bool UIUpdateFlag;
	int debugPrintTimer;
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
