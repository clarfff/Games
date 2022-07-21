#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class ATM{
    public:
        string card;
        ATM()
        {
            card = "undefined";
            pin = 0000;
        }

        ATM(string newCard, int newPin)
        {
            card = newCard;
            pin = newPin;
        }

        string alarm()
        {
            for(int i = 0; i < 3; i++)
            {
                cout << "Enter Pin: ";
                cin >> pin;
                cout << endl;
                if(pin == truePin)
                {
                    cout << "Correct! What type of account is this (savings or checking): ";
                    cin >> card;
                    return card;
                    break;
                }
                else if((i == 2 ) && (pin != truePin))
                {
                    cout << "Uh oh" << endl;
                    return "cops";
                }
                else{
                    cout << "Wrong try again." << endl;
                }
            }
        }


    private:
        int pin;
        int truePin = 1234;
};

class Savings: public ATM{
    public:
        int money;
        bool cashOut;
        int input;

        Savings(){
            money = rand();
        }

        Savings(int newMoney)
        {
            money = newMoney;
        }

        void deposit()
        {
            cout << "ACCOUNT BALANCE: " << money << endl;
            cout << "How much would you like to deposit?: ";
            cin >> input;
            cout << endl;
            money += input;
            cout << "Your new balance is: " << money << endl;
        }

        int withdraw()
        {
            if(cashOut == 0)
            {
                cout << "ACCOUNT BALANCE: " << money << endl;
                cout << "How much would you like to withdraw?: ";
                cin >> input;
                cout << endl;
                money -= input;
                cout << "Your new balance is: " << money << endl;
                return input;
            }
            else{
                cout << "Sorry, you have already taken out money this month." << endl;
            }
        }

        void savingsInput(int x)
        {
            money += x;
            cout << "Your new savings balance is: " << money << endl;
        }

        void display()
        {
            cout << "SAVINGS ACCOUNT BALANCE: " << money << endl;
        }

};

class Checking: public Savings{
    public:
        int i = 0;
        int moneyCheck;
        int cashOut;
        int input;
        int array[2][10];

        Checking()
        {
            moneyCheck = rand();
            int cashOut = 0;
        }

        Checking(int newMoneyCheck, int newCashOut)
        {
            moneyCheck = newMoneyCheck;
            cashOut = newCashOut;
        }

        void deposit()
        {
            cout << "ACCOUNT BALANCE: " << moneyCheck << endl;
            cout << "How much would you like to deposit?: ";
            cin >> input;
            cout << endl;
            moneyCheck += input;
            cout << "Your new balance is: " << moneyCheck << endl;
            i++;
        }

        int withdraw()
        {
            cout << "ACCOUNT BALANCE: " << moneyCheck << endl;
            cout << "How much would you like to withdraw?: ";
            cin >> input;
            cout << endl;
            if(input <= 700)
            {
                moneyCheck -= input;
                cout << "Your new balance is: " << moneyCheck << endl;
                return input;
            }
            else{
                cout << "Over daily limit allowed to withdraw." << endl;
            }
            i++;
        }

        int transfer()
        {
            cout << "CHECKING ACCOUNT BALANCE: " << moneyCheck << endl;
            cout << "How much would you like to transfer: ";
            cin >> input;
            cout << endl;
            moneyCheck -= input;
            cout << "Your new checking balance is: " << moneyCheck << endl;
            i++;
            return input;
        }

        void keepTrack(int which)
        {
            array[0][i] = input;
            array[1][i] = which;
        }

        void printTrans()
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    cout << array[j - 1][i - 1] << " ";
                }
                cout << endl;
            }
        }


};

int main()
{
    string get;
    ATM customer = ATM();

    get = customer.alarm();
    string run;
    int forTrans = 0;
    string looper = "undefined";

    while(looper != "end")
    {

        if(get == "cops")
        {
            cout << "You have entered your pin incorrectly three times." << endl << "The cops have been called, your account has been frozen and your card is now mine." << endl;
        }
        else if(get == "checking")
        {
            Checking acctCheck = Checking();
            Savings acctCh = Savings();
            cout << "Would you like to deposit, withdraw, transfer money or display past transactions?: ";
            cin >> run;
            if(run == "deposit")
            {
                acctCheck.deposit();
                acctCheck.keepTrack(1);
            }
            else if(run == "withdraw")
            {
                acctCheck.withdraw();
                acctCheck.keepTrack(2);
            }
            else if(run == "transfer")
            {
                acctCh.display();
                forTrans = acctCheck.transfer();
                acctCh.savingsInput(forTrans);
                acctCheck.keepTrack(2);
            }
            else if(run == "display")
            {
                acctCheck.printTrans();
            }
        }
        else if(get == "savings")
        {
            Savings acct = Savings();
            cout << "Would you like to deposit or withdraw money?: ";
            cin >> run;
            if(run == "deposit")
            {
                acct.deposit();
            }
            else if(run == "withdraw")
            {
                acct.withdraw();
            }
        }

        cout << "Would you like to keep making transactions? If not, enter 'end' :";
        cin >> looper;
        cout << endl;

        cout << "To switch between accounts, type either 'checking' or 'savings': ";
        cin >> get;
        cout << endl;
    }
}