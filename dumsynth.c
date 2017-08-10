#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

int offset;
const voices = 32;
int *sines;

void print_deviceinfo(SDL_AudioSpec a)
{
    printf(
        "freq:\t%d\n"
        "chans:\t%d\n"
        "buffer:\t%d\n",
        a.freq, a.channels, a.samples);
}

int get_period(int note)
{
    return (440*256) * pow(2, (note-60)/12.0);
}

int mix_data()
{
    return 0;
}

void audio_callback(void* userdata, Uint8* stream, int len)
{
    while(len --> 0) {
        stream[len] = ++offset % 200 > 100 ? 0x7f : -0x7f;
    }
}

int main()
{
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioSpec want = {
        .freq = 48000,
        .format = AUDIO_S16,
        .channels = 1,
        .samples = 512,
        .callback = audio_callback,
    };
    SDL_AudioSpec have;

    SDL_AudioDeviceID dev;
    if(!(dev = SDL_OpenAudioDevice(
             NULL, 0, &want, &have, SDL_AUDIO_ALLOW_ANY_CHANGE)))
        SDL_Log(SDL_GetError());

    print_deviceinfo(have);

    SDL_PauseAudioDevice(dev, 0);
    SDL_Delay(1000);
    SDL_CloseAudioDevice(dev);
}
