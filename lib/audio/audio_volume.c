/*
** EPITECH PROJECT, 2023
** audio_misc.c
** File description:
** -> Volume handling.
*/

#include <SFML/Audio.h>
#include "audio.h"

bool audio_is_volume_ok(float volume)
{
    return volume >= 0.f && volume <= 100.f;
}

/*
    If volume is in [0;100], sfx's volume is changed (volume is in percents)
    otherwise, no change is performed.
*/
static void audio_change_sfx_volume(sfSound *sfx, float volume)
{
    if (sfx && audio_is_volume_ok(volume)) {
        sfSound_setVolume(sfx, volume);
    }
}

/*
    If volume is in [0;100], bgm's volume is changed (volume is in percents)
    otherwise, no change is performed.
*/
static void audio_change_bgm_volume(sfMusic *bgm, float volume)
{
    if (bgm && audio_is_volume_ok(volume)) {
        sfMusic_setVolume(bgm, volume);
    }
}

/*
    Updates the volume of all SFX and BGM in audio structure.
*/
void audio_update_volume(audio_t *audio)
{
    audio_change_bgm_volume(audio->bgm_main, audio->bgm_volume);
    audio_change_bgm_volume(audio->bgm_boss, audio->bgm_volume);
    audio_change_bgm_volume(audio->bgm_menu, audio->bgm_volume);
    audio_change_sfx_volume(audio->sfx_quest.sound, audio->sfx_volume);
    audio_change_sfx_volume(audio->sfx_explosion.sound, audio->sfx_volume);
    audio_change_sfx_volume(audio->sfx_level_up.sound, audio->sfx_volume);
    audio_change_sfx_volume(audio->sfx_error.sound, audio->sfx_volume);
    audio_change_sfx_volume(audio->sfx_nyah.sound, audio->sfx_volume);
    audio_change_sfx_volume(audio->sfx_49_3.sound, audio->sfx_volume);
}
