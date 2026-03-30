#include "QvorovMainFrame.h"

QvorovMainFrame::QvorovMainFrame() :
	backgroundImage(LoadImage("resources/pics/peioKushtajpg.jpg")),
	backgroundTexture(LoadTextureFromImage(backgroundImage)),

	peioImage(LoadImage("resources/pics/peioQvorov.png")),
	peioTexture(LoadTextureFromImage(peioImage)),

	firstOptionSelected(false), secondOptionSelected(false), thirdOptionSelected(false), fourthOptionSelected(false), fifthOptionSelected(false), sixthOptionSelected(false),

	start(true), startTime(0.0f), howBlack(1.0f), peioTalking(false), showInterviewOptions(false), optionsIndex(0),
	optionsBox({ 465, 500, 480, 240 }),
	peioMessageBox({ 340, 50, 600, 250 }),

	// First option buttons
	helloPeioButton({ 470, 510, 470, 50 }, "Здравей,  Пейо  как  си?", GRAY,
		std::string("Здравейте,  аз  се  чуствам  превъзходно \nтова  ми  е  първото  интервю.")),

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

	whatMakesHimWriteButton({ 470, 690, 470, 50 }, "Какво чуство ви кара да пишете?", GRAY,
		std::string("Пиша, когато душата ми не намира друг изход. \n ") +
		"Болката често е първата искра, но любовта е пламъкът. \n Стихът идва, когато не мога да мълча."),

	// Third option buttons
	whatMadeHimFightButton({ 470, 510, 470, 50 }, "Какво ви подтикна към борбата?", GRAY,
		std::string("Не можех да стоя безучастен, когато народът ми стенеше.\n") +
		"Поезията е зов, но делото е отговор. Сърцето ми поиска и двете. \n" ),

	worstPartOfRevolutionButton({ 470, 570, 470, 50 }, "Какво е истинската любов?", GRAY,
		std::string("Тежи не толкова смъртта, колкото споменът за падналите другари.\n") +
		"Тежи и вината, че си останал жив.\nТези сенки никога не те напускат."),

	wasItWorthItButton({ 470, 630, 470, 50 }, "Кое е най-тешкото от революционните години?", GRAY, 
		std::string("Цената бе висока, но свободата никога не е евтина.\n") + 
		"Ако трябваше пак да избера, бих поел същия път.\n" + 
		"Човек живее истински само когато служи\n на нещо по-голямо от себе си."),

	isFateRealButton({ 470, 690, 470, 50 }, "Предопределена ли е съдбата?", GRAY,
		std::string("Съдбата е път, който вървим сами, но и път, който ни води.  \n ") +
		"Човек избира, но и е избран. Истината е някъде между двете."),

	// Fourth option buttons
	whatDoyouLeaveButton({ 470, 510, 470, 50 }, "Какво послание бихте оставили?", GRAY,
		std::string("Бъдете смели в любовта и в делото. \n") +
		"Не се страхувайте да страдате -\nстрахувайте се да живеете напразно. \n" +
		"И пазете свободата като най-свята светиня."),

	whatMakesPoetryAlive({ 470, 570, 470, 50 }, "Какво прави един стих „жив“?", GRAY,
		std::string("Жив е стихът, който носи човешка кръв и дъх.\n") +
		"Той трябва да боли, да трепти, да ранява.\nИ да остане в сърцето като белег."),

	doYoufeelMoreUnderstoodButton({ 470, 630, 470, 50 }, "Чувствате ли се неразбран или обичан?", GRAY,
		std::string("Обичан бях, но често неразбран. \n") +
		"Ако трябваше пак да избера, бих поел същия път.\n" +
		"Любовта към поета не винаги достига до човека.\nА човекът в мен бе крехък."),

	doesThePoetHaveToBeUnderstoodButton({ 470, 690, 470, 50 }, "Трябва ли поетът да бъде разбран?", GRAY,
		std::string("Поетът е сам по природа.\n") +
		"Ако някой го разбере — това е дар. \n" + 
		"Но той пише не за разбиране, а защото не може иначе."),

	// Fifth option buttons
	whyChangeGanreButton({ 470, 510, 470, 50 }, "Защо си сменихте жанра след\nИлинденското възтания?", GRAY,
		std::string("След Илинден сърцето ми не можа вече да бъде само хроника \n") +
		"видях човешката трагедия и тя поиска стих. \n" +
		"Жанрът се смени, защото думите търсеха не факти,\nа сълзи и мълчание, \n" +
		"които да превърнат болката в песен. \n" + 
		"Писах, за да изповядам съдбата на народа не като историк,\n" +
		"а като човек, който носи раните им в гърдите си."),
	
	whatDoYouMissMostButton({ 470, 570, 470, 50 }, "Какво ви липсва най-много?", GRAY,
		std::string("Липсва ми онова, което никога не можах да имам \n") +
		"истинската любов, която изгаря и спасява.\n" +
		"Липсва ми и свободата, която се изплъзна от ръцете ми.\n" +
		"Но най-много ми липсва мирът в душата, който никога не намерих."),

	ifYouCouldChangeSomethingButton({ 470, 630, 470, 50 }, "Ако можехте да промените нещо в живота си,\nкакво би било?", GRAY,
		std::string("Ако можех да променя нещо, щях да изтрия онзи миг,\n") +
		"в който не посмях да кажа всичко, което гореше в мен.\n" +
		"Щях да дам на любовта повече смелост и на тъгата\n" +
		"по-малко власт над дните ми.\n" + 
		"Но може би всяка рана ме е ковала, \n" + 
		"промяната би отнела и песента, и мълчанието ми."),

	favoritePeioPoemButton({ 470, 690, 470, 50 }, "Кое вие е любимото ваше произведение?", GRAY,
		std::string("Любимото ми произведение е „Арменци“. \n") +
		"В него аз търсих и намерих онова, което най-силно обичам\n" +
		"любовта, готова да се жертва и да умре.\n" +
		"То е родено от нощта на самотата и носи в себе си плача и надеждата на един разкъсан свят.\n" +
		"Това стихотворение ми говори като огън в мрака и ме прави по-малко сам."),

		//Sixth option buttons
		goodbyePeioButton({ 470, 690, 470, 50 }, "Благодаря ви за отделеното време\nгосподин Яворов беше ми приятно", GRAY,
			std::string("И аз благодаря, и на мен ми беше приятно"))

	//              1st button             2nd button                3rd button             4th button
	//options{ { 470, 510, 470, 50 }, { 470, 570, 470, 50 }, { 470, 630, 470, 50 }, { 470, 690, 470, 50 } }

