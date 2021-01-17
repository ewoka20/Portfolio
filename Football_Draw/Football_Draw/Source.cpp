#include <iostream> //cin,cout
#include <string>	//string
#include<array>	//array
#include<vector> //vector
#include <algorithm> //random_shuffle(), reverse()
#include <ctime>  //time()
#include <fstream> //ofstream
using namespace std;

// initialising my arrays 
void match(pair<string, int> temp[2], vector <string>&tempVect);
void score(pair<string, int> temp[2], bool zero, pair<int, int> &points);
void penalties(pair<string, int> temp[2],vector <string>&tempVect);

int main() {
	ofstream fileOut("Final-roundup.txt"); //setting up the file for access
	srand(unsigned(time(0))); //srand seeds the randomness so that the random result is different each time
	int cont = 0; //sets a counter at 0
	pair<string, int> teams[16] = {
		{"Belgium",80},{ "France",78},{"Brazil",76},{"England",74},{"Portugal",73},{"Spain",71},{"Uraguay",70},{"Argentina",69},{"Croatia",68}, {"Colombia",67}, {"Mexico",66},{ "Italy",64},{ "Denmark",63},{ "Germany",62},{ "Netherlands",61}, {"Switzerland",60}
	}; // a pair of all the teams and there "Qualities" I used a pair so that I could store multiple variable types in the one array 
	pair<string, int> temp[2]; //a temporary file to store the 2 teams who go face to face
	vector<string> rndTeams(16); //rndTeams originally stood for random teams but as I got on it just became the team holder for other vectors and pairs to access
	vector <string>tempVect(8); //Holds the winners of each round
	tempVect.reserve(40); //reserves some memory for tempVect 
	if(fileOut.is_open()){ //checks to see if the file is open so we can write over it
	cout << "Welcome to the world cup simulation, Here are your teams:" << endl; //outputs onto the console 
	fileOut << "The teams for the world cup" << endl; //outputs onto the file
	while (cont < 4) { //a count of five for the four rounds brackets, quarters, semis and finals (0-4)
		if (cont == 0) { //runs first time round couldve used a switch here maybe mightve been faster 
			for (auto& t : teams) {
				cout << t.first << endl; //outputs a list of the teams for user to see but its fast a bit of delay here might help for user experience
			}
			for (int i = 0; i < 16; i++) { //a loop for the file output and teams 
				fileOut << teams[i].first << endl; //This couldve also gone in the loop above but I'm tired
				
				rndTeams[i] = teams[i].first; //copies the teams array into a vector that can be randomised

			}
			fileOut << endl; //ends line so an extra space is added between sections
			random_shuffle(rndTeams.begin(), rndTeams.end()); //randomises the vector
		}
		else if (cont == 1){
			cout << "Your Quarter Finalists" << endl;
			fileOut << "Your Quarter Finalists" << endl;
			rndTeams.resize(8); //resizes rndTeams for the new elements to be added
			reverse(tempVect.begin(), tempVect.end()); // reverses the elements in tempVect as the format is "" "" "" ""... team team team team 
			tempVect.resize(8);//Then is resized to delete the blank spaces leaving only the teams 
			for (int i = 0; i < 8;i++) {
				cout << tempVect[i] << endl; //outputs the QF's for the user to see
				rndTeams[i] = tempVect[i]; //and adds them to rndTeams for the next set of matches
				fileOut << tempVect[i] << endl;
			}
			fileOut << endl;
			tempVect.clear(); //clearing tempVect to keep it nice for the next set of data
			tempVect.resize(4); //resizing tempVect here for the next set of matches as there will only be four winners
		}
		else if(cont == 2) {
			cout << "Your Semi Finalists" << endl;
			fileOut << "Your Semi Finalists" << endl;
			rndTeams.resize(4); 
			reverse(tempVect.begin(), tempVect.end());//reverse and resize keeps the data flowing
			tempVect.resize(4);
			for (int i = 0; i < 4; i++) {
				cout << tempVect[i] << endl;
				rndTeams[i] = tempVect[i];
				fileOut << tempVect[i] << endl;
			}	
			fileOut << endl;
			tempVect.clear();
			tempVect.resize(2); //resizes for 2 as there will be 2 winners
		}
		else if (cont == 3) {
			fileOut << "Your Finalists" << endl; //I couldve found a way to put this set of code in a function given i used it 3-4 times
			rndTeams.resize(2);
			reverse(tempVect.begin(), tempVect.end());
			tempVect.resize(2);
			for (int i = 0; i < 2; i++) {
				cout << tempVect[i] << endl;
				rndTeams[i] = tempVect[i];
				fileOut << tempVect[i] << endl;
			}
			fileOut << endl;
			tempVect.clear();
			tempVect.resize(1); //resizes to 1 because theres only one winner
		}
			cout << "Lets Begin shall we?" << endl;
			for (auto i : tempVect) { //runs for 8 matches at the start and decreases by half each time 
				temp[0].first = rndTeams.back();//adds the last two teams into the temp variable to be used
				rndTeams.pop_back(); //Then deletes the teams it added
				temp[1].first = rndTeams.back();
				rndTeams.pop_back();
				for (auto& j : teams) { //loops to find the right quality variable for the temp to take with it 
					if (j.first == temp[0].first || j.first == temp[1].first) { //checks to see if either of the teams match
						if (j.first == temp[0].first) {//then matches with right team for the right quality
							temp[0].second = j.second; //adds the quality of the team to the temp variable
						}//couldve used a search or a find here but i couldnt figure it out
						else {
							temp[1].second = j.second;
						}
					}
				}
				match(temp, tempVect); //starts match function
			}
			cont++; //cont = cont + 1 cont is a count minus u because Im creative
			

			

		}
	reverse(tempVect.begin(), tempVect.end()); //reversing the vector for the final time
	cout << "Your winner is " << tempVect.at(0);
	cout << "For a quick rundown open Final-roundup.txt in the directory" << endl;
	fileOut << "The winner is " << tempVect.at(0);
	fileOut.close(); //closes the file so we cant add more to it
	
	}
	else {
		cout << "File cannot be accessed. Terminating program" << endl;
		return -1; //exits the program if something is wrong
	}
	return 0; //ends the program
	}


