#include "QvorovMainFrame.h"

QvorovMainFrame::QvorovMainFrame() :
	backgroundImage(LoadImage("resources/pics/peioKushtajpg.jpg")),
	backgroundTexture(LoadTextureFromImage(backgroundImage)),

	peioImage(LoadImage("resources/pics/peioQvorov.png")),
	peioTexture(LoadTextureFromImage(peioImage)),

	firstOptionSelected(false), secondOptionSelected(false),

	start(true), startTime(0.0f), howBlack(1.0f), peioTalking(false), showInterviewOptions(false), optionsIndex(0),
	optionsBox({ 465, 500, 480, 240 }),
	peioMessageBox({ 340, 50, 600, 250 }),

	// First option buttons
	helloPeioButton({ 470, 510, 470, 50 }, "Здравей,  Пейо  как  си?", GRAY,
		std::string("Здравейте  аз  се  чуства  разкошно,\nтова  ми  е  първото  интервю ")),

	//Second option buttons
	biographyButton({ 470, 510, 470, 50 }, "Кой всъщност е Пейо Яворов?", GRAY,
		std::string("Кой съм аз? \n ") +
		"Поет, роден от мрака и светлината, от болката и копнежа. \n " +
		"Душа, разкъсвана между любовта, \n която изгаря, и свободата, която не чака. \n" +
		"Живях кратко, но в пламък – \n в стиховете, в борбата, в страстта.\n" +
		"Аз съм човекът, който търси \n невъзможното и плаща цената му. \n" +
		"Пламък съм – понякога светя, \n понякога изгарям, но никога не угасвам."),

	whatIsRealLoveButton({ 470, 570, 470, 50 }, "Какво е истинската любов?", GRAY,
		std::string("Любовта е огън, който едновременно топли и изгаря. \n Тя не пита дали си готов. \n ") +
		"Спасение е само за онзи, който умее да изгори докрай. \n За мен тя бе и двете."),

	needsForLovePoetryButton({ 470, 630, 470, 50 }, "Нужно ли е страдание за любовна поезия?", GRAY,
	std::string("Страданието е езикът, на който душата говори най-истински. \n ") +
	"Без него стихът остава празна черупка. \n Поетът плаща с болка за всяка своя дума."),

	whatMakesHimWriteButton({ 470, 690, 470, 50 }, "КакВо чуство ви кара да пишете", GRAY,
		std::string("Пиша, когато душата ми не намира друг изход. \n ") +
		"Болката често е първата искра, но любовта е пламъкът. \n Стихът идва, когато не мога да мълча.")
	


	//             1st button             2nd button                3rd button             4th button
	//options{ { 470, 510, 470, 50 }, { 470, 570, 470, 50 }, { 470, 630, 470, 50 }, { 470, 690, 470, 50 } }

{
	int codepoints[512];
	int count = 0;

	for (int i = 0x0400; i <= 0x04FF; i++) {
		codepoints[count++] = i;
	}

	this->textFont = LoadFontEx("resources/Fonts/2596-font.ttf", 32, codepoints, count);

	availableOptions.resize(4); // We will have 4 options at the max

	emptyButtonOne.changeCords({ 470, 510, 470, 50 });
	emptyButtonTwo.changeCords({ 470, 570, 470, 50 });
	emptyButtonThree.changeCords({ 470, 630, 470, 50 });
	emptyButtonFour.changeCords({ 470, 690, 470, 50 });

	availableOptions.at(0) = emptyButtonOne;
	availableOptions.at(1) = emptyButtonTwo;
	availableOptions.at(2) = emptyButtonThree;
	availableOptions.at(3) = emptyButtonFour;

}

void QvorovMainFrame::runVisuals(){
	DrawTexture(backgroundTexture, 0, 0, WHITE);
	DrawTexture(peioTexture, 0, 270, WHITE);

	// Interview options box
	if (showInterviewOptions) {
		DrawRectangleRec(optionsBox, Fade(BLACK, 0.5f));
		
		// Options
		for (optionsIndex = 0;optionsIndex < 4;optionsIndex++) {
			if (optionsIndex <= availableOptions.size() - 1) {
				availableOptions.at(optionsIndex).draw();
			}
			 
			
		}
	}
	

	// Has to be active only when Peio is talking
	if (peioTalking) {
		DrawRectangleRec(peioMessageBox, Fade(BLACK, 0.5f));
		DrawTextEx(textFont, peioMessage.c_str(), { peioMessageBox.x + 20, peioMessageBox.y + 20 }, 20, 5, WHITE);
	}



	
	
	if (start) {
		DrawRectangle(0, 0, 950, 750, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Интервю с Пейо Яворов", { 310, 300 }, 40, 5, WHITE);

		startTime += GetFrameTime();
		if (startTime >= 2.5f) {
			howBlack -= 0.25f * GetFrameTime();
			if (howBlack <= 0.0f) {
				start = false;
				showInterviewOptions = true;
			}
		}
	}
}



void QvorovMainFrame::runMath() {
	if (!firstOptionSelected) {
		availableOptions.at(0) = helloPeioButton;
		helloPeioButton.run(firstOptionSelected, peioTalking, peioMessage);
	}
	else if (firstOptionSelected && !secondOptionSelected) {
		availableOptions.at(0) = biographyButton;
		availableOptions.at(1) = whatIsRealLoveButton;
		availableOptions.at(2) = needsForLovePoetryButton;
		availableOptions.at(3) = whatMakesHimWriteButton;

		
		biographyButton.run(secondOptionSelected, peioTalking, peioMessage);
		whatIsRealLoveButton.run(peioTalking, peioMessage);
		needsForLovePoetryButton.run(peioTalking, peioMessage);
		whatMakesHimWriteButton.run(peioTalking, peioMessage);
	}
	else {
		availableOptions.at(0) = emptyButtonOne;
	}
}