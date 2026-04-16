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
	Sound helloPeioSound;
	Button helloPeioButton;

	// Second option buttons
	Sound biographySound;
	Button biographyButton;

	Sound whatIsRealLoveSound;
	Button whatIsRealLoveButton;

	Sound needsForLovePoetrySound;
	Button needsForLovePoetryButton;

	Sound whatMakesHimWriteSound;
	Button whatMakesHimWriteButton;
	

	// Third option buttons
	Sound whatMadeHimFightSound;
	Button whatMadeHimFightButton;

	Sound worstPartOfRevolutionSound;
	Button worstPartOfRevolutionButton;

	Sound wasItWorthItSound;
	Button wasItWorthItButton;
	

	Sound isFateRealSound;
	Button isFateRealButton;


	// Fourth option buttons
	Sound whatDoyouLeaveSound;
	Button whatDoyouLeaveButton;

	Sound whatMakesPoetryAliveSound;
	Button whatMakesPoetryAlive;

	Sound doYoufeelMoreUnderstoodSound;
	Button doYoufeelMoreUnderstoodButton;

	Sound doesThePoetHaveToBeUnderstoodSound;
	Button doesThePoetHaveToBeUnderstoodButton;

	// Fifth option buttons
	Sound whyChangeGanreSound;
	Button whyChangeGanreButton;

	Sound whatDoYouMissMostSound;
	Button whatDoYouMissMostButton;
	
	Sound ifYouCouldChangeSomethingSound;
	Button ifYouCouldChangeSomethingButton;
	
	Sound favoritePeioPoemSound;
	Button favoritePeioPoemButton;
	
	// Sixth option buttons
	Sound goodbyePeioSound;
	Button goodbyePeioButton;
	

	public:
		QvorovMainFrame();

		void runVisuals();

		void runMath();
};