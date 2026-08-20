/**
 * Faxe - C++ FMOD bindings - Minimal FFI layer
 *
 * The MIT License (MIT)
 * Copyright (c) 2016 Aaron M. Shea
 * Copyright (c) 2020 Tanner Moore
 */
#pragma once

#define IMPLEMENT_API

namespace linc {
namespace faxe {

//// System
extern bool fmod_is_initialized();
extern int fmod_init(int numChannels);
extern void fmod_update();
extern void fmod_set_auto_update(bool enabled);

//// Banks
extern int fmod_load_bank(const ::String& path);
extern void fmod_unload_bank(const ::String& path);

//// Events - One shot
extern int fmod_fire_one_shot(const ::String& eventPath);
extern int fmod_fire_one_shot_at(const ::String& eventPath, float posX, float posY, float posZ, float velX, float velY, float velZ,
    float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ);

//// Events - Managed instances (handle-based)
extern int fmod_create_instance(const ::String& eventPath);
extern void fmod_start(int handle);
extern void fmod_stop(int handle, int immediate);
extern void fmod_release(int handle);
extern void fmod_set_paused(int handle, bool paused);
extern int fmod_get_playback_state(int handle);
extern int fmod_get_timeline_position(int handle);

//// Parameters
extern float fmod_get_param(int handle, const ::String& name);
extern void fmod_set_param(int handle, const ::String& name, float value);
extern void fmod_set_global_param(const ::String& name, float value);

//// 3D Audio
extern void fmod_set_listener_attributes(int listener, float posX, float posY, float posZ, float velX, float velY, float velZ,
    float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ);
extern void fmod_set_instance_3d_attributes(int handle, float posX, float posY, float posZ, float velX, float velY, float velZ,
    float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ);

//// Bus
extern void fmod_set_bus_paused(const ::String& path, bool paused);
extern void fmod_stop_bus(const ::String& path);
extern void fmod_set_bus_volume(const ::String& path, float volume);
extern float fmod_get_bus_volume(const ::String& path);
extern void fmod_set_bus_mute(const ::String& path, bool mute);
extern bool fmod_get_bus_mute(const ::String& path);

//// Callbacks
extern void fmod_enable_callbacks(int handle);
extern bool fmod_poll_callbacks(int handle, unsigned int mask);

} // namespace faxe
} // namespace linc
