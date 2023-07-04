/*
** EPITECH PROJECT, 2023
** audio_free.c
** File description:
** -> Frees audio and sound structures.
*/

#include <my_macros.h>
#include "audio.h"

/*
    Properly frees a sound_t structure.
*/
void audio_free_sfx(sound_t *sound)
{
    if (sound) {
        FREE_IF_ALLOCATED(sound->buffer, sfSoundBuffer_destroy);
        FREE_IF_ALLOCATED(sound->sound, sfSound_destroy);
    }
}

/*
    Properly frees an audio_t structure.
*/
void audio_free(audio_t *audio)
{
    RETURN_IF(!audio);
    FREE_IF_ALLOCATED(audio->bgm_main, sfMusic_destroy);
    FREE_IF_ALLOCATED(audio->bgm_boss, sfMusic_destroy);
    FREE_IF_ALLOCATED(audio->bgm_menu, sfMusic_destroy);
    audio_free_sfx(&audio->sfx_quest);
    audio_free_sfx(&audio->sfx_explosion);
    audio_free_sfx(&audio->sfx_error);
    audio_free_sfx(&audio->sfx_49_3);
    audio_free_sfx(&audio->sfx_level_up);
    audio_free_sfx(&audio->sfx_nyah);
}