{
	int codepoints[1024];
	int count = 0;

	// ASCII printable (space 0x20 .. tilde 0x7E)
	for (int i = 0x20; i <= 0x7E; i++) codepoints[count++] = i;

	// Cyrillic block U+0400 .. U+04FF
	for (int i = 0x0400; i <= 0x04FF; i++) codepoints[count++] = i;

	// Add extra punctuation you might need
	int extras[] = { 0x00AB, 0x00BB, 0x2013, 0x2014, 0x2026, 0x2018, 0x2019 };
	for (int i = 0; i < sizeof(extras) / sizeof(extras[0]); i++) codepoints[count++] = extras[i];

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

void QvorovMainFrame::runVisuals() {
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
		DrawTextEx(textFont, peioMessage.c_str(), { peioMessageBox.x + 20, peioMessageBox.y + 20 }, 20, 3, WHITE);
	}

	if (start) {
		DrawRectangle(0, 0, 950, 750, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Интервю с Пейо Яворов", { 310, 300 }, 40, 3, WHITE);

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
		fourthOptionSelected && fifthOptionSelected && sixthOptionSelected) {
		// Wait for Peio's voice to finish talking
		// then black screen transition
		// and names of the people who worked on the project 
		// NOT FINISHED YET
		DrawRectangle(0, 0, 950, 750, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Край на интервюто", { 310, 300 }, 40, 3, WHITE);
		startTime += GetFrameTime();
		if (startTime >= 2.5f) {
			howBlack += 0.25f * GetFrameTime();
			if (howBlack >= 1.0f) {
				// Show credits
				DrawTextEx(textFont, "Програмит: Иван Георгиев 11Б\nГласът на Пейо Яворов: Лубомир Попов 11Б\nГласът на Интервюиращия: Николй Френгов 11Б", { 310, 300 }, 30, 3, WHITE);
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