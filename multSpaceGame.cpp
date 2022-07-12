#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Spaceship{
    public:
        int position[2];
        int orientation;
        int velocity;
        int lives;
        int score;
        string username;

        Spaceship()
        {   
        }

        Spaceship(string newName)
        {
            username = newName;
            position[0] = rand() % 9999;
            position[1] = rand() % 9999;
            lives = 3;
            orientation = rand() % 4;
            velocity = rand() % 99;
            score = 0;
        }

        string getName()
        {
            return username;
        }

        int getXPosition()
        {
            return position[0];
        }

        int getYPosition()
        {
            return position[1];
        }

        int getLives()
        {
            return lives;
        }

        int getOrientation()
        {
            return orientation;
        }

        int getVelocity()
        {
            return velocity;
        }

        int getScore()
        {
            return score;
        }

        void setPosition()
        {
            position[0] = (int) position[0] + (velocity * cos(orientation));
            position[1] = (int) position[1] + (velocity * sin(orientation));
        }

        void setLives()
        {
            lives--;
        }

        void setOrientation()
        {
            orientation = rand() / double(RAND_MAX);
            orientation = 360 * orientation;
        }

        void setVelocity(int x)
        {
            velocity = x;
        }

        void setScore(int x)
        {
            score = x;
        }
};

class Asteroid{
    public:
        int position[2];
        double orientation;
        int velocity;
        int size;

        Asteroid()
        {
            srand(time(0));
            position[0] = rand() % 9999;
            position[1] = rand() % 9999;
            orientation = rand() / double(RAND_MAX);
            orientation = 360 * orientation;
            velocity = rand() % 9999;
            size = rand() % 99;
        }

        double getOrientation()
        {
            return orientation;
        }

        int getXPosition()
        {
            return position[0];
        }

        int getYPosition()
        {
            return position[1];
        }

        void setVelocity(int x)
        {
            velocity = x;
        }

        void setPosition()
        {
            position[0] = (int) position[0] + (velocity * cos(orientation));
            position[1] = (int) position[1] + (velocity * sin(orientation));
        }
};

class Pulse: public Spaceship{
    public:
        int velocity;
        int position[2];
        int orientation;

        Pulse()
        {
            velocity = 500;
        }

        void setPosition(int x, int y)
        {
            position[0] = x;
            position[1] = y;
        }

        int getXPosition()
        {
            return position[0];
        }

        int getYPosition()
        {
            return position[1];
        }

        void setOrientation(double t)
        {
            orientation = t;
        }

        void track()
        {
            position[0] = (int) position[0] + (velocity * cos(orientation));
            position[1] = (int) position[1] + (velocity * sin(orientation));
        }

};

int main()
{
    cout << "Please enter a username for Spaceship One: ";
    string input;
    cin >> input;
    cout << endl;
    Spaceship uno = Spaceship(input);

    Asteroid one = Asteroid();

    cout << one.getXPosition() << "," << one.getYPosition() << endl << one.getOrientation() << endl;
    
    Pulse pulse1 = Pulse();
    pulse1.setPosition(uno.getXPosition(), uno.getYPosition());
    pulse1.setOrientation(uno.getOrientation());
    int i = 0;
    while(i != 25)
    {
        cout << "------- Spaceship ------" << endl << "Position: " << uno.getXPosition() << "," << uno.getYPosition() << endl;
        uno.setPosition();
        cout << "------- Astroid -------" << endl << "Position: " << one.getXPosition() << "," << one.getYPosition() << endl;
        one.setPosition();
        cout << "------- Pulse -------" << endl << "Position: " << pulse1.getXPosition() << "," << pulse1.getYPosition() << endl;
        pulse1.track();
        i++;
    }
}