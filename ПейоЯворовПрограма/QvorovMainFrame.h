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
	bool thirdOptionSelected;
	bool fourthOptionSelected;
	bool fifthOptionSelected;
	bool sixthOptionSelected;

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

	// Third option buttons
	Button whatMadeHimFightButton;
	Button worstPartOfRevolutionButton;
	Button wasItWorthItButton;
	Button isFateRealButton;

	// Fourth option buttons
	Button whatDoyouLeaveButton;
	Button whatMakesPoetryAlive;
	Button doYoufeelMoreUnderstoodButton;
	Button doesThePoetHaveToBeUnderstoodButton;

	// Fifth option buttons
	Button whyChangeGanreButton;
	Button whatDoYouMissMostButton;
	Button ifYouCouldChangeSomethingButton;
	Button favoritePeioPoemButton;

	// Sixth option buttons
	Button goodbyePeioButton;
	

	public:
		QvorovMainFrame();

		void runVisuals();

		void runMath();
};