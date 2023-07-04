/*
** EPITECH PROJECT, 2023
** audio_control.c
** File description:
** -> Function for audio pause/play/stop.
*/

#include "audio.h"
#include "audio_play.h"

void (*bgm_functions[3])(sfMusic*) = {
    [AUDIO_PLAY] = sfMusic_play,
    [AUDIO_STOP] = sfMusic_stop,
    [AUDIO_PAUSE] = sfMusic_pause
};

void (*sfx_functions[3])(sfSound*) = {
    [AUDIO_PLAY] = sfSound_play,
    [AUDIO_STOP] = sfSound_stop,
    [AUDIO_PAUSE] = sfSound_pause
};

/*
    Controls (pause/play/stop) the current BGM.
*/
bool audio_control_bgm(audio_t *audio, audio_control_t action)
{
    if (action < 0 || action >= AUDIO_CONTROL_MAX || !audio) {
        return false;
    }
    if (audio->current_bgm) {
        bgm_functions[action](audio->current_bgm);
        audio->bgm_state = (audio_state_t)action;
        return true;
    }
    return false;
}

/*
    Updates volume and plays a SFX.
    Does nothing if sfx is < 0 or >= SFX_MAX, but returns false, otherwise true
*/
bool audio_play_sfx(audio_t *audio, sfx_t sfx)
{
    sound_t *const sfx_ptr = audio ?
        (sound_t*)((sfMusic**)audio + BGM_MAX) + sfx : NULL;

    if (sfx < 0 || sfx >= SFX_MAX || !audio || !sfx_ptr) {
        return false;
    }
    audio_update_volume(audio);
    if (sfx_ptr->sound) {
        sfx_functions[AUDIO_PLAY](sfx_ptr->sound);
    }
    return sfx_ptr != NULL;
}

/*
    Sets current BGM's pitch.
    Does nothing there's no current BGM (returns false, otherwise true).
*/
bool audio_set_bgm_pitch(audio_t *audio, float pitch)
{
    if (audio->current_bgm) {
        sfMusic_setPitch(audio->current_bgm, pitch);
        return true;
    }
    return false;
}
