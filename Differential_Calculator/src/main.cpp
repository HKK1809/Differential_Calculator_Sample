/**
*
* @Name : Differential_Calculator/main.cpp
* @Version : 1.0
* @Programmer : Harshpreet Kaur Kathuria
* @Date : 2024-04-20
* @Released under :
* @Repository :
*
**/

#include "main.hpp"



/**
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

string Bracket_Counter (string equation) {
	float answer = 0;
	string eqn;
	//string s;
	//int OBC1 = 0;// Open bracket count before 1st closed bracket
	//int OBC1 =0;//  Open bracket count after 1st closed bracket
	//int address_CB =0; //index of closed bracket being dealt with
	//int address_OB =0; //index of open bracket being dealt with
	int size_of_equation = equation.size();
	int index_close = 0;
	int index_open = 0;
	int number_of_brackets_close = 0;
	int number_of_brackets_open = 0;

	for (int i = size_of_equation; i>=0; i--){
		if (equation[i] == '('){
				index_open = i;
				number_of_brackets_open++;
		}
		else if (equation[i] == ')') {
			index_close = i;
			answer = Equaltion_Breaker(equation.substr(index_open + 1, index_close -index_open -1 ));
		}
	}
	eqn =
return eqn;
}
**/

float Solver(int number_of_operators, vector <int> operator_identity, vector <int> operatorindex, vector <float> numbers){

	float answer = 0 ;
	int s = number_of_operators;

		for(int i=0; i < s; i++){
			if(operator_identity[i] ==3){
			numbers[i] = numbers[i]/numbers[i+1];
			numbers.erase(numbers.begin() + i + 1);
			operator_identity.erase(operator_identity.begin() + i);
			operatorindex.erase(operatorindex.begin() + i);
			s--;
			}
		}
		for(int i=0; i<s ; i++){
			if(operator_identity[i] ==2){
			numbers[i] = numbers[i] * numbers[i+1];
			numbers.erase(numbers.begin() + i +1);
			operator_identity.erase(operator_identity.begin() + i);
			operatorindex.erase(operatorindex.begin() + i);
			s--;
			}
		}
		for(int i=0; i<s; i++){
			if(operator_identity[i] ==1){
			numbers[i] = numbers[i] +numbers[i+1];
			numbers.erase(numbers.begin() + i + 1);
			operator_identity.erase(operator_identity.begin() + i);
			operatorindex.erase(operatorindex.begin() + i);
			s--;
			}
		}
		for(int i=0; i<s; i++){
			if(operator_identity[i] == 0){
			numbers[i] = numbers[i] -numbers[i+1];
			numbers.erase(numbers.begin() + i + 1);
			operator_identity.erase(operator_identity.begin() + i);
			operatorindex.erase(operatorindex.begin() + i);
			s--;
			}
		}
	answer = numbers[0];
	cout << endl << "The answer is: "<< answer << endl;
	return answer;
}

