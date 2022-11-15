42_proBase&Derive.cpp

The goal for this Project is to create a simple two-dimensional predator-prey simulation. In this simulation the prey are ants and the pred-ators are doodlebugs. These critters live in a world composed of a 20 × 20 grid of cells. Only one critter may occupy a cell at a time. The grid is  enclosed, so a critter is not allowed to move off the edges of the world. Time is simulated in time steps. Each critter performs some action every time step.


**The ants behave according to the following model:
Move.** Every time step, randomly try to move up, down, left, or right. If the neighboring cell in the selected direction is occupied or would move the ant off the grid, then the ant stays in the current cell.

**Breed.** If an ant survives for three time steps, then at the end of the time step (that is; after moving) the ant will breed. This is simulated by creat-ing a new ant in an adjacent (up, down, left, or right) cell that is empty. If there is no empty cell available, then no breeding occurs. Once an off-spring is produced, an ant cannot produce an offspring until three more time steps have elapsed.


**The doodlebugs behave according to the following model:
Move.** Every time step, if there is an adjacent ant (up, down, left, or right), then the doodlebug will move to that cell and eat the ant. Otherwise, the doodlebug moves according to the same rules as the ant. Note that a doodlebug cannot eat other doodlebugs.

**Breed.** If a doodlebug survives for eight time steps, then at the end of the time step it will spawn off a new doodlebug in the same manner as the ant.

**Starve.** If a doodlebug has not eaten an ant within the last three time steps, then at the end of the third time step it will starve and die. The doodlebug should then be removed from the grid of cells.

**During one turn, all the doodlebugs should move before the ants do.**


Initialize the world with 5 doodlebugs and 100 ants. After each time step, prompt the user to press Enter to move to the next time step. You should see a cyclical pattern between the population of predators and prey, although random perturbations may lead to the elimination of one or both species.

<img width="289" alt="1" src="https://user-images.githubusercontent.com/85269000/201489977-733fbcbd-d962-40fe-9c4f-02c8c03a080b.png">

<img width="277" alt="2" src="https://user-images.githubusercontent.com/85269000/201490007-b5005191-3e6d-4a4d-b188-15eeca6bee67.png">

Many steps later:

<img width="215" alt="3" src="https://user-images.githubusercontent.com/85269000/201490015-30b4361c-dfc2-42ac-9c83-2252b14975dd.png">


<img width="209" alt="4" src="https://user-images.githubusercontent.com/85269000/201490017-cd886e03-229f-4e93-83d3-d69a69d8308e.png">


LeetCode: https://docs.google.com/document/d/1cmRuttyxV5VkMjsvMLmH7y_Kx19h4Fmph5PG7v8N9lE/edit
