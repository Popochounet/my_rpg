/*
** EPITECH PROJECT, 2023
** save.c
** File description:
** -> Save game into a file.
*/

#include <errno.h>
#include <my_rpg.h>
#include <my_graphics.h>

const char *const SAVE_PATH = "helloworld.49.3";

save_file_state_t does_save_file_exist(void)
{
    FILE *file = fopen(SAVE_PATH, "rb");

    if (!file) {
        return errno == ENOENT ? SAVE_FILE_DOESNT_EXIST : SAVE_FILE_ERROR;
    }
    fclose(file);
    return SAVE_FILE_EXISTS;
}

bool save_to_file(player_t *player)
{
    bool status = player != NULL;
    FILE *file = status ? fopen(SAVE_PATH, "wb") : NULL;

    if (!file) {
        return false;
    }
    status &= fwrite(&player->base, sizeof(player->base), 1, file) == 1;
    status &= fwrite(&player->stat, sizeof(player->stat), 1, file) == 1;
    status &= fwrite(&player->hp.fill->data->size,
        sizeof(player->hp.fill->data->size), 1, file) == 1;
    status &= fwrite(&player->exp.fill->data->size,
        sizeof(player->exp.fill->data->size), 1, file) == 1;
    status &= fwrite(&player->type, sizeof(player->type), 1, file) == 1;
    fclose(file);
    return status;
}

bool load_from_file(player_t *player)
{
    bool status = player != NULL;
    FILE *file = status ? fopen(SAVE_PATH, "rb") : NULL;

    if (!file) {
        return false;
    }
    status &= fread(&player->base, sizeof(player->base), 1, file) == 1;
    status &= fread(&player->stat, sizeof(player->stat), 1, file) == 1;
    status &= fread(&player->hp.fill->data->size,
        sizeof(player->hp.fill->data->size), 1, file) == 1;
    status &= fread(&player->exp.fill->data->size,
        sizeof(player->exp.fill->data->size), 1, file) == 1;
    status &= fread(&player->type, sizeof(player->type), 1, file) == 1;
    fclose(file);
    return status;
}
