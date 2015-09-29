

#include <iostream>
#include <string>

using namespace std;


int playerOneScore = 0;
int playerTwoScore = 0;
int computerScore = 0;
int whosTurn = 0; //0 = player1, 1 = player2 or com


class NumberBox{
    
    public:
    NumberBox(char _value){
        
        value = _value;
        isOqupied = false;
        
    }
    
    ~NumberBox(){}
    
    char getValue(){
        return value;
    }
    
    void setValue(char v){
        value = v;
    }
    void setIsOpuqied(bool o){
        isOqupied = o;
    }
    
    
    private:
    char value;
    bool isOqupied;
    
};


NumberBox one('1');
NumberBox two('2');
NumberBox three('3');
NumberBox four('4');
NumberBox five('5');
NumberBox six('6');
NumberBox seven('7');
NumberBox eight('8');
NumberBox nine('9');



void updateGrid(){
    
    
    cout << "+---+---+---+\n"
    << "| " << one.getValue() << " | " << two.getValue() << " | " << three.getValue() << " |\n"
    << "+---+---+---+\n"
    << "| " << four.getValue() << " | " << five.getValue() << " | " << six.getValue() << " |\n"
    << "+---+---+---+n"
    << "| " << seven.getValue() << " | " << eight.getValue() << " | " << nine.getValue() << " |\n"
    << "+---+---+---+\n"
    << "\n"
    << " Player | Score\n"
    << "--------+--------------\n"
    << "Player1 |  "<< playerOneScore <<"\n"
    << "Player2 |  "<< playerTwoScore <<"\n"
    << endl;
    
}


bool isOneToNine(char num){
    if(num != '1' &&
    num != '2' &&
    num != '3' &&
    num != '4'&&
    num != '5'&&
    num != '6'&&
    num != '7'&&
    num != '8'&&
    num != '9'){
        return false;
    }
    return true;
}


/*
NumberBox getNumberBoxByValue(char value){
    if(one.getValue() == value) return one;
    if(two.getValue() == value) return two;
    if(three.getValue() == value) return three;
    if(four.getValue() == value) return four;
    if(five.getValue() == value) return five;
    if(six.getValue() == value) return six;
    if(seven.getValue() == value) return seven;
    if(eight.getValue() == value) return eight;
    if(nine.getValue() == value) return nine;
}
*/


char win(){
    
    char _one = one.getValue();
    char _two = two.getValue();
    char _three = three.getValue();
    char _four = four.getValue();
    char _five = five.getValue();
    char _six = six.getValue();
    char _seven = seven.getValue();
    char _eight = eight.getValue();
    char _nine = nine.getValue();
    char X = 'X';
    char O = 'O';
    
    if(_one == X && _two == X && _three == X ||
    _four == X && _five == X && _six == X ||
    _seven == X && _eight == X && _nine == X ||
    _one == X && _four == X && _seven == X ||
    _two == X && _five == X && _eight == X ||
    _three == X && _six == X && _nine == X ||
    _one == X && _five == X && _nine == X ||
    _three == X && _five == X && _seven == X){
        return 'X';
    }
    if(_one == O && _two == O && _three == O ||
    _four == O && _five == O && _six == O ||
    _seven == O && _eight == O && _nine == O ||
    _one == O && _four == O && _seven == O ||
    _two == O && _five == O && _eight == O ||
    _three == O && _six == O && _nine == O ||
    _one == O && _five == O && _nine == O ||
    _three == O && _five == O && _seven == O){
        return 'O';
    }
    
}





void pvpPlay(){
    
    char input;
    
    while(true){
        
        char symbol = (whosTurn == 0 )? 'O' : 'X';
        
        cin >> input;
        
        if( isOneToNine(input) ){
            
            char value = input;
            
            if(one.getValue() == value) one.setValue(symbol);
            if(two.getValue() == value) two.setValue(symbol);
            if(three.getValue() == value) three.setValue(symbol);
            if(four.getValue() == value) four.setValue(symbol);
            if(five.getValue() == value) five.setValue(symbol);
            if(six.getValue() == value) six.setValue(symbol);
            if(seven.getValue() == value) seven.setValue(symbol);
            if(eight.getValue() == value) eight.setValue(symbol);
            if(nine.getValue() == value) nine.setValue(symbol);
            
            updateGrid();
            
            whosTurn = (whosTurn == 0 )? 1 : 0;
            
            if(win() == 'X'){
                
                playerOneScore++;
                
                updateGrid();
                
                cout << "X Won!!!" << endl;
                
                break;
                
                } else if(win() == 'O'){
                
                playerTwoScore++;
                
                updateGrid();
                
                cout << "O Won!!!" << endl;
                
                break;
                
            }
            
            } else{
            
        }
        
    }
    
}




int main()
{
    updateGrid();
    
    pvpPlay();
    
}