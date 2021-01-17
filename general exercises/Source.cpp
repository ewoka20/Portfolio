#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<array>
using namespace std;

void Dtd();
void DoubTrob(int num);
void TrobDoub(int &num);
void shape();
void square();
void triangle();
void circle();
void inv();
void workout();
void pairr();
void directions();
void pointy();
void example();
void MAX();
void memories();

int main() {
	char choice;
	bool ye = true;

	while (ye == true) {
		cout << "Choose the function you want?" << endl;
		cout << "A: Double Trouble Doubled" << '\n' << "B:shape area " << '\n' << "C:Input vectors " << '\n' << "D:Vector workout " << '\n' << "E:Pairs and Tuples " << '\n' << "F:Directions " << endl;
		cout << "G:Whats the point" << '\n' << "H: The arithmetic example" << '\n' <<"I: Point to the max"<<'\n'<<"J: Making Memories"<< '\n'<< "Any other input: Exit" << endl;
		cin >> choice;
		choice = (toupper(choice));
		switch (choice) {
		case 'A':
			Dtd();
			break;
		case 'B':
			shape();
			break;
		case 'C':
			inv();
			break;
		case 'D':
			workout();
			break;
		case 'E':
			pairr();
			break;
		case 'F':
			directions();
			break;
		case 'G':
			pointy();
			break;
		case 'H':
			example();
			break;
		case 'I':
			MAX();
			break;
		case 'J':
			memories();
			break;
		default:
			ye = false;
		}

	}
	return 0;
}
void Dtd() {
	int num;
	cout << "Input a number" << endl;
	cin >> num;
	DoubTrob(num);
	cout << num << "By val" << endl;
	TrobDoub(num);
	cout  << num << "By ref" << endl;
}
void DoubTrob(int num){
	num = num * 2;
	cout << num << '\t';
}
void TrobDoub(int &num) {
	num = num * 2;
	cout << num << '\t';
}
void shape() {
	char choose;
	cout << "Would you like to:" << '\n' << "1:Calculate the area of a square" << '\n' << "2:Calculate the area of a circle" << '\n' << "3:Calculate the area of a triangle" << endl;
	cin >> choose;
	switch (choose) {
	case '1':
		square();
		break;
	case '2':
		circle();
		break;
	case '3':
		triangle();
		break;
	default:
		cout << "You are now exited because i couldnt be asked to loop" << endl;
	}


}
void circle() {
	float radius,area,pi = 3.14;
	cout << "Enter the radius" << endl;
	cin >> radius;
	area = pi * (radius * radius);
	cout << "The area is: " << area << endl;
}
void square() {
	float length, width, area;
	cout << "Enter the length" << endl;
	cin >> length;
	cout << "Enter the width" << endl;
	cin >> width;
	area = length * width;
	cout << "The area is: " << area << endl;
}
void triangle() {
	float length, width, area;
	cout << "Enter the length" << endl;
	cin >> length;
	cout << "Enter the width" << endl;
	cin >> width;
	area = (length * width)/2;
	cout << "The area is: " << area << endl;
}
void inv() {
	vector<int> Victor(5);
	
	cout << "Enter 5 integers" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> Victor.at(i);
	}
	for (auto t:Victor){
		cout << t << " ";
	}
	cout << endl;
	
}
void workout() {
	vector<int> work = { 43,24,52,16,7,13,535,35,634,434 };
	for (auto w : work) {
		cout << w << " ";
	}
	cout << endl;
	cout << *min_element(work.begin(), work.end()) << endl;
	cout << *max_element(work.begin(), work.end()) << endl;
	work.resize(20);
	for (auto w : work) {
		cout << w << " ";
	}
	cout << endl;
	cout << "Enter 10 more values" << endl;
	for (int i = 10; i < 20; i++) {
		cin >> work.at(i);
	}
	for (auto w : work) {
		cout << w << " ";
	}
	cout << endl;
	work.push_back(23);
	work.push_back(28);
	for (auto w: work) {
		cout << w << " ";
	}
	cout << endl;
	work.pop_back();
	work.pop_back();
	for (auto w : work) {
		cout << w << " ";
	}
	cout << endl;
	work.clear();
	cout << work.size() << endl;
	if (work.empty()) {
		cout << "Vector is empty" << endl;
	}
	else {
		cout << "Vector is not empty" << endl;
	}
}
void pairr() {
	pair<string, int> team("sugerville", 21);
	tuple<string, double, int> salt("salt lake city", 34.9, 32);
	cout << team.first << " is ranked " << team.second << " In the league" << endl;
	cout << "but over to weather," << '\n' << "Well tom it looks like " << get<0>(salt) << " is having a warm one with highs of " << get<1>(salt) << " degrees celcius"<<'\n'<< "but with winds raging up to " << get<2>(salt) << "mph expect fire tornados back to you tom" << endl;
	cout << "Thank you weather, why did your parents name you this way?" << endl;
}
void directions() {
	enum direct {
		UP, 
		DOWN,
		LEFT,
		RIGHT
	};
	direct dire;
	char dir;
	cout << "Press w a s or d" << endl;
	cin >> dir;
	dir = (tolower(dir));

	switch (dir) {
	case 'w':
		dire = UP;
		break;
	case 'a':
		dire = LEFT;
		break;
	case 's':
		dire = DOWN;
		break;
	case 'd':
		dire = LEFT;
		break;
	default:
		cout << "You put in wrong letter sorry" << endl;
	}
	//Enums dont make sense to me plus i probably dont need them for my assessment so \-_-/
}
void pointy() {
	int* myIntPtr = NULL;
	int myInt;
	
	cout << "Enter a integer" << endl;
	cin >> myInt;

	myIntPtr = &myInt;
	cout << *myIntPtr << " " << myIntPtr << " ";
	*myIntPtr = 34;
	cout << *myIntPtr << endl;;
}
void example() {
	string texts[6] = { "Jake", "Coral", "Sam", "Lee", "John", "Ron" };
	//point to first element, don't need to use & ahead of array name
	string* pTexts = texts;

	pTexts += 3; //moves pointer to fourth element in array
	cout << *pTexts << endl;  //outputs Lee

	pTexts -= 2; //moves pointer to second element in array
	cout << *pTexts << endl; //outputs coral

	string* pEnd = &texts[6]; //new pointer assigned address of end element

	pTexts = texts; //original pointer reassigned to first element

	while (pTexts != pEnd) { //while first pointer is not equal to end pointer
		cout << *pTexts << endl; //output dereference value of pointer
		pTexts++; //increment pointer through the array
	}
}

void MAX() {
	int numbers[10]={0,0,0,0,0,0,0,0,0,0};
	int* myIntPtr = numbers;

	cout << "Input 10 random numbers" << endl;
	for (int i = 0; i < 10;i++) {
		cin >> numbers[i];
	}
	
	for (auto m : numbers) {
		if (m > * myIntPtr) {
			*myIntPtr = m;
		}
	}
	cout << "The largest number is " << *myIntPtr << endl;;
}
void memories() {
	int* IntPt;
	string* StrPt;
	int Num = 9;
	string word = "Hey";
	IntPt = &Num;
	StrPt = &word;
	cout << "Int memory address " << IntPt << '\n' << "Int Value" << *IntPt << endl;
	*IntPt = 20;
	cout << "New int value" << *IntPt << endl;
	cout << "String memory address " << StrPt << '\n' << "String Value" << *StrPt << endl;
	*StrPt = "Hello";
	cout << "new String value" << *StrPt << endl;
}