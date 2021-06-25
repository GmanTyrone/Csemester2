#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Class Choice
class Choice {
protected:
	string text;
	char route;

public:
	virtual ~Choice() {};
	Choice();
	Choice(string text, char route);
	string getText();
};
Choice::Choice()
	: text("")
	, route('x')
{

}
Choice::Choice(string text, char route)
	: text(text)
	, route(route)
{

}
string Choice::getText() {
	return text;
}

//Subclass Choice A
class ChoiceA : public Choice {
public:
	ChoiceA();
	ChoiceA(string text);
};
ChoiceA::ChoiceA()
	: Choice()
{

}
ChoiceA::ChoiceA(string text)
	: Choice(text, 'a')
{

}

//Sublcass choice b
class ChoiceB : public Choice {
public:
	ChoiceB();
	ChoiceB(string text);
};
ChoiceB::ChoiceB()
	: Choice()
{

}
ChoiceB::ChoiceB(string text)
	: Choice(text, 'b')
{

}

//Class Question
class Question {
private:
	Question * ARoute;
	Question* BRoute;
	ChoiceA AChoice;
	ChoiceB BChoice;
	string story;
	std::map<string, string> pathUniqueModifiers;
	int modPos;
	bool modded;

private:
	void modifyStory(string path);

public:
	Question();
	Question(string AChoice, string BChoice, bool modded);
	~Question();

	// functions
	void makeRoutes(Question* A, Question* B);
	void ask(string path);
	Question* goA();
	Question* goB();
	// Story text before the questions
	void giveStory(string story);
	// adds another piece of text to make sense, because other paths lead to the same
	void addStoryModifier(string storyMod, string path);
};
Question::Question()
	: ARoute(nullptr)
	, BRoute(nullptr)
	, AChoice("")
	, BChoice("")
	, story("")
	, modPos(-1)
	, modded(false)
{
	// mod is set to -1, so when it checks expecting a 0 then it'll mean no mod added
}
Question::Question(string AChoice, string BChoice, bool modded = false)
	: ARoute(nullptr)
	, BRoute(nullptr)
	, AChoice(AChoice)
	, BChoice(BChoice)
	, story("")
	, modPos(-1)
	, modded(modded)
{

}
Question::~Question() {
	ARoute = nullptr;
	BRoute = nullptr;
}
void Question::makeRoutes(Question* A, Question* B) {
	this->ARoute = A;
	this->BRoute = B;
}
void Question::ask(string path) {
	if (modded) {
		modifyStory(path);
	}
	cout << story << endl << endl;
	cout << AChoice.getText() << "(a) or " << BChoice.getText() << "(b)?" << endl;
}
Question* Question::goA() {
	cout << "Chosen was: " << AChoice.getText() << ".\n" << endl;
	if (ARoute == nullptr) {
		cout << "You are getting deported, and go back to latin america." << endl;
	}
	return ARoute;
}
Question* Question::goB() {
	cout << "Chosen was: " << BChoice.getText() << ".\n" << endl;
	if (BRoute == nullptr) {
		cout << "You are getting deported, and go back to latin america." << endl;
	}
	return BRoute;
}
void Question::giveStory(string story) {
	this->story = story;
	// checks and add mod if needed
	if (modded) {
		int i, len = story.length();
		for (i = 0; i < len; ++i) {
			if (story.at(i) == '^') {
				modPos = i;
			}
		}
	}
}
void Question::addStoryModifier(string storyMod, string path) {
	if (modPos >= 0) {
		pathUniqueModifiers[path] = storyMod;
	}
}
void Question::modifyStory(string path) {
	if (modPos == story.length() - 1) {
		story.append(pathUniqueModifiers[path]);
		// erase the '^' symbol at the end of the string
		story.erase(story.end() - 1);
	}
	else {
		story.insert(modPos, pathUniqueModifiers[path]);
		// after the mod is inserted, the '^' symbol will get moved to where it was (modPos) + the length of string that was just inserted
		story.erase(modPos + pathUniqueModifiers[path].length(), 1);
	}
}

