#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

class Spaceship{
    public:
        int position[2];
        double orientation;
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
            orientation = rand() / double(RAND_MAX);
            orientation = 360 * orientation;
            //velocity = rand() % 99;
            velocity = 0;
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

        double getOrientation()
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

        double updateOrientation(string a)
        {
            if(a == "d")
            {
                orientation += 1;
            }
            else if(a == "a")
            {
                orientation -= 1;
            }
            return orientation;
        }

        int updateVelocity(string b)
        {
            if(b == "w")
            {
                velocity += 1;
            }
            else if(b == "s")
            {
                velocity -= 1;
            }
            return velocity;
        }

        void collision()
        {
            position[0] = rand() % 9999;
            position[1] = rand() % 9999;
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
            velocity = rand() % 99;
            size = rand() % 9;
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

        int getSize()
        {
            return size;
        }

        void setVelocity(int x)
        {
            velocity = x;
        }

        void setSize()
        {
            size = 0;
        }

        void setPosition()
        {
            position[0] = (int) position[0] + (velocity * cos(orientation));
            position[1] = (int) position[1] + (velocity * sin(orientation));
        }
};

class Pulse{
    public:
        int velocity;
        int position[2];
        int orientation;

        Pulse()
        {
            velocity = 150;
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
    int x;
    int y;
    int h;
    int xpt;
    int ypt;
    int hpt;
    bool flag = false;
     //Define the array for space
    char space[20][50];
    // Define characters for each item
    char spaceship2 = 'V';
    char asteroid2 = 'X';
    char laser = 'Q';

    string input;

    Spaceship uno = Spaceship(input);

    Asteroid one = Asteroid();

    cout << one.getXPosition() << "," << one.getYPosition() << endl << one.getOrientation() << endl;
    
    //Pulse pulse1 = Pulse();
    Pulse pulse[100];
    pulse[0] = Pulse();
    //pulse1.setPosition(uno.getXPosition(), uno.getYPosition());
    //pulse1.setOrientation(uno.getOrientation());
    int i = 0;
    int j = 0;
    while(true)
    {
        cout << "------- Spaceship ------" << endl << "Position: " << uno.getXPosition() << "," << uno.getYPosition() << endl;
        uno.setPosition();
        cout << "------- Astroid -------" << endl << "Position: " << one.getXPosition() << "," << one.getYPosition() << endl;
        one.setPosition();
        //cout << "------- Pulse -------" << endl << "Position: " << pulse1.getXPosition() << "," << pulse1.getYPosition() << endl;
        cout << "------- Spaceship Orientation -------" << endl << uno.getOrientation() << endl;
        //pulse1.track();
        i++;
        // Populate the array with blank space characters
        
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                space[i][j] = '-';
            }
        }
        space[(int)(uno.getXPosition() *.001)][(int)(uno.getYPosition() *.001)] = spaceship2;
        space[(int)(one.getXPosition()*.001)][(int)(one.getYPosition()*.001)] = asteroid2;

        if(flag == true)
        {
            space[(int)(pulse[j].getXPosition()*.001)][(int)(pulse[j].getYPosition()*.001)] = laser;
            pulse[j].track();
            xpt = one.getXPosition() - pulse[j].getXPosition();
            ypt = one.getYPosition() - pulse[j].getYPosition();
            hpt = xpt^2 + ypt^2;
            hpt = sqrt(hpt);
            if(hpt < one.getSize())
            {
                cout << "track: " << hpt << endl;
                cout << "Asteroid Destroyed" << endl;
                one.setSize();
                break;
            }

            cout << "got here" << endl;
        }
    
        for(int i = 0; i < 20; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                cout << space[i][j];
            }
            cout << endl;
        }

        cin >> input;

        if(input == "w" || input == "s")
        {
            cout << "Velocity: " << uno.updateVelocity(input) << endl;
        }
        else if(input == "a" || input == "d")
        {
            cout << "Orientation: " << uno.updateOrientation(input) << endl;
        }
        else if(input == "k")
        {
            j++;
            pulse[j] = Pulse();
            pulse[j].setOrientation(uno.getOrientation());
            pulse[j].setPosition(uno.getXPosition(), uno.getYPosition());
            space[(int)(pulse[j].getXPosition()*.001)][(int)(pulse[j].getYPosition()*.001)] = laser;
            flag = true;
            cout << "shot" << endl;
        }
        else if(input == "stop")
        {
            break;
        }
        
        x = one.getXPosition() - uno.getXPosition();
        y = one.getYPosition() - uno.getYPosition();
        h = x^2 + y^2;
        h = sqrt(h);
        if(h < one.getSize())
        {
            uno.setLives();
            if(uno.getLives() > 0)
            {
                cout << "Lives left: " << uno.getLives() << endl;
                uno.collision();
            }
            else if(uno.getLives() == 0)
            {
                cout << "------- Game Over -------" << endl;
                break;
            }
        }
    }
    // loop that updates the array everytime something move
    //for(int i = 0; i < spaceship.length; i++)
    //{
    //}
}