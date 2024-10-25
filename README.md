# conveyGameOfLife
 simulation of Conway's Game of Life in C++ using a 2D grid-based console display
Conway's Game of Life Simulation Project in C++

  This project simulates Conway's Game of Life, a cellular automaton, using a 2D grid where 
  cells can be "alive" or "dead." Each cell's state evolves over generations based on the 
  number of live neighbors surrounding it. The rules are simple:

      1. Survival: A live cell with 2 or 3 live neighbors stays alive.
      2. Birth: A dead cell with exactly 3 live neighbors becomes alive.
      3. Death: Live cells with fewer than 2 or more than 3 neighbors die.

  The project includes several pre-set patterns, and each pattern evolves following these 
  rules. The simulation is displayed in the console, creating a visualization of complex 
  patterns and behaviors emerging from simple initial configurations.

  Key Features:
  - Multiple predefined patterns that initialize the grid in various configurations
  - Functions to apply Game of Life rules, counting neighbors, and updating cell states
  - Continuous console display to observe pattern evolution over time

  How to Run:
  - Compile and run this project from the terminal. Once running, select a pattern and 
    observe its progression based on Conway's Game of Life rules