void match(pair<string, int> temp[2], vector <string>&tempVect){ //sets the match up the teams have six chances at the goal
	pair<int, int> points; //making points for the team score
	int action; //for the randomiser
	bool side; //defines which side scores
	points.first = 0; //declares point as 0 before each match
	points.second = 0;
	cout << temp[0].first << " VS " << temp[1].first << endl; //announces who is fighting who //Could add this to the file if I wanted
	for (int i = 0; i < 6; i++) {
		action = rand() % 99 + 1; // gets a random number between 1 and 99 for the next chance
		if (action <= 99 && action >= 67) { //lets team 1 shoot
			side = true;
			score(temp, side, points); //each team has an equal chance 1 in 3 to shoot but theres also 1 in 3 chance that no one scores
			
		}
		else if (action <= 66 && action >= 34) { //lets team 2 shoot
			side = false;
			score(temp, side, points);
		}else{
			cout << "No one scores" << endl; //nothing happens
		}
	}
	cout << "Final score " << temp[0].first << " " << points.first << " " << points.second << " " << temp[1].first << endl; //displays the final score
	
	if (points.first > points.second) { //if the first team scored more they win
		cout << temp[0].first << " WINS" << endl;
		tempVect.push_back(temp[0].first); //and this pushes back the tempVect to add the winner
	}
	else if (points.second > points.first) {//likewise if the second team win 
		cout << temp[1].first << " WINS" << endl;
		tempVect.push_back(temp[1].first);
	}
	else { //if theres a tie
		cout << "We have to go into penalties to decide" << endl;
		penalties(temp,tempVect); //we go to penalties
	}
}

void score(pair<string, int> temp[2], bool zero, pair<int, int> &points) { //function for whether or not a team scores
	int goal, save;
	goal = rand() % 100 + 40; //sets a random number between 40 and 100
	save = rand() % 120 + 60; //sets a random number between 60 and 120
	if (zero == true) { //zero is the bool name in the function
		if (goal > temp[0].second) { //if goal is greater than the teams quality
			cout << temp[0].first << " Misses" << endl; //their shot misses
		}
		else if(save > temp[1].second){ //otherwise the shoot right at the goal, but only score if the save is higher than the opposing teams quality
			cout << "GOOOAL for " << temp[0].first << endl;
			points.first++; //points get incremented here
		}
		else {
			cout << temp[1].first << " Saved the shot" << endl; //in which it is saved
		}
		
	}else{
		if (goal > temp[1].second) {
			cout << temp[1].first << " Misses" << endl;
		}
		else if (save > temp[0].second) {
			cout << "GOOOAL for " << temp[1].first << endl; //same is true on the reverse
			points.second++;
		}
		else {
			cout << temp[0].first << " Saved the shot" << endl;
		}
	}

}
void penalties(pair<string, int> temp[2],vector <string>& tempVect) { //function for penalties
	pair<int, int> points; //re-initialised points here as we can use them to count how many goals we have
	bool side,loop = true;
	while (loop == true){
	for (int i = 0; i < 5; i++) { //it will loop 5 times given the team each a chance to score
			side = true;
			score(temp, side, points);
			side = false;
			score(temp, side, points);
	}
	if (points.first > points.second) { //if one team scores more penalties than another they win
		cout << temp[0].first << " WINS" << endl;
		tempVect.push_back(temp[0].first);
		loop = false;
	}
	else if (points.second > points.first) {
		cout << temp[1].first << " WINS" << endl;
		tempVect.push_back(temp[1].first);
		loop = false;
	}
	else {//this is meant to simulate the sudden death round but it doesnt work see comment below
		while (points.first == points.second ) { //when the first team scores this doesnt work as planned?
			side = true;
			score(temp, side, points);
			side = false; //again just lets both teams shoot 
			score(temp, side, points);
		}
	}
	}
}

