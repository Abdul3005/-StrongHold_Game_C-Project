# -StrongHold_Game_C-Project
# StrongHold Kingdom Manager - C++ OOP Game

## Overview
StrongHold Kingdom Manager is a text-based strategy game where you take on the role of a medieval ruler managing your kingdom's resources, army, population, and economy. The game features object-oriented programming principles in C++ to simulate various aspects of kingdom management.

## Game Features

- **Population Management**: Control peasant, merchant, and noble populations
- **Resource System**: Manage food, wood, stone, and iron resources
- **Army Management**: Recruit, train, and maintain soldiers
- **Economy System**: Collect taxes, manage treasury, and handle inflation
- **Banking System**: Take loans, repay debts, and deal with corruption
- **Random Events**: Handle unpredictable kingdom events like famines, plagues, and revolts
- **Save/Load System**: Save your game progress and load it later

## How to Play

1. **Initialize your kingdom** by naming your ruler and setting up initial resources
2. **Manage your population** by building housing and gathering resources
3. **Maintain your army** by recruiting, training, and feeding soldiers
4. **Control your economy** through tax rates and treasury management
5. **Handle bank operations** including loans and audits
6. **Process each month** to see the effects of your decisions
7. **Respond to random events** that can impact your kingdom

## Classes and Components

### Main Classes:
- **Leadership**: Tracks ruler name and kingdom stability
- **Population**: Manages total population, births, deaths, and illness
- **Army**: Handles recruits, trained soldiers, morale, and corruption
- **Economy**: Manages treasury, tax rates, and inflation
- **Resources**: Tracks food, wood, stone, and iron supplies
- **Bank**: Handles loans, interest, and corruption
- **KingdomEvent**: Generates and processes random events
- **GameState**: Handles saving and loading game progress

### Social Classes:
- **Peasant**: Base working class population
- **Merchant**: Middle class that contributes to economy
- **Noble**: Upper class with political influence

## Compilation and Running

To compile and run the game:
1. Ensure you have a C++ compiler installed (g++, clang++, etc.)
2. Compile all .cpp files together:
   ```bash
   g++ *.cpp -o StrongHold
   ```
3. Run the executable:
   ```bash
   ./StrongHold
   ```

## Game Mechanics

- Resources are gathered automatically each month based on population
- Food spoilage occurs over time
- Army morale and corruption are affected by leadership stability
- Random events can trigger at any time with various effects
- Population happiness affects overall kingdom stability

## Tips for Success

- Balance your tax rates to keep all social classes happy
- Maintain enough food for your population and army
- Keep your army well-fed and paid to prevent coups
- Build enough housing to accommodate population growth
- Be cautious with loans as they increase corruption

Enjoy ruling your kingdom in StrongHold Kingdom Manager!