class Game {
private:
	string pathStr;
	Question* currentQuestion;
	Question bird;
	Question lake;
	Question stone;
	Question spear;
	Question spare;
	Question cook;
	Question act;
	Question cansado;
	Question apotheosis;
	Question tired;
	Question god;
	Question linked;
	Question sense;
	Question pachon;
    Question pescado;
    Question largo;
    Question feliz;
    Question noches;
    Question banana;
    Question despacito;
    Question nombrex;
    Question malapractica;
    Question aburrido;
    Question jesucristo;
    Question cicada;
    Question based;
    Question popito;

	void linkQuestions();

public:
	Game();

	// function declarations
	void travelTo(char pathChoice);
	void gameLoop();
	void printOptions();
	bool receiveInput(string& userInput);
};
Game::Game()
	: pathStr("")
	, currentQuestion(nullptr)
	, bird("Keep walking", "Throw a stone at it")//done
	, lake("Spare it", "Use your umbrella as a spear")//done
	, stone("Might as well cook it", "Run from the crime scene")//done
	, spear("Eat it all in one sitting", "Risk being seen with the evidence of your crime")//done
	, spare("You are god", "Goodbye")//done
	, cook("It tastes good", "It tastes bad")//done
	, act("look NDHU hate", "check Elearning")//done
	, apotheosis("Give yourself to the authorities", "Run to the forest to try to live as a savage", true)// tier 4 done
	, tired("Run towards the light", "You are still young")//done
	, god("Tell them of your nefound god status", "Say hi to them")//done
	, linked("Go to the crowd", "Go to your meeting")//done
	, sense("Use the money of your stipend", "Take a bank loan")//done
	, pachon("Look for a job here in Taiwan", "Apply for an scholarship to keep studying")//done
	, cansado("I saw the perpetrator, it was xiahong", "Whoever did it did us all a favor")//done
    , pescado("I didn't do it I'm innocent!(Lie?)", "I didn't do it I'm innocent!(True?)", true)// tier 5 d one
    , largo("Get outta here", "At least you'll drink horchata again")//done
    , feliz("Cooperate with the police", "Run and risk getting shot")//done
    , noches("Physics", "Calculus")//done
    , banana("Be an hipocrite", "Suck it you're an atheist till the end")//done
    , despacito("You don't know the lyrics but try your best", "Fake your own death")//done
    , nombrex("Shame on you!", "SHAME!")//done
    , malapractica("No hablo chino", "Attack them")//done
    , aburrido("They also hated Jesus for telling the truth", "Take back your words and compromise your character(WRONG OPTION)")//done
    , jesucristo("Go back to latin america and help financially from there", "Risk it")//done
    , cicada("Guess I'll get deported", "Go to the embassy and ask for asylum")//done
    , based("Ask the bank for more money", "Let miss Gena know how you used your stipend")//done
    , popito("Commit TAX fraud", "Spend all you money on drugs")//done
{
    // Story Path
	linkQuestions();
	//Introduction
	bird.giveStory("THE GREAT NDHU ADVENTURE! You are taking a walk through NDHU's campus. "
		"You can spot in the vicinity one of those birds that are in the 1000 nt bills, and are also the school macot");

	// ---------------------------------------ROAD 1------------------------------------------ //
	// bird a choice path "a"
	lake.giveStory("As you walk the forest, trying to forget the sight of that bird... you decide to go to the lake to relax. "
		"It's a beautiful sunset at the lake, the lake is a little bit dirty now, but still it is a good view of the sunset. "
		"However you still have the bird on your mind, and your thirst for blood remains unquenched. Then you spot a big koi swimming near you.");
	// bird b choice path "b"
	stone.giveStory("Yo throw the stone at the bird and luckily it dies. You are glad it is dead but now you committed a crime.");
	// -------------------------------------------------------------------------------------- //

	// ---------------------------------------ROAD 2------------------------------------------ //
	// lake a choice path "aa"
	spare.giveStory("When we live in a society we all make an agreement not to kill each other. Everyone you interact with is capable of killing you. "
		"Yet as we partake in this society we agree not to do it. This is how the world works");
	// lake b choice path "ab"
	spear.giveStory("Thinking quickly you construct a homemade spear using only some string, an umbrella and a spear "
		"You take aim and throw the spear at the fish, hitting it right between the eyes "
		"You retrieve the fish from the lake and start cooking it right away.");
	// stone a choice path "ba"
	cook.giveStory("Seing how the bird has few meat you decide to slow cook it in the oven, with some seasoning, purple onions, garlic, red wine "
		"you also add oregano and some stock that you have made from the marrow of the bones of your previous victims.");
	// stone b choice path "bb"
	act.giveStory("You move quickly to the forest till you reach the dorms, you enter quickly but taking your temperature as the good boy you are "
		"It is summer vacation there is nothing good to do so you just chill and browse the interenet");
	// ------------------------------------------------------------------------------------- //

	// ---------------------------------------ROAD 3------------------------------------------ //
	// spear b choice path "abb"
	// act b choice path "bbb"
	apotheosis.giveStory("You just killed an animal"
		" How do you feel about it you murderer? ^"
		" They are onto you you need to get out of here");
	apotheosis.addStoryModifier("The school website says that they are looking for you."
		, "bbb");
	apotheosis.addStoryModifier("It was a magical fish that could talk and grant you a wish. Or maybe not, you won't ever know now. "
		, "abb");
	// spare a choice path "aaa"
	god.giveStory("This fish's life is in your hands, you are the one who decides whether it lives or dies "
		"This fact makes you realize that you are god and you cant help but say it outloud: 'I am become death the destroyer of worlds'"
		" You see your friends at the cafeteria, they just had lunch and they are walking towards you");
	// spare b choice path "aab"
	linked.giveStory("You walk away and see a gathering of people at your right. "
		"But you are running late for a meeting with miss Gena");
	// cook a choice path "baa"
	sense.giveStory("This is one tasty chicken. "
		"You want everybody to taste this chicken and decide to open a restaurant."
		"What method of financing you dream will you choose?");
	// cook b choice path "bab"
	pachon.giveStory("You abandon your dreams of becoming a chef and focus on your studies. "
		"4 years past by and you are finished with your bachelor degree.");
	// act a choice path "bba"
	cansado.giveStory("You look NDHU hate apparently someone found the dead bird. "
		" People want justice for the bird."
		"What will you comment on the post?");
	// spear a choice path "aba"
	tired.giveStory("You feel a very acute pain in your stomach "
		",maybe this wasn't a good idea."
		" Oh god, you see a light.");
	// --------------------------------------------------------------------------------------- //

    // ---------------------------------------ROAD 4------------------------------------------ //
    // linked a choice "aaba"
    // cansado a choice "bbaa"
    pescado.giveStory("^ "
                      "People want justice for the bird. It is a serious crime. "
                      "Even pidgeons (which are a plage) you cannot kill. "
                      "You can't get out of this one");
    pescado.addStoryModifier("Someone else killed the bird and framed you for the murder. Since you were the last seen there."
                             , "aaba");
    pescado.addStoryModifier("They don't believe your lies.", "bbaa");
    // linked b choice "aabb"
    largo.giveStory("Miss Gena wants to talk to you about your academic performance. "
                      "You have the worst gpa in the university."
                      " The only reason you haven't been expelled yet is because you are the only Guatemalan here. "
                      "The university has given you many chances but can no longer tolerate your stupidity. "
                      "Miss Gena bids you farewell and says she hopes to never see you again.");
    // apotheosis a choice "abba" and "bbba"
    nombrex.giveStory("Yoo cooperate with the authorities. You are a dissapointment to your family and a disgrace your country.");
    // apotheosis b choice "abbb" and "bbbb"
    malapractica.giveStory("Living in the forest your only sustain is the school mascot bird, they start noticing their reduced number "
                         "so people get into the foresto to investigate. "
                         "They found you.");
    // god a choice "aaaa"
    feliz.giveStory("You tell them how you have become god. "
                       "Your friend love you so they let the authorities now about yous psychotic breakdown."
                       "The police come to interrogate you.");
    // god b choice "aaab"
    noches.giveStory("You say Hi to your friends."
                          " Your friends let you know they released the scores of the tests. "
                          "You know you failed both of the exams but still want to ask. "
                          "What score you want to know first? (Your fate is already decided your choice doesnt matter)");
    // sense a choice "baaa"
    based.giveStory("You take all your money from your stipend to rent a local at zhixue street."
                    " The local is not doing well and you ran out of money.");
    // sense b choice "baab"
    popito.giveStory("You take up a loan. Your business booms and you become very rich. "
                       "You pay back your loan and become financially stable. Life has never been better.");
    // pachon a choice "baba"
    jesucristo.giveStory("You find a suitable job and a cute girlfriend. You two have kids and then you remember "
                        "you forgot to update your documents and you didn't even apply for a job permit.");
    // pachon b choice "babb"
    cicada.giveStory("You apply for an scholarship. But because of your poor academic success during your bachelor you get denied. "
                        "What do you do now?");
    // cansado b choice "bbab" // a choice is above for the pescado object
    aburrido.giveStory("The NDHU OIA calls you for a meeting because of your values, they can't let international student go around spreading hate. "
                        "Do you want to tell something before being expelled from university?");
    // tired a choice "abaa"
    banana.giveStory("The light at the end of the tunel is Jesus"
                        ". Do you accept Jesus Christ as your lord and savior?");
    // tired b choice "abab"
    despacito.giveStory("You manage to survive the food poisoning. "
                         "All the taiwanese want you to sing despacito.");
    // ---------------------------------------END------------------------------------------ //
}

