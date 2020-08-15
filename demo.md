# Demo

## Some words
> There was an old story in UW about a chamber underneath...\
About heros defeating monsters to acquire the final treasure: A GOLDEN GOOSE!\
However, strange happenings are afoot in the chamber this term.\
The monsters have revolted and demanded to be made the heroes due to their negative portrayal in previous iterations of CC3k!

## Before the game starts

So that basically is the story. It’s a story about bad guys(at least what they portrayed as).

Basically, before reading this document, you should have successfully compiled the program using the Makefile. Then there should be a cc3k executable under the current directory.

Before running the actual program, we HIGHLY suggest you to resize the terminal window to 79*32 for the best view experience.

## CC3K
Run the cc3k executable and the following should appear:
```
> ./cc3k
|-----------------------------------------------------------------------------|
|                                                                             |
|                                                                             |
|                                                                             |
|                                                                             |
|                                                                             |
|           /-------|\    /-------|\   |-------\     |----|\  /----\          |
|          /        ||   /        ||   |++++++++|    |    || /    /|          |
|         |   /-----||  |   /-----||   |----\+++|    |    ||/    //           |
|         |   |/-----/  |   |/-----/        |+++|    |    |/    //            |
|         |   ||        |   ||         |----/+++|    |         //             |
|         |   ||        |   ||         |++++++++|    |        |/              |
|         |   ||        |   ||         |++++++++|    |         \              |
|         |   ||        |   ||         |----\+++|    |    |\    \             |
|         |   \-----|\  |   \-----|\        |+++|    |    ||\    \            |
|          \        ||   \        ||   |----/+++|    |    || \    \           |
|           \-------||    \-------||   |++++++++/    |----||  \----/|         |
|            \-------/     \-------/   |-------/      \----/   \----/         |
|                                                                             |
|                                                                             |
|                                                                             |
|                                                                             |
|                                                                             |
|-----------------------------------------------------------------------------|
There was an old story in UW about a chamber underneath...
About heros defeating monsters to acquire the final treasure: A GOLDEN GOOSE!
However, strange happenings are afoot in the chamber this term.
The monsters have revolted and demanded to be made the heroes due to their negative portrayal in previous iterations of CC3k!

Enter the race you wish to be:
```
It asks for a race. A race for player is either one of:

| Race | HP | Attack | Defence | Description |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| Shade | 125 | 25 | 25 | N/A |
| Drow | 150 | 25 | 15 | All potions have their effect magnified by 1.5 |
| Vampire | 50 | 25 | 25 | Gains 5 HP every successful attack and has no maximum HP |
| Troll | 120 | 25 | 15 | Regains 5 HP every turn; HP is capped at 120 HP |
| Goblin | 110 | 15 | 20 | Steals 5 gold from every slain enemy |

If you don't select one, we will pick shade as a default for you. It is recommanded to pick Troll for this demo for smoother experience. If you are a high-level player of CC3K you can ignore the previous sentence.

Type the first letter of each race in lower case to select it. The following shold appear:
```
> t
|-----------------------------------------------------------------------------|
|                                                                             |
| |--------------------------|        |-----------------------|               |
| |L....@.E........G.........|        |G................PG...O|               |
| |..................G...L.W.+########+.......L........P.....P|-------|       |
| |....................W.....|   #    |................G..............|--|    |
| |....L.W...................|   #    |...............P..................|--| |
| |----------+---------------|   #    |----+----------------|...............| |
|            #                 #############                |...............| |
|            #                 #     |-----+------|         |...............| |
|            #                 #     |....G.......|         |........P......| |
|            ###################     |....O....W..|   ######+.............M.| |
|            #                 #     |P..\.......G|   #     |..P............| |
|            #                 #     |-----+------|   #     |--------+------| |
|  |---------+-----------|     #           #          #              #        |
|  |.............H.......|     #           #          #         |----+------| |
|  |G..G...H.............|     ########################         |.W.........| |
|  |.........P...........|     #           #                    |...........| |
|  |.............P......O|     #    |------+--------------------|...........| |
|  |..HW.................|     #    |.......................................| |
|  |...................L.+##########+.......................................| |
|  |.............L.......|          |.............P...............G.........| |
|  |---------------------|          |---------------------------------------| |
|                                                                             |
|-----------------------------------------------------------------------------|
Race: Troll Gold: 0                                                  Floor 1
HP: 120
Atk: 25
Def: 15
Action: Player character has spawned.
Enter your command:
```
You have successfully entered the chamber! The first thing you would probably notice is the text display of the map. You can see enemies, potions and treasures placed all over the chamber. Enemies are in these type:

| Race | HP | Attack | Defence | Description |
| ----------- | ----------- | ----------- | ----------- | ----------- |
| Shade | 125 | 25 | 25 | N/A |
| Drow | 150 | 25 | 15 | All potions have their effect magnified by 1.5 |
| Vampire | 50 | 25 | 25 | Gains 5 HP every successful attack and has no maximum HP |
| Troll | 120 | 25 | 15 | Regains 5 HP every turn; HP is capped at 120 HP |
| Goblin | 110 | 15 | 20 | Steals 5 gold from every slain enemy |
