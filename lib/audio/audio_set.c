/*
** EPITECH PROJECT, 2023
** audio_set.c
** File description:
** -> Sets or unsets BGM and SFX.
*/

#include "audio.h"

/*
    Changes the active BGM to one in the enum bgm_t.
    If bgm isn't valid (< 0 or >= BGM_MAX), nothing is done, false is returned
        otherwise true.
    If start is true, the BGM immediately starts playing, otherwise it will
        need to be started manually.
*/
bool audio_set_active_bgm(audio_t *audio, bgm_t bgm, bool start)
{
    sfMusic *const new_bgm = audio ? *(bgm + (sfMusic**)(audio)) : NULL;

    if (bgm < 0 || bgm >= BGM_MAX || !new_bgm) {
        return false;
    }
    if (audio->current_bgm) {
        bgm_functions[AUDIO_PAUSE](audio->current_bgm);
    }
    audio->current_bgm = new_bgm;
    audio_update_volume(audio);
    if (start) {
        bgm_functions[AUDIO_PLAY](audio->current_bgm);
    }
    return true;
}
