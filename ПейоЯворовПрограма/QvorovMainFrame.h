#include "raylib.h"
#include "Button.h"

#include <vector>
#include <algorithm>
#include <string>

class QvorovMainFrame
{
	Image backgroundImage;
	Texture2D backgroundTexture;
	Image peioImage;
	Texture2D peioTexture;

	Rectangle optionsBox;
	Rectangle peioMessageBox;

	//Rectangle options[4];
	std::vector<Button> availableOptions;
	int optionsIndex;

	bool start;
	float startTime;
	Font textFont;
	float howBlack;
	bool peioTalking;
	bool showInterviewOptions;
	std::string peioMessage;

	// Stages
	bool firstOptionSelected;
	bool secondOptionSelected;

	// Defined button
	Button emptyButtonOne;
	Button emptyButtonTwo;
	Button emptyButtonThree;
	Button emptyButtonFour;

	// First option buttons
	Button helloPeioButton;

	// Second option buttons
	Button biographyButton;
	Button whatIsRealLoveButton;
	Button needsForLovePoetryButton;
	Button whatMakesHimWriteButton;


	public:
		QvorovMainFrame();

		void runVisuals();

		void runMath();
};