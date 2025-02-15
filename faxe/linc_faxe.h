/**
* Faxe - FMOD bindings for Haxe
*
* The MIT License (MIT)
*
* Copyright (c) 2016 Aaron M. Shea
* Copyright (c) 2020 Tanner Moore
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#define IMPLEMENT_API

#if (defined __MWERKS__)
	#include <SIOUX.h>
#endif

#include <fmod_studio.hpp>

namespace linc
{
	namespace faxe
	{
		//// FMOD System

		/**
		 * Turns on print statements for any errors happening within the FMOD integration
		 * \param[onOff] turns debug messages on or off
		 */
		extern void fmod_set_debug(bool onOff);

		/**
		 * Only needed for the html5 API. Will always return true here
		 */
		extern bool fmod_is_initialized();

		/**
		 * Initialization of FMOD sound system
		 * \param[numChannels] number of channels to allocate for this sound system
		 */
		extern void fmod_init(int numChannels = 32);
		
		/**
		 * Update the FMOD command buffer, should be called once per "tick"
		 */
		extern void fmod_update();
		
		/**
		 * Should be called by a background thread. Updates FMOD 60 times per second until a SIGTERM is received
		 */
		extern void update_fmod_async();


		/**
		 * Sets a global parameter value by name, including the path if needed.
		 * \param[paramName] ::String Parameter name, including the path if needed (case-insensitive)
		 * \param[value] float Value for given name.
		 */
    extern void fmod_set_param_by_name(const ::String& paramName, float value);

		/**
		 * Sets the 3D attributes of the listener.
     * \param[listener] int Index of listener to set 3D attributes on. Listeners are indexed from 0, to FMOD_MAX_LISTENERS - 1, in a multi-listener environment.
		 * \param[posX] float X Position in world space used for panning and attenuation
		 * \param[posY] float Y Position in world space used for panning and attenuation
		 * \param[posZ] float Z Position in world space used for panning and attenuation
		 * \param[velocityX] float X Velocity in world space used for doppler
		 * \param[velocityY] float Y Velocity in world space used for doppler
		 * \param[velocityZ] float Z Velocity in world space used for doppler
		 * \param[forwardX] float X Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[forwardY] float Y Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[forwardZ] float Z Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[upX] float X Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[upY] float Y Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[upZ] float Z Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[attenuationX] float X Position used for calculating attenuation
		 * \param[attenuationY] float Y Position used for calculating attenuation
		 * \param[attenuationZ] float Z Position used for calculating attenuation
		 */
		extern void fmod_set_listener_attributes(int listener, float posX, float posY, float posZ, float velX, float velY, float velZ, float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ, float attenuationX, float attenuationY, float attenuationZ );

		/**
		 * Sets the 3D attributes of the listener.
     * \param[listener] int Index of listener to set 3D attributes on. Listeners are indexed from 0, to FMOD_MAX_LISTENERS - 1, in a multi-listener environment.
		 * \param[posX] float X Position in world space used for panning and attenuation
		 * \param[posY] float Y Position in world space used for panning and attenuation
		 * \param[posZ] float Z Position in world space used for panning and attenuation
		 * \param[velocityX] float X Velocity in world space used for doppler
		 * \param[velocityY] float Y Velocity in world space used for doppler
		 * \param[velocityZ] float Z Velocity in world space used for doppler
		 * \param[forwardX] float X Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[forwardY] float Y Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[forwardZ] float Z Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[upX] float X Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[upY] float Y Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[upZ] float Z Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 */
		extern void fmod_set_listener_attributes_no_atten(int listener, float posX, float posY, float posZ, float velX, float velY, float velZ, float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ );

		//// Sound Banks

		/**
		 * Load a FMOD sound bank file
		 * \param[bankName] ::String the file path of the sound bank to load
		 */
		extern void fmod_load_bank(const ::String& bankName);

		/**
		 * Unload a FMOD sound bank file
		 * \param[bankName] ::String the file path of the sound bank to unload
		 */
		extern void fmod_unload_bank(const ::String& bankName);
		
		//// Event Descriptions

		/**
		 * Load an event description from a loaded bank
		 * Event instances are spawned from event descriptions
		 * Event descriptions are loaded automatically when creating event instances
		 * \param[eventPath] ::String the path of the event
		 */
		extern void fmod_load_event_description(const ::String& eventPath);

		/**
		 * Check if an event description is currently loaded
		 * \param[eventDescriptionName] ::String the event description to check
		 */
		extern bool fmod_is_event_description_loaded(const ::String& eventDescriptionName);

		//// Events

		/**
		 * Create and play an event instance in a fire-and-forget fashion
		 * There is no way to interact with these events once they are started
		 * Follows the Master Track rules set in the Event's settings in FMOD Studio (Max Instances, Stealing, and probably more)
		 * \param[eventPath] ::String the bank path of the event
		 */
		extern void fmod_create_event_instance_one_shot(const ::String& eventPath);

		/**
		 * Create and play an event instance in a fire-and-forget fashion
		 * There is no way to interact with these events once they are started
		 * Follows the Master Track rules set in the Event's settings in FMOD Studio (Max Instances, Stealing, and probably more)
		 * \param[eventPath] ::String the bank path of the event
		 */
		extern void fmod_create_event_instance_one_shot_at(const ::String& eventPath, float posX, float posY, float posZ, float velX, float velY, float velZ, float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ );

		/**
		 * Create and play an event instance and store a reference to it
		 * Events created with this method can receive other commands via this API (like passing in parameters)
		 * \param[eventPath] ::String the bank path of the event
		 * \param[eventInstanceName] ::String the name to assign to the new event instance
		 */
		extern void fmod_create_event_instance_named(const ::String& eventPath, const ::String& eventInstanceName);

		/**
		 * Check if an event instance is currently loaded
		 * \param[eventInstanceName] ::String the event instance to check
		 */
		extern bool fmod_is_event_instance_loaded(const ::String& eventInstanceName);

		/**
		 * Sends the "play" command to an existing event instance
		 * \param[eventInstanceName] ::String the name of the event instance
		 */
		extern void fmod_play_event_instance(const ::String& eventInstanceName);

		/**
		 * Sends the "pause" or "unpause" command to all event instances on a given bus
		 * \param[busPath] ::String the path to the bus
		 * \param[shouldBePaused] bool if the event instance should be paused
		 */
		extern void fmod_set_pause_for_all_events_on_bus(const ::String& busPath, bool shouldBePaused);

		/**
		 * Sends the "stop" command to all event instances on a given bus
		 * \param[busPath] ::String the path to the bus
		 */
		extern void fmod_stop_all_events_on_bus(const ::String& busPath);

		/**
		 * Sends the "pause" or "unpause" command to an existing event instance
		 * \param[eventInstanceName] ::String the name of the event instance
		 * \param[shouldBePaused] bool if the event instance should be paused
		 */
		extern void fmod_set_pause_on_event_instance(const ::String& eventInstanceName, bool shouldBePaused);

		/**
		 * Sends the "stop" command to an existing event instance
		 * \param[eventInstanceName] ::String the name of the event instance
		 */
		extern void fmod_stop_event_instance(const ::String& eventInstanceName);

		/**
		 * Immediately stops an existing event instance
		 * \param[eventInstanceName] ::String the name of the event instance
		 */
		extern void fmod_stop_event_instance_immediately(const ::String& eventInstanceName);

		/**
		 * Release a loaded event instance from memory
		 * \param[eventInstanceName] ::String the name of the event instance
		 */
		extern void fmod_release_event_instance(const ::String& eventInstanceName);

		/**
		 * Check to see if an event instance is currently playing
		 * \param[eventInstanceName] ::String the name of the event instance
		 * \return ::Bool if the event is currently playing
		 */
		extern bool fmod_is_event_instance_playing(const ::String& eventInstanceName);

		/**
		 * Get the playback state of an existing event instance
		 * \param[eventInstanceName] ::String the name of the event instance
		 */
		extern FMOD_STUDIO_PLAYBACK_STATE fmod_get_event_instance_playback_state(const ::String& eventInstanceName);

		/**
		 * Check to see if an event is currently playing
		 * \param[eventInstanceName] ::String the name of the event to get param value from
		 * \param[paramName] ::String the name of the param to GET
		 * \return float the current value of the param from the specified event
		 */
		extern float fmod_get_event_instance_param(const ::String& eventInstanceName, const ::String& paramName);

		/**
		 * Set the parameter value of a loaded event
		 * \param[eventInstanceName] ::String the name of the event that contains the parameter to set
		 * \param[paramName] ::String the name of the param to SET
		 * \param[value] float the new value to set the param to
		 */
		extern void fmod_set_event_instance_param(const ::String& eventInstanceName, const ::String& paramName, float value);

		/**
		 * Set the 3d attributes of a loaded event
		 * \param[eventInstanceName] ::String the name of the event that contains the parameter to set
		 * \param[posX] float X Position in world space used for panning and attenuation
		 * \param[posY] float Y Position in world space used for panning and attenuation
		 * \param[posZ] float Z Position in world space used for panning and attenuation
		 * \param[velocityX] float X Velocity in world space used for doppler
		 * \param[velocityY] float Y Velocity in world space used for doppler
		 * \param[velocityZ] float Z Velocity in world space used for doppler
		 * \param[forwardX] float X Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[forwardY] float Y Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[forwardZ] float Z Forwards orientation, must be of unit length (1.0) and perpendicular to up
		 * \param[upX] float X Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[upY] float Y Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 * \param[upZ] float Z Upwards orientation, must be of unit length (1.0) and perpendicular to forward
		 */
		extern void fmod_set_event_instance_3d_attributes(const ::String& eventInstanceName, float posX, float posY, float posZ, float velX, float velY, float velZ, float forwardX, float forwardY, float forwardZ, float upX, float upY, float upZ );

		//// Callbacks

		/**
		 * Tracks playback callback events for a given event instance
		 * Callbacks can be checked with fmod_check_callbacks_for_event_instance
		 * \param[eventInstanceName] ::String the name of the loaded event instance to track
		 * \see https://tanneris.me/FMOD-Callback-Types
		 */
		extern void fmod_set_callback_tracking_for_event_instance(const ::String& eventInstanceName);

		/**
		 * Can only be used after assigning the event listener to an event instance
		 * Checks for any FMOD_STUDIO_EVENT_CALLBACK_TYPE callbacks to have occured on the primary event instance
		 * Once a callback value specifiied by mask is read, that specific callback value is reset to 0
		 * \param[eventInstanceName] ::String the name of the registered event instance to check
		 * \param[callbackEventMask] ::unsigned int the bitmask that corresponds to the underlying callback type you want to check
		 * \see https://tanneris.me/FMOD-Callback-Types
		 */
		extern bool fmod_check_callbacks_for_event_instance(const ::String& eventInstanceName, unsigned int callbackEventMask);

	} // faxe + fmod namespace
} // linc namespace
