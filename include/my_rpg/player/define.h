/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-myrpg-florent.guittre
** File description:
** define
*/

#ifndef DEFINE_PLAYER_H_
    #define DEFINE_PLAYER_H_

    #define BASE_HP 100
    #define BASE_STRENGTH 1
    #define BASE_DEXTERITY 40
    #define BASE_RESISTANCE 5

    #define HP_MAX 200
    #define STRENGTH_MAX 10
    #define DEXTERITY_MAX 25
    #define RESISTANCE_MAX 50

    #define IS_MAX_HP(stat) (stat >= HP_MAX)
    #define IS_MAX_STRENGTH(stat) (stat >= STRENGTH_MAX)
    #define IS_MAX_DEXTERITY(stat) (stat >= DEXTERITY_MAX)
    #define IS_MAX_RESISTANCE(stat) (stat >= CONSTITUTION_MAX)

    #define STAT_POINTS_PER_LEVEL 5

const static int XP_FOR_LEVEL[] = {
    0,
    10,
    20,
    30,
    40,
    50,
    60,
    70,
    80,
    90,
    100,
    110,
    120,
    130,
    140,
    150,
    160,
    170,
    180,
    190,
    200,
    210,
    220,
    230,
    240,
    250,
    260,
    270,
    280,
    290,
    300
};

#endif /* !DEFINE_PLAYER_H_ */
