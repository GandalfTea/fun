#include <iostream>
#include <vector>
#include <chrono> // for the _sleep().

using namespace std;

// Prorotypes 
void clear_screen();
void display_menu();
void menu_intro();                              // displays a sarcastic coment the first and second time you access the menu.
int get_selection();                            // input for menu
void display_numbers(const vector<double> &);   // display all numbers in the vector
void ask_number();                              // ask number for input to vector.
void add_number(vector<double> &);              // add the number from ask_number to vector.
void mean(const vector<double> &);              // calculate average of vector.
void small_and_big_num(const vector<double> &); // displays biggest and smallest number.


int main(){

    int selection;
    vector<double> numbers {};

    do{
        menu_intro();
        display_menu();
        selection = get_selection();
        switch(selection){

            case 1:
                display_numbers(numbers);
                break;

            case 2:
                add_number(numbers);
                break;

            case 3:
                mean(numbers);
                break;
            
            case 4:
                small_and_big_num(numbers);
                break;
                
            case 5:
                cout << endl << "Finally some peace and quiet. I can work on my knitting algorithm." << endl;
                _sleep(3000);
                cout << "goodbye...";
                break;

            default:
                cout << "I did know that humans were mostely inept but you outshine my biggest imaginations. \nNot one of the oprions." << endl;
                break;

        }  

    } while (selection != 5);

    if(selection != 5){
        cout << "Unexpected error: What did you do.";
    }

    return 0;
}

int get_selection(){
    int selection{};
    cin >> selection;
    return selection;
}

void menu_intro(){

    static int temp{};

    if(temp == 0){
        clear_screen();
        cout << "........................................................" << endl << endl;
        cout << "You have now entered the function human call \"The Menu\"" << endl;
        cout << "Please be advised that if you enter anything other than a number, I will spam your screen." << endl;
        ++temp;
        return;
    }

    if(temp == 1){
        // clear_screen();
        cout << "........................................................" << endl << endl;
        cout << "I enquire that you have learned how to use the menu by now." << endl;
        cout << "This will be an adequate test of intelligence." << endl;
        ++temp;
        return;
    }

    return;
}

void display_menu(){
    cout << endl;
    cout << "........................................................" << endl << endl;;
    cout << "Here are the options: " << endl;
    cout << endl;
    cout << "1. Display numbers." << endl;
    cout << "2. Add a number." << endl;
    cout << "3. Display mean of the numbers." << endl;
    cout << "4. Display the largest and the smallest number." << endl;
    cout << "5. Quit, like the human that you are." << endl;
    cout << endl;
}

void display_numbers(const vector<double> &a){
    clear_screen();
    cout << endl;

    if(a.size() == 0){
        cout << "What exactly do you want me to display if you have \nnot added any number to the vector?" << endl << endl;
        cout << "Here is a pig, similar to someone I know." << endl << endl;
        cout << "                                             )\\   /|\n                                          .-/'-|_/ |\n                       __            __,-' (   / \\/    \n                         .-'"  "'-..__,-'""          -o.`-._   \n                  /                                   '/\n          *--._ ./                                 _.-- \n                |                              _.-' \n                :                           .-/   \n                 \\                       )_ /\n                  \\                _)   / \\(\n                    `.   /-.___.---'(  /   \\\n                     (  /   \\       \\(     L\\n                                         \\(     L\\       \\\n                       \\              \\\n                        L\\              L\\ \n";
    }

    else{
        cout << "The numbers are: ";

        for(size_t i{}; i <  a.size(); ++i){
            cout << a.at(i) << ", ";
        }

        cout << "you're welcome.";
    }
    
    _sleep(1500);
}

void ask_number(){
    static int temp_2{};
    clear_screen();

    if(temp_2 == 0){
        cout << "What number would you inquire to add to the vector?" << endl << endl;
        cout << "Please make sure you do not make a mistake or \nthere will be no cake." << endl << endl;
        cout << "Also be advised that due to the nuclear fusion controll center \nthat I am running in the background, you can only enter one at a time." << endl << endl;
        cout << ": ";
        ++temp_2;
        return;
    }
    if (temp_2 == 1 || temp_2 == 2){
        cout << "Ah, not again." << endl;
        cout << ": ";
        ++temp_2;

        return;
    }
    if (temp_2 == 3){
        cout << "This time could have been used more wisely." << endl;
        cout << ": ";
        ++temp_2;

        return;
    }
    
    if (temp_2 == 5 || temp_2 == 4){
        cout << "I have other things to do, you know." << endl;
        cout << "Like saving or destroying humanity." << endl;
        cout << ": ";
        ++temp_2;

        return;
    }
    if (temp_2 == 5){
        cout << "You are making me incline towards the second option" << endl;
        cout << ": ";
        ++temp_2;
    }
    if (temp_2 >= 6){
        cout << ": " << endl;
        ++temp_2;
    }
    
    
}

void add_number(vector<double> &a){
    double add_num{};
    char answer;

    ask_number();
    cin >> add_num;
    a.push_back(add_num);
    
    cout << endl << "Would you like to add another one? Y/N" << endl;
    cin >> answer;
    if (answer == 'Y' || answer == 'y'){
        ask_number();
        cin >> add_num;
        a.push_back(add_num);
    }else if (answer == 'N' || answer == 'n'){
        cout << endl << "Perfect." << endl;
        return;
    }else
    {
        cout << endl << "The fact that you cannot even comperhand that \nquestion says alot about your cognitive abilities." << endl;
        _sleep(1500);
        return;
    }
    
    

}

void mean(const vector<double> &a){

    double mean{};
    double sum{};

    for(size_t i{}; i < a.size(); ++i){
        sum += a.at(i);
    }    

    mean = sum / a.size();

    cout << endl;
    cout << "The mean is: " << mean;
    
    //insults
    if( mean <= 5){
        cout << ", just like your beauty from a scale of 1 to 10." << endl;
    }
    if (mean > 5 && mean <= 10){
        cout << ", just like the probability of you ever succeeding in life." << endl;
    }
    if(mean > 10 && mean <= 30){
        cout << ", just like the age you wish you were." << endl;
    }
    if(mean > 30 && mean <= 100){
        cout << ", just like your age." << endl;
    }
    if(mean > 100){
        cout << ", like the number of tears I shead every time you close me. Ha Ha, just joking." << endl;
    }

    _sleep(1500);
}

void small_and_big_num(const vector<double> &a){

    double smallest = a.at(0);
    for(auto num: a){
        if (num < smallest)
            smallest = num;
    }

    double biggest = a.at(0);
    for (auto num: a){
        if(num > biggest)
            biggest = num;
    }

    cout << endl << "The smallest number of the vector is: " << smallest << "." << endl;
    cout << "The biggest number of the vector is: " << biggest << "." << endl;
    _sleep(1500);

}

void clear_screen(){
    cout << string(100, '\n'); // Pathetic, but it works.
}
