/*
** EPITECH PROJECT, 2023
** audio_init_free.c
** File description:
** -> Initializes audio and sound structures.
*/

#include <my_macros.h>
#include "audio.h"
#include "audio_path.h"

const float AUDIO_DONT_CHANGE_VOLUME = -1.f;
const float AUDIO_BGM_DEFAULT_VOLUME = 75.f;
const float AUDIO_SFX_DEFAULT_VOLUME = 100.f;

/*
    Initializes all pointers of an audio structure to NULL.
    For both BGM and SFX volume:
        -> sets it if in [0;100], otherwise sets the default value.
*/
void audio_init_base(audio_t *audio, float bgm_volume, float sfx_volume)
{
const float bgm_volumes[2] = { AUDIO_BGM_DEFAULT_VOLUME, bgm_volume };
const float sfx_volumes[2] = { AUDIO_BGM_DEFAULT_VOLUME, sfx_volume };

    *audio = (audio_t) {
        .bgm_main = NULL,
        .bgm_boss = NULL,
        .bgm_menu = NULL,
        .sfx_quest = { .buffer = NULL, .sound = NULL },
        .sfx_explosion = { .buffer = NULL, .sound = NULL },
        .sfx_error = { .buffer = NULL, .sound = NULL },
        .sfx_level_up = { .buffer = NULL, .sound = NULL },
        .sfx_nyah = { .buffer = NULL, .sound = NULL },
        .current_bgm = NULL,
        .bgm_volume = bgm_volumes[audio_is_volume_ok(bgm_volume)],
        .bgm_state = AUDIO_NOT_YET_STARTED,
        .sfx_volume = sfx_volumes[audio_is_volume_ok(sfx_volume)],
    };
}

/*
    Properly initializes a BGM, frees all allocated memory if a problem
        is encountered while initialization.
    Returns false on error, otherwise true
    Any value of volume not in [0;100] won't change the volume.
*/
bool audio_init_bgm(sfMusic **bgm, const char *path, float bgm_volume)
{
    RETURN_VALUE_IF(!bgm || !path, false);
    FREE_IF_ALLOCATED(*bgm, sfMusic_destroy);
    *bgm = sfMusic_createFromFile(path);
    RETURN_VALUE_IF(!(*bgm), false);
    sfMusic_setLoop(*bgm, true);
    return true;
}

/*
    Properly initializes a SFX, frees all allocated memory if a problem
        is encountered while initialization.
    Returns false on error, otherwise true
    Any value of volume not in [0;100] won't change the volume.
*/
bool audio_init_sfx(sound_t *sound, const char *path, float volume)
{
    RETURN_VALUE_IF(!sound || !path, false);
    audio_free_sfx(sound);
    sound->buffer = sfSoundBuffer_createFromFile(path);
    sound->sound = sfSound_create();
    if (!sound->buffer || !sound->sound) {
        audio_free_sfx(sound);
        return false;
    }
    sfSound_setBuffer(sound->sound, sound->buffer);
    return true;
}

static bool audio_init_impl(audio_t *audio, float bgm, float sfx)
{
    bool status = true;

    status &= audio_init_bgm(&audio->bgm_main, BGM_MAIN_PATH, bgm);
    status &= audio_init_bgm(&audio->bgm_menu, BGM_MENU_PATH, bgm);
    status &= audio_init_bgm(&audio->bgm_boss, BGM_BOSS_PATH, bgm);
    status &= audio_init_sfx(&audio->sfx_quest, SFX_QUEST_PATH, sfx);
    status &= audio_init_sfx(&audio->sfx_explosion, SFX_EXPLOSION_PATH, sfx);
    status &= audio_init_sfx(&audio->sfx_level_up, SFX_LEVEL_UP_PATH, sfx);
    status &= audio_init_sfx(&audio->sfx_error, SFX_ERROR_PATH, sfx);
    status &= audio_init_sfx(&audio->sfx_nyah, SFX_NYAH_PATH, sfx);
    status &= audio_init_sfx(&audio->sfx_49_3, SFX_49_3_PATH, sfx);
    return status;
}

/*
    Properly initialized an audio_t structure.
    For both bgm_volume and sfx_volume:
        -> Any value of volume not in [0;100] won't change the volume.
    Frees all that has been initializes if initialization cannot finish.
*/
bool audio_init(audio_t *audio, float bgm_volume, float sfx_volume)
{
    bool status = audio != NULL;

    RETURN_VALUE_IF(!status, false);
    audio_init_base(audio, bgm_volume, sfx_volume);
    status &= audio_init_impl(audio, bgm_volume, sfx_volume);
    if (!status) {
        audio_free(audio);
        return false;
    }
    audio->current_bgm = audio->bgm_menu;
    audio_update_volume(audio);
    return true;
}
