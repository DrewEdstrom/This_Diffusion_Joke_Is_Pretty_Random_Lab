#ifndef PARTICLE_H_INC
#define PARTICLE_H_INC

class Particle
{
    private:
    //the 1D position of the particle
    int position;

    public:
    //default constructor, position of particle is zero
    Particle()
    : position{0}
    {
    }

    //returns position of particle
    inline int get_position() const
    {
        return position;
    }

    //sets new position for particle
    inline void set_position(int new_pos)
    {
        position = new_pos;
    }

    //reduces the value of position, moving the particle "left"
    inline void move_left()
    {
        position--;
    }

    //increases the value of position, moving the particle "right"
    inline void move_right()
    {
        position++;
    }
};

#endif
