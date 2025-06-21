# DimSoles

## How to Play

- Build and launch the program
- Press any key to start the game
- Create your character
- Enter your selections and you're good to go!

## Story Synopsis

You character wakes up in a burnt down village and need to break the curse keeping everyone alive forever, you being a warmblood can do that.

## Controls

- Enter numbers to make choices

## Features Implemented

- Lambda functions for simplifying code
- Auto keyword to subvert type conversion in simple applications
- Many conditionals and loops
- Enums to track game states, enemy types and area types

## File Structure

- each source file, minus main, has a corresponding header for simple management purposes
- main acts as the entry point, the game loop exists within game
- player and enemy are for the player class and enemy class respectively and handle the creation of respective objects
- commands is a generic file for any miscellaneous functions I needed
- area handles the different areas in the map and the enemies they contain

## Challenges Faced

- Control flow has always been a hassle, the use of enumes, do while loops, and switch cases helped a lot, specifically enums, those were a life saver.
- Scope: Went into this project with big, complicated ideas and ended up getting caught up in my own feature creep and had to restart a couple of times. Eventually I took a more procedural, or "waterfall" approach, where I coded as I went, not great for long term maintainability but it helped me get the ball rolling.

## Future Improvements

- Dynamic options
- Cause and effect gameplay
- file i/o (ran out of time)
- better formatting with terminal colors and printf formatting