float Equaltion_Breaker(string equation){
	float answer = 0;
	int size_of_equation = equation.size();
	int number_of_operators = 0 ;
	int a = 1; // used to identify if the first number is negative or positive, it stays 1 if it is positive else it becomes ZERO
	vector <int> operatorindex;
	vector <int> operator_identity;

//--------------------Count Number of Operators, index and identify them-------------------------------------//

	for (int i = 0;  i <= size_of_equation; i++) {
		if (equation[i] == '/' ){
			operatorindex.push_back(i);
			operator_identity.push_back(3);
		}
		else if (equation[i] == '*'){
			operatorindex.push_back(i);
			operator_identity.push_back(2);
		}
		else if (equation[i] == '+'){
			operatorindex.push_back(i);
			operator_identity.push_back(1);
		}
		else if (equation[i] == '-'){
			operatorindex.push_back(i);
			operator_identity.push_back(0);
			if (i == 0){
				a = 0;
			}
		}
	}
	number_of_operators = operator_identity.size();

//----------------------------Identification of number in the equation(vector)-----------------------------------------------//

	vector <string> numerics[number_of_operators + a];

	if(a == 1){
		numerics[0] = equation.substr(0, operatorindex[0]);
		for (int i = 1 ; i < number_of_operators + 1 ; i++){
			numerics[i] = equation.substr((operatorindex[i-1] + 1), (operatorindex[i] - operatorindex[i-1] -1));
		}
	}
	else if (a == 0) {
		for (int i = 0 ; i < number_of_operators; i++){
			numerics[i] = (equation.substr((operatorindex[i]+1), (operatorindex[i+1] - operatorindex[i] -1)));
		}
	}

//-------------------------------Error detection such as repetitive--------------------------------------------------//

	if ((operatorindex[0] == 0) && (operator_identity[0] != 0)){
		cout << "Unnecessary operator at the beginning of equation, please enter equation again" << endl;
		error();
		exit(0);
	}
	for(int i=0; i < number_of_operators-1; i++){
		if (operatorindex[i]+1 == operatorindex[i+1]){
			cout << "Indecipherable operator combination, please begin again: " << endl;
			error();
			exit(0);
		}
	}

 //** 	ATTEMPT TO ADD A FUNCTION THAT SEND USER BACK TO THE MAIN FUNCTION TO ENTER THE EQUATION AGAIN!!!

//--------------------- convert the numbers saved as string into float---------------------------------------------------//
	float num =0;
	vector <float> numbers;
	for (int i = 0; i <number_of_operators + a ; i++ ){
		num = std::stof(numerics[i]);
		numbers.push_back(num);

	}

//------------------ELemination of negative sign in the beginning if present--------------------------------------------//

	if( a == 0){
		float num = numbers[0];
		numbers[0] = -1 * num;
		operatorindex.erase(operatorindex.begin());
		operator_identity.erase(operator_identity.begin());
		number_of_operators--;
	}

//-----------------Equation Solving begins----------------------------------------------------------------------------//

	answer = Solver(number_of_operators, operator_identity, operatorindex, numbers);
	return answer;
}

//--------------Loop to remove blank spaces in the equation------------------------------------------------------------//

string Space_Remover (string equation) {
	string eqn;
	string s;
	int size_of_equation = equation.size();
	for (int i = 0;  i <= size_of_equation; i++) {
		if (equation[i] != ' '){
			s = equation[i];
			eqn.append(s);
		}
	}
	return eqn;
}


void Algorithm_Solver() {
	//int Bracket_Breaker_x = 0;
	string equation;
	string eqn;
	float answer;
	cout << "Please enter BDMAS to be solved, \n" << endl;
	cout << "Please do NOT enter any variables here \n" << endl;
	cin.ignore();
	getline(cin >> ws, equation);

	eqn = Space_Remover(equation);
	answer = Equaltion_Breaker(eqn);
	cout << answer <<endl;
/**	if(areBracketsBalanced(equation)){
		x = Equaltion_Breaker(eqn);
	}
	else{
		cout << "Error in bracket combination." <<endl;
		error();
		exit(0);
	}
	x = Equaltion_Breaker(eqn);
	cout << x <<endl; **/
}

void help() {
	cout << "\n\n";
	cout << " Your Personal Calculator ------------------------------\n";
	cout << "\t a\t\t Solving BDMAS EQUATIONS\n";
	cout << "\t h\t\t Help\n";
	cout << "\t e\t\t Exit\n";
	cout << "\n\n";
}

void error() {
	cout << "Error : Input is anonymous!\n";
}

int main(int argc, char** argv) {
	unsigned char type;
	bool flag=true;
	while(flag) {
		cout << "------------------\n";
		cout << "(a) For solving a BDMAS equation\n";
		cout << "(b) For solving an equation with single variable\n";
		cout << "(y) For help\n";
		cout << "(z) To exit\n";

		cout << "Enter Your type: \n";
		cin >> type;
		switch(type) {
			case 'a':
				Algorithm_Solver();
			break;
			case 'y':
				help();
			break;
			case 'z':
				flag=false;
			break;
			default:
				error();
			break;
		}
	}
	return 0;
}


