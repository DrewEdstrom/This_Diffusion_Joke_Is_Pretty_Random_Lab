#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "particle.h"

using namespace std;

void simulate_particle_walk(Particle &p, int num_steps, int num_trials
                            , vector<int> &steps_arr
                            , vector<int> &trials_arr
                            , vector<int> &final_pos_arr);

int main()
{
    //where the number of steps being taken is stored
    vector<int> steps;
    //where the trial number is stored
    vector<int> trials;
    //where the final position from a particle walk is stored
    vector<int> final_positions;
    //the particle whose position is manipulated
    Particle p;
    
    //seed for random number generator
    srand(static_cast<int>(time(0)));
    cout << "\n\nWelcome to the 1D particle walk simulation!"
            << "\n\nRunning simulation...";
    //particle walk w/ 10 steps & 10 trials
    simulate_particle_walk(p, 10, 10, steps, trials, final_positions);
    //particle walk w/ 100 steps & 10 trials
    simulate_particle_walk(p, 100, 10, steps, trials, final_positions);
    //particle walk w/ 1000 steps & 10 trials
    simulate_particle_walk(p, 1000, 10, steps, trials, final_positions);
    //particle walk w/ 10000 steps & 10 trials
    simulate_particle_walk(p, 10000, 10, steps, trials, final_positions);
    //particle walk w/ 100000 steps & 10 trials
    simulate_particle_walk(p, 100000, 10, steps, trials, final_positions);
    cout << "\n\nResults:\n\n" 
            << "Number of Steps (N) | Trial Number (M) | Final Position (D)";

    //print results to screen in a table
    for(size_t i = 0; i < final_positions.size(); i++)
    {
        cout << "\n" << string(59, '-')
                << "\n" << setw(20) << left << steps[i] << "| "
                << setw(17) << left << trials[i] << "| "
                << setw(18) << left << final_positions[i];
    }
    
    return 0;
}

//simulate 1D movement of a Particle object given a number of steps and 
//number of trials. saves pairs of steps taken, trial number, and final
//position to 3 parallel arrays passed to function
void simulate_particle_walk(Particle &p, int num_steps, int num_trials
                            , vector<int> &steps_arr
                            , vector<int> &trials_arr
                            , vector<int> &final_pos_arr)
{
    int coin_flip;

    //reset the position of the particle to 0
    p.set_position(0);

    for(int t = 0; t < num_trials; t++)
    {
        trials_arr.push_back(t+1);
        steps_arr.push_back(num_steps);
        for(int s = 0; s < num_steps; s++)
        {
            //generate a number between 0 and 1
            coin_flip = rand() % 2;
            //move particle left or right depending on coin flip result
            (coin_flip == 0) ? p.move_left() : p.move_right();

            //append the position of the particle to the final_pos_arr 
            //after the last step is taken
            if(s == (num_steps - 1))
            {
                final_pos_arr.push_back(p.get_position());
            }
        }
    }
}
