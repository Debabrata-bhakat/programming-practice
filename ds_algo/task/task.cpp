#include <iostream>
#include <string>
using namespace std;

int first(string el,string * sep);
bool isNumber(string s);
bool isValid(string elevator, int & num_of_users, int &most_pass);

int first(string el,string * sep){

    // string *sep = new string[el.length()];
    int sep_index = 0;
    for (int i = 0; i < el.length(); i++)
    {
        char curr = el[i];
        // Characters + or -
        if (curr == 'M' or curr == 'C' or curr == 'O' or curr == '+' or curr == '-'){
            sep[sep_index++] = curr;
        }
        // Numbers
        if(curr >= 48 and curr <= 57){
            string number_string = "";
            number_string += curr;
            while (i+1<el.length() and el[i+1]>=48 and el[i+1]<=57)
            {
                i++;
                number_string += el[i];
            }
            sep[sep_index++] = number_string;
        }
        
    }
    return sep_index;
}

bool isValid(string elevator, int & num_of_users, int &most_pass){
    most_pass = 0;
    string *sep = new string[elevator.length()];
    int res = first(elevator,sep);
    if (sep[0] != "M") return false;
    int curr_state = 1;
    int total_users = 0;
    int number;
    for (int i = 1; i < res; i++)
    {
        switch (curr_state)
        {
            case 1: // Find floor number
                if (!isNumber(sep[i]))
                {   
                    // cout << "Here1";
                    return false;   
                }
                curr_state = 2;
                
                break;
            case 2: // Floor number is found; either go to next floor or open the door
                if (sep[i] == "M")
                {
                    curr_state = 1;
                }
                if(sep[i] == "O")
                {
                    curr_state = 3;
                }
                if (sep[i] != "M" and sep[i] != "O")
                {
                    // cout << "Here2";
                    return false;
                }
                
                break;
            
            case 3: //Lift is open, now either close it or '+'
                if (sep[i] == "C")
                {
                    curr_state = 4;
                }
                if (sep[i] == "+")
                {
                    curr_state = 5;
                }
                if (sep[i] == "-")
                {
                    curr_state = 6;
                }
                
                if (sep[i] != "C" and sep[i] != "+" and sep[i] != "-")
                {
                    // cout << "Here3";
                    return false;
                }
                break;
                
            case 4://Lift is closed, either open it or move to next floor
                if (sep[i] == "O")
                {
                    curr_state = 3;
                }
                if (sep[i] == "M")
                {
                    curr_state = 1;
                }
                if (sep[i] != "O" and sep[i] != "M")
                {
                    // cout << "Here4";
                    return false;
                }
                
                break;
                
            case 5: // this is addition of users
                if (!isNumber(sep[i]))
                {
                    // cout << "Here5";
                    return false;
                }
                number = stoi(sep[i]);
                total_users += number;
                if (total_users > most_pass)
                {
                    most_pass = total_users;
                }
                
                if (i+1<res and sep[i+1] == "C")
                {
                    i++;
                    curr_state = 4;
                }
                else if (i+1<res and sep[i+1] == "+")
                {
                    curr_state = 7;
                }
                else if (i+1<res and sep[i+1] == "-")
                {
                    curr_state = 7;
                }
                else if (i+1 == res)
                {
                    continue;
                }
                
                break;

            case 6: // this is deletion of users
                if (!isNumber(sep[i]))
                {
                    // cout << "Here6";
                    return false;
                }
                number = stoi(sep[i]);
                total_users -= number;
                if (total_users < 0)
                {
                    // cout << "Here7";
                    return false;
                }
                

                if (i+1<res and sep[i+1] == "C")
                {
                    i++;
                    curr_state = 4;
                }
                else if (i+1<res and sep[i+1] == "+")
                {
                    curr_state = 7;
                }
                else if (i+1<res and sep[i+1] == "-")
                {
                    curr_state = 7;
                }
                else if (i+1 == res)
                {
                    continue;
                }
                
                

                break;

            case 7:
                if (sep[i] == "+")
                {
                    curr_state = 5;
                }
                if (sep[i] == "-")
                {
                    curr_state = 6;
                }
                if (sep[i] != "+" and sep[i] != "-")
                {
                    return false;
                }
                break;
                
            default: // code to be executed if n doesn't match any cases
            cout << "Some error" << endl;
        }

    }
    num_of_users = total_users;
    return true;
    
}



bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;
 
    return true;
}


// Above three are utility functions

bool isValidElevatorString(string elevatorstring){
    int totol_users = 0;
    int max = 0;
    return isValid(elevatorstring, totol_users, max);
}


bool doorsOpen(string elevatorstring){
    string *sep = new string[elevatorstring.length()];
    int res = first(elevatorstring,sep);
    int total_users = 0;
    int most_pass = 0;
    if(isValid(elevatorstring, total_users, most_pass)){
        for (int i = res-1; i >=0 ; i--)
        {
            if (sep[i] == "O")
            {
                return true;
            }
            if (sep[i] == "C")
            {
                return false;
            }
            
        }
        
    }
    return false;
}


int endingPassengers(string elevatorstring){
    int total_users = 0;
    int most_pass = 0;
    if (isValid(elevatorstring, total_users, most_pass))
    {
        return total_users;
    }
    else return -1;
    
}

int mostPassengers(string elevatorstring){
    int total_users = 0;
    int most_pass = 0;
    if (isValid(elevatorstring, total_users, most_pass))
    {
        return most_pass;
    }
    else return -1;
}

int endingFloor(string evalstring){
    int total_users = 0;
    int most_pass = 0;
    if(!isValid(evalstring, total_users, most_pass)){
        return -1;
    }
    string *sep = new string[evalstring.length()];
    int res = first(evalstring,sep);
    for (int i = res-1; i >= 0; i--)
    {
        if (sep[i] == "M")
        {
            string level_string = sep[i+1];
            int level = stoi(level_string);
            return level;
        }
        
    }
    return -1;
    
}
int highestFloor(string evalstring){
    int total_users = 0;
    int most_pass = 0;
    int max = 0;
    if(!isValid(evalstring, total_users, most_pass)){
        return -1;
    }
    string *sep = new string[evalstring.length()];
    int res = first(evalstring,sep);
    for (int i = res-1; i >= 0; i--)
    {
        if (sep[i] == "M")
        {
            string level_string = sep[i+1];
            int level = stoi(level_string);
            if (level > max){
                max = level;
            }
        }
        
    }
    return max;
}

int main(){
    string s;
    cin >> s;
    int total_users = 0;
    // string *sep = new string[s.length()];
    // int res = first(s,sep);
    // for (int i = 0; i < res; i++)
    // {
    //     cout << sep[i] << endl;
    // }
    cout << isValidElevatorString(s) << endl;
    cout << total_users << endl;
    cout << endingPassengers(s) << endl;
    cout << mostPassengers(s) << endl;
    cout << highestFloor(s) << endl;
    cout << endingFloor(s) << endl;
}