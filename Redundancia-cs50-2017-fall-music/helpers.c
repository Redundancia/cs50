// Helper functions for music

#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
        int x = atoi(&fraction[0]);
        int y = atoi(&fraction[2]);
        int duracel = 8/y*x;
        return duracel;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    //Use A4 as standard frequency
    float hertz = 440;
    char note2 = note[0];
    //If there are no sharps/flats
    if (strlen(note) == 2)
    {
        //Change the frequency according to octaves
        int octave = atoi(&note[1]);
        octave = 4 - octave;
        if (octave > 0)
        {
            hertz /= pow(2, octave);
        }
        else if (octave < 0)
        {
            octave *= -1;
            hertz = hertz * (pow(2.0, octave));
        }
    }

    //If there are sharps/flats
    else
    {
        if (strlen(note) == 3)
        {
            char note3 = note[1];
            int octave = atoi(&note[2]);
            octave = 4 - octave;

            //Change frequency according to octaves
            if (octave > 0)
            {
                hertz /= pow(2, octave);
            }
            if (octave < 0)
            {
                octave *= -1;
                hertz *= pow(2, octave);
            }

            //Change frequency according to flats/sharps
            if (note3 == 'b')
            {
                hertz *= pow(2, (-1.0/12.0));
            }
            if (note3 == '#')
            {
                hertz *= pow(2, (1.0/12.0));
            }
        }
    }

    //Change frequency according to letters
    if (note2 == 'B')
    {
        hertz *= pow(2, 2.0/12.0);
    }
    if (note2 == 'C')
    {
        hertz *= pow(2, -9.0/12.0);
    }
    if (note2 == 'D')
    {
        hertz *= pow(2, -7.0/12.0);
    }
    if (note2 == 'E')
    {
        hertz *= pow(2, -5.0/12.0);
    }
    if (note2 == 'F')
    {
        hertz *= pow(2, -4.0/12.0);
    }
    if (note2 == 'G')
    {
        hertz *= pow(2, -2.0/12.0);
    }
    //Return and round the given frequency, if they give us some gibberish value we still give them 440 tho
    return round(hertz);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    // if (s[0] == '\n')
    if (strlen(s) == 0)
    {
       return true;
    }
    else
    {
        return false;
    }
}