/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <stdio.h>

#include "cell.h"

typedef struct cell_s inventory_t;
typedef struct cell_helper_s inventory_helper_t;

inventory_t inventory_create(void);
void inventory_dump(inventory_t *inventory);
void inventory_init(inventory_t *inventory);
bool inventory_is_empty(inventory_t *inventory);
void inventory_add(inventory_t *inv1, inventory_t *inv2);
bool inventory_ge_cmp(const inventory_t *inv1, const inventory_t *inv2);