#include "NotepadComponent.h"


NotepadComponent::NotepadComponent(const String& name, const String& contents) : FileBasedDocument(".jnote", "*.jnote",
	"Browse for note to load",
	"Choose file to save note to"),
	textValueObject(contents)
{
	// we need to use an separate Value object as our text source so it doesn't get marked
	// as changed immediately
	setName(name);

	editor.setMultiLine(true);
	editor.setReturnKeyStartsNewLine(true);
	editor.getTextValue().referTo(textValueObject);
	addAndMakeVisible(editor);
	editor.addListener(this);
}

NotepadComponent::~NotepadComponent()
{
	editor.removeListener(this);
}

void NotepadComponent::resized()
{
	editor.setBounds(getLocalBounds());
}

String NotepadComponent::getDocumentTitle()
{
	return getName();
}

Result NotepadComponent::loadDocument(const File& file)
{
	editor.setText(file.loadFileAsString());
	return Result::ok();
}

Result NotepadComponent::saveDocument(const File& file)
{
	// attempt to save the contents into the given file
	FileOutputStream os(file);

	if (os.openedOk())
		os.writeText(editor.getText(), false, false);

	return Result::ok();
}

File NotepadComponent::getLastDocumentOpened()
{
	// not interested in this for now
	return File::nonexistent;
}

void NotepadComponent::setLastDocumentOpened(const File& /*file*/)
{
	// not interested in this for now
}

#if JUCE_MODAL_LOOPS_PERMITTED
File NotepadComponent::getSuggestedSaveAsFile(const File&)
{
	return File::getSpecialLocation(File::userDesktopDirectory).getChildFile(getName()).withFileExtension("jnote");
}

void NotepadComponent::textEditorTextChanged(TextEditor& ed)
{
	// let our FileBasedDocument know we've changed
	if (&ed == &editor)
		changed();
}

#endif