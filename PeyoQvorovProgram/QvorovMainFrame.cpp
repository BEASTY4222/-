#include "QvorovMainFrame.h"

QvorovMainFrame::QvorovMainFrame(bool mode) :
	firstOptionSelected(false), secondOptionSelected(false), thirdOptionSelected(false), fourthOptionSelected(false), fifthOptionSelected(false), sixthOptionSelected(false),

	start(true), startTime(0.0f), howBlack(1.0f), peioTalking(false), showInterviewOptions(false), optionsIndex(0),
	mode(mode)

	//              1st button             2nd button                3rd button             4th button
	//options{ { 470, 510, 470, 50 }, { 470, 570, 470, 50 }, { 470, 630, 470, 50 }, { 470, 690, 470, 50 } }

{
	SetMasterVolume(1.0f);  // max volume

	if(mode){ // full screen mode
		//images
		backgroundImage = LoadImage("../resources/pics/peioKushtaFullScreen.png");
		peioImage = LoadImage("../resources/pics/peioQvorovFullScreen.png");

		//Rectangles
		buttonOneRec = { 1200, 510, 670, 100 };
		buttonTwoRec = { 1200, 620, 670, 100 };
		buttonThreeRec = { 1200, 730, 670, 100 };
		buttonFourRec = { 1200, 840, 670, 100 };

		optionsBox = { 1185, 500, 695, 450 };
		peioMessageBox = { 800, 20, 1060, 455 };
		blacknessPos = { 0, 0, 1980, 1100 };
		peioTitlePos = { 760, 300 };
		creditsPos = { 60, 900 };
		creditsSize = 50;
		textSize = 40;


		//questions that needed formating
		formatedQuestions[0] = "Какво е най-тежкото\nот революционните години?";
		formatedQuestions[1] = "Ако можехте да промените нещо\nв живота си, какво би било?";

	}
	else{ // windowed mode
		//images
		backgroundImage = LoadImage("../resources/pics/peioKushta.png");
		peioImage = LoadImage("../resources/pics/peioQvorov.png");

		//Rectangles
		buttonOneRec = { 470, 510, 470, 50 };
		buttonTwoRec = { 470, 570, 470, 50 };
		buttonThreeRec = { 470, 630, 470, 50 };
		buttonFourRec = { 470, 690, 470, 50 };

		optionsBox = { 465, 500, 480, 240 };
		peioMessageBox = { 340, 50, 600, 250 };
		blacknessPos = { 950, 750, 1000, 1000 };
		peioTitlePos = { 310, 300 };
		creditsPos = { 20, 670 };
		creditsSize = 30;
		textSize = 20;

		//questions that needed formating
		formatedQuestions[0] = "Какво е най-тежкото от\nреволюционните години?";
		formatedQuestions[1] = "Ако можехте да промените нещо в живота си,\nкакво би било?";

	}

	backgroundTexture = LoadTextureFromImage(backgroundImage);
	peioTexture = LoadTextureFromImage(peioImage);

	
	// First option buttons
	helloPeioSound = LoadSound("../resources/voiceRecordings/question0.wav");
	helloPeioButton = Button(buttonOneRec, "Здравей,  Пейо  как  си?", GRAY,
		std::string("Здравейте,  аз  се  чуствам  превъзходно \nтова  ми  е  първото  интервю."),helloPeioSound,textSize);

	//Second option buttons
	biographySound = (LoadSound("../resources/voiceRecordings/question0.5.wav"));
	biographyButton = Button(buttonOneRec, "Кой всъщност е Пейо Яворов?", GRAY,
		std::string("Кой съм аз? \n ") +
		"Поет, роден от мрака и светлината, от болката и копнежа. \n " +
		"Душа, разкъсвана между любовта, \n която изгаря, и свободата, която не чака. \n" +
		"Живях кратко, но в пламък – \n в стиховете, в борбата, в страстта.\n" +
		"Аз съм човекът, който търси \n невъзможното и плаща цената му. \n" +
		"Пламък съм – понякога светя, \n понякога изгарям, но никога не угасвам.",biographySound,textSize);

	whatIsRealLoveSound = (LoadSound("../resources/voiceRecordings/question1.wav"));
	whatIsRealLoveButton = Button(buttonTwoRec, "Какво е истинската любов?", GRAY,
		std::string("Любовта е огън, който едновременно топли и изгаря. \n Тя не пита дали си готов. \n ") +
		"Спасение е само за онзи, който умее да изгори докрай. \n За мен тя бе и двете.",whatIsRealLoveSound,textSize);

	needsForLovePoetrySound = (LoadSound("../resources/voiceRecordings/question3.wav"));
	needsForLovePoetryButton = Button(buttonThreeRec, "Нужно ли е страдание за любовна поезия?", GRAY,
		std::string("Страданието е езикът, на който душата говори най-истински. \n ") +
		"Без него стихът остава празна черупка. \n Поетът плаща с болка за всяка своя дума.",needsForLovePoetrySound,textSize);

	whatMakesHimWriteSound = (LoadSound("../resources/voiceRecordings/question7.wav"));
	whatMakesHimWriteButton = Button(buttonFourRec, "Какво чуство ви кара да пишете?", GRAY,
		std::string("Пиша, когато душата ми не намира друг изход. \n ") +
		"Болката често е първата искра, но любовта е пламъкът. \n Стихът идва, когато не мога да мълча.",whatMakesHimWriteSound,textSize);

	// Third option buttons
	whatMadeHimFightSound = (LoadSound("../resources/voiceRecordings/question4.wav"));
	whatMadeHimFightButton = Button(buttonOneRec, "Какво ви подтикна към борбата?", GRAY,
		std::string("Не можех да стоя безучастен, когато народът ми стенеше.\n") +
		"Поезията е зов, но делото е отговор. Сърцето ми поиска и двете. \n",whatMadeHimFightSound,textSize);

	worstPartOfRevolutionSound = (LoadSound("../resources/voiceRecordings/question5.wav"));
	worstPartOfRevolutionButton = Button(buttonTwoRec, formatedQuestions[0], GRAY,
		std::string("Тежи не толкова смъртта, колкото споменът за падналите другари.\n") +
		"Тежи и вината, че си останал жив.\nТези сенки никога не те напускат.",worstPartOfRevolutionSound,textSize);

	wasItWorthItSound = (LoadSound("../resources/voiceRecordings/question6.wav"));
	wasItWorthItButton = Button(buttonThreeRec, "Струваше ли си личната цена?", GRAY, 
		std::string("Цената бе висока, но свободата никога не е евтина.\n") + 
		"Ако трябваше пак да избера, бих поел същия път.\n" + 
		"Човек живее истински само когато служи\n на нещо по-голямо от себе си.",wasItWorthItSound,textSize);

	isFateRealSound = (LoadSound("../resources/voiceRecordings/question11.wav"));
	isFateRealButton = Button(buttonFourRec, "Предопределена ли е съдбата?", GRAY,
		std::string("Съдбата е път, който вървим сами, но и път, който ни води.  \n ") +
		"Човек избира, но и е избран. Истината е някъде между двете.",isFateRealSound,textSize);

	// Fourth option buttons
	whatDoyouLeaveSound = (LoadSound("../resources/voiceRecordings/question12.wav"));
	whatDoyouLeaveButton = Button(buttonOneRec, "Какво послание бихте оставили?", GRAY,
		std::string("Бъдете смели в любовта и в делото. \n") +
		"Не се страхувайте да страдате -\nстрахувайте се да живеете напразно. \n" +
		"И пазете свободата като най-свята светиня.",whatDoyouLeaveSound,textSize);

	whatMakesPoetryAliveSound = (LoadSound("../resources/voiceRecordings/question8.wav"));
	whatMakesPoetryAlive = Button(buttonTwoRec, "Какво прави един стих жив?", GRAY,
		std::string("Жив е стихът, който носи човешка кръв и дъх.\n") +
		"Той трябва да боли, да трепти, да ранява.\nИ да остане в сърцето като белег.",whatMakesPoetryAliveSound,textSize);

	doYoufeelMoreUnderstoodSound = (LoadSound("../resources/voiceRecordings/question14.wav"));
	doYoufeelMoreUnderstoodButton = Button(buttonThreeRec, "Чувствате се неразбран или обичан?", GRAY,
		std::string("Обичан бях, но често неразбран. \n") +
		"Ако трябваше пак да избера, бих поел същия път.\n" +
		"Любовта към поета не винаги достига до човека.\nА човекът в мен бе крехък.",doYoufeelMoreUnderstoodSound,textSize);

	doesThePoetHaveToBeUnderstoodSound = (LoadSound("../resources/voiceRecordings/question9.wav"));
	doesThePoetHaveToBeUnderstoodButton = Button(buttonFourRec, "Трябва ли поетът да бъде разбран?", GRAY,
		std::string("Поетът е сам по природа.\n") +
		"Ако някой го разбере — това е дар. \n" + 
		"Но той пише не за разбиране, а защото не може иначе.",doesThePoetHaveToBeUnderstoodSound,textSize);

	// Fifth option buttons
	whyChangeGanreSound = (LoadSound("../resources/voiceRecordings/question2.wav"));
	whyChangeGanreButton = Button(buttonOneRec, "Защо си сменихте жанра след\nИлинденското възтания?", GRAY,
		std::string("След Илинден сърцето ми не можа вече да бъде само хроника \n") +
		"видях човешката трагедия и тя поиска стих. \n" +
		"Жанрът се смени, защото думите търсеха не факти,\nа сълзи и мълчание, \n" +
		"които да превърнат болката в песен. \n" + 
		"Писах, за да изповядам съдбата на народа не като историк,\n" +
		"а като човек, който носи раните им в гърдите си.",whyChangeGanreSound,textSize);

	whatDoYouMissMostSound = (LoadSound("../resources/voiceRecordings/question15.wav"));
	whatDoYouMissMostButton = Button(buttonTwoRec, "Какво ви липсва най-много?", GRAY,
		std::string("Липсва ми онова, което никога не можах да имам \n") +
		"истинската любов, която изгаря и спасява.\n" +
		"Липсва ми и свободата, която се изплъзна от ръцете ми.\n" +
		"Но най-много ми липсва мирът в душата, който никога не намерих.",whatDoYouMissMostSound,textSize);

	ifYouCouldChangeSomethingSound = (LoadSound("../resources/voiceRecordings/question13.wav"));
	ifYouCouldChangeSomethingButton = Button(buttonThreeRec, formatedQuestions[1], GRAY,
		std::string("Ако можех да променя нещо, щях да изтрия онзи миг,\n") +
		"в който не посмях да кажа всичко, което гореше в мен.\n" +
		"Щях да дам на любовта повече смелост и на тъгата\n" +
		"по-малко власт над дните ми.\n" + 
		"Но може би всяка рана ме е ковала, \n" + 
		"промяната би отнела и песента, и мълчанието ми.",ifYouCouldChangeSomethingSound,textSize);

	favoritePeioPoemSound = (LoadSound("../resources/voiceRecordings/question10.wav"));
	favoritePeioPoemButton = Button(buttonFourRec, "Кое вие е любимото ваше произведение?", GRAY,
		std::string("Любимото ми произведение е „Арменци“. \n") +
		"В него аз търсих и намерих онова, което най-силно обичам\n" +
		"любовта, готова да се жертва и да умре.\n" +
		"То е родено от нощта на самотата и носи в себе си плача и надеждата на един разкъсан свят.\n" +
		"Това стихотворение ми говори като огън в мрака и ме прави по-малко сам.",favoritePeioPoemSound,textSize);

		//Sixth option buttons
		goodbyePeioSound = (LoadSound("../resources/voiceRecordings/question16.wav"));
		goodbyePeioButton = Button(buttonFourRec, "Благoдаря ви за отделеното време\nгосподин Яворов беше ми приятно.", GRAY,
			std::string("И аз благодаря, и на мен ми беше приятно."), goodbyePeioSound,textSize);

	int codepoints[1024];
	int count = 0;

	// ASCII printable (space 0x20 .. tilde 0x7E)
	for (int i = 0x20; i <= 0x7E; i++) codepoints[count++] = i;

	// Cyrillic block U+0400 .. U+04FF
	for (int i = 0x0400; i <= 0x04FF; i++) codepoints[count++] = i;

	// Add extra punctuation you might need
	int extras[] = { 0x00AB, 0x00BB, 0x2013, 0x2014, 0x2026, 0x2018, 0x2019 };
	for (int i = 0; i < sizeof(extras) / sizeof(extras[0]); i++) codepoints[count++] = extras[i];

	this->textFont = LoadFontEx("../resources/fonts/2596-font.ttf", 32, codepoints, count);

	availableOptions.resize(4); // We will have 4 options at the max

	emptyButtonOne.changeCords(buttonOneRec);
	emptyButtonTwo.changeCords(buttonTwoRec);
	emptyButtonThree.changeCords(buttonThreeRec);
	emptyButtonFour.changeCords(buttonFourRec);

	availableOptions.at(0) = emptyButtonOne;
	availableOptions.at(1) = emptyButtonTwo;
	availableOptions.at(2) = emptyButtonThree;
	availableOptions.at(3) = emptyButtonFour;

}