void Game::linkQuestions() {
	bird.makeRoutes(&lake, &stone);
	// Ask the questions with the possible options
	currentQuestion = &bird;

	lake.makeRoutes(&spare, &spear);
	stone.makeRoutes(&cook, &act);

	spare.makeRoutes(&god, &linked);
	cook.makeRoutes(&sense, &pachon);
	act.makeRoutes(&cansado, &apotheosis);
	spear.makeRoutes(&tired, &apotheosis);

    god.makeRoutes(&feliz, &noches);
    linked.makeRoutes(&pescado, &largo);
    sense.makeRoutes(&based, &popito);
    pachon.makeRoutes(&jesucristo, &cicada);
    cansado.makeRoutes(&pescado, &aburrido);
    apotheosis.makeRoutes(&nombrex, &malapractica);
    tired.makeRoutes(&banana, &despacito);
}

//Checks the input
void Game::travelTo(char pathChoice) {
	if (pathChoice == 'a') {
		currentQuestion = currentQuestion->goA();
		pathStr.append("a");
	}
	else if (pathChoice == 'b') {
		currentQuestion = currentQuestion->goB();
		pathStr.append("b");
	}
	else {
		cout << "You have no option, enter a or b... or quit" << endl;
	}
}


//asks the question
void Game::printOptions() {
	currentQuestion->ask(pathStr);
}


