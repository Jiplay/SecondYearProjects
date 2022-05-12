/*
** EPITECH PROJECT, 2021
** bombaInterraction.cpp
** File description:
** bombaInterraction.cpp
*/

#include "../../Include/gamebox.hpp"
#include "../../Include/gamebomba.hpp"
#include "../../Include/gamecore.hpp"


// gamebomba gamecore::bombaPlace()
// {
//     if (IsKeyPressed(KEY_Q)) {
//         place_bomba = true;
//         if (lastkey == RIGHT) {
//             bombaPos = {(float)(playerPosition.x + 2.0f), (float)playerPosition.y, (float)(playerPosition.z) };
//             gamebomba b(bombaPos);
//             return b;
//         }
//         if (lastkey == LEFT) {
//             bombaPos = {(float)(playerPosition.x - 2.0f), (float)playerPosition.y, (float)(playerPosition.z) };
//             gamebomba b(bombaPos);
//             return b;
//         }
//         if (lastkey == DOWN) {
//             bombaPos = {(float)(playerPosition.x), (float)playerPosition.y, (float)(playerPosition.z + 2.0f) };
//             gamebomba b(bombaPos);
//             return b;
//         }
//         if (lastkey == UP) {
//             bombaPos = {(float)(playerPosition.x), (float)playerPosition.y, (float)(playerPosition.z - 2.0f) };
//             gamebomba b(bombaPos);
//             return b;
//         }
//     }
// }