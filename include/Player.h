#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player();
        unsigned int _playerXcord = 1;
        unsigned int _playerYcord = 1;

    protected:

    private:
        unsigned int _points = 0;
        void movePlayer();

};

#endif // PLAYER_H