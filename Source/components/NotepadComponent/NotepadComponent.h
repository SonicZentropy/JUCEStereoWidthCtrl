#ifndef NOTEPAD_COMPONENT_H_INCLUDED
#define NOTEPAD_COMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class NotepadComponent : public Component,
	public FileBasedDocument,
	private TextEditor::Listener
{

public:
	NotepadComponent(const String& name, const String& contents);

	~NotepadComponent();

	void resized() override;

	String getDocumentTitle() override;

	Result loadDocument(const File& file) override;

	Result saveDocument(const File& file) override;

	File getLastDocumentOpened() override;

	void setLastDocumentOpened(const File& /*file*/) override;

#if JUCE_MODAL_LOOPS_PERMITTED
	File getSuggestedSaveAsFile(const File&) override;
#endif

private:
	Value textValueObject;
	TextEditor editor;

	void textEditorTextChanged(TextEditor& ed) override;

	void textEditorReturnKeyPressed(TextEditor&) override {}
	void textEditorEscapeKeyPressed(TextEditor&) override {}
	void textEditorFocusLost(TextEditor&) override {}

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NotepadComponent);
};

#endif //NOTEPAD_COMPONENT_H_INCLUDED