void QvorovMainFrame::runVisuals() {
	DrawTexture(backgroundTexture, 0, -10, WHITE);
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
		DrawTextEx(textFont, peioMessage.c_str(), { peioMessageBox.x + 20, peioMessageBox.y + 20 }, textSize, 3, WHITE);
	}

	if (start) {
		DrawRectangleRec(blacknessPos, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Интервю с Пейо Яворов", peioTitlePos, creditsSize, 3, WHITE);

		startTime += GetFrameTime();
		if (startTime >= 2.5f) {
			howBlack -= 0.25f * GetFrameTime();
			if (howBlack <= 0.0f) {
				start = false;
				showInterviewOptions = true;
			}
		}
	}

	// Black screen transition at the end of the interview
	// Also show credits
	if (firstOptionSelected && secondOptionSelected && thirdOptionSelected &&
		fourthOptionSelected && fifthOptionSelected && sixthOptionSelected) 
		{
		// Wait for Peio's voice to finish talking
		// then black screen transition
		// and names of the people who worked on the project 
		// NOT FINISHED YET
		DrawRectangleRec(blacknessPos, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Край на интервюто", peioTitlePos, creditsSize, 3, WHITE);
		startTime += GetFrameTime();
		if (startTime >= 2.5f) {
			howBlack += 0.25f * GetFrameTime();
			if (howBlack >= 1.0f) {
				// Show credits
				DrawTextEx(textFont, "Програмист : Иван Георгиев 11Б\nГласът на Пейо : Любомир Попов 11Б", creditsPos, creditsSize, 3, WHITE);
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
	else if (firstOptionSelected && secondOptionSelected && !thirdOptionSelected) {
		availableOptions.at(0) = whatMadeHimFightButton;
		availableOptions.at(1) = worstPartOfRevolutionButton;
		availableOptions.at(2) = wasItWorthItButton;
		availableOptions.at(3) = isFateRealButton;


		whatMadeHimFightButton.run(thirdOptionSelected, peioTalking, peioMessage);
		worstPartOfRevolutionButton.run(peioTalking, peioMessage);
		wasItWorthItButton.run(peioTalking, peioMessage);
		isFateRealButton.run(peioTalking, peioMessage);
	}
	else if (firstOptionSelected && secondOptionSelected && thirdOptionSelected && !fourthOptionSelected) {
		availableOptions.at(0) = whatDoyouLeaveButton;
		availableOptions.at(1) = whatMakesPoetryAlive;
		availableOptions.at(2) = doYoufeelMoreUnderstoodButton;
		availableOptions.at(3) = doesThePoetHaveToBeUnderstoodButton;


		whatDoyouLeaveButton.run(fourthOptionSelected, peioTalking, peioMessage);
		whatMakesPoetryAlive.run(peioTalking, peioMessage);
		doYoufeelMoreUnderstoodButton.run(peioTalking, peioMessage);
		doesThePoetHaveToBeUnderstoodButton.run(peioTalking, peioMessage);
	}
	else if (firstOptionSelected && secondOptionSelected && thirdOptionSelected && fourthOptionSelected && !fifthOptionSelected) {
		availableOptions.at(0) = whyChangeGanreButton;
		availableOptions.at(1) = whatDoYouMissMostButton;
		availableOptions.at(2) = ifYouCouldChangeSomethingButton;
		availableOptions.at(3) = favoritePeioPoemButton;


		whyChangeGanreButton.run(fifthOptionSelected, peioTalking, peioMessage);
		whatDoYouMissMostButton.run(peioTalking, peioMessage);
		ifYouCouldChangeSomethingButton.run(peioTalking, peioMessage);
		favoritePeioPoemButton.run(peioTalking, peioMessage);
	}
	else if (firstOptionSelected && secondOptionSelected && thirdOptionSelected && fourthOptionSelected && fifthOptionSelected && !sixthOptionSelected) {
		availableOptions.at(0) = emptyButtonOne;
		availableOptions.at(1) = emptyButtonTwo;
		availableOptions.at(2) = emptyButtonThree;
		availableOptions.at(3) = goodbyePeioButton;

		goodbyePeioButton.run(sixthOptionSelected, peioTalking, peioMessage);
	}
	else {
		availableOptions.at(0) = emptyButtonOne;
		availableOptions.at(1) = emptyButtonTwo;
		availableOptions.at(2) = emptyButtonThree;
		availableOptions.at(3) = emptyButtonFour;
	}


}