//Take the string input and looks if its good
bool Game::receiveInput(string& userInput) {

	bool badInput = true;
	do {
		cout << "(quit, a or b)>> ";
		getline(cin, userInput);
		// takes the input
		int len = (int)(userInput.length());

		// puts it into lower case
		if (len > 1) {
			for (int i = 0; i < len; ++i) {
				if (isupper(userInput[i])) {
					userInput[i] = tolower(userInput[i]);
				}
			}
		}
		//Goes out if you quit
		char choiceChar = userInput[0];
		if (userInput == "quit") {
			return true;
		}
		//Looks if its a character or a valid character
		else if (len == 0 || len > 1) {
			cout << "Enter only one character or quit." << endl;
		}
		else if (choiceChar != 'a' && choiceChar != 'b') {
			cout << "You think this is a game? Enter a or b." << endl;
		}
		else {
			badInput = false;
		}

	} while (badInput);


	return false;
}

void Game::gameLoop() {

	string userInput = "", path = "";

	while (true) {
		// print story and options
		printOptions();

		//Only true when it quits
		if (receiveInput(userInput)) {
			break;
		}
		// go to the option in the input
		travelTo(userInput[0]);

		// Exits the loop when story ends
		if (currentQuestion == nullptr) {
			break;
		}
	}

}

//main
int main(void) {
    Game game;
	game.gameLoop();

	return 0;
}
